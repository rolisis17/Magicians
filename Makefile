SRCS = magician.c utils.c
NAME = philo
CC = cc -Wall -Wextra -Werror -g
RM = rm -rf

all:$(NAME)

$(NAME):
	@$(CC) $(SRCS) -pthread -o $(NAME)

clean:
	@echo "Nothing to clean;"

fclean:
	$(RM) $(NAME)

re: fclean all