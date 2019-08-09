#include "../checker.h"

/*
void ft_bubble_sort_list_2(t_stacks main_struct, t_lis *begin)
{
	t_lis	*tmp;
	int 	tmp_int;

	tmp = begin;
	while (tmp && tmp->next)
	{
		if (tmp->num > tmp->next->num)
		{
			tmp_int = tmp->num;
			tmp->num = tmp->next->num;
			tmp->next->num = tmp_int;
		}
		else if (tmp->num == tmp->next->num)
		{
			ft_putstr_fd("Error\n", 2);
			exit (1);
		}
		tmp = tmp->next;
	}
}

void ft_bubble_sort_list(t_stacks main_struct)
{
	t_lis	*begin;

	begin = main_struct.a;
	while (main_struct.a)
	{
		ft_bubble_sort_list_2(main_struct, begin);
		main_struct.a = main_struct.a->next;
	}
	main_struct.a = begin;
}

void	ft_check_duplicates(t_stacks main_struct)
{
	char *str;
	t_lis *begin;
	int i;
	int sovp;

	i = 0;
	begin = main_struct.a;
	str = (char*)malloc(sizeof(char) + (main_struct.a->len + 1));
	while (main_struct.a)
	{
		str[i] = main_struct.a->num;
		main_struct.a = main_struct.a->next;
		i++;
	}
	str[i] = '\0';
	main_struct.a = begin;
	while (main_struct.a)
	{
		while ()
		{
			if (main_struct.a->num == ft_atoi(str[]))
				//continue here
		}

	}
}
*/

int		ft_atoi_for_over(const char *str)
{
    int				counter;
    int				result;
    int				sign;

    sign = 1;
    result = 0;
    counter = 0;
    while ((str[counter] > 7 && str[counter] < 14) || str[counter] == ' ')
        counter++;
    if (str[counter] == '-')
    {
        sign = -1;
        counter++;

    }
    while (str[counter] > '\0')
    {
        if (result * 10 / 10 != result && sign == 1)
            return (-1);
        else if (result * 10 / 10 != result && sign == -1)
            return (0);
        result = (result * 10) + (str[counter++] - '0');
    }
    return (result * sign);
}

int is_int(char **tmp)
{
    int i;
    long long cmp;

    cmp = 0;
    i = 0;
    while (tmp[i])
    {
        if (ft_strlen(tmp[i]) >= 10)
        {
            if (tmp[i][0] == '-')
            {
                cmp = ft_atoi_for_over(tmp[i]);
                if (cmp == 0 || ft_strcmp("-2147483649", tmp[i]) == 0)
                    return (0);
            }
            else
            {
                cmp = ft_atoi_for_over(tmp[i]);
                if (cmp < 0)
                    return (0);
            }
        }
        i++;
    }
    return (1);
}

int is_need_parsing(char **argv)
{
    int i;

    i = 0;
    while (argv[1][i])
    {
        if (argv[1][i] == ' ')
            return (1);
        i++;
    }
    return (0);
}