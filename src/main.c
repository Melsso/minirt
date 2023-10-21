/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:35:26 by smallem           #+#    #+#             */
/*   Updated: 2023/10/21 19:31:32 by smallem          ###   ########.fr       */
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
		
}
