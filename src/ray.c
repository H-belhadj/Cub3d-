/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:10:04 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/05/27 13:24:27 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"
// // #define map->width 512
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

// void player_view(t_info *map, int y, int x)
// {
// 	if(map->map[y][x] == 'N')
// 		map->view = (3 * M_PI) / 2;
// 	else if(map->map[y][x] == 'S')
// 		map->view = M_PI / 2;
// 	else if(map->map[y][x] == 'E')
// 		map->view = 0;
// 	else if(map->map[y][x] == 'W')
// 		map->view = M_PI;
// }


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



void pos_player(t_info *map)
{
	int i;
	int j;

	i = -1;
	while(map->map[++i])
	{
		j = 0;
		while(map->map[i][j])
		{
			if(ft_strchr("NSWE", map->map[i][j]))
			{
				map->player_x = (j + 0.5) * TILE_SIZE - TILE_PLAYER_SIZE / 2;
				map->player_y = (i + 0.5) * TILE_SIZE - TILE_PLAYER_SIZE / 2;
                map->map[i][j] = '0';
				return;
			}
			j++;
		}
	}
	
}

void	var_init(t_info *info)
{
	info->viewangle = 60 * (M_PI / 180);
	info->player.speedretate = SPEED_R * (M_PI / 180);
	// info->player.speedretate_m = M_SPEED_R * (M_PI / 180);
	info->player.speedmove = (CUBE * SPEED_M) / 20 ;
	info->player.dirturn = 0;
	info->player.dirwalk = 0;
	info->rad = M_PI / 180;
}

void	vapsangle(double *angle)
{
	*angle = fmod(*angle, 2 * M_PI);
	if (*angle < 0)
		*angle += 2 * M_PI;
}

void	turn_left(t_info *info,int flag)
{
	info->player.dirturn = 1;
	if (flag)
		info->angle += info->player.dirturn
			* info->player.speedretate_m;
	else
		info->angle += info->player.dirturn
			*  info->player.speedretate;
	vapsangle(&info->angle);
}

void	turn_right(t_info *info,int flag)
{
	info->player.dirturn = -1;
	if (flag)
		info->angle += info->player.dirturn
			*  info->player.speedretate_m;
	else
		info->angle += info->player.dirturn
			*  info->player.speedretate;
	vapsangle(&info->angle);
}

void	check_dir_angle(t_info *info)
{
    int i = 0;
    while(info->map[i])
    {
        int j = 0;
        while(info->map[i][j])
        {
            if (info->map[i][j] == 'W')
            	info->angle = M_PI;
            if (info->map[i][j] == 'E')
            	info->angle = 0;
            if (info->map[i][j] == 'S')
            	info->angle = M_PI / 2;
            if (info->map[i][j] == 'N')
            	info->angle = 3 * M_PI / 2;
            j++;
        }
        i++;
        
    }

}

// void	line(    t_info *data, double dis, double ang, int color)
// {
// 	int	x;
// 	int	y;
// 	int	i;

// 	i = 0;
// 	while (i < dis)
// 	{
// 		x = data->player_x + i * cos(ang);
// 		y = data->player_y + i * sin(ang);
// 		if ((x >= 0 && x < data->player_x) && (y >= 0 && y < data->player_y))
// 			mlx_put_pixel(data->img ,x, y, color);
// 		i++;
// 	}
// }

// void	drawray(    t_info *data)
// {
// 	int	i;

// 	i = 0;
// 	while (i < data->nbr_rays)
// 	{
// 		line(data ,data->ray[i].dis, data->ray[i].angle, 0xFFFFFF);
// 		i++;
// 	}
// }

int	lenofmap(char **arr)
{
	int	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}

t_cord	smallest(t_info *mlx, t_cord c1, t_cord c2)
{
	float	d1;
	float	d2;

	d1 = sqrt((c1.xstep - mlx->player_x) * (c1.xstep - mlx->player_x) + \
				(c1.ystep - mlx->player_y) * (c1.ystep - mlx->player_y));
	d2 = sqrt((c2.xstep - mlx->player_x) * (c2.xstep - mlx->player_x) + \
				(c2.ystep - mlx->player_y) * (c2.ystep - mlx->player_y));
	if (d1 < d2)
	{
		c1.is_vertical = false;
		return (c1);
	}
	c2.is_vertical = true;
	return (c2);
}

bool	has_wall(t_info *mlx, float x, float y)
{

    mlx->rows = ft_strlen(mlx->map[0]);
    mlx->cols = lenofmap(mlx->map);


    // int width = get_width();
    // int height = get_height();
	if (x < 0 || x > mlx->width || y < 0 || y > mlx->height)
		return (true);
	x = floor(x / TILE_SIZE);
	y = floor(y / TILE_SIZE);
	if (x < 0 || x >= mlx->rows || y < 0 || y >= mlx->cols)
		return (false);
	if (mlx->map[(int)y][(int)x] == '1')
		return (true);
	return (false);
}

t_cord	horizontal_intersection(t_info *mlx, float ray_angle)
{
	t_cord	cord;
	int		sign;
	bool	is_ray_facing_up;

	is_ray_facing_up = ray_angle > M_PI && ray_angle < 2 * M_PI;
	sign = 1;
	if (is_ray_facing_up)
		sign = -1;
	cord.ystep = floor(mlx->player_y / TILE_SIZE) * TILE_SIZE;
	if (!is_ray_facing_up)
		cord.ystep += TILE_SIZE;
	cord.xstep = mlx->player_x + (cord.ystep - mlx->player_y) / tan(ray_angle);
	while (true)
	{
		if ((is_ray_facing_up && \
				has_wall(mlx, cord.xstep, cord.ystep - TILE_SIZE)) || \
			(!is_ray_facing_up && \
				has_wall(mlx, cord.xstep, cord.ystep)))
			break ;
		cord.xstep += sign * TILE_SIZE / tan(ray_angle);
		cord.ystep += sign * TILE_SIZE ;
	}
	return (cord);
}

t_cord	vertical_intersection(t_info *mlx, float ray_angle)
{
	t_cord	cord;
	int		sign;
	bool	is_ray_facing_left;

	is_ray_facing_left = ray_angle > M_PI / 2 && ray_angle < 1.5 * M_PI;
	sign = 1;
	cord.xstep = ceil(mlx->player_x / TILE_SIZE) * TILE_SIZE;
	if (is_ray_facing_left)
	{
		cord.xstep -= TILE_SIZE;
		sign = -1;
	}
	cord.ystep = mlx->player_y - (mlx->player_x - cord.xstep) * tan(ray_angle);
	while (true)
	{
        if(ray_angle == M_PI / 2 || ray_angle < 1.5 * M_PI )
        {
            // cord.xstep = mlx->player_x;
            cord.ystep = mlx->player_y;
            break ;
        }
		if ((is_ray_facing_left && \
				has_wall(mlx, cord.xstep - TILE_SIZE, cord.ystep)) || \
			(!is_ray_facing_left && \
				has_wall(mlx, cord.xstep, cord.ystep)))
			break ;
		cord.xstep += sign * TILE_SIZE;
		cord.ystep += sign * TILE_SIZE * tan(ray_angle); 
	}
	return (cord);
}


void drawLine(t_info *map, float x1, float y1, float x2, float y2)
{
    float dx, dy, step, x, y;
    int i;

    dx = x2 - x1;
    dy = y2 - y1;

    if (fabs(dx) >= fabs(dy))
        step = fabs(dx);
    else
        step = fabs(dy);

    dx = dx / step;
    dy = dy / step;
    x = x1;
    y = y1;

    uint32_t color = 0xFF0000FF; // Red color (format: 0xRRGGBBAA)

    i = 0;

    while (i <= step)
    {

        // if (map->map[(int)y / TILE_SIZE][(int)x /TILE_SIZE] != '1')
        if (x > 0 && x < map->width && y > 0 && y < map->height)
            mlx_put_pixel(map->img, (int)x, (int)y, color); // Set the color to red
        x += dx;
        y += dy;
        i++;
    }
}

double deg2rad(double degrees)
{
    return degrees * (M_PI / 180.0);
}
// int	is_wall(double x, double y)
// {
//     t_info *map;
// 	if (map->map[(int)(y) / CUBE][(int)(x) / CUBE] == '1'
// 		|| map->map[(int)(y) / CUBE][(int)(x) / CUBE] == ' ')
// 		return (1);
// 	return (0);
// }
void hook_key(void *arg)
{
    t_info *map = (t_info*)arg;
    int target_x = map->player_x;
    int target_y = map->player_y;

    if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
        mlx_close_window(map->mlx);

    if (mlx_is_key_down(map->mlx, MLX_KEY_W))
        target_y -= PLAYER_SPEED;
    if (mlx_is_key_down(map->mlx, MLX_KEY_S))
        target_y += PLAYER_SPEED;
    if (mlx_is_key_down(map->mlx, MLX_KEY_A))
        target_x -= PLAYER_SPEED;
    if (mlx_is_key_down(map->mlx, MLX_KEY_D))
        target_x += PLAYER_SPEED;
    if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
        map->angle += deg2rad(3);
    else if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT)) 
        map->angle -= deg2rad(3);

    // if(map->angle > 2 * M_PI)
    //         map->angle -=  2 * M_PI;
    // if(map->angle < 0)
    //         map->angle +=  2 * M_PI;
            
    int map_x = target_x / TILE_SIZE;
    int map_y = target_y / TILE_SIZE;

    // printf("w: %d, h: %d => %c\n", map_x, map_y, map->map[map_y][map_x]);
    if ( map->map[map_y][map_x] == '0' )
    {
        // Draw line from player to target
        
        // Update player's position
        map->player_x = target_x;
        map->player_y = target_y;
    }
        // printf("error\n");
        draw_map(map);
        float xf, yf;
        if(map->angle > 2 * M_PI)
            map->angle -=  2 * M_PI;
        if(map->angle < 0)
            map->angle +=  2 * M_PI;
            
        map->angle_fov = map->angle - deg2rad(FOV / 2);
        // map->angle -= deg2rad(FOV / 2);
        // printf("the angele is == %f\n", map->angle);

        t_cord inter;
        int i = 0;
        while(i < FOV)
        {
            map->angle_fov += deg2rad(1);
            if(map->angle_fov > 2 * M_PI)
                map->angle_fov -=  2 * M_PI;
            if(map->angle_fov < 0)
                map->angle_fov +=  2 * M_PI;
            inter = smallest(map, horizontal_intersection(map, map->angle_fov), vertical_intersection(map, map->angle_fov));
            printf("%f\n", map->angle_fov);
            // inter = vertical_intersection(map, map->angle_fov);
            drawLine(map, map->player_x + 4.5 , map->player_y + 4.5 ,inter.xstep  , inter.ystep );
            i++;
        }
            
        xf = cos(map->angle) * inter.xstep;
        yf = sin(map->angle) * inter.ystep;

        //ray intersaction

        // mlx_put_pixel(map->img, map->player_x, map->player_y,);
        // drawLine(map, map->player_x + 4.5 , map->player_y + 4.5 ,inter.xstep  , inter.ystep );

        
        // drawLine(map, map->player_x + 4.5 , map->player_y + 4.5 ,map->player_x + xf + 4.5 , map->player_y + yf + 4.5);
        // drawray(map);
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

    if (!info || !info->map || !info->img)
    {
        fprintf(stderr, "Invalid parameters or uninitialized map/image\n");
        return;
    }


    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            char tile = info->map[i][j];
            uint32_t color;
    
                if (tile == '1')
                    color = 0x000000FF; // Black color
                else 
                    color = 0xFFFFFFFF; // White color
                  
            for (y = 0; y < TILE_SIZE; y++)
            {
                for (x = 0; x < TILE_SIZE; x++)
                {
                    pixel_x = j * TILE_SIZE + x;
                    pixel_y = i * TILE_SIZE + y;

                    // Check if the pixel is on the border of the tile
                    if (x == 0 || x == TILE_SIZE - 1 || y == 0 || y == TILE_SIZE - 1)
                        mlx_put_pixel(info->img, pixel_x, pixel_y, 0x00FF00FF);
                    else
                        mlx_put_pixel(info->img, pixel_x, pixel_y, color);
                }
            }
           
        }
    }


    for (i = 0; i < TILE_PLAYER_SIZE; ++i) {
        for (j = 0; j < TILE_PLAYER_SIZE; ++j) {

            int x = info->player_x + i;
            int y = info->player_y + j;

            mlx_put_pixel(info->img, x, y, 0x0000FFFF);

        }
    }
}

// void draw_plyer(void *param)
// {
    
    
// }



void init(t_info *map)
{

    map->width = get_width() * TILE_SIZE;
    map->height = get_height() * TILE_SIZE;

    map->mlx = mlx_init(map->width, map->height, "CUB3D", 0);
    if (!map->mlx) {
        fprintf(stderr, "Failed to initialize MLX\n");
        return;
    }

    map->img = mlx_new_image(map->mlx, map->width, map->height);
    if (!map->img)
    {
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
    check_dir_angle(map);
    mlx_loop_hook(map->mlx, hook_key, map);
    mlx_loop(map->mlx);
}
