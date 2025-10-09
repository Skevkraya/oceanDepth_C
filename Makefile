CC = gcc
CFLAGS = -Wall -Wextra -Iheaders -Iheaders/items
SRC_DIR = sources
OBJ_DIR = build
BIN = oceanDepth.exe

SRC = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))


    ifeq ($(shell uname 2>/dev/null),)
        MKDIR = if not exist build mkdir build
        RM = rmdir /S /Q build & del /Q oceanDepth.exe 2>nul || true
    else
        MKDIR = mkdir -p build
        RM = rm -rf build oceanDepth.exe
    endif

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)   # ✅ crée build/items/ si besoin
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM)
