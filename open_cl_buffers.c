/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_cl_buffers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 15:49:41 by ssoraka           #+#    #+#             */
/*   Updated: 2020/02/16 15:49:42 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_fractol.h"

int		ft_read_buffers(t_open_cl *cl, int num, int need_wait)
{
	void *ptr;

	ptr = cl->buff[num].arr;
	if (clEnqueueReadBuffer(cl->queue, cl->buff[num].buffer, need_wait, 0
	, cl->buff[num].buff_used, ptr, 0, NULL, NULL) != CL_SUCCESS)
		return (FALSE);
	return (TRUE);
}

int		ft_write_buffers(t_open_cl *cl, int num, int need_wait)
{
	void *ptr;

	ptr = cl->buff[num].arr;
	if (clEnqueueWriteBuffer(cl->queue, cl->buff[num].buffer, need_wait, 0
	, cl->buff[num].buff_used, ptr, 0, NULL, NULL) != CL_SUCCESS)
		return (FALSE);
	return (TRUE);
}

int		ft_create_buffers(t_open_cl *cl, int num)
{
	cl->buff[num].buffer = clCreateBuffer(cl->context, CL_MEM_READ_WRITE
	, cl->buff[num].buff_used, NULL, &(cl->errcode_ret));
	if (cl->errcode_ret != CL_SUCCESS)
		return (FALSE);
	return (TRUE);
}

int		ft_create_all_buffers(t_open_cl *cl)
{
	int i;

	i = 0;
	while (i < BUFFER_COUNT)
	{
		if (!ft_create_buffers(cl, i))
			return (FALSE);
		if (!ft_write_buffers(cl, i, CL_TRUE))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
