/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:09:19 by ricardo           #+#    #+#             */
/*   Updated: 2022/05/10 17:08:26 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	**parse_map(int fd, t_game *game)
{
	int		j;
	int		i;
	int		len;
	char	*line;
	char	*str;

	line = get_next_line(fd);
	len = ft_strlen(line);
	game->map.lline = len - 1;
	i = 0;
	while (line)
	{
		str = malloc(len);
		if (!str)
			ft_error(3, game);
		j = -1;
		while (line[++j] != '\n' && line[j])
			str[j] = line[j];
		game->map.matrix[i] = str;
		free(line);
		line = get_next_line(fd);
		i++;
	}
	printf("%s", line);
	return (game->map.matrix);
}

static int	check_border(char c, t_game *game)
{
	if (c != '1')
	{
		ft_error(2, game);
	}
	return (1);
}

static void	check_playable_map(char c, t_game *game)
{
	if (c != 'E' && c != 'P' && c != 'C' && c != '1' && c != '0')
		ft_error(2, game);
	if (c == 'E')
	{
		game->map.cont_e++;
	}
	else if (c == 'P')
	{
		game->map.cont_p++;
	}
	else if (c == 'C')
	{
		game->map.cont_c++;
	}
}

static int	check_content(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	game->map.cont_e = 0;
	game->map.cont_p = 0;
	game->map.cont_c = 0;
	while (game->map.matrix[j])
	{
		i = 0;
		while (game->map.matrix[j][i])
		{		
			if (i == 0 || i == game->map.lline - 1 || j == 0
				|| j == game->map.nline - 1)
				check_border(game->map.matrix[j][i], game);
			else
				check_playable_map(game->map.matrix[j][i], game);
			i++;
		}
		j++;
	}
	if (game->map.cont_p != 1 || game->map.cont_c < 1 || game->map.cont_e < 1)
		ft_error(2, game);
	return (1);
}

int	get_map(char *nmap, t_game *game)
{
	int		fd;

	fd = open(nmap, O_RDONLY);
	game->map.matrix = ft_calloc(game->map.nline + 1, sizeof(char *));
	if (!game->map.matrix)
		ft_error(3, game);
	parse_map(fd, game);
	if (game->map.lline == game->map.nline)
		ft_error(2, game);
	check_content(game);
	return (1);
}
