#include "../../push_swap_files/push_swap.h"

void ft_print_command1(t_stacks *main_struct, char *command)
{
	if (!ft_strcmp("sa", command))
	{
		SA;
		ft_putstr_fd("sa\n", main_struct->fd);
	}
	else if (!ft_strcmp("sb", command))
	{
		SB;
		ft_putstr_fd("sb\n", main_struct->fd);
	}
	else if (!ft_strcmp("ss", command))
	{
		SS;
		ft_putstr_fd("ss\n", main_struct->fd);
	}
	else if (!ft_strcmp("pa", command))
	{
		PA;
		ft_putstr_fd("pa\n", main_struct->fd);
	}
}

void ft_print_command2(t_stacks *main_struct, char *command)
{
	if (!ft_strcmp("pb", command))
	{
		PB;
		ft_putstr_fd("pb\n", main_struct->fd);
	}
	else if (!ft_strcmp("ra", command))
	{
		RA;
		ft_putstr_fd("ra\n", main_struct->fd);
	}
	else if (!ft_strcmp("rb", command))
	{
		RB;
		ft_putstr_fd("rb\n", main_struct->fd);
	}
	else if (!ft_strcmp("rr", command))
	{
		RR;
		ft_putstr_fd("rr\n", main_struct->fd);
	}
}

void ft_print_command3(t_stacks *main_struct, char *command)
{
	if (!ft_strcmp("rra", command))
	{
		RRA;
		ft_putstr_fd("rra\n", main_struct->fd);
	}
	else if (!ft_strcmp("rrb", command))
	{
		RRB;
		ft_putstr_fd("rrb\n", main_struct->fd);
	}
	else if (!ft_strcmp("rrr", command))
	{
		RRR;
		ft_putstr_fd("rrr\n", main_struct->fd);
	}
}

void ft_print_command(t_stacks *main_struct, char *command)
{
	ft_print_command1(main_struct, command);
	ft_print_command2(main_struct, command);
	ft_print_command3(main_struct, command);
}