/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:14:40 by aatbir            #+#    #+#             */
/*   Updated: 2024/06/02 21:24:03 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"
int is_valid_textures(t_info *info, char *filename)
{
	char *first;
	char *second;
	char *third;
	char *fourth;

	first = valid_first_info(info, filename);
	second = valid_second_info(info, filename);
	third = valid_third_info(info, filename);
	fourth = valid_fourth_info(info, filename);
	if (!first || !second || !third || !fourth)
	{
		free(first);
		free(second);
		free(third);
		free(fourth);
		throw_err_2("Error\nPath to texture is not found\n");
	}
	free(first);
	free(second);
	free(third);
	free(fourth);
	return (0);
}

int compare_dup_text(t_info *info, char *filename)
{
	char **str;

	str = store_get_info_in_array(info, filename);
	if (!str)
		return (0);
	if ((compare(str[0], str[1]) == 0) || (compare(str[0], str[2]) == 0) || (compare(str[0], str[3]) == 0) || (compare(str[0], str[4]) == 0) || (compare(str[0], str[5]) == 0) || (compare(str[1], str[2]) == 0) || (compare(str[1], str[3]) == 0) || (compare(str[1], str[4]) == 0) || (compare(str[1], str[5]) == 0) || (compare(str[2], str[3]) == 0) || (compare(str[2], str[4]) == 0) || (compare(str[2], str[5]) == 0) || (compare(str[2], str[5]) == 0) || (compare(str[3], str[4]) == 0) || (compare(str[3], str[5]) == 0) || (compare(str[4], str[5]) == 0))
		throw_err_2("Error\nDuplicated Identifier\n");
	return (arr_free(str), 0);
}
int is_cub(char *filename)
{
	char *ext;

	ext = ft_strchr(filename, '.');
	if (ft_strlen(filename) < 5)
		return (printf("invalid name\n"), 0);
	if (ft_strncmp(ext, ".cub", 4) == 0 && ft_strlen(ext) == 4)
		return (printf("TEST 1: good💪\n"), 1);
	return (0);
}
// ====cheack map======

void *free_(char **file)
{
	int i;

	i = -1;
	while (file[++i])
		free(file[i]);
	free(file);
	return (NULL);
}

int lines_number(char *str)
{
	char *s;
	int fd;
	int i;

	i = 0;
	fd = open(str, O_RDWR);
	s = get_next_line(fd);
	while (s)
	{
		++i;
		free(s);
		s = get_next_line(fd);
	}
	free(s);
	close(fd);
	return (i);
}

int all_white(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int end(char **map, char *file_name)
{
	int e;

	if (!file_name || !map)
		return (0);

	e = 0;
	while (map[e])
		e++;
	e--;
	// skip all line with whitespaces
	while (map[e] && all_white(map[e]))
		e--;
	return (e);
}
int skip_part1(char **tab)
{

	int i;
	int c;

	i = -1;
	c = 0;
	while (tab[++i] && c < 6)
	{
		if ((tab[i][0] == ' ' || tab[i][0] == '\t') && !all_white(tab[i]))
			c++;
		else if (tab[i][0] != '\n' && ft_strlen(tab[i]) >= 1)
			c++;
	}
	if (all_white(tab[i]))
		while (tab[i] && all_white(tab[i]))
			i++;
	return (i);
}

int len2darray(char **array)
{
	int i = 0;
	while (array[i])
		i++;
	return (i);
}

void put_map(char **map, char *file_name)
{

	int i;
	int j;
	// int	n;
	// int map_end;

	i = skip_part1(map);

	(void)file_name;
	// printf("map");
	// while (map[i])
	// 	printf("line : %s\n", map[i++]);
	// exit(0);
	info_path->info->map = ft_calloc(sizeof(char *), ((len2darray(map) - i) + 1));
	j = 0;
	// n = 0;
	// map_end = end(map, file_name);

	// while (map[i] && i <= map_end)
	// {
	// 	info_path->info->map[j] = map[i];
	// 	j++;
	// 	i++;
	// }
	while (map[i])
	{
		if (!map[i][0])
			i++;
		else
			info_path->info->map[j++] = ft_strdup(map[i++]);
	}
	info_path->info->map[j] = NULL;
	i = 0;
	free_(map);
	// while (info_path->info->map[i])
	// 	printf("line : '%s' : \n", info_path->info->map[i++]);
}

int empty_line(void)
{
	int i;

	i = 0;
	while (info_path->info->map[i])
	{

		if (all_white(info_path->info->map[i]))
			return (0);
		i++;
	}
	return (1);
}

int player_num(void)
{
	int i;
	int j;
	int c;

	i = -1;
	c = 0;
	while (info_path->info->map[++i])
	{
		j = -1;
		while (info_path->info->map[i][++j])
		{
			if (info_path->info->map[i][j] == 'N' ||
				info_path->info->map[i][j] == 'S' ||
				info_path->info->map[i][j] == 'E' ||
				info_path->info->map[i][j] == 'W')
			{
				c++;
			}
		}
	}
	if (c != 1)
		return (0);
	return (1);
}
int check_existance(char c)
{
	int i;
	int j;
	int count;

	count = 0;
	i = -1;
	while (info_path->info->map[++i])
	{
		j = -1;
		while (info_path->info->map[i][++j])
		{
			if (info_path->info->map[i][j] == c)
				count++;
		}
	}
	if (!count)
		return (0);
	return (1);
}

int check_content(void)
{
	int i;
	int j;

	i = -1;
	while (info_path->info->map[++i])
	{
		j = -1;
		while (info_path->info->map[i][++j])
		{
			if (info_path->info->map[i][j] != '0' && info_path->info->map[i][j] != '1' && info_path->info->map[i][j] != '\n' && info_path->info->map[i][j] != 'N' && info_path->info->map[i][j] != 'S' && info_path->info->map[i][j] != 'E' && info_path->info->map[i][j] != 'W' && info_path->info->map[i][j] != ' ')
				// {
				// 	if(info_path->info->map[i][j] == ' ')
				// 		info_path->info->map[i][j] = '0';
				// }
				// else
				return (0);
		}
	}
	if (!player_num())
		return (0);
	return (1);
}
void player_pos(void)
{
	int i;
	int j;

	i = -1;
	// printf("STORMY\n");
	while (info_path->info->map[++i])
	{
		j = -1;
		while (info_path->info->map[i][++j])
		{
			if (info_path->info->map[i][j] == 'N' || info_path->info->map[i][j] == 'S' || info_path->info->map[i][j] == 'E' || info_path->info->map[i][j] == 'W')
			{
				info_path->info->pos = info_path->info->map[i][j];
				info_path->info->x = i;
				info_path->info->y = j;
			}
		}
	}
}
int map_len(void)
{
	int i;

	i = 0;
	while (info_path->info->map[i])
		i++;
	return (i);
}

void check_contour_right_left(char **map)
{
	int i = 0;

	// Check the left wall
	while (map[i])
	{
		if (map[i][0] != '1' && map[i][0] != ' ')
		{
			throw_err_2("the left wall is not fully 1 or space\n");
		}
		i++;
	}

	i = 0;

	// Check the right wall
	while (map[i])
	{
		int len = strlen(map[i]);
		if (map[i][len - 1] != '1' && map[i][len - 1] != ' ')
		{
			throw_err_2("the right wall is not fully 1 or space\n");
		}
		i++;
	}
}

void check_contour_up_down(char **map)
{
	int j;

	j = 0;
	if (map[0])
	{
		while (map[0][j])
		{
			if (map[0][j] == '1' || map[0][j] == ' ')
				j++;
			else
				throw_err_2("the upper wall is not fully 1\n");
		}
	}
	j = 0;
	if (map[map_len() - 1])
	{
		while (map[map_len() - 1][j])
		{
			if (map[map_len() - 1][j] == '1' || map[map_len() - 1][j] == ' ')
				j++;
			else
				throw_err_2("the lower wall is not fully 1\n");
		}
	}
}
int is_closed(char c)
{
	(void)c;
	// ;
	// int i = 0;
	// int j = 0;
	int len_map = map_len();
	// int row_length;

	if (len_map == 0)
		return 0; // Map is empty

	// while (info_path->info->map[i][j] && (info_path->info->map[i][j] == ' ' || info_path->info->map[i][j] == '1'))
	// 	j++;
	// if (info_path->info->map[i][j])
	// 	return (0);
	// while (info_path->info->map[++i][j] && i < len_map - 1)
	// {
	// 	j = 0;
	// 	while (info_path->info->map[i][j] == ' ')
	// 		j++;
	// 	if (info_path->info->map[i][j] && info_path->info->map[i][j] != '1')
	// 		return (0);
	// 	j = strlen(info_path->info->map[i]);
	// 	while (info_path->info->map[i][j] == ' ')
	// 		j--;
	// 	if (info_path->info->map[i][j] && info_path->info->map[i][j] != '1')
	// 		return (0);
	// }
	// while (info_path->info->map[i][j] && (info_path->info->map[i][j] == ' ' || info_path->info->map[i][j] == '1'))
	// 	j++;
	// if (info_path->info->map[i][j])
	// 	return (0);
	// while (i < len_map)
	// {
	// 	j = strlen(info_path->info->map[i]);
	// 	while (info_path->info->map[i][j] != 0)
	// 	{
	// 		if (info_path->info->map[i][j] == '0' || info_path->info->map[i][j] == c)
	// 		{
				
	// 		}
	// 	}
	// }
	return 1;
}

int check_first_last(void)
{
	int i;
	int e;

	i = -1;
	while (info_path->info->map[0][++i])
	{
		if (info_path->info->map[0][i] == '0' || info_path->info->map[0][i] == info_path->info->pos)
			return (0);
	}
	e = map_len() - 1;
	i = -1;
	while (info_path->info->map[e][++i])
	{
		if (info_path->info->map[e][i] == '0' || info_path->info->map[e][i] == info_path->info->pos)
			return (0);
	}
	return (1);
}

int checker_map1(char *file_name)
{
	// (void)filename;
	put_map(ft_split(read_file(file_name), '\n'), file_name);

	if (!empty_line())
		return (0);
	if (!check_content())
		return (0);
	player_pos();
	if (!check_first_last())
		return (0);
	if (!is_closed(info_path->info->pos))
	{
		printf("%c\n", info_path->info->pos);
		return (0);
	}
	// printf("ERRRRRRRRR\n");
	// exit(1);
	printf("MapIsGood\n");
	return (1);
}

void parsing(t_info *info, char *filename)
{
	// check_ext(filename);
	int i;
	compare_dup_text(info, filename);
	is_valid_textures(info, filename);
	valid_rgb_f(info, filename);
	valid_rgb_c(info, filename);
	i = 0;
	if (!checker_map1(filename))
	{
		printf("MapIsBAD🆘\n");
		return;
	}
	// while(info_path->info->map[i])
	// 	printf("%s\n", info_path->info->map[i++]);
	// if (!x)
	// 	printf("pist\n");
}
