NAME = libftprintf.a

LIBNAME = ./libft/libft.a

HEADER = ft_printf.h

C_FILES = ft_print_hex.c ft_print_ptr.c ft_putnbr.c ft_putunbr.c \
	ft_print_int.c ft_print_uint.c ft_print_str.c ft_print_char.c ft_printf.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror

O_FILES = $(C_FILES:.c=.o)

all: $(LIBNAME) $(NAME)

$(LIBNAME): ./libft/libft.h
	make bonus -C ./libft/

$(NAME): $(O_FILES) $(LIBNAME)
	cp $(LIBNAME) $(NAME)
	ar rcs $(NAME) $(O_FILES)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

clean:
	make clean -C ./libft/
	rm -rf $(O_FILES)

fclean: clean
	rm -rf $(LIBNAME)
	rm -rf $(NAME)

re: fclean all
