CC=cc
FLAGS=-Wall -Wextra -Werror -g3 -pthread
SRCS=main.c args.c utils.c init.c memory.c
OBJS=$(SRCS:.c=.o)
NAME=philo

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $^ -o $@

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all
