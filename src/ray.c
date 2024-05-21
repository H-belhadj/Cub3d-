/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:10:04 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/05/21 21:41:57 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"
// // #define WIDTH 512
// // #define HEIGHT 512

// // static mlx_image_t* image;

// // // -----------------------------------------------------------------------------

// int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

// void ft_randomize(void* param)
// {
// 	(void)param;
// 	for (uint32_t i = 0; i < WIDTH; ++i)
// 	{
// 		for (uint32_t y = 0; y < HEIGHT; ++y)
// 		{
// 			uint32_t color = ft_pixel(255, 255, 255, 255);
// 			mlx_put_pixel(info_path->info->img, i, y, color);
// 		}
// 	}
// }

// // void ft_hook(void* param)
// // {
// // 	mlx_t* mlx = param;

// // 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// // 		mlx_close_window(mlx);
// // 	if (mlx_is_key_down(mlx, MLX_KEY_UP))
// // 		image->instances[0].y -= 5;
// // 	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
// // 		image->instances[0].y += 5;
// // 	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
// // 		image->instances[0].x -= 5;
// // 	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
// // 		image->instances[0].x += 5;
// // }


// // // -----------------------------------------------------------------------------

// // int32_t run_game(void)
// // {
// // 	mlx_t* mlx;

// // 	// Gotta error check this stuff
// // 	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
// // 	{
// // 		puts(mlx_strerror(mlx_errno));
// // 		return(EXIT_FAILURE);
// // 	}
// // 	if (!(image = mlx_new_image(mlx, 12, 12)))
// // 	{
// // 		mlx_close_window(mlx);
// // 		puts(mlx_strerror(mlx_errno));
// // 		return(EXIT_FAILURE);
// // 	}
// // 	if (mlx_image_to_window(mlx, image, 256 - 6, 256 - 6) == -1)
// // 	{
// // 		mlx_close_window(mlx);
// // 		puts(mlx_strerror(mlx_errno));
// // 		return(EXIT_FAILURE);
// // 	}
	
// // 	mlx_loop_hook(mlx, ft_randomize, mlx);
// // 	mlx_loop_hook(mlx, ft_hook, mlx);

// // 	mlx_loop(mlx);
// // 	mlx_terminate(mlx);
// // 	return (EXIT_SUCCESS);
// // }

// //key HOOK function

// void	key_hook(mlx_key_data_t keydata, void* param)
// {
// 	(void)param;
// 	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE && keydata.modifier == MLX_CONTROL)
// 		puts("Gotta grab it all!");
// }

// void hook_key(void *arg)
// {
// 	info_path->info->mlx = arg;
// 	if (mlx_is_key_down(info_path->info->mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(info_path->info->mlx);
// 	if (mlx_is_key_down(info_path->info->mlx, MLX_KEY_UP))
// 		info_path->info->img->instances[0].y -= 5;	
// 	if (mlx_is_key_down(info_path->info->mlx, MLX_KEY_DOWN))
// 		info_path->info->img->instances[0].y += 5;
// 	if (mlx_is_key_down(info_path->info->mlx, MLX_KEY_LEFT))
// 		info_path->info->img->instances[0].x -= 5;
// 	if (mlx_is_key_down(info_path->info->mlx, MLX_KEY_RIGHT))
// 		info_path->info->img->instances[0].x += 5;
// }

// // void player_view(t_info *map, int y, int x)
// // {
// // 	if(map->map[y][x] == 'N')
// // 		map->view = (3 * M_PI) / 2;
// // 	else if(map->map[y][x] == 'S')
// // 		map->view = M_PI / 2;
// // 	else if(map->map[y][x] == 'E')
// // 		map->view = 0;
// // 	else if(map->map[y][x] == 'W')
// // 		map->view = M_PI;
// // }

// // void player_pos(t_info *map)
// // {
// // 	int i;
// // 	int j;

// // 	i = -1;
// // 	while(map->map[++i])
// // 	{
// // 		j = 0;
// // 		while(map->map[i][j])
// // 		{
// // 			if(ft_strchr("NSWE", map->map[i][j]))
// // 			{
// // 				map->x = j * PIXEL_SIZE;
// // 				map->y = i * PIXEL_SIZE;
// // 				player_view(map, i, j);
// // 				return;
// // 			}
// // 			j++;
// // 		}
// // 	}
	
// // }

// void init(t_info *map)
// {
// 	map->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", 1);
// 	map->img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
// 	mlx_image_to_window(map->mlx, map->img, 0, 0);


// 	// Drawing LOGIC
// 	//{
// 				// mlx_loop_hook(mlx, drawing map, mlx);
// 			// mlx_loop_hook(map->mlx, hook_key, &map);

// 				mlx_loop_hook(map->mlx, ft_randomize, map);
// 	mlx_loop_hook(map->mlx, hook_key, map);
// 		// printf("error\n");
// 			//======>drawing map:
// 			/**
// 			 * 
// 			 * 1- loopi 3la image 
			
// 			// */
// 			// while(info_path->info->map[i])
// 			// 	printf("%s\n", info_path->info->map[i++]);
// 	//}
// 	// KEY HOOK LOGIC
// 	// hook_key(map->mlx);
// 	mlx_loop(map->mlx);
// }

#include "../includes/head.h"

// int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

// void ft_randomize(void* param)
// {
//     t_info *map = (t_info*)param;

//     for (uint32_t i = 0; i < 128; ++i)
//     {
//         for (uint32_t y = 0; y < 128; ++y)
//         {
//             uint32_t color = ft_pixel(255, 255, 255, 255);
//             mlx_put_pixel(map->img, i, y, color); // Corrected the argument here
//         }
//     }
// }

void hook_key(void *arg)
{
    t_info *map = (t_info*)arg;

    if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
        mlx_close_window(map->mlx);
    if (mlx_is_key_down(map->mlx, MLX_KEY_UP))
        map->img->instances[0].y -= 5;    
    if (mlx_is_key_down(map->mlx, MLX_KEY_DOWN))
        map->img->instances[0].y += 5;
    if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
        map->img->instances[0].x -= 5;
    if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
        map->img->instances[0].x += 5;
}

void key_hook(mlx_key_data_t keydata, void* param)
{
    (void)param;
    if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE && keydata.modifier == MLX_CONTROL)
        puts("Gotta grab it all!");
}

void    my_mlx_pixel_put(t_info *data, int x, int y, unsigned int color)
{
    char *dst;
    
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}
// Draw box
void draw_box(unsigned int color, int x, int y) {
    int i, j;
    i = 0;

    while (i < TILE_SIZE) {
        j = 0;
        while (j < TILE_SIZE) {
            my_mlx_pixel_put(info_path->info->image, x * TILE_SIZE + j, y * TILE_SIZE + i, color);
	        printf("haitam where is the error\n");
            j++;
        }
        i++;
    }
	return;
}

void draw_map(void *parm) {
    (void)parm;
    int i, j;
    i = 0;
    while (info_path->info->map[i]) {
        j = 0;
        while (info_path->info->map[i][j]) {
            if (info_path->info->map[i][j] == '1'){
                draw_box(0x000000, j, i);}
            else if (info_path->info->map[i][j] == '0'){
                draw_box(0xFFFFFF, j, i);}
            j++;
        }
        i++;
    }
	return;
}

int get_height()
{
	int i;
	i = 0;
	while(info_path->info->map[i])
		i++;
	return (i);	
}

int get_width()
{
	int i;
	int j;
	i = 0;
	while(info_path->info->map[i])
	{
		j = 0;
		while(info_path->info->map[i][j])
			j++;
		i++;
	}
	return (j);	
}	

void init(t_info *map)
{
	int width = get_width() * TILE_SIZE;
	int height = get_height() * TILE_SIZE;
	
    map->mlx = mlx_init(width, height, "CUB3D", 1);
    map->img = mlx_new_image(map->mlx, width, height);
    mlx_image_to_window(map->mlx, map->img, 0, 0);
    mlx_loop_hook(map->mlx, draw_map, map);
	printf("error\n");
    
	
	//keyhook is done
    mlx_loop_hook(map->mlx, hook_key, map);

    mlx_loop(map->mlx);
}