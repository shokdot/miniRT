RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
RESET	= \033[0;37m
SKY		= \033[1;36m

NAME = miniRT

SRC_DIR = srcs/
OBJ_DIR = build/
SUBDIRS = parsing

LIBFTPATH = libs/libft/
LISTPATH = libs/list_c/

INCLPATH = includes/ #$(LIBFTPATH) #$(LISTPATH)includes/

SRCDIRS = $(addprefix $(SRC_DIR)/, $(SUBDIRS))
SRCS = $(notdir $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))) $(notdir $(SRC_DIR)/main.c)
OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

# UNAME = $(shell uname -s)
# ARCH = $(shell uname -m)
# ifeq ($(UNAME), Darwin)
# 	ifeq ($(ARCH), arm64)
# 		LREADLINE = -L/opt/homebrew/Cellar/readline/8.2.13/lib -l readline
# 		INCLPATH += /opt/homebrew/Cellar/readline/8.2.13/include
# 	else
# 		LREADLINE = -Lreadline_local/lib -lreadline
# 		INCLPATH += ./readline_local/include/
# 	endif
# else
# 	LREADLINE = -Lreadline_local -lreadline
# endif

CFLAGS = -Wall -Wextra -Werror -I
DEBUG = -fsanitize=address -g3
HEADERS = $(foreach H, $(INCLPATH), $(wildcard $(H)*.h))

LIBFT = $(LIBFTPATH)libft.a
LIST = $(LISTPATH)liblist_c.a

LIBFLAGS = -L$(LIBFTPATH) -l ft  -L$(LISTPATH) -l list_c # -L$(SETPATH) -lset $(LREADLINE)

all : $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(LIBFT) $(LIST) $(OBJ_DIR) $(OBJ) $(HEADERS)  Makefile
	@$(CC) $(CFLAGS) $(INCLPATH) $(LIBFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN) Executable file has been created $(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) Makefile
	@$(CC) $(CFLAGS) $(INCLPATH) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/*/%.c $(HEADERS) Makefile
	@$(CC) $(CFLAGS) $(INCLPATH) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFTPATH) all

$(LIST) :
	@make -C $(LISTPATH) all

clean :
	@make -C $(LIBFTPATH) clean
	@make -C $(LISTPATH) clean
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

#config:

.PHONY : all clean fclean re push #config
