/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol_struct.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 20:59:39 by ssoraka           #+#    #+#             */
/*   Updated: 2019/04/19 13:13:30 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_STRUCT_H
# define FT_FRACTOL_STRUCT_H

# include "ft_fractol.h"
# include "ft_cl.h"

typedef struct			s_vis
{
	struct s_param		param;
	struct s_pict		pic;
	void				*mlx;
	void				*win;
}						t_vis;

typedef struct			s_all
{
	struct s_vis		*vis;
	struct s_open_cl	*cl;

}						t_all;

typedef struct			s_shape
{
	int					color;
	int					index;
	int					len;
	int					only_index;
	int					is_particles;
	int					form;
	int					(*print)(t_pict *, t_point *, struct s_shape *);
}						t_shape;

typedef struct			s_prog
{
	char				file[50];
	char				kernel[50];
	unsigned int		arg_count;
	unsigned int		arg[2];
}						t_prog;

#endif
