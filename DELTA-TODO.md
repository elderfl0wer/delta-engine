# 2D Rigid-Body Physics Engine in C: Architectural Roadmap

This technical roadmap outlines the complete architecture, memory layouts, and pipeline logic required to build a deterministic 2D rigid-body physics engine from scratch in C. Graphics implementation is intentionally deferred to the final stage, allowing the entire core system to be developed and verified using pure mathematical validation.

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
  - [ ] Add physical mass properties: `mass` and cache `invMass` ($1/	ext{mass}$) where static/unmovable bodies use an `invMass = 0.0f`.
  - [ ] Add surface coefficients: `restitution` (bounciness clamp $0.0 \le e \le 1.0$) and `friction`.
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
    - [ ] Compute current acceleration: $ec{a} = ec{g} + (ec{F}_{	ext{accumulated}} 	imes 	ext{invMass})$.
    - [ ] Update velocity: $ec{v} = ec{v} + ec{a} \cdot dt$.
    - [ ] Update position: $ec{x} = ec{x} + ec{v} \cdot dt$.
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
  - [ ] Calculate relative interface velocity vector: $ec{v}_{	ext{rel}} = ec{v}_B - ec{v}_A$.
  - [ ] Extract projection velocity along the collision normal vector: $v_{	ext{normal}} = ec{v}_{	ext{rel}} \cdot ec{n}$.
  - [ ] Early out check: If $v_{	ext{normal}} > 0$, shapes are already separating. Do not resolve.
  - [ ] Calculate the impulse scalar value using restitution coefficient: $j = rac{-(1 + e)(ec{v}_{	ext{rel}} \cdot ec{n})}{	ext{invMass}_A + 	ext{invMass}_B}$.
  - [ ] Update target linear velocity parameters immediately using impulse direction scales:
    - [ ] $ec{v}_A = ec{v}_A - (j \cdot 	ext{invMass}_A) \cdot ec{n}$
    - [ ] $ec{v}_B = ec{v}_B + (j \cdot 	ext{invMass}_B) \cdot ec{n}$

---

## Phase 6: Graphics Subsystem Integration
*Deferred completely to the final stage.*

- [ ] **Engine State Decoupled Rendering Wrapper**
  - [ ] Implement a simple wrapper to pass data blocks from the engine arrays out to an isolated graphics API layer.
  - [ ] Map engine vector coordinate axes onto window pixel screenspace scales.
  - [ ] Write dynamic basic shape primitives drawing functions (e.g., rasterizing plain colored square wireframes and lines for tracking radii/normals visually using tools like Raylib, SDL2, or OpenGL).
