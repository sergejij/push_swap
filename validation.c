#include "push_swap.h"

char **ft_shift_matrix(char **argv, int argc)
{
	char **for_parse;
	int i;

	i = 1;
	for_parse = (char**)malloc(sizeof(char*) * (argc));
	while (argv[i])
	{
		for_parse[i - 1] = (char*)malloc(sizeof(char) * (ft_strlen(argv[i] + 1)));
		for_parse[i - 1] = argv[i];
		i++;
	}
	for_parse[i - 1] = NULL;
	return (for_parse);
}

int	ft_parse_and_fill(t_stacks    *main_struct, int argc, char **argv)
{
	char        **tmp;
	int 		i;

	i = 0;
	if (argc == 2 && is_need_parsing(argv))
	{
		tmp = ft_strsplit(argv[1], ' ');
		if (is_correct_input(tmp))
			(*main_struct).a = ft_create_stack(ft_count_word(argv[1], ' '), tmp);
		else
			return (0);
		while (tmp[i])
			ft_strdel(&tmp[i++]);
	}
	else
	{
		tmp = ft_shift_matrix(argv, argc);
		if (is_correct_input(tmp))
			(*main_struct).a = ft_create_stack(argc, tmp);
		else
			return (0);
	}
	free(tmp); // почему если чищу циклом каждую строчку двумерного массива, то ошибок больше чемy так?
	return (1);
}