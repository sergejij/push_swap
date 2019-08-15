#include "../checker.h"


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
    if (str[counter] == '+')
    	counter++;
    else if (str[counter] == '-')
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

int is_need_parsing(char **argv, t_stacks main_struct)
{
    int i;
	int j;

    i = 0;
    if (main_struct.debug_mode)
    	j = 2;
    else
    	j = 1;
    while (argv[j][i])
    {
        if (argv[j][i] == ' ')
            return (1);
        i++;
    }
    return (0);
}

void	ft_free_matrix(char **tmp)
{
	int i;

	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}