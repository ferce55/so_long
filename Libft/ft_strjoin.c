/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 11:10:39 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/05/10 16:39:41 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	size_t	i;
	size_t	j;
	size_t	tot_len;

	tot_len = ft_strlen(s1) + ft_strlen(s2);
	if (!tot_len)
		return (0);
	tmp = malloc(tot_len + 1);
	if (!tmp)
		return (0);
	i = 0;
	j = 0;
	if (s1)
	{
		while (i < tot_len && s1[j])
			tmp[i++] = s1[j++];
	}
	j = 0;
	while (i < tot_len && s2[j])
		tmp[i++] = s2[j++];
	tmp[i] = '\0';
	free((char *)s1);
	return (tmp);
}
