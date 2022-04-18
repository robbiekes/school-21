NAME = push_swap
BONUSNAME = checker

CC = gcc
RM = rm -rf

SRCDIR = ./srcs/
OBJDIR = ./obj/
INCDIR = ./includes/
LIBFTDIR = ./libft/

SRCS = push_swap.c \
	parsing.c \
	pars_funcs.c \
	algorithm.c	\
	free_lists.c \
	push.c \
	regular_func.c \
	reverses.c \
	rotations.c	\
	rotations2.c \
	swaps.c	\
	utils.c \
	ft_split.c

OBJ = $(addprefix $(OBJDIR), $(SRCS:.c=.o))

BONUSSRCS = checker.c \
	get_next_line.c \
	get_next_line_utils.c \
	parsing.c \
	pars_funcs.c \
	free_lists.c \
	push.c \
	regular_func.c \
	reverses.c \
	rotations.c	\
	rotations2.c \
	swaps.c	\
	utils.c \
	ft_split.c

BONUSOBJ = $(addprefix $(OBJDIR), $(BONUSSRCS:.c=.o))

all: $(NAME)

$(OBJDIR)%.o : $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@ -O2 -I$(INCDIR)

$(NAME): $(OBJDIR) $(OBJ)
	$(CC) $(CFLAGS)  $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(BONUSNAME)

$(BONUSNAME): $(OBJDIR) $(BONUSOBJ)
	$(CC) $(CFLAGS)  $(BONUSOBJ) -o $(BONUSNAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

p:
	python3 temp.py