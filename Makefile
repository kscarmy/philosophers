NAME_LIBFT = philosophers.a

NAME = philo

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC_C = srcs/ft_exit_error.c\
			srcs/ft_utils.c\

MAIN_C = srcs/main.c\

OBJS = ft_exit_error.o\
			ft_utils.o\


all : $(NAME)

$(NAME) :
	@$(CC) $(CFLAGS) $(SRC_C) -c
	@ar -rc $(NAME_LIBFT) $(OBJS)
	@ranlib $(NAME_LIBFT)
	@$(CC) $(CFLAGS) $(MAIN_C) $(NAME_LIBFT) -o $(NAME)

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(NAME_LIBFT)

re : fclean all
	@rm -rf $(OBJS)
