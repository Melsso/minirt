/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:44:12 by smallem           #+#    #+#             */
/*   Updated: 2023/10/26 19:49:35 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_cylinder	*init_cylinder(char **param, t_data *data)
{
	t_cylinder	*cylinder;	
	t_cylinder	*last;
	int			i;

	last = data->cylinder;
	while (last && last->next)
		last = last->next;
	i = 0;
	while (param[i])
		i++;
	if (i != 6)
		ft_ex(1, "WRONG NUMBER OF PARAMS", data, param);
	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		ft_ex(1, "MALLOC ERROR", data, param);
	set_vector(&cylinder->pos, param[1]);
	set_vector(&cylinder->vector, param[2]);
	cylinder->diameter = ft_atof(param[3]);
	cylinder->height = ft_atof(param[4]);
	set_vector(&cylinder->rgb, param[5]);
	cylinder->next = NULL;
	if (!data->cylinder)
		data->cylinder = cylinder;
	else
		last->next = cylinder;
	return (data->cylinder);
}

char	**correct_str(char *str)
{
	int	i;
	int	j;
	char	**m;

	m = ft_split(str, ' ');
	if (!m)
		return (NULL);
	i = 0;
	if (m[i][0] != 'A' && m[i][0] != 'C' && m[i][0] != 'L')
		if (ft_strncmp(m[i], "sp", 2) && ft_strncmp(m[i], "pl", 2)
			&& ft_strncmp(m[i], "cy", 2))
			return (NULL);
	while (m[++i])
	{
		j = -1;
		while (m[i][++j])
		{
			if (m[i][j] < '0' || m[i][j] > '9')
			{
				if (m[i][j] != ' ' && m[i][j] != ',' && m[i][j] != '.'
					&& m[i][j] != '\n' && m[i][j] != '-')
					return (free_split(m), NULL);
			}
		}
	}
	return (m);
}

int	set_vector(t_vec3 *vec, char *param)
{
	char	**tmp;

	tmp = ft_split(param, ',');
	if (!tmp)
		return (0);
	vec->x = ft_atof(tmp[0]);
	vec->y = ft_atof(tmp[1]);
	vec->z = ft_atof(tmp[2]);
	return (1);
}
