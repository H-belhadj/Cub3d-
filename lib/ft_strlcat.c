/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 22:26:30 by aatbir            #+#    #+#             */
/*   Updated: 2022/10/17 19:36:14 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t	i;
	size_t	s;
	size_t	v;

	if (len == 0)
		return (ft_strlen(src));
	else if (len < ft_strlen(dest))
		v = ft_strlen(src) + len;
	else
		v = ft_strlen(src) + ft_strlen(dest);
	i = 0;
	while (dest[i] != '\0')
		i++;
	s = 0;
	while (src[s] != '\0' && i + 1 < len)
	{
		dest[i] = src[s];
		s++;
		i++;
	}
	dest[i] = '\0';
	return (v);
}
