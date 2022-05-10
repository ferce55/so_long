/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:06:39 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/05/10 15:39:16 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/libft.h"
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_player
{
	void	*ptr;
	int		x;
	int		y;
}			t_player;

typedef struct s_collec
{
	void	*ptr;
	size_t	count;
}			t_collec;

typedef struct s_map
{
	char	**matrix;
	int		nline;
	int		lline;
	size_t	cont_e;
	size_t	cont_p;
	size_t	cont_c;
}			t_map;

typedef struct s_game
{
	size_t		nmoves;
	void		*ptr;
	void		*win;
	void		*wall;
	void		*floor;
	void		*exit;
	t_map		map;
	t_player	player;
	t_collec	collec;
}			t_game;

char	*get_next_line(int fd);
int		ft_error(int ecode, t_game *game);
size_t	ft_checklen(const char *s);
int		get_map(char *nmap, t_game *game);
void	ft_freestruc(t_game *game);
int		start_game(t_game *game);
void	ft_import_xpm(t_game *game);
void	ft_init_map(t_game *game);

#endif