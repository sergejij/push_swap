
#ifndef P_S_CHECKER_H
#define P_S_CHECKER_H
# define SA sa(main_struct)
# define SB sb(main_struct)
# define SS ss(main_struct)
# define PB pb(main_struct)
# define PA pa(main_struct)
# define RA ra(main_struct)
# define RB rb(main_struct)
# define RR rr(main_struct)
# define RRA rra(main_struct)
# define RRB rrb(main_struct)
# define RRR rrr(main_struct)

# define BUFF_SIZE 2
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"


typedef struct              s_lis
{
	int                    	num;
	struct        s_lis    	*next;
	struct        s_lis    	*prev;
	int 					common_and_pos_a_b[3];
	int 					number_el;
}                           t_lis;

typedef struct              s_stacks
{
	t_lis                   *a;
	t_lis                   *b;
	int 					a_len;
	int 					b_len;
	int 					min_actions;
	int 					flag_stay_in_first;
	int 					fd;
	int 					counter;
}							t_stacks;

typedef struct              s_flags
{
	int 					debug_mode;
	int 					count_mode;
	int 					file_mode;
	char					*file_name;
	int 					num_sep_flags;
}							t_flags;

int		get_next_line(const int fd, char **line);

/*--------------------------auxiliary--------------------------*/

int		ft_length_list(const t_lis *start);
int 	is_correct_input(char **str);
void	ft_list_clear(t_lis **begin_list);
void	ft_free_matrix(char **tmp);
void	ft_debag(t_lis *a, t_lis *b, char *command);
void 	ft_show_usage_ch();
void 	ft_show_usage_ps();

int is_need_parsing(char **argv, t_flags flags_struct);
int		is_int(char **tmp);
int		ft_atoi_for_over(const char *str);
void	ft_error();
void ft_initialization(t_flags *flags_struct, t_stacks *main_struct, int fd);

void ft_print_command(t_stacks *main_struct, char *command);
void ft_change_meanings(int *first, int *second, char sign);

/*----------------------------moves----------------------------*/

void    sa(t_stacks	*main_struct);
void    sb(t_stacks	*main_struct);
void    ss(t_stacks *stacks);

void    pb(t_stacks *stacks);
void    pa(t_stacks *stacks);

void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rr(t_stacks *stacks);

void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);

/*--------------------------validation--------------------------*/

char **ft_shift_matrix(char **argv, int argc, char **tmp);
int	    ft_parse(char **argv, t_stacks    *main_struct);
int	ft_parse_and_fill(t_stacks    *main_struct, t_flags    *flags_struct, int argc, char **argv);
void ft_parse_flags(t_flags *flags_struct, char **argv);

void    ft_check_dup(int *array, int len, int i, int j);
void    ft_check_duplicates(t_stacks    *main_struct);
t_lis    *ft_create_stack(char **tmp);


#endif //P_S_CHECKER_H
