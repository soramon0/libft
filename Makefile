LIB_NAME = libft.a
SRCS_NAMES = ./is_alpha.c
OBJS_NAMES = ./ft_alpha.o
INCLUDES_DIR = libft.h
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(LIB_NAME)

$(LIB_NAME):
	cc $(CFLAGS) -c ./ft_isalpha.c -o ./ft_isalpha.o
	ar rc $(LIB_NAME) $(OBJS_NAMES)
	ranlib $(LIB_NAME)

testrun:
	@cc $(CFLAGS) ./ft_isalpha.c ./test/ft_isalpha.c -o testrunner
	@./testrunner
	@rm -f testrunner

clean:
	rm -f $(OBJS_NAMES)

fclean: clean
	rm -f $(LIB_NAME)

re: fclean all

.PHONY: all clean fclean re
