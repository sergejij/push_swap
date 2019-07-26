/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 17:06:47 by ubartemi          #+#    #+#             */
/*   Updated: 2019/07/26 12:03:46 by ubartemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

int		main(void)
{
	int		fd;
	int		ret;
	char	*line;

	ret = 0;
	fd = 0;
	line = NULL;
	fd = open("2600-0.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_putstr(line);
		ft_putchar('\n');
		ft_strdel(&line);
	}
	close(fd);
	return (0);
}
