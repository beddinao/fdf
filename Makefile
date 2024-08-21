#SRC = init.c cordination.c drawing.c drawing_utils.c formulas.c drawing_2.c fdf.c \
#	  general_utils.c parsing_file.c specific_task_utils.c \
#	  get_next_line.c get_next_line_utils.c \
#	  formulas_utils.c parsing_utils.c

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
