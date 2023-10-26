/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:36:10 by smallem           #+#    #+#             */
/*   Updated: 2023/10/26 19:43:21 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	open_file(char *file_name)
{
	int	i;

	i = -1;
	while (file_name[++i])
		;
	if (i < 3)
		return (0);
	if (!ft_strncmp(&file_name[i - 4], ".rt", 3))
		return (0);
	i = open(file_name, O_RDONLY);
	if (i == -1)
		return (0);
	else
		return (i);
}

static void	init_data(t_data *data)
{
	int	i;
	char	**param;

	i = -1;
	while (data->mat[++i])
	{
		param = correct_str(data->mat[i]);
		if (!param)
			ft_ex(1, "Invalid parameters", data, NULL);
		if (data->mat[i][0] == 'A')
			data->alight = init_alight(param, data);
		else if (data->mat[i][0] == 'C')
			data->camera = init_camera(param, data);
		else if (data->mat[i][0] == 'L')
			data->light = init_light(param, data);
		else if (data->mat[i][0] == 's' && data->mat[i][1] == 'p')
			data->sphere = init_sphere(param, data);
		else if (data->mat[i][0] == 'p' && data->mat[i][1] == 'l')
			data->plane = init_plane(param, data);
		else if (data->mat[i][0] == 'c' && data->mat[i][1] == 'y')
			data->cylinder = init_cylinder(param, data);
	}
}

static void	fill_mat(int fd, t_data *data, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		data->mat[i] = get_next_line(fd);
		if (!data->mat[i])
			ft_ex(1, "GNL ERROR", NULL, data->mat);
	}
	data->alight = NULL;
	data->camera = NULL;
	data->cylinder = NULL;
	data->light = NULL;
	data->plane = NULL;
	data->sphere = NULL;
	init_data(data);
}

void	check_input(int fd, t_data *data, char *file_name)
{
	char	*tmp;
	int		size;

	tmp = get_next_line(fd);
	if (!tmp)
		ft_ex(1, "GNL ERROR", NULL, NULL);
	size = 1;
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
		if (tmp)
			size++;
	}
	data->mat = malloc(sizeof(char *) * (size + 1));
	close(fd);
	if (!data->mat)
		ft_ex(1, "MALLOC ERROR", NULL, NULL);
	data->mat[size] = NULL;
	fd = open(file_name, O_RDONLY);
	if (!fd)
		ft_ex(1, "FILE ERROR", NULL, data->mat);
	fill_mat(fd, data, size);
}
