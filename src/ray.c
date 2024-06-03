/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:10:04 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/06/03 21:23:15 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void _short(t_info *map, double x_percent, mlx_texture_t	*tex)
{
	uint8_t			*pixelx;
	uint8_t			*pixeli;
	
	int x_tex = x_percent * tex->width;
	int y_tex;
	int y_start = map->y_wall1;
	int y_end = map->y_wall1 + map->y_wall2;
	if (y_end > map->height) 
		y_end = map->height;
	int x_map = map->x_wall1;
	int y_map = y_start * (y_start > 0);
	double k = (double)tex->height / map->y_wall2;

	while (y_map < y_end)
	{
		y_tex = k * (y_map - y_start);
		pixelx = &tex->pixels[(((int)y_tex * tex->width) + (int)x_tex) * tex->bytes_per_pixel];
		pixeli = &map->img->pixels[(((int)y_map * map->img->width) + (int)x_map) * tex->bytes_per_pixel];
		ft_memmove(pixeli, pixelx,  tex->bytes_per_pixel);
		y_map++;
	}
	
}

void my_mlx_texture_to_image(t_info* map, double x_percent)
{
	mlx_texture_t	*tex;
	t_cord	inter;

	inter = map->inter;
	if (!inter.is_vertical)
	{
		x_percent = inter.xstep / TILE_SIZE - ((int) inter.xstep / TILE_SIZE);
		tex = map->tex_north;
		if (map->player_y - inter.ystep < 0)
		{
			tex = map->tex_south;
			x_percent = 1.0 - x_percent;
		}
	}
	else
	{
		x_percent = inter.ystep / TILE_SIZE - ((int) inter.ystep / TILE_SIZE);
		tex = map->tex_east;
		if (map->player_x - inter.xstep > 0)
		{
			tex = map->tex_west;
			x_percent = 1.0 - x_percent;
		}
	}
	_short(map, x_percent, tex);
}

void check_dir(t_info *map, int i, int j)
{
	if (map->map[i][j] == 'W')
		map->angle = M_PI;
	if (map->map[i][j] == 'E')
		map->angle = 0;
	if (map->map[i][j] == 'S')
		map->angle = M_PI / 2;
	if (map->map[i][j] == 'N')
		map->angle = 3 * M_PI / 2;
	
}


void    pos_player(t_info *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			check_dir(map, i, j);
			if (ft_strchr("NSWE", map->map[i][j]))
			{
				map->player_x = (j + 0.5) * TILE_SIZE - TILE_PLAYER_SIZE / 2;
				map->player_y = (i + 0.5) * TILE_SIZE - TILE_PLAYER_SIZE / 2;
				map->map[i][j] = '0';
				return ;
			}
		}
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

double pow_2(double x) {
	return x * x;
}

t_cord	smallest(t_info *mlx, t_cord c1, t_cord c2)
{
	float	d1;
	float	d2;

	// d1 = sqrt((c1.xstep - mlx->player_x) * (c1.xstep - mlx->player_x) + \
	// 			(c1.ystep - mlx->player_y) * (c1.ystep - mlx->player_y));
	// d2 = sqrt((c2.xstep - mlx->player_x) * (c2.xstep - mlx->player_x) + \
	// 			(c2.ystep - mlx->player_y) * (c2.ystep - mlx->player_y));
	
	d1 = pow_2(c1.xstep - mlx->player_x) + pow_2(c1.ystep - mlx->player_y);
	d2 = pow_2(c2.xstep - mlx->player_x) + pow_2(c2.ystep - mlx->player_y);
	
	if (d1 < d2)
	{
		mlx->dis = sqrt(d1);
		c1.is_vertical = false;
		return (c1);
	}
	mlx->dis = sqrt(d2);
	c2.is_vertical = true;
	return (c2);
}

bool	has_wall(t_info *mlx, int x, int y)
{
	x /= TILE_SIZE;
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

	mlx->is_ray_facing_up = ray_angle > M_PI;
	sign = 1;
	if (mlx->is_ray_facing_up)
		sign = -1;
	cord.ystep = (int)(mlx->player_y / TILE_SIZE) * TILE_SIZE;
	if (!mlx->is_ray_facing_up)
		cord.ystep += TILE_SIZE;
	cord.xstep = mlx->player_x + (cord.ystep - mlx->player_y) / tan(ray_angle);
	const float dx = sign * TILE_SIZE / tan(ray_angle);
	const float dy = sign * TILE_SIZE;
	while (true)
	{
		if ((mlx->is_ray_facing_up && \
				has_wall(mlx, cord.xstep, cord.ystep - TILE_SIZE)) || \
			(!mlx->is_ray_facing_up && \
				has_wall(mlx, cord.xstep, cord.ystep)))
			break ;
		cord.xstep += dx;
		cord.ystep += dy;
	}
	return (cord);
}

t_cord	vertical_intersection(t_info *mlx, float ray_angle)
{
	t_cord	cord;
	int		sign;

	mlx->is_ray_facing_left = ray_angle > M_PI / 2 && ray_angle < 1.5 * M_PI;
	sign = 1;
	cord.xstep = (int) (1 + mlx->player_x / TILE_SIZE) * TILE_SIZE;
	if (mlx->is_ray_facing_left)
	{
		cord.xstep -= TILE_SIZE;
		sign = -1;
	}
	cord.ystep = mlx->player_y - (mlx->player_x - cord.xstep) * tan(ray_angle);
	mlx->dx = sign * TILE_SIZE;
	mlx->dy = sign * TILE_SIZE * tan(ray_angle);
	while (true)
	{
		if ((mlx->is_ray_facing_left && \
				has_wall(mlx, cord.xstep - TILE_SIZE, cord.ystep)) || \
			(!mlx->is_ray_facing_left && \
				has_wall(mlx, cord.xstep, cord.ystep)))
			break ;
		cord.xstep += mlx->dx;
		cord.ystep += mlx->dy; 
	}
	return (cord);
}

void	drawalls(t_info *map, double i)
{
	int wall_height;
	
	wall_height = (int) (30000.0 / map->dis);
	map->x_wall1 = i;
	map->x_wall2 = i;
	map->y_wall1 = map->height / 2 - wall_height / 2;
	map->y_wall2 = wall_height;
	my_mlx_texture_to_image(map,0);
}

double	deg2rad(double degrees)
{
	return	(degrees * (M_PI / 180.0));
}

void	rgb(t_info *map)
{
	int i;
	int j;
	
	i = -1;
	while (++i < (map->height / 2))
	{
		j = -1;
		while (++j < map->width)
			mlx_put_pixel(map->img, j, i, \
				ft_pixel(map->_c[0], map->_c[1], map->_c[2], map->alpha));
	}
	i = (map->height / 2);
	while (i < map->height)
	{
		j = -1;
		while (++j < map->width)
			mlx_put_pixel(map->img, j, i, \
			ft_pixel(map->_f[0], map->_f[1], map->_f[2], map->alpha));
		i++;
	}
}
void rotation(t_info *map)
{
	if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
		map->angle += deg2rad(2.5);
	else if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT)) 
		map->angle -= deg2rad(2.5);
}

void hooks(t_info *map, double *target_x, double *target_y)
{
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map->mlx);
	if (mlx_is_key_down(map->mlx, MLX_KEY_W))
	{
		*target_x += 2 * cos(map->angle);
		*target_y += 2 * sin(map->angle);
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_S))
	{
		*target_x -= 2 * cos(map->angle);
		*target_y -= 2 * sin(map->angle);	
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_A))
	{
		*target_y -= 2 * cos(map->angle);
		*target_x += 2 * sin(map->angle);
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_D))
	{
		*target_y += 2 * cos(map->angle);
		*target_x -= 2 * sin(map->angle);
	}
	rotation(map);
}
void protection(t_info *map)
{
	if (map->angle >= 2 * M_PI)
		map->angle -= 2 * M_PI;
	else if (map->angle < 0)
		map->angle += 2 * M_PI;
}

void problem(t_info *map, double *target_x, double *target_y)
{
	int map_x = ((map->player_x + ((*target_x) * 2) ) / TILE_SIZE) ;
	int map_y = ((map->player_y + ((*target_y) * 2) ) / TILE_SIZE) ;
	if (map_x > 0 && map_x < get_width() && map_y > 0 && map_y < get_height()
		&& map->map[map_y][map_x] == '0')
	{
		map->player_x += *target_x;
		map->player_y += *target_y;
	}
	
}
void loop_ray(t_info *map)
{
	double k ;
	double disrays;
	t_cord h;
	t_cord v;
	
	k = 0;
	disrays = deg2rad(FOV) / map->width;
	map->angle_fov = map->angle - deg2rad(FOV / 2);
	while (k < map->width)
	{
		if (map->angle_fov > 2 * M_PI)
			map->angle_fov -= 2 * M_PI;
		if (map->angle_fov < 0)
			map->angle_fov += 2 * M_PI;
		h =  horizontal_intersection(map, map->angle_fov);
		h.is_vertical = false;
		v = vertical_intersection(map, map->angle_fov);
		v.is_vertical = true;   
		map->inter = smallest(map, h, v);
		map->dis *= cos(map->angle - map->angle_fov);
		drawalls(map, k);
		map->angle_fov += disrays;
		k++;
	}
}
void hook_key(void *arg)
{    
	t_info *map;
	double target_x;
	double target_y;

	map = (t_info*)arg;
	target_x = 0;
	target_y = 0;
	rgb(map);
	hooks(map, &target_x, &target_y);
	protection(map);
	problem(map, &target_x, &target_y);
	loop_ray(map);
}

int	get_height(void)
{
	int	i;

	i = 0;
	while (info_path->info->map[i])
		i++;
	return (i);
}

int get_width(void)
{
	int	i;
	int	j;
	int	max_width;

	i = 0;
	j = 0;
	max_width = 0;
	while (info_path->info->map[i])
	{
		j = 0;
		while (info_path->info->map[i][j])
			j++;
		if (j > max_width)
			max_width = j;
		i++;
	}
	return (max_width);
}
void text(t_info *map)
{
	map->tex_north = mlx_load_png("./masjiid.png");
	map->tex_south = mlx_load_png("./palestineflag.png");
	map->tex_west = mlx_load_png("./smallx.png");
	map->tex_east = mlx_load_png("./iceberg.png");
	
}

void init(t_info *map)
{
	text(map);
	map->width = HEIGHT;
	map->height = WIDTH;
	map->mlx = mlx_init(map->width, map->height, "CUB3D", 0);
	if (!map->mlx) 
		throw_err_2("Failed to initialize MLX\n");
	map->img = mlx_new_image(map->mlx, map->width, map->height);
	if (!map->img)
	{
		fprintf(stderr, "Failed to create new image\n");
		mlx_terminate(map->mlx);
		return ;
	}
	if (mlx_image_to_window(map->mlx, map->img, 0, 0) < 0)
	{
		fprintf(stderr, "Failed to put image to window\n");
		mlx_delete_image(map->mlx, map->img);
		mlx_terminate(map->mlx);
		return ;
	}
	map->rows = ft_strlen(map->map[0]);
	map->cols = lenofmap(map->map);
	mlx_loop_hook(map->mlx, hook_key, map);
	mlx_loop(map->mlx);
}
