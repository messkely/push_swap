NAME = push_swap
FILES = mandatory/moves/push.c \
		mandatory/moves/swap.c \
		mandatory/moves/rotate.c \
		mandatory/moves/rev_rotate.c mandatory/push_swap.c \
		mandatory/algo/chunks.c \
		mandatory/algo/sorting_stack.c \
		mandatory/linked_list_utils/fill_stack.c \
		mandatory/linked_list_utils/garbage_collector.c \
		mandatory/linked_list_utils/is_sorted.c \
		mandatory/linked_list_utils/linked_list_utils.c \
		mandatory/linked_list_utils/printList.c \
		bonus/ft_split.c \
		bonus/parssing_utils_1.c \
		bonus/parssing_utils_2.c

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

mk : re 
	make clean
	clear

.PHONY : clean
