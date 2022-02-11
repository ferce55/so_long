/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:23:46 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/02/11 18:17:20 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_errormsg(char *str)
{
	ft_putstr_fd(str, 1);
	exit(1);
}

int	ft_error(int ecode)
{
	if (ecode == 0)
		ft_errormsg("ERROR\nEl numero de argumentos es erroneo");
	if (ecode == 1)
		ft_errormsg("ERROR\nEl nombre del mapa es erroneo");
	return (0);
}
