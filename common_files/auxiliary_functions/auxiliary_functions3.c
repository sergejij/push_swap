#include "../checker.h"

void ft_debag(t_lis *a, t_lis *b, char *command)
{
	ft_putstr("Execute the command - ");
	ft_putstr(command);
	ft_putchar('\n');
	ft_putstr("\033[33;1;4mStack A:\033[0m");
	while (a)
	{
		ft_putchar(' ');
		ft_putnbr(a->num);
		a = a->next;
	}
	ft_putchar('\n');
	ft_putstr("\033[34;1;4mStack B:\033[0m");
	while (b)
	{
		ft_putchar(' ');
		ft_putnbr(b->num);
		b = b->next;
	}
	ft_putstr("\n---------------------------------------------\n");
}

void ft_initialization(t_flags *flags_struct, t_stacks *main_struct, int fd)
{
	flags_struct->debug_mode = 0;
	flags_struct->count_mode = 0;
	flags_struct->file_mode = 0;
	flags_struct->num_sep_flags = 0;
	flags_struct->file_name = NULL;
	main_struct->counter = 0;
	main_struct->fd = fd;
	main_struct->a = NULL;
	main_struct->b = NULL;
	main_struct->a_len = 0;
	main_struct->b_len = 0;
	main_struct->min_actions = 0;
	main_struct->flag_stay_in_first = 0;
}

void ft_show_usage_ch()
{
	ft_putstr("Usage: ./checker [options] <args>\n");
	ft_putstr("options:\n\t -v  debugger\n");
	ft_putstr("\t -c  number of operations performed\n");
	ft_putstr("\t -f [file_name]  read instructions to ");
	ft_putstr("file (this option should be the last one)\n\n");
	ft_putstr("Example:\n");
	ft_putstr("\t./checker <args>\n");
	ft_putstr("\t./checker -v <args>\n");
	ft_putstr("\t./checker -c <args>\n");
	ft_putstr("\t./checker -f [file_name] <args>\n\n");
	ft_putstr("\tYou also can combine options\n");
	ft_putstr("\t./checker -vc <args>\n");
	ft_putstr("\t./checker -fvc [file_name] <args>\n");
	exit (1);
}

void ft_show_usage_ps()
{
	ft_putstr("Usage: ./push_swap [options] <args>\n");
	ft_putstr("options:\n");
	ft_putstr("\t -f [file_name]  write instructions to file\n\n ");
	ft_putstr("Example:\n");
	ft_putstr("\t./push_swap <args>\n");
	ft_putstr("\t./push_swap -f [file_name] <args>\n");
	exit (1);
}

void ft_change_meanings(int *first, int *second, char sign)
{
	if (sign == '+')
	{
		(*first)++;
		(*second)++;
	}
	else if (sign == '-')
	{
		(*first)--;
		(*second)--;
	}
}
