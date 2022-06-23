NAME = philo
MAIN = main.c
PRINTF = ft_printf
LIBPRINTF = ft_printf/libftprintf.a
SRC = parsing.c atoi.c threads.c time.c print.c free.c
OBJS = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror -pthread
HEADER = include/philosophers.h ft_printf/ft_printf.h
DEL = rm -f

all: $(NAME)

%.o: %.c
	cc $(FLAGS) -c $<

$(NAME): $(LIBPRINTF) $(OBJS) $(HEADER)
	cc $(FLAGS) $(LIBPRINTF) $(MAIN) $(OBJS) -o $(NAME)

sanitize: FLAGS += -fsanitize=address -g
sanitize: re all

$(LIBPRINTF):
	$(MAKE) -C $(PRINTF)

clean:
	$(DEL) $(OBJS)
	$(MAKE) -C $(PRINTF) clean

fclean: clean
	$(DEL) $(NAME)
	$(MAKE) -C $(PRINTF) fclean

re: fclean all

.PHONY: all re clean fclean