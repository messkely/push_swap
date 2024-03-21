NAME = push_swap
NAME_BONUS = checker
FILES = mandatory/moves/push.c \
		mandatory/moves/swap.c \
		mandatory/moves/rotate.c \
		mandatory/moves/rev_rotate.c mandatory/push_swap.c \
		mandatory/algo/chunks.c \
		mandatory/algo/sorting_stack.c \
		mandatory/function_utils/fill_stack.c \
		mandatory/function_utils/garbage_collector.c \
		mandatory/function_utils/is_sorted.c \
		mandatory/function_utils/linked_list_utils.c \
		mandatory/function_utils/printList.c \
		mandatory/function_utils/ft_split.c \
		mandatory/function_utils/parssing_utils_1.c \
		mandatory/function_utils/parssing_utils_2.c
FILES_BONUS = bonus/moves/push_bonus.c \
		bonus/moves/swap_bonus.c \
		bonus/moves/rotate_bonus.c \
		bonus/moves/rev_rotate_bonus.c \
		bonus/function_utils/fill_stack_bonus.c \
		bonus/function_utils/garbage_collector_bonus.c \
		bonus/function_utils/is_sorted_bonus.c \
		bonus/function_utils/linked_list_utils_bonus.c \
		bonus/function_utils/ft_split_bonus.c \
		bonus/function_utils/parssing_utils_1_bonus.c \
		bonus/function_utils/parssing_utils_2_bonus.c \
		bonus/function_utils/check_moves.c \
		bonus/checker.c \
		lib/get_next_line/get_next_line.c \
		lib/get_next_line/get_next_line_utils.c

OBJS = $(FILES:.c=.o)
OBJS_BONUS = $(FILES_BONUS:.c=.o)
FLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f
$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

# $(NAME_BONUS) : $(OBJS_BONUS)
# 	$(CC) $(FLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)
all : $(NAME)
# bonus : $(NAME_BONUS)

bonus : $(OBJS_BONUS)
	$(CC) $(FLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)
%.o : %.c includes/push_swap.h
	$(CC) $(FLAGS) -c $< -o $@
%.o : %.c includes/checker.h
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(RM) $(NAME) $(NAME_BONUS)

re : fclean all

mk : re bonus
	make clean
	clear

test: mk
	@echo "Running visualization script..."
	./visualizer-1_1.py $$(seq 0 100 | sort -R)

.PHONY : clean
