/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:36:13 by smallem           #+#    #+#             */
/*   Updated: 2023/10/26 20:01:16 by smallem          ###   ########.fr       */
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

void	print_data(t_data *data)
{
	if (data->alight)
	{
		t_alight	*tmp = data->alight;
		while (tmp)
		{
			printf("A lr:%f, r:%f g:%f b:%f\n", tmp->lratio, tmp->rgb.x, tmp->rgb.y, tmp->rgb.z);
			tmp = tmp->next;
		}
	}
	if (data->camera)
	{
		t_camera *tmp = data->camera;
		printf("C x:%f y:%f z:%f Vx:%f Vy:%f Vz:%f FOV:%d\n", tmp->pos.x, tmp->pos.y, tmp->pos.z,
			tmp->vector.x, tmp->vector.y, tmp->vector.z, tmp->view_field);
	}
	if (data->light)
	{
		t_light	*tmp = data->light;
		while (tmp)
		{
			printf("L x:%f y:%f z:%f lbr:%f\n", tmp->pos.x, tmp->pos.y, tmp->pos.z, tmp->lbratio);
			tmp = tmp->next;
		}

	}
	if (data->plane)
	{
		t_plane	*tmp = data->plane;
		while(tmp)
		{
			printf("pl x:%f y:%f z:%f Vx:%f Vy:%f Vz:%f r:%f g:%f b:%f\n", tmp->pos.x, tmp->pos.y, tmp->pos.z,
				tmp->vector.x, tmp->vector.y, tmp->vector.z, tmp->rgb.x, tmp->rgb.y, tmp->rgb.z);
			tmp = tmp->next;
		}

	}
	if (data->sphere)
	{
		t_sphere	*tmp = data->sphere;
		while (tmp)
		{
			printf("sp x:%f y:%f z:%f d:%f r:%f g:%f b:%f\n", tmp->pos.x, tmp->pos.y, tmp->pos.z, tmp->diameter,
				tmp->rgb.x, tmp->rgb.y, tmp->rgb.z);
			tmp = tmp->next;
		}

	}
	if (data->cylinder)
	{
		t_cylinder	*tmp = data->cylinder;
		while (tmp)
		{
			printf("cy x:%f y:%f z:%f Vx:%f Vy:%f Vz:%f d:%f h:%f r:%f g:%f b:%f\n", tmp->pos.x, tmp->pos.y, tmp->pos.z,
				tmp->vector.x, tmp->vector.y, tmp->vector.z, tmp->diameter, tmp->height,
				tmp->rgb.x, tmp->rgb.y, tmp->rgb.z);
			tmp = tmp->next;
		}
	}
}
double ft_atof(char *str)
{
    double result = 0.0;
    double fraction = 0.0;
    double divisor = 10.0;
    int sign = 1;

    if (*str == '-')
	{
        sign = -1;
        str++;
    }
	else if (*str == '+')
        str++;
    while (*str != '\0' && (*str >= '0' && *str <= '9'))
	{
        result = result * 10 + (*str - '0');
        str++;
    }
    if (*str == '.')
	{
        str++;
        while (*str != '\0' && (*str >= '0' && *str <= '9'))
		{
            fraction += (*str - '0') / divisor;
            divisor *= 10;
            str++;
        }
    }
    return sign * (result + fraction);
}
