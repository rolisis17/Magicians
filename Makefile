SRCS = magician.c utils.c parse.c threads.c init.c existence.c time_not_exist.c cat.c check.c
NAME = philo
CC = cc -Wall -Wextra -Werror -g #-fsanitize=address
RM = rm -rf

all:$(NAME)

$(NAME):
	$(CC) $(SRCS) -pthread -o $(NAME)

clean:
	@echo "Nothing to clean;"

fclean:
	$(RM) $(NAME)

re: fclean all