#include "./includes/ft_cl.h"

# define NEW 0
# define OLD 1

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
	if (color == STYLE_ONE)
		return (set_colors(0, blue, green, red));
	else if (color == STYLE_TWO)
		return (set_colors(0, red, blue, green));
	else if (color == STYLE_THREE)
		return (set_colors(0, blue, red, green));
	else if (color == STYLE_FOUR)
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
	int		type = param->fract;

	id = get_global_id(0);
	i = 0;
	x = id % CONST_WIDTH;
	y = id / CONST_WIDTH;
	c_re = (x - param->center.x) / param->len + param->d.x;
	c_im = (y - param->center.y) / param->len + param->d.y;
	re[NEW] = c_re;
	im[NEW] = c_im;


		if (type == MAND)
        {
    		while (re[NEW] * re[NEW] + im[NEW] * im[NEW] < 4 && ++i < iter)
   	 		{
    			re[OLD] = re[NEW];
        		im[OLD] = im[NEW];
        		im[NEW] = 2 * im[OLD] * re[OLD] + c_im;
        	    re[NEW] = re[OLD] * re[OLD] - im[OLD] * im[OLD] + c_re;
    		}
    	}
    	else if (type == JUL)
    	{
    		while (re[NEW] * re[NEW] + im[NEW] * im[NEW] < 4 && ++i < iter)
   	 		{
    			re[OLD] = re[NEW];
        		im[OLD] = im[NEW];
        		im[NEW] = 2 * im[OLD] * re[OLD] + param->jul.y;
        	    re[NEW] = re[OLD] * re[OLD] - im[OLD] * im[OLD] + param->jul.x;
    		}
    	}
    	else if (type == MY_1)
    	{
    		while (re[NEW] * re[NEW] + im[NEW] * im[NEW] < 4 && ++i < iter)
   	 		{
    			re[OLD] = re[NEW];
        		im[OLD] = im[NEW];
        		im[NEW] = -2 * im[OLD] * re[OLD] + c_im;
        	    re[NEW] = re[OLD] * re[OLD] - im[OLD] * im[OLD] + c_re;
    		}
    	}
    	else if (type == MY_2)
    	{
    		while (re[NEW] * re[NEW] + im[NEW] * im[NEW] < 4 && ++i < iter)
   	 		{
    			re[OLD] = re[NEW];
        		im[OLD] = im[NEW];
        		im[NEW] = 2 * im[OLD] * re[OLD] * re[OLD] + re[OLD] * re[OLD] * im[OLD] - im[OLD] * im[OLD] * im[OLD] + c_im;
        	    re[NEW] = re[OLD] * re[OLD] * re[OLD] - im[OLD] * im[OLD] * re[OLD] - 2 * re[OLD] * im[OLD] * im[OLD] + c_re;
    		}
    	}
		else if (type == BRN_SP)
		{
			while (re[NEW] * re[NEW] + im[NEW] * im[NEW] < 4 && ++i < iter)
			{
				re[OLD] = re[NEW];
				im[OLD] = im[NEW];
				im[NEW] = 2.0 * fabs(re[OLD] * im[OLD]) + c_im;
				re[NEW] = re[OLD] * re[OLD] - im[OLD] * im[OLD] + c_re;
			}
		}
		else if (type == CEL_MAN)
		{
			while (re[NEW] * re[NEW] + im[NEW] * im[NEW] < 4 && ++i < iter)
			{
				re[OLD] = re[NEW];
				im[OLD] = im[NEW];
				im[NEW] = 2.0 * re[OLD] * im[OLD] + c_im;
				re[NEW] = fabs(re[OLD] * re[OLD] - im[OLD] * im[OLD]) + c_re;
			}
		}
		else if (type == CEL_MANBAR)
		{
			while (re[NEW] * re[NEW] + im[NEW] * im[NEW] < 4 && ++i < iter)
			{
				re[OLD] = re[NEW];
				im[OLD] = im[NEW];
				im[NEW] = -2.0 * re[OLD] * im[OLD] + c_im;
				re[NEW] = fabs(re[OLD] * re[OLD] - im[OLD] * im[OLD]) + c_re;
			}
		}
		else if (type == CEL_PER)
		{
			while (re[NEW] * re[NEW] + im[NEW] * im[NEW] < 4 && ++i < iter)
			{
				re[OLD] = re[NEW];
				im[OLD] = im[NEW];
				im[NEW] = -2.0 * fabs(re[OLD]) * im[OLD] + c_im;
				re[NEW] = fabs(re[OLD] * re[OLD] - im[OLD] * im[OLD]) + c_re;
			}
		}
		else if (type == SPIDER)
		{
			while (re[NEW] * re[NEW] + im[NEW] * im[NEW] < 4 && ++i < iter)
			{
				re[OLD] = re[NEW];
				im[OLD] = im[NEW];
				re[NEW] = re[OLD] * re[OLD] - im[OLD] * im[OLD] + c_re;
				im[NEW] = 2.0 * re[OLD] * im[OLD] + c_im;
				c_im = c_im / 2 + im[NEW];
				c_re = c_re / 2 + re[NEW];
			}
		}

		if (i < iter)
			data[id] = choose_color(i, iter, param->style);
		else
			data[id] = 0;

}