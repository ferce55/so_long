/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_checkers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:09:32 by ricardo           #+#    #+#             */
/*   Updated: 2022/04/05 10:09:34 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

size_t	ft_checklen(const char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!s)
		return (i);
	while (s[i] != '\0')
	{
		if (s[i] != '\n')
			len++;
		i++;
	}
	return (len);
}
