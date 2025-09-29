CC = gcc
CFLAGS = -Wall -Wextra -Iheaders
SRC = $(wildcard sources/*.c)
OBJ = $(patsubst sources/%.c, build/%.o, $(SRC))

oceanDepth.exe: $(OBJ)
	$(CC) $(OBJ) -o $@ -lmingw32


build/%.o: sources/%.c
	@if not exist build mkdir build
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build oceanDepth.exe
