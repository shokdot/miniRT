RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
RESET	= \033[0;37m
SKY		= \033[1;36m

NAME = libft.a

SRC = $(wildcard *.c)
HEADERS = $(wildcard ../../includes/*.h)
INCLUDE = -I ../../includes
OBJS = $(SRC:.c=.o)
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all:$(NAME)

$(NAME): $(OBJS) $(HEADERS)
	@echo "$(YELLOW) Compiling libft object files $(RESET)"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(GREEN) Libft is done! $(RESET)"

clean:
	@$(RM) $(OBJS)
	@echo "$(RED) Deleting libft files! $(RESET)"

fclean: clean
	@$(RM) $(NAME)

re:fclean all

%.o:%.c
	@cc $(CFLAGS) $(INCLUDE) -c $< -o $@

.PHONY: all bonus clean fclean re
