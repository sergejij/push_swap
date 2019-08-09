NAME_PUSH = push_swap
NAME_CHECKER = checker

PATH_COMMON = ./common_files/
PATH_PUSH = ./common_files/

SRC_PUSH = ./push_swap_files/push_swap.c \
		   ./push_swap_files/sort.c \
		   ./push_swap_files/has_gap.c \
		   ./push_swap_files/count_actions.c \
		   ./push_swap_files/moves.c \
		   ./push_swap_files/throwing.c
SRC_CHECKER =   $(PATH_COMMON)checker.c
SRC_COMMON =	$(PATH_COMMON)auxiliary_functions/auxiliary_functions.c \
				$(PATH_COMMON)auxiliary_functions/auxiliary_functions2.c \
				$(PATH_COMMON)validation/validation.c \
				$(PATH_COMMON)validation/validation2.c \
				$(PATH_COMMON)moves/swap.c \
				$(PATH_COMMON)moves/push.c \
				$(PATH_COMMON)moves/rotate.c \
				$(PATH_COMMON)moves/reverse_rotate.c \
				$(PATH_COMMON)get_next_line.c

OBJ_PUSH = push_swap.o \
		   sort.o \
		   has_gap.o \
		   count_actions.o \
		   moves.o \
		   throwing.o
OBJ_CHECKER =   checker.o
OBJ_COMMON =	auxiliary_functions.o \
				auxiliary_functions2.o \
				validation.o \
				validation2.o \
				swap.o \
				push.o \
				rotate.o \
				reverse_rotate.o \
				get_next_line.o \

FLAGS = -Wall -Wextra -Werror

all: $(NAME_PUSH) $(NAME_CHECKER)

$(NAME_PUSH): $(SRC_PUSH) $(LIB)
	make re -C $(PATH_COMMON)libft/
	gcc -c -Wall -Werror -Wextra $(SRC_PUSH) -I. -g
	gcc -c -Wall -Werror -Wextra $(SRC_COMMON) -I.$(PATH_COMMON)
	gcc -Wall -Werror -Wextra $(OBJ_PUSH) $(OBJ_COMMON) -lft -L$(PATH_COMMON)libft/ -o $(NAME_PUSH)

$(NAME_CHECKER): $(SRC_CHECKER) $(LIB)
	gcc -c -Wall -Werror -Wextra $(SRC_CHECKER) $(SRC_COMMON) -I.
	gcc -Wall -Werror -Wextra $(OBJ_CHECKER) $(OBJ_COMMON) -lft -L$(PATH_COMMON)libft/ -o $(NAME_CHECKER)

clean:
	make clean -C $(PATH_COMMON)libft/
	rm -f $(OBJ_COMMON) $(OBJ_CHECKER) $(OBJ_PUSH)

fclean: clean
	make fclean -C $(PATH_COMMON)libft/
	rm -f $(NAME_PUSH)
	rm -f $(NAME_CHECKER)

re: fclean all
