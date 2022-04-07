/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:06:39 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/04/07 10:46:13 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_map
{
    char    **matrix;
    int     nline;
    int     lline;
    size_t  cont_e;
    size_t  cont_p;
    size_t  cont_c;
}           t_map;

char	*get_next_line(int fd);
int		ft_error(int ecode, t_map *map);
size_t	ft_checklen(const char *s);
int     get_map(char *nmap, t_map *map);
void    ft_freestruc(t_map *map);

#endif