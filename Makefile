CC = clang
CFLAGS = -Iinclude -Wall -Wextra -Wpedantic
LDFLAGS = -Xlinker /subsystem:console

all: vector2 vector3

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

clean:
	del tests\*.exe
