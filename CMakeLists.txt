cmake_minimum_required(VERSION 3.14)
project(p_s C)

set(CMAKE_C_STANDARD 11)
include_directories(.)
add_executable(p_s main.c auxiliary_functions.c validation.c moves/swap.c moves/push.c moves/rotate.c moves/reverse_rotate.c get_next_line.c)
target_link_libraries(p_s ${CMAKE_SOURCE_DIR}/libft/libft.a)
