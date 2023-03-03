CC = cc
FLAGS = -Wall -Wextra -Werror
SRC = libft/ft_atoi.c libft/ft_putnbr.c libft/ft_isdigit.c libft/ft_strlen.c libft/ft_putstr_fd.c libft/ft_memset.c
OBJ = $(SRC:.c=.o)
SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus


all : $(OBJ)
	$(CC) $(FLAGS) client.c  -o $(CLIENT)  $^
	$(CC) $(FLAGS) server.c  -o $(SERVER)  $^
bonus : $(OBJ)
	$(CC) $(FLAGS) client_bonus.c  -o $(CLIENT_BONUS)  $^
	$(CC) $(FLAGS) server_bonus.c  -o $(SERVER_BONUS)  $^

%.o : %.c minitalk.h
	$(CC) $(FLAGS) -o $@ -c $<


clean :
	rm -f $(OBJ)
	
fclean : clean
	rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)
re : fclean all 

.PHONY : all bonus clean fclean re