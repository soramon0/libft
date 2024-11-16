LIB_NAME = libft.a
SRC = $(shell find . -type f -name '*.c' -not -path './tests/*' -not -path './*bonus.c')
SRC_WITH_BONUS = $(shell find . -type f -name '*.c' -not -path './tests/*')
OBJ = $(SRC:.c=.o)
OBJ_WITH_BONUS = $(SRC_WITH_BONUS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(LIB_NAME)

$(LIB_NAME):
	$(CC) $(CFLAGS) -c $(SRC)
	ar rcs $(LIB_NAME) $(OBJ)

start:
	@$(CC) $(CFLAGS) $(SRC_WITH_BONUS) ./tests/run.c -o run
	@./run
	@rm -f run 

testrun:
	$(CC) $(CFLAGS) -c $(SRC) ./tests/ft_isalpha.c -o testrunner
	cc $(CFLAGS) -c $(SRC)
	@./testrunner
	@rm -f testrunner

bonus:
	$(CC) $(CFLAGS) -c $(SRC_WITH_BONUS)
	ar rcs $(LIB_NAME) $(OBJ_WITH_BONUS)

clean:
	rm -f $(OBJ_WITH_BONUS)

fclean: clean
	rm -f $(LIB_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
