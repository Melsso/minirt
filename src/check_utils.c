/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:44:35 by smallem           #+#    #+#             */
/*   Updated: 2023/10/26 19:48:50 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_alight	*init_alight(char **param, t_data *data)
{
	t_alight	*alight;
	t_alight	*last;
	int			i;

	last = data->alight;
	while (last && last->next)
		last = last->next;
	i = 0;
	while (param[i])
		i++;
	if (i != 3)
		ft_ex(1, "WRONG NUMBER OF PARAMS", data, param);
	alight = malloc(sizeof(t_alight));
	if (!alight)
		ft_ex(1, "MALLOC ERROR", data, param);
	alight->lratio = ft_atof(param[1]);
	set_vector(&alight->rgb, param[2]);
	alight->next = NULL;
	if (!data->alight)
		data->alight = alight;
	else
		last->next = alight;
	free_split(param);
	return (data->alight);
}

t_camera	*init_camera(char **param, t_data *data)
{
	t_camera	*camera;
	int			i;

	if (data->camera)
		ft_ex(1, "Invalid input: Two cameras!", data, param);
	i = 0;
	while (param[i])
		i++;
	if (i != 4)
		ft_ex(1, "WRONG NUMBER OF PARAMS", data, param);
	camera = malloc(sizeof(t_camera));
	if (!camera)
		ft_ex(1, "MALLOC ERROR", data, param);
	set_vector(&camera->pos, param[1]);
	set_vector(&camera->vector, param[2]);
	camera->view_field = ft_atoi(param[3]);
	data->camera = camera;
	return (data->camera);
}

t_light	*init_light(char **param, t_data *data)
{
	t_light	*light;
	t_light	*last;
	int		i;

	last = data->light;
	while (last && last->next)
		last = last->next;
	i = 0;
	while (param[i])
		i++;
	if (i != 3)
		ft_ex(1, "WRONG NUMBER OF PARAMS", data, param);
	light = malloc(sizeof(t_light));
	if (!light)
		ft_ex(1, "MALLOC ERROR", data, param);
	set_vector(&light->pos, param[1]);
	light->lbratio = ft_atof(param[2]);
	light->next = NULL;
	if (!data->light)
		data->light = light;
	else
		last->next = light;
	return (data->light);
}

t_sphere	*init_sphere(char **param, t_data *data)
{
	t_sphere	*sphere;
	t_sphere	*last;
	int			i;

	last = data->sphere;
	while (last && last->next)
		last = last->next;
	i = 0;
	while (param[i])
		i++;
	if (i != 4)
		ft_ex(1, "WRONG NUMBER OF PARAMS", data, param);
	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		ft_ex(1, "MALLOC ERROR", data, param);
	set_vector(&sphere->pos, param[1]);
	sphere->diameter = ft_atof(param[2]);
	set_vector(&sphere->rgb, param[3]);
	sphere->next = NULL;
	if (!data->sphere)
		data->sphere = sphere;
	else
		last->next = sphere;
	return (data->sphere);
}

t_plane	*init_plane(char **param, t_data *data)
{
	t_plane	*plane;
	t_plane	*last;
	int		i;

	last = data->plane;
	while (last && last->next)
		last = last->next;
	i = 0;
	while (param[i])
		i++;
	if (i != 4)
		ft_ex(1, "WRONG NUMBER OF PARAMS", data, param);
	plane = malloc(sizeof(t_plane));
	if (!plane)
		ft_ex(1, "MALLOC ERROR", data, param);
	set_vector(&plane->pos, param[1]);
	set_vector(&plane->vector, param[2]);
	set_vector(&plane->rgb, param[3]);
	plane->next = NULL;
	if (!data->plane)
		data->plane = plane;
	else
		last->next = plane;
	return (data->plane);
}
