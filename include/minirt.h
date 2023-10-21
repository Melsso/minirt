/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:07:02 by musenov           #+#    #+#             */
/*   Updated: 2023/10/21 20:19:13 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# ifndef WIDTH
#  define WIDTH 1700
# endif

# ifndef HEIGHT
#  define HEIGHT 1000
# endif

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"


typedef struct s_alight
{
	float	lratio;
	int	red;
	int	blue;
	int	green;
}	t_alight;

typedef struct s_camera
{
	float	x;
	float	y;
	float	z;
	float	vector[3];
	int		view_field;
}	t_camera;

typedef struct s_light
{
	float	x;
	float	y;
	float	z;
	float	lbratio;
}	t_light;

typedef struct s_sphere
{
	float	x;
	float	y;
	float	z;
	float	diameter;
	int	red;
	int	blue;
	int	green;
}	t_sphere;

typedef struct s_plane
{
	float	x;
	float	y;
	float	z;
	float	vector[3];
	int	red;
	int	blue;
	int	green;
}	t_plane;

typedef struct s_cylinder
{
	float	x;
	float	y;
	float	z;
	float	vector[3];
	float	diameter;
	float	height;
	int	red;
	int	blue;
	int	green;
}	t_cylinder;

typedef struct s_data
{
	t_alight	*alight;
	t_camera	*camera;
	t_light		*light;
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
	char		**mat;
}	t_data;

int	open_file(char *file_name);
void	ft_ex(int ex_stat, char *str, t_data *data, char **ptr);

void	free_data(t_data *data);
void	free_split(char **mat);

t_cylinder	*init_alight(char **param, t_data *data);
t_alight	*init_alight(char **param, t_data *data);
t_camera	*init_camera(char **param, t_data *data);
t_light	*init_light(char **param, t_data *data);
t_sphere	*init_sphere(char **param, t_data *data);
t_plane	*init_plane(char **param, t_data *data);


#endif