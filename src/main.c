/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:35:26 by smallem           #+#    #+#             */
/*   Updated: 2023/10/26 20:12:12 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	main(int argc, char **argv)
{
	int	fd;
	t_data	data;

	if (argc != 2)
		ft_ex(1, "Bad usage", NULL, NULL);
	fd = open_file(argv[1]);
	if (!fd)
		ft_ex(1, "Bad file", NULL, NULL);
	check_input(fd, &data, argv[1]);
	// print_data(&data);
	data.win = mlx_init(WIDTH, HEIGHT, "Mini_Rt", false);
	render(&data);
	mlx_key_hook(data.win, events, &data);
	mlx_loop(data.win);
	mlx_terminate(data.win);
}
