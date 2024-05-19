/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:14:11 by aatbir            #+#    #+#             */
/*   Updated: 2024/05/19 11:28:31 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <fcntl.h>
# include "lib/get_next_line.h"
# include "lib/libft.h"
# include "mlx/include/MLX42/MLX42.h"



# define TILE_SIZE 64
// # define arr_str 60

typedef struct s_info
{
	char	*first_info;
	char	*second_info;
	char	*third_info;
	char	*fourth_info;
	char	*first_color;
	char	*second_color;
	int		_f[3];
	int		_c[3];
	int		x;
	int		y;
	char pos;
}	t_info;

// typedef struct s_player
// {
// 	float	x;
// 	float	y;
// 	float	arr_str;
// 	char	_snew;
// }	t_player;

typedef struct s_map
{
	t_info	*info;
	int		wid;
	int		hei;
	char	**map;
}	t_map;

t_map *info_path;

char	*read_file(char *filename);
void	ft_free_info(t_info *info);

t_info	*get_info(t_info *info, char *filename);
void	throw_err_2(char *err_msg);

int		only(char *line, int c, int d);
int		check_if_only_numbers(char **str);
int		valid_rgb_f(t_info *info, char *filename);
int		valid_rgb_c(t_info *info, char *filename);
char	**splimed_key_value_6(char *filename);


char	*ft_strtrim(char const *s1, char const *set);
char	*valid_first_info(t_info *info, char *filename);
char	*valid_second_info(t_info *info, char *filename);
char	*valid_third_info(t_info *info, char *filename);
char	*valid_fourth_info(t_info *info, char *filename);
int		*split_first_color(t_info *info, char *filename);
char	**textures(void);
int		compare_dup_text(t_info *info, char *filename);
void	parsing(t_info *info, char *filename);
int		compare(char *s1, char *s2);

void	arr_free(char **s);

char	**store_get_info_in_array(t_info *info, char *filename);
char	*valid_first_info(t_info *info, char *filename);
char	*ft_half_strtrim(char const *s1, char const *set);

char	*take_first_string(char *line);
char	*start_with(char *first_word, char *target, size_t size);
int		is_valid_textures(t_info *info, char *filename);
void check_get_info(t_info	*info, char *filename);


#endif