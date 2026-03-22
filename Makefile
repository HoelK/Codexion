CC=cc
FLAGS=-Wall -Wextra -Werror -g3 -pthread -I./header
SRCS=src/main.c \
	 src/routine.c \
	 src/monitor.c \
	 src/args.c \
	 src/utils.c \
	 src/init.c \
	 src/memory.c \
	 src/access.c
OBJS=$(SRCS:.c=.o)
NAME=codexion

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
