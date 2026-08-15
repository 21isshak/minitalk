SRC_SERVER = server.c
SRC_CLIENT = client.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
CC = gcc -Wall -Werror -Wextra
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
RM = rm -f
NAME_SERVER = server
NAME_CLIENT = client

all: $(NAME_SERVER) $(NAME_CLIENT)

$(LIBFT):
		$(MAKE) -C libft

$(PRINTF):
		$(MAKE) -C ft_printf

$(NAME_SERVER): $(OBJ_SERVER) $(LIBFT) $(PRINTF)
				$(CC) -o $(NAME_SERVER) $(OBJ_SERVER) $(LIBFT) $(PRINTF)

$(NAME_CLIENT): $(OBJ_CLIENT) $(LIBFT) $(PRINTF)
				$(CC) -o $(NAME_CLIENT) $(OBJ_CLIENT) $(LIBFT) $(PRINTF)

clean:
		$(MAKE) clean -C libft
		$(MAKE) clean -C ft_printf
		$(RM) $(NAME_SERVER).o $(NAME_CLIENT).o

fclean: clean
		$(MAKE) fclean -C libft
		$(MAKE) fclean -C ft_printf
		$(RM) $(NAME_SERVER) $(NAME_CLIENT)

re: fclean $(NAME_SERVER) $(NAME_CLIENT)

.PHONY: all clean fclean re
