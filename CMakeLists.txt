cmake_minimum_required(VERSION 3.14)
project(p_s C)

set(CMAKE_C_STANDARD 11)
include_directories(.)
#add_executable(p_s checker.c auxiliary_functions/auxiliary_functions.c validation/validation.c
#        moves/swap.c moves/push.c moves/rotate.c moves/reverse_rotate.c get_next_line.c validation/validation2.c
#        auxiliary_functions/auxiliary_functions2.c push_swap_files/sort.c push_swap_files/has_gap.c
#        push_swap_files/count_actions.c push_swap_files/moves.c push_swap_files/throwing.c)

add_executable(p_s push_swap.c auxiliary_functions/auxiliary_functions.c validation/validation.c
        moves/swap.c moves/push.c moves/rotate.c moves/reverse_rotate.c get_next_line.c validation/validation2.c
        auxiliary_functions/auxiliary_functions2.c push_swap_files/sort.c push_swap_files/has_gap.c
        push_swap_files/count_actions.c push_swap_files/moves.c push_swap_files/throwing.c)

target_link_libraries(p_s ${CMAKE_SOURCE_DIR}/libft/libft.a)
