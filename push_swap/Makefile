NAME=push_swap
CC=cc
HEADER=push_swap.h
CFLAGS= -Wall -Wextra -Werror
MAKEFILE=Makefile
SRCS=main.c\
	push_swap.c \
	utils.c\
	ft_lstnew.c\
	ft_lstadd_front.c\
	ft_lstadd_back.c\
	ft_lstdelone.c\
	ft_lstclear.c\
	ft_lstfirst.c\
	ft_lstlast.c\
	ft_lstsize.c\
	ft_lstmap.c\
	operations_1.c\
	operations_2.c\
	five_sort.c\
	big_sort.c\
	big_sort_utils.c\
	ret_help.c\

OBJS=$(SRCS:.c=.o)

.PHONY: all clean fclean re

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

%.o: %.c $(MAKEFILE) $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
 
clean:
	rm -f *.o

fclean: clean
	rm -f push_swap

re: fclean all
