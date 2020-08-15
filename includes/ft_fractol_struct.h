/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 20:59:39 by ssoraka           #+#    #+#             */
/*   Updated: 2019/04/19 13:13:30 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_STRUCT_H
# define FT_FDF_STRUCT_H

# include "ft_fractol.h"

typedef double		t_real;

typedef struct		s_point
{
	int				y;
	int				x;
	int				z;
}					t_point;

typedef struct		s_dpoint
{
	t_real			y;
	t_real			x;
	t_real			z;
}					t_dpoint;

typedef struct		s_vektr
{
	int				color;
	struct s_dpoint	abs;
	struct s_point	zoom;
}					t_vektr;

typedef struct		s_pict
{
	void			*img;
	int				*addr;
	int				*index;
	int				*z_buffer;
	int				*addr_copy;
	int				*z_buffer_copy;
	int				cell;
	int				bits_per_pixel;
	int				size_line;
	int				count_line;
	int				count_byte;
	int				endian;
}					t_pict;

typedef struct		s_oxyz
{
	struct s_dpoint	oy;
	struct s_dpoint	ox;
	struct s_dpoint	oz;
}					t_oxyz;

typedef struct		s_param
{
	int				exit;
	int				is_points_change;

	int				iter;
	double			len;

	struct s_dpoint	mouse;
	struct s_dpoint	center;

}					t_param;

typedef struct		s_vis
{
	struct s_param	param;
	struct s_pict	pic;
	void			*mlx;
	void			*win;
}					t_vis;

typedef struct		s_all
{
	struct s_vis	*vis;
	struct s_open_cl	*cl;

}					t_all;

typedef struct		s_shape
{
	int				color;
	int				index;
	int				len;
	int				only_index;
	int				is_particles;
	int				form;
	int				(*print)(t_pict *, t_point *, struct s_shape *);
}					t_shape;

typedef struct		s_prog
{
	char			file[50];
	char			kernel[50];
	unsigned int	arg_count;
	unsigned int	arg[2];
}					t_prog;

#endif
