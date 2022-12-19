NAME=philo
CC=cc
HEADER=philo.h
CFLAGS= -Wall -Wextra -Werror
MAKEFILE=Makefile
SRCS=philo.c\
	utils.c\
	utils_2.c\
	exit.c\
	actions.c
	
OBJS=$(SRCS:.c=.o)

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

%.o: %.c $(MAKEFILE) $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re