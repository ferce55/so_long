/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:09:19 by ricardo           #+#    #+#             */
/*   Updated: 2022/04/06 10:53:22 by ricardo          ###   ########.fr       */
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
	str = malloc(len);
	if (!str)
		ft_error(3, map);
	i = 0;
	while (line)
	{
		j = -1;
		while (line[++j] != '\n' && line[j])
			str[j] = line[j];
		map->matrix[i] = str;
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map->matrix[i] = line;
	return (map->matrix);
}

/*static int	check_borders(t_map *map)
{
	int	i;
	int	j;
	int	numite;

	numite = 0;
	j = 0;
	while (map->matrix[j])
	{
		i = 0;
		if (j == 0 || j == map->nline - 1)
		{
			while (map->matrix[j][i] && map->matrix[j][i] != '\n')
			{
				if (map->matrix[j][i++] != '1')
					ft_error(2, map);
			}
		}
		else if (map->matrix[j][0] != '1' || map->matrix[j][map->lline - 2] != '1')
				ft_error(2, map);
		j++;
	}
	return (1);
}*/

static int	check_border(char c, t_map *map)
{
	if (c != '1')
	{
		ft_error(2, map);
	}
	return (1);
}

/*static int	check_playable_map(char c, t_map *map)
{
	if (c != 'E' && c != 'P')
}*/

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
			//else
				//check_playable_map(map->matrix[j][i], map);
			i++;
		}
		j++;
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
	map->matrix = parse_map(fd, map);
//	check_borders(map);
	check_content(map);
	return (1);
}
