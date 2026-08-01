# Delta Physics Engine

Delta is a lightweight physics engine written in C, focused on implementing Newtonian mechanics primarily in 2 dimensions.

## Status

Delta is currently **very unstable** and under active development.

The project has intentionally not been versioned yet, will begin when `v1` comes out.

## Features

* 2D vector mathematics
* 2D rigid bodies
* Force and acceleration handling
* Gravity calculations
* Coulomb force calculations
* Collision detection (in development)

## Building

Delta currently uses a Makefile for building.

```sh
# Builds all tests
make tests

# Builds as static library
make lib

# Builds all
make
```

## License

Currently uses [GNU GPL-v3](LICENSE), may change on `v1` release of project.
