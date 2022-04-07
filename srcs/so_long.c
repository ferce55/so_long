/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:18:35 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/04/07 12:23:30 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	bye(void)
{
	system("leaks -q so_long");
}

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

static int	count_lines(char *nmap)
{
	int			fd;
	int			i;
	size_t		len;
	char		*line;

	fd = open(nmap, O_RDONLY);
	i = 0;
	len = 0;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
		if (len != ft_checklen(line) && i != 1 && line)
			return (-1);
		len = ft_checklen(line);
	}
	free(line);
	close(fd);
	return (i);
}

static int	check_map(char *nmap, t_map *map)
{
	if (check_fname(nmap) == 0)
		ft_error(1, map);
	map->nline = count_lines(nmap);
	if (map->nline < 3)
		ft_error(2, map);
	get_map(nmap, map);
	return (1);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	//atexit(bye);
	map = ft_calloc(1, sizeof(t_map));
	if (argc != 2)
		ft_error(0, map);
	check_map(argv[1], map);
	ft_freestruc(map);
	return (0);
}
