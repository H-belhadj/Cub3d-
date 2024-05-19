/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <aatbir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:31:52 by aatbir            #+#    #+#             */
/*   Updated: 2024/05/16 11:24:12 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

char	**textures(void)
{
	char	**text;

	text = (char **)malloc(sizeof(char *) * 7);
	if (!text)
		return (NULL);
	text[0] = ft_strdup("NO");
	text[1] = ft_strdup("SO");
	text[2] = ft_strdup("EA");
	text[3] = ft_strdup("WE");
	text[4] = ft_strdup("F");
	text[5] = ft_strdup("C");
	text[6] = NULL;
	return (text);
}

int	compare(char *s1, char *s2)
{
	return (ft_strncmp(s1, s2, 2));
}
