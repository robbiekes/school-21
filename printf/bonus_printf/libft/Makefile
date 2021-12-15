NAME = libft.a

FLAGS = -Wall -Wextra -Werror

C_FILES = ft_bzero.c	ft_isalpha.c	ft_tolower.c	ft_memchr.c	ft_memmove.c	ft_strdup.c	ft_strlen.c \
	ft_strrchr.c	ft_calloc.c	ft_isascii.c	ft_memcmp.c	ft_memset.c	ft_strlcat.c	ft_strncmp.c \
	ft_toupper.c	ft_atoi.c	ft_isprint.c	ft_isalnum.c	ft_isdigit.c	ft_memcpy.c	ft_strchr.c	ft_strlcpy.c \
	ft_strnstr.c	ft_substr.c	ft_strjoin.c	ft_strtrim.c	ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c	\
	ft_putnbr_fd.c	ft_strmapi.c ft_split.c	ft_itoa.c	ft_striteri.c

O_FILES = $(C_FILES:.c=.o)

BONUS_C_FILES = ft_lstnew_bonus.c ft_lstsize_bonus.c	ft_lstlast_bonus.c	ft_lstadd_front_bonus.c	ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c ft_lstclear_bonus.c	ft_lstiter_bonus.c	ft_lstmap_bonus.c

BONUS_O_FILES = $(BONUS_C_FILES:.c=.o)

all: $(NAME)

$(NAME): $(O_FILES)
	ar rcs ${NAME} ${O_FILES}

bonus: ${O_FILES} $(BONUS_O_FILES)
	ar rcs ${NAME} ${O_FILES} $(BONUS_O_FILES)

%.o : %.c libft.h
	gcc $(FLAGS) -c $< -o $@ -I libft.h

clean:
	rm -rf $(O_FILES) $(BONUS_O_FILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all
