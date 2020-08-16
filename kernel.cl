#include "./includes/ft_cl.h"

# define NEW 0
# define OLD 1
# define HEIGHT 1000
# define WIDTH 1000

int		set_colors(unsigned char o, unsigned char r, unsigned char g, unsigned char b);
int 		choose_color(int i, int max, int color);


int		set_colors(unsigned char o, unsigned char r, \
		unsigned char g, unsigned char b)
{
	return ((int)o << 24 | (int)r << 16 | (int)g << 8 | (int)b);
}

int 		choose_color(int i, int max, int color)
{
	int			red;
	int			blue;
	int			green;
	double		n;
//	int			s = 100;

	n = (double)i / (double)max;
	red = (int)(9 * (1 - n) * pow(n, 3) * 255);
	green = (int)(15 * pow((1 - n), 2) * pow(n, 2) * 255);
	blue = (int)(8.5 * pow((1 - n), 3) * n * 255);
	if (color == 1)
		return (set_colors(0, red, blue, green));
	else if (color == 0)
		return (set_colors(0, blue, green, red));
	else if (color == 2)
		return (set_colors(0, blue, red, green));
	else if (color == 3)
		return (set_colors(0, red, green, blue));
	return (0);
}

__kernel void draw(__global int *data, __global t_param *param)
{
	double	re[2];
	double	im[2];
	double	c_re;
	double	c_im;
	int		i;
	size_t	id;
	int		x;
	int		y;
	int		iter = param->iter;
	int		color = 0xFFFFFF;

	id = get_global_id(0);
	i = 0;
	x = id % WIDTH;
	y = id / HEIGHT;
	c_re = (x - param->center.x) / param->len + param->d.x;
	c_im = (y - param->center.y) / param->len + param->d.y;
	re[NEW] = c_re;
	im[NEW] = c_im;

	while (re[NEW] * re[NEW] + im[NEW] * im[NEW] < 4 && ++i < iter)
	{
		re[OLD] = re[NEW];
		im[OLD] = im[NEW];
		im[NEW] = 2 * im[OLD] * re[OLD] + c_im;
		re[NEW] = re[OLD] * re[OLD] - im[OLD] * im[OLD] + c_re;
	}


		if (i < iter)
			data[id] = choose_color(i, iter, color);
		else
			data[id] = 0;
}