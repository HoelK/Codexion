CC=cc
FLAGS=-Wall -Wextra -Werror -g3 -pthread -I./header
SRCS=src/main.c \
	 src/routine.c \
	 src/args.c \
	 src/utils.c \
	 src/init.c \
	 src/memory.c
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
