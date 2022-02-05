NAME 			= 	pipex

CC 				= 	gcc
RM 				= 	rm -rf

SRCDIR 			= 	./srcs/
OBJDIR 			= 	./obj/
INCDIR 			= 	./includes/

SRCS 			= pipe.c ft_split.c

OBJ 			= 	$(addprefix $(OBJDIR), $(SRCS:.c=.o))

BONUSOBJ 		= 	$(addprefix $(OBJDIR), $(BONUSSRCS:.c=.o))

all				: 	$(NAME)

$(OBJDIR)%.o 	: 	$(SRCDIR)%.c $(INCDIR)/pipex.h
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
