CC = cc
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
LIB = lib

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))

LIB_DIR = $(LIB)/minilibx_macos
COMPILER_FLAGS = -I$(INCLUDE_DIR) -I$(LIB_DIR) -g -Wall -Werror -Wextra
LIB_FLAGS = -lmlx -framework OpenGl -framework Appkit
NAME = fdf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LIB_FLAGS) $(COMPILER_FLAGS) -o $(NAME) $(OBJ)
	@cd $(LIB_DIR) && $(MAKE)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE_DIR)/fdf.h
	@mkdir -p $(dir $@)
	$(CC) $(COMPILER_FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(BUILD_DIR)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean
