RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
RESET	= \033[0;37m
SKY		= \033[1;36m

NAME = miniRT

SRC_DIR = srcs/
OBJ_DIR = build
SUBDIRS = init_data parsing utils

LIBFTPATH = libs/libft/
LISTPATH = libs/list_c/

INCLPATH = includes/

SRCDIRS = $(addprefix $(SRC_DIR)/, $(SUBDIRS))
SRCS = $(notdir $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))) $(notdir $(SRC_DIR)/main.c)
OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

PLATFORM = $(shell uname -s)

ifeq ($(PLATFORM), Darwin)
	INCLPATH += libs/mlx_mac/
	MLXPATH = libs/mlx_mac/
	XFLAGS = -framework OpenGL -framework AppKit
else
#INCLPATH += libs/mlx_mac/
#MLXPATH = libs/mlx_mac/
#XFLAGS = -framework OpenGL -framework AppKit
endif

CFLAGS = -Wall -Wextra -Werror
DEBUG = -fsanitize=address -g3
HEADERS = $(foreach H, $(INCLPATH), $(wildcard $(H)*.h))
CMP_HEADERS = $(patsubst %,-I%, $(INCLPATH))

LIBFT = $(LIBFTPATH)libft.a
LIST = $(LISTPATH)liblist_c.a
MLX = $(MLXPATH)libmlx.a

LIBFLAGS = -L$(LISTPATH) -l list_c -L$(LIBFTPATH) -l ft -L$(MLXPATH) -l mlx $(XFLAGS)

all : $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJ) $(LIST) $(LIBFT) $(MLX)  $(HEADERS)  Makefile
	@$(CC) $(DEBUG) $(CFLAGS) $(CMP_HEADERS) $(OBJ) $(LIBFLAGS) -o $(NAME)
	@echo "$(GREEN) Executable file has been created $(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) Makefile
	@$(CC) $(DEBUG) $(CFLAGS) $(CMP_HEADERS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/*/%.c $(HEADERS) Makefile
	@$(CC) $(DEBUG) $(CFLAGS) $(CMP_HEADERS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFTPATH) all

$(LIST):
	@make -C $(LISTPATH) all

$(MLX):
	@make -C $(MLXPATH) all

clean :
	@make -C $(LIBFTPATH) clean
	@make -C $(LISTPATH) clean
	@make -C $(MLXPATH) clean
	@rm -f $(OBJ_DIR)/*.o
	@rm -rf $(OBJ_DIR)
	@echo "$(RED) Object files have been deleted $(RESET)"

fclean : clean
	@make -C $(LIBFTPATH) fclean
	@make -C $(LISTPATH) fclean
	@rm -f $(NAME)
	@echo "$(RED) Executable file has been deleted $(RESET)"

re : fclean all

push:
	@read -p "Enter branch name: " branch; \
	read -p "Enter commit message: " msg; \
	git add .; \
	git commit -m "$$msg"; \
	git push -u origin "$$branch"

.PHONY : all clean fclean re push
