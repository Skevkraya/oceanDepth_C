CC = gcc
CFLAGS = -Wall -Wextra -Iheaders
SRC = $(wildcard sources/*.c)
OBJ = $(patsubst sources/%.c, build/%.o, $(SRC))

# Détection de l’OS
    ifeq ($(shell uname 2>/dev/null),)
        MKDIR = if not exist build mkdir build
        RM = rmdir /S /Q build & del /Q oceanDepth.exe 2>nul || true
    else
        MKDIR = mkdir -p build
        RM = rm -rf build oceanDepth.exe
    endif

oceanDepth.exe: $(OBJ)
	$(CC) $(OBJ) -o $@

build/%.o: sources/%.c
	@$(MKDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM)
