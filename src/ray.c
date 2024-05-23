/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:10:04 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/05/23 12:36:26 by hbelhadj         ###   ########.fr       */
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
// void draw_box(unsigned int color, int x, int y) {
//     int i, j;
//     i = 0;

//     while (i < TILE_SIZE)
//     {
//         j = 0;
//         while (j < TILE_SIZE)
//         {
//             if(x > 0 && x < get_width() * TILE_SIZE && y > 0 && y < get_height() * TILE_SIZE)
//                 mlx_put_pixel(info_path->info->img, x, y, color);
//             j++;
//         }
//         i++;
//     }
// 	return;
// }

#include "../includes/head.h"

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

int get_height()
{
    int i = 0;
    while (info_path->info->map[i])
        i++;
    return i;
}

int get_width()
{
    int i = 0;
    int max_width = 0;
    while (info_path->info->map[i]) {
        int j = 0;
        while (info_path->info->map[i][j])
            j++;
        if (j > max_width)
            max_width = j;
        i++;
    }
    return max_width;
}

void draw_map(void *param)
{
    t_info *info = (t_info *)param;
    int x, y, i, j;
    int pixel_x, pixel_y;
    int width = get_width();
    int height = get_height();

    if (!info || !info->map || !info->img) {
        fprintf(stderr, "Invalid parameters or uninitialized map/image\n");
        return;
    }

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            char tile = info->map[i][j];
            uint32_t color;

            if (tile == '1') {
                color = 0x000000FF; // Black color
            } else if (tile == '0') {
                color = 0xFFFFFFFF; // White color
            } else if (strchr("NWSE", tile)) {
                color = 0x00FF0000; // Red color for NWSE
            } else {
                continue; // Skip if it's neither '1', '0', nor 'NWSE'
            }

            for (y = 0; y < TILE_SIZE; y++) {
                for (x = 0; x < TILE_SIZE; x++) {
                    pixel_x = j * TILE_SIZE + x;
                    pixel_y = i * TILE_SIZE + y;

                    if ((uint32_t)pixel_x < info->img->width && (uint32_t)pixel_y < info->img->height) {
                        mlx_put_pixel(info->img, pixel_x, pixel_y, color);
                    }
                }
            }
        }
    }
}

void init(t_info *map)
{
    // // Actual map data
    char *actual_map[] = {
        "11111",
        "10001",
        "10S01",
        "10001",
        "10001",
        "10001",
        "11001",
        "10001",
        "10001",
        "10001",
        "10001",
        "10001",
        "11111",
        NULL
    };

    map->map = actual_map;

    int width = get_width() * TILE_SIZE;
    int height = get_height() * TILE_SIZE;

    map->mlx = mlx_init(WIDTH, height, "CUB3D", 1);
    if (!map->mlx) {
        fprintf(stderr, "Failed to initialize MLX\n");
        return;
    }

    map->img = mlx_new_image(map->mlx, width, height);
    if (!map->img) {
        fprintf(stderr, "Failed to create new image\n");
        mlx_terminate(map->mlx);
        return;
    }

    if (mlx_image_to_window(map->mlx, map->img, 0, 0) < 0) {
        fprintf(stderr, "Failed to put image to window\n");
        mlx_delete_image(map->mlx, map->img);
        mlx_terminate(map->mlx);
        return;
    }

    draw_map(map);
    
    mlx_loop_hook(map->mlx, hook_key, map);
    mlx_loop(map->mlx);
}
