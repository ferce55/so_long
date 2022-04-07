/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:09:19 by ricardo           #+#    #+#             */
/*   Updated: 2022/04/07 12:25:16 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	**parse_map(int fd, t_map *map)
{
	int		j;
	int		i;
	int		len;
	char	*line;
	char	*str;

	line = get_next_line(fd);
	len = ft_strlen(line);
	map->lline = len - 1;
	i = 0;
	while (line)
	{
		str = malloc(len);
		if (!str)
			ft_error(3, map);
		j = -1;
		while (line[++j] != '\n' && line[j])
			str[j] = line[j];
		map->matrix[i] = str;
		free(line);
		line = get_next_line(fd);
		i++;
	}
	return (map->matrix);
}

static int	check_border(char c, t_map *map)
{
	if (c != '1')
	{
		ft_error(2, map);
	}
	return (1);
}

static void	check_playable_map(char c, t_map *map)
{
	if (c != 'E' && c != 'P' && c != 'C' && c != '1' && c != '0')
		ft_error(2, map);
	if (c == 'E')
	{
		map->cont_e++;
	}
	else if (c == 'P')
	{
		map->cont_p++;
	}
	else if (c == 'C')
	{
		map->cont_c++;
	}
}

static int	check_content(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	map->cont_e = 0;
	map->cont_p = 0;
	map->cont_c = 0;
	while (map->matrix[j])
	{
		i = 0;
		while (map->matrix[j][i])
		{
			if (i == 0 || i == map->lline - 1 || j == 0 || j == map->nline - 1)
				check_border(map->matrix[j][i], map);
			else
				check_playable_map(map->matrix[j][i], map);
			i++;
		}
		j++;
	}
	if (map->cont_p != 1 || map->cont_c < 1 || map->cont_e < 1)
	{
		ft_error(2, map);
	}
	return (1);
}

int	get_map(char *nmap, t_map *map)
{
	int		fd;
	int		len;

	fd = open(nmap, O_RDONLY);
	map->matrix = ft_calloc(map->nline + 1, sizeof(char *));
	if (!map->matrix)
		ft_error(3, map);
	parse_map(fd, map);
	if (map->lline == map->nline)
		ft_error(2, map);
	check_content(map);
	return (1);
}
