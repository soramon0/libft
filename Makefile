LIB_NAME = libft.a
SRC = $(shell find . -type f -name '*.c' -not -path './tests/*')
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(LIB_NAME)

$(LIB_NAME):
	$(CC) $(CFLAGS) -c $(SRC)
	ar rc $(LIB_NAME) $(OBJ)
	ranlib $(LIB_NAME)

start:
	@$(CC) $(CFLAGS) $(SRC) ./tests/run.c -o run
	@./run
	@rm -f run 

testrun:
	$(CC) $(CFLAGS) -c $(SRC) ./tests/ft_isalpha.c -o testrunner
	cc $(CFLAGS) -c $(SRC)
	@./testrunner
	@rm -f testrunner

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIB_NAME)

re: fclean all

.PHONY: all clean fclean re
