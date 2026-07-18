# 2D Rigid-Body Physics Engine in C: Architectural Roadmap

This technical roadmap outlines the complete architecture, memory layouts, and pipeline logic required to build a deterministic 2D rigid-body physics engine from scratch in C. This roadmap is entirely text- and data-driven; no graphics code or visual rendering libraries are required.

---

## Phase 1: The Linear Algebra Foundations
*Before you can simulate a universe, you need to define its coordinate space.*

- [ ] **Vector2D Math Library**
  - [ ] Define a `Vector2D` struct containing `float x, y`.
  - [ ] Implement primitive vector math operations:
    - [ ] `Vec2_Add(v1, v2)` and `Vec2_Sub(v1, v2)`
    - [ ] `Vec2_Scale(v, scalar)`
    - [ ] `Vec2_Dot(v1, v2)` (returns scalar float)
    - [ ] `Vec2_Cross(v1, v2)` (2D cross product yielding a scalar float)
  - [ ] Implement magnitude and unit normalization operations:
    - [ ] `Vec2_LengthSquared(v)` (preferred for performance comparison checks)
    - [ ] `Vec2_Length(v)` (requires `sqrtf`)
    - [ ] `Vec2_Normalize(v)` (handles safe division by zero)

---

## Phase 2: Core Data Layout & World State
*Structuring how bodies live in memory.*

- [ ] **RigidBody Specifications**
  - [ ] Create a `RigidBody` struct layout.
  - [ ] Add linear kinematic state components: `position`, `velocity`, `acceleration`, `forceAccumulator`.
  - [ ] Add physical mass properties: `mass` and cache `invMass` (1.0 / mass) where static/unmovable bodies use an `invMass = 0.0f`.
  - [ ] Add surface coefficients: `restitution` (bounciness clamp between 0.0 and 1.0) and `friction`.
- [ ] **Shape Definitions (Variant Tag/Union Pattern)**
  - [ ] Design an enum tag for shape classification (e.g., `SHAPE_CIRCLE`, `SHAPE_BOX`).
  - [ ] Implement shape structures:
    - [ ] Circle: `float radius`.
    - [ ] Box (AABB): `Vector2D halfExtents` (distance from center to edge on X and Y).
  - [ ] Link shapes to the `RigidBody` struct via an explicit reference or embedded variant union.
- [ ] **The Physics World Container**
  - [ ] Set up a global allocation array or continuous dynamic buffer (`RigidBody* bodies`) to store the active entities.
  - [ ] Add execution scene configuration options: constant constant-force vectors like a global `gravity` vector.

---

## Phase 3: The Engine Pipeline & Kinematics Loop
*Getting things moving step-by-step using a stable clock.*

- [ ] **The Semi-Implicit Euler Integrator**
  - [ ] Implement physics state step function accepting a discrete `float dt` time interval.
  - [ ] For every non-static body:
    - [ ] Compute current acceleration: `a = gravity + (forceAccumulator * invMass)`
    - [ ] Update velocity: `v = v + a * dt`
    - [ ] Update position: `x = x + v * dt`
    - [ ] Zero out `forceAccumulator` array inputs to prepare for the next tick frame loop.
- [ ] **Fixed Time Step Loop Accumulator**
  - [ ] Build a main program simulation wrapper that locks execution updates.
  - [ ] Tracks frame duration time, accumulates real elapsed time into a local pool, and updates physics via constant steps (e.g., `dt = 1.0f / 60.0f`) to keep behavior strictly deterministic.

---

## Phase 4: The Collision Pipeline (Narrowphase)
*Detecting intersection geometry without applying reactions yet.*

- [ ] **Manifold Architecture Blueprint**
  - [ ] Create a `CollisionManifold` dataset layout to hold interception outputs.
  - [ ] Include fields: pointers or indices to `bodyA` and `bodyB`, a unit `normal` vector, `penetrationDepth`, and boolean flag `isColliding`.
- [ ] **Intersection Detection Function Matrix**
  - [ ] Implement Circle vs Circle intersection (`DetectCircleCircle(bodyA, bodyB, manifold)`).
  - [ ] Implement Box vs Box (AABB vs AABB) intersection (`DetectBoxBox(bodyA, bodyB, manifold)`).
  - [ ] Implement Circle vs Box hybrid intersection checks.

---

## Phase 5: The Impulse Solver
*Forcing bodies apart and updating velocity components correctly.*

- [ ] **Positional Displacement Correction (Linear Penetration Resolution)**
  - [ ] Implement a method to shift bodies backwards along the manifold normal using their relative inverse mass parameters.
  - [ ] Introduce a scalar percentage factor (commonly called a "slop factor" between 20% to 80%) to stop jitter artifacts on objects resting flush against floors.
- [ ] **Impulse Resolution Solver**
  - [ ] Calculate relative interface velocity vector: `v_rel = v_B - v_A`
  - [ ] Extract projection velocity along the collision normal vector: `v_normal = v_rel • normal`
  - [ ] Early out check: If `v_normal > 0`, shapes are already separating. Do not resolve.
  - [ ] Calculate the impulse scalar value using restitution coefficient: `j = -(1 + e) * v_normal / (invMass_A + invMass_B)`
  - [ ] Update target linear velocity parameters immediately using impulse direction scales:
    - [ ] `v_A = v_A - (j * invMass_A) * normal`
    - [ ] `v_B = v_B + (j * invMass_B) * normal`

---

## Phase 6: Pure Data Validation (No Graphics)
*Verifying engine accuracy entirely through the console.*

- [ ] **Console-Based State Logging**
  - [ ] Create a telemetry logger function: `LogWorldState(World* world, float totalSimTime)`.
  - [ ] Format outputs neatly to show critical scalar metrics (`[Time: 2.45s] Body 0 - Pos: (0.00, 4.21), Vel: (0.00, -9.81)`).
- [ ] **Unit Test Verification Scenarios**
  - [ ] Test 1: Single body dropping under constant gravity. Verify freefall equations ($y = 0.5 \cdot g \cdot t^2$) match data precisely.
  - [ ] Test 2: Perfect elastic collision ($e = 1.0$) between two identical circle masses. Verify total kinetic energy is perfectly conserved before and after impact.
  - [ ] Test 3: Static boundary floor test. Verify a dropping ball hits a heavy unmovable platform (`invMass = 0.0f`), rebounds, and settles cleanly without falling through the floor or jittering uncontrollably.
