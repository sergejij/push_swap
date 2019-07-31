#include "../push_swap.h"

int    ft_sort_array(int *array, int len)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while (i < len - 1)
    {
        j = 0;
        while (j < len - 1)
        {
            if (array[j] > array[j + 1])
            {
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
            else if (array[j] == array[j + 1])
            {
                ft_putstr_fd("Error\n", 2);
                exit (1);
            }
            j++;
        }
        i++;
    }
    return (array[len / 2]);
}

void    ft_check_duplicates(t_stacks    *main_struct)
{
    int *array;
    t_lis *begin;
    int i;

    main_struct->a_len = ft_length_list(main_struct->a);
    i = 0;
    begin = main_struct->a;
    if (!(array = (int*)malloc(sizeof(int) * main_struct->a_len)))
        exit (1);
    while (main_struct->a)
    {
        array[i++] = main_struct->a->num;
        main_struct->a = main_struct->a->next;
    }
    main_struct->a = begin;
    main_struct->median = ft_sort_array(array, main_struct->a_len);
    free(array);
}

t_lis    *ft_create_stack(char **tmp)
{
    int     i;
    t_lis *begin;
    t_lis *stack;
    t_lis *new;

    i = 0;
    stack = malloc(sizeof(t_lis));
    begin = stack;
    while (tmp[i + 1])
    {
        stack->num = ft_atoi(tmp[i++]);
        new = malloc(sizeof(t_lis));
        stack->next = new;
        new->prev = stack;
        new->next = NULL;
        stack = new;
    }
    stack->num = ft_atoi(tmp[i]);
    return (begin);
}

