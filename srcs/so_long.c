/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:18:35 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/02/11 19:00:54 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_fname(char *fname)
{
	size_t	fname_size;

	fname_size = ft_strlen(fname);
	if (fname_size <= 3)
		return (0);
	if (fname[fname_size - 4] != '.')
		return (0);
	if (fname[fname_size - 3] != 'b')
		return (0);
	if (fname[fname_size - 2] != 'e')
		return (0);
	if (fname[fname_size - 1] != 'r')
		return (0);
	return (1);
}

static size_t	count_lines(char *nmap)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(nmap, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line != NULL)
		{
			i++;
			free(line);
			line = get_next_line(fd);
		}
	}
	ft_putchar_fd(i + '0', 1);
	close(fd);
	return (i);
}

static int	check_map(char *nmap)
{
	if (check_fname(nmap) == 0)
		ft_error(1);
	count_lines(nmap);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_error(0);
	check_map(argv[1]);
	return (0);
}
