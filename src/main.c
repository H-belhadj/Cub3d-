/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:58:34 by aatbir            #+#    #+#             */
/*   Updated: 2024/06/01 17:23:09 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

typedef struct key_value
{
	char	*key;
	char	*value;
}	t_kv;


int	main(int ac, char **av)
{
	t_info	*info ;
	char	**str;
	// t_info  map;
	// char	*take;
	int		i;

	i = 0;
	info = malloc(sizeof(t_info));
	info_path = (t_map*)ft_calloc(sizeof(t_map), 1);
	info_path->info = info;
	(void)ac;
	if (!av[1])
		return (printf("Error\n"), -1);
	str = store_get_info_in_array(info, av[1]);
	// while(str[i])
	// 	printf("%s\n", str[i++]);
	// printf ("%c\n", info_path->info->pos);
	// info->first_color = 0;
	// info->first_info = 0;
	// info
	// info = get_info(info, av[1]);
	// while (str[i])
	// {
	// 	printf("str[%d] => %s\n", i +1, str[i]);
	// 	i++;
	// }
	// check_get_info(info, av[1]);
	// printf("+first : %s\n", info->first_info);
	// printf("+second : %s\n", info->second_info);
	// printf("+third : %s\n", info->third_info);
	// printf("+fourth : %s\n", info->fourth_info);
	// printf("+color 1 : %s\n", info->first_color);
	// printf("+color 2 : %s\n", info->second_color);
	parsing(info, av[1]);
	pos_player(info);
	init(info);
	// run_game();
	arr_free(str);
	// system("leaks cub3D");
	return (0);
}
