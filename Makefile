RESOURC = client.c server.c
RESOURCB = client_bonus.c server_bonus.c
OBJECTS = $(RESOURC:.c=.o)
OBJECTSB = $(RESOURCB:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra

all: server client

bonus: server_bonus client_bonus

server: server.o printf
	@$(CC) -o $@ $< ft_printf/libftprintf.a

server_bonus: server_bonus.o printf
	@$(CC) -o $@ $< ft_printf/libftprintf.a

client: client.o printf
	@$(CC) -o $@ $< ft_printf/libftprintf.a

client_bonus: client_bonus.o printf
	@$(CC) -o $@ $< ft_printf/libftprintf.a

%.o: %.c 
	@$(CC) $(CFLAGS) -c $< 

printf: 
	@make -C ft_printf

clean :
	@rm -f $(OBJECTS)
	@rm -f $(OBJECTSB)
	@make -C ft_printf clean

fclean : clean
	@rm -f server client ft_printf/libftprintf.a
	@rm -f server_bonus client_bonus ft_printf/libftprintf.a

re : fclean all