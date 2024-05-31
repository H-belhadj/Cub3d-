/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:10:04 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/05/31 20:09:56 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void my_mlx_texture_to_image(t_info* map)
{
	uint8_t* pixelx;
	uint8_t* pixeli;
    //calc
    // printf("haitam errr\n");
    double ok;
    double x_calc = (modf((map->inter.xstep) / TILE_SIZE, &ok)) * TILE_SIZE;
    double y_calc = (modf((map->inter.ystep) / TILE_SIZE, &ok)) * TILE_SIZE;
    // printf("x_cal===%f || y_calc===%f\n", x_calc, y_calc);
    //first condition
    //second condtion
    double x_tex, y_tex;
    x_tex = 0;
    y_tex = 0;
    
    
    mlx_texture_t* photos = map->tex1;
    
        printf("x_img====%f || y_img====%f\n", x_calc, y_calc);

    if(x_calc <= 0.1)
    {
        photos = map->tex1;
        x_tex = (y_calc * photos->width) / TILE_SIZE;
        y_tex = 0;
    }
    else if(y_calc <= 0.1)
    {
        photos = map->tex2;
        x_tex = (x_calc * photos->width) / TILE_SIZE;
        y_tex = 0;
    }

    else if(x_calc > TILE_SIZE - 0.1)
    {
        photos = map->tex3;
        x_tex = (y_calc * photos->width) / TILE_SIZE;
        y_tex = 0;
    }
    else if(y_calc > TILE_SIZE - 0.1)
    {
        photos = map->tex4;
        x_tex = (x_calc * photos->width) / TILE_SIZE;
        y_tex = 0;
    }
    
    // double y_tex = (y_calc * photos->width) / TILE_SIZE ;
    double x_img = map->x_wall1;
    double y_img = map->y_wall1;
    double y_plus = photos->height / (map->y_wall2 - map->y_wall1);

    
    
    // printf("x_img====%d || y_img====%d\n", x_img, y_img);
	while (y_tex < photos->height && y_img < map->y_wall2)
	{
        if (((y_tex * photos->width) + x_tex) * photos->bytes_per_pixel > 0 &&
            (((y_tex * photos->width) + x_tex) * photos->bytes_per_pixel < (photos->width * photos->height) * photos->bytes_per_pixel) 
            && ((y_img * map->img->width) + x_img) * photos->bytes_per_pixel > 0
            && (((y_img * map->img->width) + x_img) * photos->bytes_per_pixel < (map->img->width * map->img->height) * photos->bytes_per_pixel))
        {
		    pixelx = &photos->pixels[(((uint32_t)y_tex * photos->width) + (uint32_t)x_tex) * photos->bytes_per_pixel];
		    pixeli = &map->img->pixels[(((uint32_t)y_img * map->img->width) + (uint32_t)x_img) * photos->bytes_per_pixel];
		    memmove(pixeli, pixelx,  photos->bytes_per_pixel);
        }
        y_tex += y_plus;
        y_img +=1;
	}
}

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
	info->viewangle = FOV * (M_PI / 180);
	info->player.speedretate = SPEED_R * (M_PI / 180);
	info->player.speedmove = (CUBE * SPEED_M) / 20 ;
	info->player.dirturn = 0;
	info->player.dirwalk = 0;
	info->rad = M_PI / 180;
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

int	lenofmap(char **arr)
{
	int	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}
//mo3adalat vitafors

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
        mlx->dis = d1;
		c1.is_vertical = false;
		return (c1);
	}
    mlx->dis = d2;
	c2.is_vertical = true;
	return (c2);
}

bool	has_wall(t_info *mlx, int x, int y)
{	
	x /=  TILE_SIZE;
	y /= TILE_SIZE;
	if (x < 0 || x >= mlx->rows || y < 0 || y >= mlx->cols)
		return (true);
	if (mlx->map[(int)y][(int)x] == '1')
		return (true);
	return (false);
}

t_cord	horizontal_intersection(t_info *mlx, float ray_angle)
{
	t_cord	cord;
	int		sign;
	bool	is_ray_facing_up;

	is_ray_facing_up = ray_angle > M_PI;
	sign = 1;
	if (is_ray_facing_up)
		sign = -1;


        
	cord.ystep = (int) (mlx->player_y / TILE_SIZE) * TILE_SIZE;
	if (!is_ray_facing_up)
		cord.ystep += TILE_SIZE ;
	cord.xstep = mlx->player_x + (cord.ystep - mlx->player_y) / tan(ray_angle);
    
	const float dx = sign * TILE_SIZE / tan(ray_angle);
    const float dy = sign * TILE_SIZE;
    
    while (true)
	{
		if ((is_ray_facing_up && \
				has_wall(mlx, cord.xstep, cord.ystep - TILE_SIZE)) || \
			(!is_ray_facing_up && \
				has_wall(mlx, cord.xstep, cord.ystep)))
			break ;
		cord.xstep += dx;
		cord.ystep += dy ;

        if (cord.xstep > mlx->width || cord.xstep < 0) break;
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
	cord.xstep = (int) (1 + mlx->player_x / TILE_SIZE) * TILE_SIZE;
	if (is_ray_facing_left)
	{
		cord.xstep -= TILE_SIZE ;
		sign = -1;
	}
	cord.ystep = mlx->player_y - (mlx->player_x - cord.xstep) * tan(ray_angle);

    const float dx =  sign * TILE_SIZE;
    const float dy = sign * TILE_SIZE * tan(ray_angle);
	while (true)
	{
		if ((is_ray_facing_left && \
				has_wall(mlx, cord.xstep - TILE_SIZE, cord.ystep)) || \
			(!is_ray_facing_left && \
				has_wall(mlx, cord.xstep, cord.ystep)))
			break ;
		cord.xstep += dx;
		cord.ystep += dy; 
	}
	return (cord);
}


void drawLine(t_info *map, int x1, int y1, int x2, int y2, uint32_t color)
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

    // color = 0xFF0000FF; // Red color (format: 0xRRGGBBAA)


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

void drawalls(t_info *map, double i)
{
    map->x_wall1 = i;
    map->x_wall2 = i;
    map->y_wall1 = (map->height / 2) - ((map->height / 2) / map->dis) * TILE_SIZE;
    map->y_wall2 = (map->height / 2) + ((map->height / 2) / map->dis)* TILE_SIZE;
    
    my_mlx_texture_to_image(map);
    
    // drawLine(map, map->x_wall1, map->y_wall1 , map->x_wall2, map->y_wall2 , 0xFF0000FF);
}
double deg2rad(double degrees)
{
    return degrees * (M_PI / 180.0);
}
void hook_key(void *arg)
{    


    t_info *map = (t_info*)arg;
    double target_x = map->player_x;
    double target_y = map->player_y;

    // int b = 0;
    // int c = 0;
    for (int i = 0; i < map->height; i++)
    {
        for (int j = 0; j < map->width; j++)
        {
             
                mlx_put_pixel(map->img, j, i, 0x000000);
               
        }
    }

    if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
        mlx_close_window(map->mlx);

    if (mlx_is_key_down(map->mlx, MLX_KEY_W))
    {

        target_x += PLAYER_SPEED * cos(map->angle);
        target_y += PLAYER_SPEED * sin(map->angle);
    }
    if (mlx_is_key_down(map->mlx, MLX_KEY_S))
    {
        target_x -= PLAYER_SPEED * cos(map->angle);
        target_y -= PLAYER_SPEED * sin(map->angle);
        
    }
    if (mlx_is_key_down(map->mlx, MLX_KEY_A))
    {
        target_y -= PLAYER_SPEED * cos(map->angle);
        target_x += PLAYER_SPEED * sin(map->angle);
    }
    if (mlx_is_key_down(map->mlx, MLX_KEY_D))
    {
        target_y += PLAYER_SPEED * cos(map->angle);
        target_x -= PLAYER_SPEED * sin(map->angle);
    }
    if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
        map->angle += deg2rad(2.5);
    else if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT)) 
        map->angle -= deg2rad(2.5);

    if(map->angle >= 2 * M_PI)
            map->angle -=  2 * M_PI;
    else if(map->angle < 0)
        map->angle +=  2 * M_PI;

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
    // draw_map(map);
    // float xf, yf;
        
            
    map->angle_fov = map->angle - deg2rad(FOV / 2);
    // map->angle -= deg2rad(FOV / 2);
    // printf("the angele is == %f\n", map->angle);

    double i = 0;
    double disrays = deg2rad(FOV)/ map->width;
    

    
    // printf("dis ===> %f\n", disrays);
    // int fov = map->viewangle / map->width;
    while(i <= map->width)
    {
        // map->angle_fov += deg2rad(1);
        if(map->angle_fov > 2 * M_PI)
            map->angle_fov -=  2 * M_PI;
        if(map->angle_fov < 0)
            map->angle_fov +=  2 * M_PI;

        // printf("angle: %f\n", map->angle_fov);


        t_cord h =  horizontal_intersection(map, map->angle_fov);
        h.is_vertical = false;
        t_cord v = vertical_intersection(map, map->angle_fov);
        v.is_vertical = true;

        // drawLine(map, map->player_x, map->player_y, h.xstep, h.ystep, 0x0000FFFF);
        // drawLine(map, map->player_x, map->player_y, v.xstep, v.ystep, 0xFF0000FF);
        
            
        map->inter = smallest(map, h, v);
        // printf("%f\n", map->angle_fov);
        // inter = vertical_intersection(map, map->angle_fov);
        drawalls(map, i);
        // drawLine(map, map->player_x  , map->player_y ,inter.xstep  , inter.ystep , 0xFF0000FF);
        map->angle_fov += disrays;
        i++;
    }

        // my_mlx_texture_to_image(map, map->tex);


        //ray intersaction

        // mlx_put_pixel(map->img, map->player_x, map->player_y,);
        // drawLine(map, map->player_x + 4.5 , map->player_y + 4.5 ,inter.xstep  , inter.ystep );

        
        // drawLine(map, map->player_x + 4.5 , map->player_y + 4.5 ,xf + 4.5 ,yf + 4.5);
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
                    if((pixel_x > 0 && pixel_x < info->width && pixel_y > 0 && pixel_y < info->height))
                    {
                        if (x == 0 || x == TILE_SIZE - 1 || y == 0 || y == TILE_SIZE - 1 )
                            mlx_put_pixel(info->img, pixel_x, pixel_y, 0x00FF00FF);
                        else
                            mlx_put_pixel(info->img, pixel_x, pixel_y, color);
                        
                    }
                }
            }
           
        }
    }


    for (i = 0; i < TILE_PLAYER_SIZE; ++i) {
        for (j = 0; j < TILE_PLAYER_SIZE; ++j) {

            double x = info->player_x + i;
            double y = info->player_y + j;
            
            if (x > 0 && x < info->width && y > 0 && y < info->height)
                mlx_put_pixel(info->img, x, y, 0x0000FFFF);

        }
    }
}

// void draw_plyer(void *param)
// {
    
    
// }


void init(t_info *map)
{
    map->tex1 = mlx_load_png("./iceberg.png");
    map->tex2 = mlx_load_png("./drafanov.png");
    map->tex3 = mlx_load_png("./rose.png");
    map->tex4 = mlx_load_png("./smallx.png");

    map->width = WIDTH;
    map->height = HEIGHT;

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
    map->rows = ft_strlen(map->map[0]);
    map->cols = lenofmap(map->map);
    check_dir_angle(map);
    // mlx_key_hook(map->mlx, hook_key, map);
    mlx_loop_hook(map->mlx, hook_key, map);
    mlx_loop(map->mlx);
}
