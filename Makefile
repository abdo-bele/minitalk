RESOURC = client.c server.c
OBJECTS = $(RESOURC:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra

all: server client

bonus: server client

server: server.o printf
	@$(CC) -o $@ $< ft_printf/libftprintf.a

client: client.o printf
	@$(CC) -o $@ $< ft_printf/libftprintf.a

%.o: %.c 
	@$(CC) $(CFLAGS) -c $< 

printf: 
	@make -C ft_printf

clean :
	@rm -f $(OBJECTS)
	@make -C ft_printf clean

fclean : clean
	@rm -f server client ft_printf/libftprintf.a

re : fclean all