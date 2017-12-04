/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhovnuv <ozhovnuv@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 18:52:04 by ozhovnuv          #+#    #+#             */
/*   Updated: 2017/03/01 18:45:06 by ozhovnuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	fill_coord(t_map_inf *inf, int k, int j, int z)
{
	inf->mp[k][j].z = -z;
	inf->mp[k][j].x = j;
	inf->mp[k][j].y = k;
}

void	ft_error(int err_msg)
{
	if (err_msg == 1)
		ft_putstr("Wrong file. Exiting.\n");
	else if (err_msg == 2)
		ft_putstr("Usage : ./fdf <filename> \n");
	else
		ft_putstr("Found wrong line length. Exiting.\n");
	exit(0);
}

void	ft_move_map(t_map_inf *in)
{
	int i;
	int j;

	i = -1;
	while (++i < in->rows)
	{
		j = -1;
		while (++j < in->cols)
		{
			in->p[i][j].x += 500;
			in->p[i][j].y += 500;
		}
	}
}

void	ft_zoom(t_map_inf *inf, t_map_st *mp, t_map *p)
{
	p->x = (mp->x - (inf->cols / 2)) * inf->scale_x;
	p->y = (mp->y - (inf->rows / 2)) * inf->scale_y;
	p->z = mp->z * inf->scale_z;
	p->color = mp->color;
}
