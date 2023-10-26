/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:35:59 by smallem           #+#    #+#             */
/*   Updated: 2023/10/26 20:12:27 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	events(mlx_key_data_t key, void *param)
{
	t_data	*data;

	data = param;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
	{
		mlx_terminate(data->win);
		exit(0);
	}
	render(data);
}

static int	encode_rgb(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8);	
}

// static void	render_bg(t_data *data)
// {
	
// }

void	render(t_data *data)
{
	data->img = mlx_new_image(data->win, 500, 500);
	for (int i = 0; i < 500; i++)
	{
		for (int j = 0; j < 500; j++)
			mlx_put_pixel(data->img, i, j, encode_rgb(255,255,255) + 0);
	}
	mlx_image_to_window(data->win, data->img, 100, 100);
}
