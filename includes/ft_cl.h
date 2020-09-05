/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cl.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 20:59:39 by ssoraka           #+#    #+#             */
/*   Updated: 2019/04/19 13:13:30 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CL_H
# define FT_CL_H

# define CONST_WIDTH 1000
# define CONST_HEINTH 1000

typedef enum	e_fract
{
	MAND,
	JUL,
	MY_1,
	MY_2,
	BRN_SP,
	CEL_MAN,
	CEL_MANBAR,
	CEL_PER,
	SPIDER,
	FRACT_COUNT
}				t_fract;

typedef enum	e_color_style
{
	STYLE_ONE,
	STYLE_TWO,
	STYLE_THREE,
	STYLE_FOUR,
	STYLE_COUNT
}				t_color_style;

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
	int				is_const_change;

	int				iter;
	int				style;
	int				fract;
	double			len;

	struct s_dpoint d;
	struct s_dpoint jul;
	struct s_dpoint	mouse;
	struct s_dpoint	center;

}					t_param;

#endif
