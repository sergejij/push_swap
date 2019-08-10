cmake_minimum_required(VERSION 3.14)
project(p_s C)

set(CMAKE_C_STANDARD 11)
include_directories(.)
add_executable(p_s common_files/checker.c common_files/auxiliary_functions/auxiliary_functions.c common_files/validation/validation.c
                common_files/moves/swap.c common_files/moves/push.c common_files/moves/rotate.c common_files/moves/reverse_rotate.c common_files/get_next_line.c common_files/validation/validation2.c
                common_files/auxiliary_functions/auxiliary_functions2.c)

#add_executable(p_s push_swap_files/push_swap.c common_files/auxiliary_functions/auxiliary_functions.c common_files/validation/validation.c
#        common_files/moves/swap.c common_files/moves/push.c common_files/moves/rotate.c common_files/moves/reverse_rotate.c common_files/get_next_line.c common_files/validation/validation2.c
#        common_files/auxiliary_functions/auxiliary_functions2.c push_swap_files/sort.c push_swap_files/has_gap.c
#        push_swap_files/count_actions.c push_swap_files/moves.c push_swap_files/throwing.c)

target_link_libraries(p_s ${CMAKE_SOURCE_DIR}/common_files/libft/libft.a)
