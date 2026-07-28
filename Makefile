CC = clang
CFLAGS = -Iinclude -Wall -Wextra -Wpedantic -O2
LDFLAGS = -Xlinker /subsystem:console

RAYLIB_INC = -Idemos/raylib/raylib/include
RAYLIB_LIB = -Ldemos/raylib/raylib/lib -lraylib
RAYLIB_LINK = -lopengl32 -lgdi32 -lwinmm -luser32 -lshell32 -ladvapi32

all: vector2 vector3 rigidbody2d

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

demoraylib:
	$(CC) $(CFLAGS) $(RAYLIB_INC) \
		src/math/vector2.c \
		src/math/vector3.c \
		src/physics/rigidbody2d.c \
		demos/raylib/demo.c \
		-o demoraylib.exe \
		$(RAYLIB_LIB) \
		$(RAYLIB_LINK) \
		$(LDFLAGS)

clean:
	rm -f tests/*.exe demoraylib.exe