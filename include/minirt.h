/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:07:02 by musenov           #+#    #+#             */
/*   Updated: 2023/10/26 20:08:57 by smallem          ###   ########.fr       */
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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_alight	t_alight;
typedef struct s_alight
{
	float	lratio;
	t_vec3	rgb;
	t_alight	*next;
}	t_alight;

typedef struct s_camera	t_camera;
typedef struct s_camera
{
	t_vec3	pos;
	t_vec3	vector;
	int		view_field;
}	t_camera;

typedef struct s_light	t_light;
typedef struct s_light
{
	t_vec3	pos;
	double	lbratio;
	t_light	*next;
}	t_light;

typedef struct s_sphere	t_sphere;
typedef struct s_sphere
{
	t_vec3	pos;
	t_vec3	rgb;
	double	diameter;
	t_sphere	*next;
}	t_sphere;

typedef struct s_plane	t_plane;
typedef struct s_plane
{
	t_vec3	pos;
	t_vec3	vector;
	t_vec3	rgb;
	t_plane	*next;
}	t_plane;

typedef struct s_cylinder	t_cylinder;
typedef struct s_cylinder
{
	t_vec3	pos;;
	t_vec3	vector;
	t_vec3	rgb;
	double	diameter;
	double	height;
	t_cylinder	*next;
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
	mlx_t		*win;
	mlx_image_t	*img;
}	t_data;


/////gnl//////
char	*free_all(char *str, char *buffer);
char	*ft_read(char *str, int fd, ssize_t bytes_read);
char	*get_next_line(int fd);
char	*ft_get_buffer(char *str);


///////////
int	open_file(char *file_name);
void	ft_ex(int ex_stat, char *str, t_data *data, char **ptr);

void	free_data(t_data *data);
void	free_split(char **mat);
int	set_vector(t_vec3 *vec, char *param);

char	**correct_str(char *str);

void	check_input(int fd, t_data *data, char *file_name);

t_cylinder	*init_cylinder(char **param, t_data *data);
t_alight	*init_alight(char **param, t_data *data);
t_camera	*init_camera(char **param, t_data *data);
t_light	*init_light(char **param, t_data *data);
t_sphere	*init_sphere(char **param, t_data *data);
t_plane	*init_plane(char **param, t_data *data);

void	print_data(t_data *data);
double	ft_atof(char *str);



void	events(mlx_key_data_t key, void *param);

void	render(t_data *data);

#endif