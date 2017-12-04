/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhovnuv <ozhovnuv@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:24:05 by ozhovnuv          #+#    #+#             */
/*   Updated: 2017/02/27 19:02:15 by ozhovnuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_start_inf_points(int i, int j, t_points *p, t_map **map)
{
	p->p1_col = map[i][j].color;
	p->x0 = map[i][j].x;
	p->y0 = map[i][j].y;
}

void	ft_print_map(t_image *im, t_map_inf *inf, t_map **map)
{
	int			i;
	int			j;
	t_points	*p;

	p = (t_points*)malloc(sizeof(t_points));
	i = -1;
	while (++i < inf->rows)
	{
		j = -1;
		while (++j < inf->cols)
		{
			ft_start_inf_points(i, j, p, map);
			if (j < (inf->cols - 1))
			{
				ft_chooce_points(i, j + 1, p, map);
				ft_line(im, p);
			}
			if (i < (inf->rows - 1))
			{
				ft_chooce_points(i + 1, j, p, map);
				ft_line(im, p);
			}
		}
	}
}

void	ft_line(t_image *im, t_points *p)
{
	p->dx = abs(p->x - p->x0);
	p->dy = abs(p->y - p->y0);
	p->sx = p->x >= p->x0 ? 1 : -1;
	p->sy = p->y >= p->y0 ? 1 : -1;
	if (p->dy <= p->dx)
		ft_paint_by_x(im, p);
	else
		ft_paint_by_y(im, p);
}

void	ft_paint_by_x(t_image *im, t_points *p)
{
	int i;
	int x;
	int y;

	x = p->x0;
	y = p->y0;
	p->d = (p->dy * 2) - p->dx;
	p->d1 = p->dy * 2;
	p->d2 = (p->dy - p->dx) * 2;
	ft_pix_to_im(p, im, x, y);
	x += p->sx;
	i = 1;
	while (i <= p->dx)
	{
		if (p->d > 0)
		{
			p->d += p->d2;
			y += p->sy;
		}
		else
			p->d += p->d1;
		ft_pix_to_im(p, im, x, y);
		i++;
		x += p->sx;
	}
}

void	ft_paint_by_y(t_image *im, t_points *p)
{
	int i;
	int x;
	int y;

	x = p->x0;
	y = p->y0;
	p->d = (p->dx * 2) - p->dy;
	p->d1 = p->dx * 2;
	p->d2 = (p->dx - p->dy) * 2;
	ft_pix_to_im(p, im, x, y);
	y += p->sy;
	i = 1;
	while (i <= p->dy)
	{
		if (p->d > 0)
		{
			p->d += p->d2;
			x += p->sx;
		}
		else
			p->d += p->d1;
		ft_pix_to_im(p, im, x, y);
		i++;
		y += p->sy;
	}
}
