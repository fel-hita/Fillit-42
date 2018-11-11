
CFLAG = -Wall -Wextra -Werror

SRC = error.c fillit.c functionlst.c functetris.c sqrt.c libft/ft*

NAME = fillit

all : $(NAME)
$(NAME) :
	gcc -c $(CFLAG) $(SRC)
	gcc -o $(NAME) *.o

clean :
	rm -f *.o
	rm -f .DS_Store
fclean : clean
	rm -f fillit
re : fclean all