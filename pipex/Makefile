NAME 			= 	pipex
BONUSNAME		= 	pipex_bonus

CC 				= 	gcc
CFLAGS			= 	-Wall -Wextra -Werror
RM 				= 	rm -rf

SRCDIR 			= 	./srcs/
OBJDIR 			= 	./obj/
INCDIR 			= 	./includes/

SRCS 			= 	pipex.c ft_split.c	utils.c
BONUSSRCS		= 	pipex_bonus.c # create files with mand functions which are used in bonuses

OBJ 			= 	$(addprefix $(OBJDIR), $(SRCS:.c=.o))

BONUSOBJ 		= 	$(addprefix $(OBJDIR), $(BONUSSRCS:.c=.o))

all				: 	$(NAME)

$(OBJDIR)%.o 	: 	$(SRCDIR)%.c $(INCDIR)pipex.h
					$(CC) $(CFLAGS) -c $< -o $@ -I$(INCDIR) 

$(BONUSDIR)%.o 	: 	$(SRCDIR)%.c $(INCDIR)pipex_bonus.h
					$(CC) $(CFLAGS) -c $< -o $@ -I$(INCDIR) 

$(NAME)			: 	$(OBJDIR) $(OBJ) $(INCDIR) 
					$(CC) $(OBJ) -o $(NAME)

clean			:
					$(RM) $(OBJDIR)

fclean			: 	clean
					$(RM) $(NAME)

re				: 	fclean all

bonus			: 	$(BONUSNAME)

$(BONUSNAME)	: 	$(OBJDIR) $(BONUSOBJ)
					$(CC) $(CFLAGS)  $(BONUSOBJ) -o $(BONUSNAME)

$(OBJDIR)		:
					mkdir -p $(OBJDIR)
$(BONUSDIR)		:
					mkdir -p $(BONUSOBJ)