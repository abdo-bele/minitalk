NAME = libftprintf.a

SRC = ft_putchar.c ft_putstr.c ft_putnbr.c ft_printf.c ft_printf.c \
		ft_puthex.c

SRCB = 

OBJ = $(SRC:%.c=%.o)

OBJB = $(SRCB:%.c=%.o)

CFALGS =  -Wall -Wextra -Werror

CC = cc

INCLUDE = ft_printf.h

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

%.o : %.c $(INCLUDE)
	@$(CC) $(CFALGS) -c $< -o $@


clean:
	@rm -rf $(OBJ) $(OBJB)

fclean: clean
	@rm -rf $(NAME)

re: fclean all