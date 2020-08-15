/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cl_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 20:59:39 by ssoraka           #+#    #+#             */
/*   Updated: 2019/04/19 13:13:30 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CL_STRUCT_H
# define FT_CL_STRUCT_H

# include "ft_fractol.h"

# define PROGRAMS_COUNT 1
# define PROGRAMM_SIZE 10000

typedef enum	e_buf
{
	PARAM = 0, //буффер параметров
	IMAGE, //буфер изображения
	BUFFER_COUNT
}				t_buf;

typedef struct		s_buff
{
	cl_mem			buffer;
	void			*arr;
	size_t			count;
	size_t			*g_work_size;
	size_t			buff_used;
}					t_buff;

typedef struct			s_open_cl
{
	cl_platform_id		platform;
	cl_uint				num_platform;
	cl_device_type		device_type;
	cl_uint				num_devices;
	cl_device_id		device;
	cl_context			context;
	cl_command_queue	queue;
	struct s_buff		buff[BUFFER_COUNT + 1];
	cl_program			program[PROGRAMS_COUNT + 1];
	cl_kernel			kernel[PROGRAMS_COUNT + 1];
	size_t				buff_index[PROGRAMS_COUNT + 1];
	cl_int				errcode_ret;
}						t_open_cl;

#endif
