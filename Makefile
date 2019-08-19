NAME_PUSH = push_swap
NAME_CHECKER = checker

PATH_COMMON = ./common_files/
PATH_PUSH = ./push_swap_files/

SRC_PUSH = $(PATH_PUSH)push_swap.c \
		   $(PATH_PUSH)sort.c \
		   $(PATH_PUSH)has_gap.c \
		   $(PATH_PUSH)count_actions.c \
		   $(PATH_PUSH)moves.c \
		   $(PATH_PUSH)throwing.c \
		   $(PATH_PUSH)sort_sequence.c \
		   $(PATH_PUSH)count_double.c
SRC_CHECKER =   $(PATH_COMMON)checker.c
SRC_COMMON =	$(PATH_COMMON)auxiliary_functions/auxiliary_functions.c \
				$(PATH_COMMON)auxiliary_functions/auxiliary_functions2.c \
				$(PATH_COMMON)auxiliary_functions/auxiliary_functions3.c \
				$(PATH_COMMON)auxiliary_functions/auxiliary_functions4.c \
				$(PATH_COMMON)validation/validation.c \
				$(PATH_COMMON)validation/validation2.c \
				$(PATH_COMMON)moves/swap.c \
				$(PATH_COMMON)moves/push.c \
				$(PATH_COMMON)moves/rotate.c \
				$(PATH_COMMON)moves/reverse_rotate.c \
				$(PATH_COMMON)get_next_line.c \
				$(PATH_COMMON)bonuses.c

OBJ_PUSH = push_swap.o \
		   sort.o \
		   has_gap.o \
		   count_actions.o \
		   moves.o \
		   throwing.o \
		   sort_sequence.o \
		   count_double.o
OBJ_CHECKER =   checker.o
OBJ_COMMON =	auxiliary_functions.o \
				auxiliary_functions2.o \
				auxiliary_functions3.o \
				auxiliary_functions4.o \
				validation.o \
				validation2.o \
				swap.o \
				push.o \
				rotate.o \
				reverse_rotate.o \
				get_next_line.o \
				bonuses.o

FLAGS = -Wall -Wextra -Werror

all: $(NAME_PUSH) $(NAME_CHECKER)

$(NAME_PUSH): $(SRC_PUSH)
	make re -C $(PATH_COMMON)libft/
	gcc -c $(FLAGS) $(SRC_PUSH) -I.
	gcc -c $(FLAGS) $(SRC_COMMON) -I.$(PATH_COMMON)
	gcc $(FLAGS) $(OBJ_PUSH) $(OBJ_COMMON) -lft -L$(PATH_COMMON)libft/ -g -o $(NAME_PUSH)

$(NAME_CHECKER): $(SRC_CHECKER)
	gcc -c $(FLAGS) $(SRC_CHECKER) $(SRC_COMMON) -I.
	gcc $(FLAGS) $(OBJ_CHECKER) $(OBJ_COMMON) -lft -L$(PATH_COMMON)libft/ -g -o $(NAME_CHECKER)

clean:
	make clean -C $(PATH_COMMON)libft/
	rm -f $(OBJ_COMMON) $(OBJ_CHECKER) $(OBJ_PUSH)

fclean: clean
	make fclean -C $(PATH_COMMON)libft/
	rm -f $(NAME_PUSH)
	rm -f $(NAME_CHECKER)

re: fclean all
