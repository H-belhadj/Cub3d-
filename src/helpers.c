/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 20:52:36 by aatbir            #+#    #+#             */
/*   Updated: 2024/05/20 12:19:59 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"
// void	ft_free_info(t_info *info)
// {
// 	if (info->first_info)
// 		free(info->first_info);
// 	if (info->second_info)
// 		free(info->second_info);
// 	if (info->third_info)
// 		free(info->third_info);
// 	if (info->fourth_info)
// 		free(info->fourth_info);
// 	if (info->first_color)
// 		free(info->first_color);
// 	if (info->second_color)
// 		free(info->second_color);
// 	free(info);
// }

void	arr_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

int	check_if_only_numbers(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!(str[i][j] >= '0' && str[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	throw_err_2(char *err_msg)
{
	printf("%s", err_msg);
	exit(1);
}
