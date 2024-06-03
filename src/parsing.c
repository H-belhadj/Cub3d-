/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:14:00 by aatbir            #+#    #+#             */
/*   Updated: 2024/06/03 17:49:48 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int	is_closed(char c)
{
	int	i;
	int	j;

	i = 0;
	while (info_path->info->map[++i] && i < map_len())
	{
		j = -1;
		while (info_path->info->map[i][++j])
		{
			if (info_path->info->map[i][j] == c)
			{
				if ((info_path->info->map[i][j - 1] == ' '
					|| info_path->info->map[i][j - 1] == 0)
					|| (info_path->info->map[i][j + 1] == ' '
					|| info_path->info->map[i][j + 1] == 0)
					|| (info_path->info->map[i - 1][j] == ' '
					|| j + 1 >= (int)ft_strlen(info_path->info->map[i - 1]))
					|| (info_path->info->map[i + 1][j] == ' '
					|| j + 1 >= (int)ft_strlen(info_path->info->map[i + 1])))
					return (0);
			}
		}
	}
	return (1);
}

int	check_first_last(void)
{
	int	i;
	int	e;

	i = -1;
	while (info_path->info->map[0][++i])
	{
		if (info_path->info->map[0][i] == '0' 
			|| info_path->info->map[0][i] == info_path->info->pos)
			return (0);
	}
	e = map_len() - 1;
	i = -1;
	while (info_path->info->map[e][++i])
	{
		if (info_path->info->map[e][i] == '0' 
			|| info_path->info->map[e][i] == info_path->info->pos)
			return (0);
	}
	return (1);
}

int	checker_map1(char *file_name)
{
	put_map(ft_split(read_file(file_name), '\n'), file_name);
	if (!empty_line())
		return (0);
	if (!check_content())
		return (0);
	player_pos();
	if (!check_first_last())
		return (0);
	if (!is_closed(info_path->info->pos || !is_closed('0')))
		return (0);
	printf("MapIsGood\n");
	return (1);
}

void	parsing(t_info *info, char *filename)
{
	compare_dup_text(info, filename);
	is_valid_textures(info, filename);
	valid_rgb_f(info, filename);
	valid_rgb_c(info, filename);
	if (!checker_map1(filename))
		throw_err_2("MapIsBAD🆘\n");
}
