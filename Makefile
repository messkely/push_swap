NAME = push_swap
FILES = mandatory/moves/push.c mandatory/moves/swap.c mandatory/moves/rotate.c \
		mandatory/moves/rev_rotate.c push_swap.c parssing_utils.c Doubly_linked_list_lib.c \
		ft_split.c sorting_algo.c
OBJS = $(FILES:.c=.o)
FLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o : %.c includes/push_swap.h
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean
