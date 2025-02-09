#
#

GREEN	= \033[1;32m
RESET	= \033[0;37m


NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

CFLAGS+= -DSTRINGPUTX11 -w

all: $(NOM)

$(NOM):	$(OBJ)
	@ar -rcs $(NOM) $(OBJ)
	@echo "$(GREEN) MLX lib is done! $(RESET)"

clean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

%.o: %.m
	@$(CC) $(CFLAGS) -c $< -o $@

re: clean all
