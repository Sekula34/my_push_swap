NAME = push_swap

CC = cc 

COMP_FLAGS = -Wall -Wextra -Werror

SOURCE = push_swap.c \
main.c \
valid_input.c \
initialize_list.c \
utility_function.c \
duplicate_checker.c \
push_swap2.c \
set_relative_value.c \
valid_value.c \
radix_sort.c \
sorter.c \
sorter_utils.c

OBJS := $(SOURCE:%.c=%.o)

%.o: %.c push_swap.h
	$(CC) $(COMP_FLAGS) -c $< -o $@

$(NAME): push_swap.h $(OBJS)
	cd libft && $(MAKE) && $(MAKE) bonus 
	$(CC) $(COMP_FLAGS) -o $(NAME) $(OBJS) ./libft/libft.a

.PHONY: clean fclean re all

all: $(NAME)

clean:
	cd libft && $(MAKE) fclean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
