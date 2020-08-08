/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 20:59:39 by ssoraka           #+#    #+#             */
/*   Updated: 2019/04/19 13:13:30 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include "../libft/libft.h"
# include "ft_buttons.h"

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "mlx.h"
# include "ft_fdf_struct.h"

# if defined(__linux__)
#  include "X11/X.h"
#  define KEY_PRESS_MASK KeyPressMask
#  define POINTER_MOTION_MASK PointerMotionMask
#  define BUTTON_PRESS_MASK ButtonPressMask
#  define BUTTON_RELEASE_MASK ButtonReleaseMask
#  define KEY_PRESS KeyPress
#  define KEY_RELEASE KeyRelease
#  define BUTTON_PRESS ButtonPress
#  define BUTTON_RELEASE ButtonRelease
#  define MOTION_NOTIFY MotionNotify
# else
#  define KEY_PRESS_MASK 0
#  define POINTER_MOTION_MASK 0
#  define BUTTON_PRESS_MASK 0
#  define BUTTON_RELEASE_MASK 0
#  define KEY_PRESS 		2
#  define KEY_RELEASE 		3
#  define BUTTON_PRESS 		4
#  define BUTTON_RELEASE 		5
#  define MOTION_NOTIFY 		6
# endif

# define ABS(nbr) ((nbr) >= 0 ? (nbr) : (-1) * (nbr))

/*
**	добавляем по 2 вершины между вершинами расчетной модели для сплайна
*/

# define COLOR_UP 0xFFFFFF
# define COLOR_DOWN 0x704214

# define DEFAULT_LINE_COLOR 0xFF00

# define BACKGROUND_COLOR 0x8F8F8F

# define WHITE_COLOR 0xFFFFFF
# define BLACK_COLOR 0x0
# define DEFAULT_COLOR -1
# define UNPRINTABLE -100

# define ZERO_COLOR 0xFF00
# define UP_COLOR 0xFF0000
# define DOWN_COLOR 0xFF

# define RED_COLOR 0xFF0000
# define GREEN_COLOR 0xFF00
# define BLUE_COLOR 0xFF
# define ACTIVE_COLOR RED_COLOR
# define CREATE_COLOR BLUE_COLOR

# define MSG_ERROR1 "Malloc error\0\0Not valid map\0File not found"

# define DELTA_Z 0.01
# define SPEED 10
# define ROTATE_ANGLE 0.05 / 180.0

/*
**	images
*/
# define CONST_LEN 500
# define CONST_RADIUS 1000
# define CONST_WIDTH 500
# define CONST_HEINTH 340
# define CAM_X (CONST_WIDTH / 2)
# define CAM_Y (CONST_HEINTH / 2)
# define RADIUS 3

# define DEFAULT_INDEX 0
# define MIN_INTEGER 0x80000000

typedef enum	e_form
{
	POINT,
	POINT_INDEX,
	RECTANGLE,
	CIRCLE
}				t_form;

/*
**	main.c
*/
void		ft_exit(t_all *all, char *error_message);
void		ft_my_function(t_all *all);

/*
**	hooks.c
*/
int			ft_mouse_press(int button, int x, int y, void *parameters);
int			ft_mouse_release(int button, int x, int y, void *parameters);
int			ft_mouse_move(int x, int y, void *parameters);
int			ft_loop_hook(void *parameters);
void		ft_init_hooks(t_all *all);

/*
**	mouse.c
*/
int			ft_mouse_on_window(int x, int y);
int			ft_mouse_get_new_pos(int x, int y, t_param *param);
t_vektr		*ft_get_nearest_point(t_all *all, t_param *param);
void		ft_try_change_active_point(t_param *param, t_vektr *active);

/*
**	print_shapes.c
*/
void		ft_init_shape(t_shape *shape, t_form form, t_bool is_particle);


/*
**	images.c
*/
int			ft_create_img(t_pict *pic, void *mlx, int width, int height);
t_vis		*ft_create_mlx(int width, int heigth, char *name);
void		ft_destroy_img(t_pict *pic);
t_vis		*ft_destroy_mlx(t_vis **vis);

/*
**	picture.c
*/
void		ft_clear_image(t_pict *pic);

/*
**	keys.c
*/
int			ft_rotate_and_csale(t_param *param, int key);
int			ft_shift(t_param *vis, int key);
int			ft_deal_key(int key, void *parametrs);
int			ft_csale_picture(t_param *vis, int button);

/*
**	points.c
*/
void		ft_fill_point(t_point *p, int y, int x, int z);
void		ft_fill_dpoint(t_dpoint *p, t_real y, t_real x, t_real z);
t_real		ft_vekt_cos(t_dpoint a, t_dpoint b);
t_real		ft_dot_dpoints(t_dpoint *a, t_dpoint *b);
t_real		ft_vektr_len(t_dpoint *a);

/*
**	points2.c
*/
void		ft_create_xyz(t_oxyz *oxyz);
void		ft_normilize_vektor(t_dpoint *vek);
void		ft_get_perp_vekt_from_two(t_dpoint *answer, t_dpoint *a,
		t_dpoint *b);
t_dpoint	ft_ret_norm(t_dpoint *a, t_dpoint *b, t_dpoint *c);

#endif
