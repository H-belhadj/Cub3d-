/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:10:04 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/05/20 10:26:46 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void mlxinit(t_info *cub3d, t_map *value)
{
 // Initialize the height and width values
    value->hei = 50;
    value->wid = 50;

    // Initialize the MLX instance with width, height, title, and resize flag
    cub3d->mlx = mlx_init(640, 360, "Tutorial Window - Draw Pixel", false);
    if (cub3d->mlx == NULL) {
        // Handle error
        fprintf(stderr, "Failed to initialize mlx.\n");
        return;
    }

    // Create a new image to draw pixels
    cub3d->img = mlx_new_image(cub3d->mlx, 640, 360);
    if (cub3d->img == NULL) {
        // Handle error
        fprintf(stderr, "Failed to create image.\n");
        return;
    }

    // Put the image into the window
    mlx_image_to_window(cub3d->mlx, cub3d->img, 0, 0);

    // Draw a pixel in the middle of the window
    mlx_put_pixel(cub3d->img, 640/2, 360/2, 0xFFFFFF);

    // Start the event loop
    mlx_loop(cub3d->mlx);
}