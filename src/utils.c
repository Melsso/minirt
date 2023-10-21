/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:36:13 by smallem           #+#    #+#             */
/*   Updated: 2023/10/21 19:39:10 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	free_split(char **mat)
{
	int	i;

	i = -1;
	while (mat[++i])
		free(mat[i]);
	free(mat);
	mat = NULL;
}

void	free_data(t_data *data)
{
	if (data->alight)
		free(data->alight);
	if (data->camera)
		free(data->camera);
	if (data->cylinder)
		free(data->cylinder);
	if (data->camera)
		free(data->light);
	if (data->camera)
		free(data->light);
	if (data->plane)
		free(data->plane);
	data->alight = NULL;
	data->light = NULL;
	data->camera = NULL;
	data->cylinder = NULL;
	data->plane = NULL;
	data->sphere = NULL;
	free_split(data->mat);		
}

void	ft_ex(int ex_stat, char *str, t_data *data, char **ptr)
{
	if (str)
		printf("%s\n", str);
	if (ptr)
		free_split(ptr);
	if (data)
		free_data(data);
	exit(ex_stat);
}
