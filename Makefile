CC = clang
CFLAGS = -Iinclude -Wall -Wextra -Wpedantic -O2
LDFLAGS = -Xlinker /subsystem:console

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

clean:
	rm -f tests/*.exe demoraylib.exe