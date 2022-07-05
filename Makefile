NAME = philo
MAIN = main.c
SRC = parsing.c atoi.c simulation.c time_death.c print_and_death.c threads_and_eat.c mutex_init.c
OBJS = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror -pthread
HEADER = include/philosophers.h
DEL = rm -f

all: $(NAME)

%.o: %.c
	cc $(FLAGS) -c $<

$(NAME): $(LIBPRINTF) $(OBJS) $(HEADER)
	cc $(FLAGS) $(LIBPRINTF) $(MAIN) $(OBJS) -o $(NAME)

sanitize: FLAGS += -fsanitize=thread -g
sanitize: re all

clean:
	$(DEL) $(OBJS)

fclean: clean
	$(DEL) $(NAME)

re: fclean all

.PHONY: all re clean fclean