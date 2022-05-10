/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:18:35 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/05/07 20:14:20 by ricardo          ###   ########.fr       */
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

static int	check_map(char *nmap, t_game *game)
{
	if (check_fname(nmap) == 0)
		ft_error(1, game);
	game->map.nline = count_lines(nmap);
	if (game->map.nline < 3)
		ft_error(2, game);
	get_map(nmap, game);
	return (1);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_game	*game;

	//atexit(bye);
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		ft_error(3, game)
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		ft_error(3, game);
	game->map = map;
	if (argc != 2)
		ft_error(0, game);
	check_map(argv[1], game);
	start_game(game);
	ft_freestruc(game);
	return (0);
}
