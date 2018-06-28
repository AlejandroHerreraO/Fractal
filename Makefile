FILES_C = src/main.c src/draw.c src/frac.c src/com.c src/mlx.c src/utils.c
FILES_O = main.o draw.o frac.o com.o mlx.o utils.o
NAME = fractol
FLAGS = -Wall -Wextra -Werror
FRAMEWORKS = -framework OpenGL -framework AppKit
LIBS = -L . -lft -lmlx -lpthread

all: $(NAME)

lft:
	@make -C libft/ all

$(NAME): lft
	@echo "\033[0;5;33mMaking minilibx\033[0m"
	@make -C minilibx/ all
	@echo "\033[0;32mFinished making \033[97;40mminilibx\033[0m"
	@cp minilibx/libmlx.a ./
	@cp libft/libft.a ./
	@echo "\033[0;5;33mCompiling and building\033[0m"
	@gcc -c $(FLAGS) $(FILES_C) -I ./includes -I ./minilibx
	@gcc -o $(NAME) $(FLAGS) $(FILES_O) -I ./includes -I ./minilibx $(FRAMEWORKS) $(LIBS)
	@echo "\033[0;32mFinished building \033[40;97m$(NAME)\033[0m"

clean:
	@/bin/rm -f $(FILES_O) $(FILES_O)
	@make -C libft/ clean
	@make -C minilibx/ clean

fclean:
	@/bin/rm -f $(FILES_O) $(FILES_O)
	@/bin/rm -f $(NAME)
	@/bin/rm -f libft.a
	@/bin/rm -f libmlx.a
	@make -C libft/ fclean
	@make -C minilibx/ clean

re:	fclean all

test:
	@echo "\033[0;34mRemaking for test\033[0m"
	@rm $(NAME)
	@gcc -c $(FLAGS) $(FILES_C) -I ./includes -I ./minilibx
	@gcc -o $(NAME) $(FLAGS) $(FILES_O) -I ./includes -I ./minilibx $(FRAMEWORKS) $(LIBS)

retest: test
