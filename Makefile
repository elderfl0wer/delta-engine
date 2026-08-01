CC = clang
AR = llvm-ar

CFLAGS = -Iinclude -Wall -Wextra -Wpedantic -O2
LDFLAGS = -Xlinker /subsystem:console

SRC = \
	src/math/vector2.c \
	src/math/vector3.c \
	src/physics/rigidbody2d.c

OBJ = \
	build/math/vector2.o \
	build/math/vector3.o \
	build/physics/rigidbody2d.o

all: vector2 vector3 rigidbody2d static
tests: vector2 vector3 rigidbody2d
lib: static

static: build $(OBJ)
	$(AR) rcs build/delta.lib $(OBJ)

build:
	mkdir -p build/math build/physics

build/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

vector2:
	$(CC) $(CFLAGS) \
		src/math/vector2.c \
		src/math/vector3.c \
		tests/vector2.c \
		-o tests/vector2.exe $(LDFLAGS)

vector3:
	$(CC) $(CFLAGS) \
		src/math/vector3.c \
		src/math/vector2.c \
		tests/vector3.c \
		-o tests/vector3.exe $(LDFLAGS)

rigidbody2d:
	$(CC) $(CFLAGS) \
		src/math/vector3.c \
		src/math/vector2.c \
		src/physics/rigidbody2d.c \
		tests/rigidbody2d.c \
		-o tests/rigidbody2d.exe $(LDFLAGS)

clean:
	rm -f tests/*.exe build/*.o build/*.a
	rm -rf build/
