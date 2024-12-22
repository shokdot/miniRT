RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
RESET	= \033[0;37m

NAME = liblist_c.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs
OBJ_DIR = build
SUBDIRS = insertion deletion make_node get_index

INCLPATH = ../../includes
INCLUDES = $(foreach H, $(INCLPATH), -I $(H))
HEADERS = $(foreach H, $(INCLPATH), $(wildcard $(H)*.h))

LIBFTPATH = ../libft/

SRCDIRS = $(addprefix $(SRC_DIR)/, $(SUBDIRS))
SRCS = $(notdir $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))) $(notdir $(wildcard $(SRC_DIR)/*.c))
OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

AR = ar rc
RM = rm -rf

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJ)
	@echo "$(YELLOW) Compiling List object files $(RESET)"
	@$(AR) $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(GREEN) List lib done! $(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) Makefile
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/*/%.c $(HEADERS) Makefile
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED) Cleaning List lib $(RESET)"

re: fclean all


.PHONY: all clean fclean re
