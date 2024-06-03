/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:14:00 by aatbir            #+#    #+#             */
/*   Updated: 2024/06/03 23:51:16 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int	is_closed(char c)
{
	int	i;
	int	j;

	i = -1;
	while (info_path->info->map[++i] && i < map_len())
	{
		j = -1;
		// printf("--->%s\n", info_path->info->map[i]);
		while (info_path->info->map[i][++j])
		{
			// if ((info_path->info->map[i][j] == ' ' || info_path->info->map[i][j] == '0' || 
			// 	info_path->info->map[i][j] == 'N' || info_path->info->map[i][j] == 'W' || info_path->info->map[i][j] == 'S' || info_path->info->map[i][j] == 'E')
			// 	 && info_path->info->map[i+1] && ft_strlen(info_path->info->map[i+1]) < (size_t)j)
			// 		return(0);
			if (info_path->info->map[i][j] == '0' || (info_path->info->map[i][j] == 'N' || info_path->info->map[i][j] == 'W' || info_path->info->map[i][j] == 'S' || info_path->info->map[i][j] == 'E'))
			{
				if ((i == 0 || (size_t)j >= ft_strlen(info_path->info->map[i - 1])) || 
					info_path->info->map[i - 1][j] == ' ' || info_path->info->map[i - 1][j] == '\n')
					return (0);
				if ((!info_path->info->map[i + 1] || (size_t)j >= ft_strlen(info_path->info->map[i + 1])) || 
					info_path->info->map[i + 1][j] == ' ' || info_path->info->map[i + 1][j] == '\n')
					return (0);
				if (i == 0 || info_path->info->map[i][j - 1] == ' ' || info_path->info->map[i][j - 1] == '\n')
					return (0);
				if (!info_path->info->map[i][j + 1] || info_path->info->map[i][j + 1] == ' ' || info_path->info->map[i][j + 1] == '\n')
					return (0);
			}
			if (info_path->info->map[i][j] == c)
			{
				// if (map[j][i] == c)
				// {
				// 	if ((j == 0 || i > ft_strlen(map[j - 1])) || 
				// 		map[j - 1][i] == ' ' || map[j - 1][i] == '\n')
				// 		return (1);
				// 	if ((!map[j + 1] || i > ft_strlen(map[j + 1])) || 
				// 		map[j + 1][i] == ' ' || map[j + 1][i] == '\n')
				// 		return (1);
				// 	if (i == 0 || map[j][i - 1] == ' ' || map[j][i - 1] == '\n')
				// 		return (1);
				// 	if (!map[j][i + 1] || map[j][i + 1] == ' ' || map[j][i + 1] == '\n')
				// 		return (1);
				// }
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


// char	**spliting(char const *s, char c)
// {
// 	char	**del_s;
// 	size_t	x;
// 	size_t	y;
// 	size_t	z;

// 	x = 0;
// 	y = 0;
// 	del_s = (char **)malloc(sizeof(char *) * (wordlen(s, c) + 1));
// 	if (!del_s || !s)
// 		return (NULL);
// 	while (x < wordlen(s, c) && s[y] != '\0')
// 	{
// 		if (s[y] == '\n' && s[y+1] && s[y+1] == '\n')
// 		{
// 			del_s[x] = "";
// 			continue;
// 		}
// 		while (s[y] == c)
// 			y++;
// 		z = y;
// 		while (s[y] != c && s[y] != '\0')
// 			y++;
// 		del_s[x] = ft_alloclist(&s[z], y - z);
// 		if (del_s[x] == 0)
// 			return (ft_free(del_s));
// 		x++;
// 	}
// 	del_s[x] = NULL;
// 	return (del_s);
// }

void    free_arr(char **ar)
{
    int    i;

    i = -1;
    while (ar[++i])
        free(ar[i]);
    free(ar);
}

char    **arrjoin(char **ar, char *line, int size)
{
    char    **rtrn;
    int        i;
    int        j;

    i = -1;
    if (!line)
        return (ar);
    rtrn = ft_calloc(sizeof(char *), (size + 2));
    while (ar[++i])
        rtrn[i] = ft_calloc(1, ft_strlen(ar[i]) + 1);
    i = -1;
    while (ar[++i])
    {
        j = -1;
        while (ar[i][++j])
            rtrn[i][j] = ar[i][j];
    }
    rtrn[i] = ft_strdup(line);
    free_arr(ar);
    free(line);
    return (rtrn);
}

char    **map_to_ar(int fd)
{
    int        i;
    char    **map;
    char    *line;

    map = ft_calloc(sizeof(char *), 1);
    line = get_next_line(fd);
    while (1)
    {
        i = 0;
        if (line == NULL)
            return (free_arr(map), NULL);
        while ((line[i] && line[i] == ' ') || line[i] == '\n')
            i++;
        if (line[i])
            break ;
        free(line);
        line = get_next_line(fd);
    }
    map = arrjoin(map, line, i++);
    while (line)
    {
        line = get_next_line(fd);
        map = arrjoin(map, &line[0], i++);
    }
    return (free(line), map);
}

int	checker_map1(char *file_name)
{
	int fd = open(file_name, O_RDONLY);

	put_map(map_to_ar(fd), file_name);
	printf("yes\n");
	// for(int i = 0; info_path->info->map[i] ;i++)
	// 	printf("======%s|\n", info_path->info->map[i]);
	// exit(0);
	if (!empty_line())
		return (0);
	if (!check_content())
		return (0);
	player_pos();
	if (!check_first_last())
		return (0);
	if (!is_closed(info_path->info->pos || !is_closed('0')))
		return (0);
	// printf("errororor\n");
	// exit(1);
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
	{
		throw_err_2("MapIsBAD🆘\n");
	}
	
}
