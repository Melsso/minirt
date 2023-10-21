/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:44:12 by smallem           #+#    #+#             */
/*   Updated: 2023/10/21 20:17:40 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_cylinder	*init_cylinder(char **param, t_data *data)
{
	int		i;


	i = 0;
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
				if (m[i][j] != ' ' && m[i][j] != ',' && m[i][j] != '.')
					return (free_split(m), NULL);
			}
		}
	}
	return (m);
}
