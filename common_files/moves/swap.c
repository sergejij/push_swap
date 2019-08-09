#include "../checker.h"

void    sa(t_stacks	*main_struct)
{
	t_lis *begin;
	int tmp;

	tmp = 0;
	begin = main_struct->a;
	if (begin->next)
	{
		tmp = begin->num;
		begin->num = begin->next->num;
		begin->next->num = tmp;
	}
}
void    sb(t_stacks	*main_struct)
{
	t_lis *begin;
	int tmp;

	tmp = 0;
	begin = main_struct->b;
	if (begin->next)
	{
		tmp = begin->num;
		begin->num = begin->next->num;
		begin->next->num = tmp;
	}
}

void    ss(t_stacks	*main_struct)
{
	sa(&(*main_struct));
	//ft_print_list(main_struct.a);
	sb(&(*main_struct));
}