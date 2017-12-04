/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grad_pix_to_im.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhovnuv <ozhovnuv@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:45:54 by ozhovnuv          #+#    #+#             */
/*   Updated: 2017/02/27 19:14:01 by ozhovnuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void			ft_pix_to_im(t_points *p, t_image *im, int x, int y)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (p->p1_col == p->p2_col)
	{
		if (im->w > x && im->h > y && x >= 0 && y >= 0)
		{
			r = (p->p1_col & 0xFF);
			g = ((p->p1_col & 0xFF00) >> 8);
			b = ((p->p1_col & 0xFF0000) >> 16);
			im->data[y * im->sizeline + x * 4] = r;
			im->data[y * im->sizeline + x * 4 + 1] = g;
			im->data[y * im->sizeline + x * 4 + 2] = b;
		}
	}
	else
		ft_grad(p, x, y, im);
}

static void		ft_grad_y(t_points *p, int y)
{
	int r;
	int g;
	int b;

	r = (double)(p->r2 - p->r1) / (double)(p->y - p->y0) * (double)(y - p->y0);
	g = (double)(p->g2 - p->g1) / (double)(p->y - p->y0) * (double)(y - p->y0);
	b = (double)(p->b2 - p->b1) / (double)(p->y - p->y0) * (double)(y - p->y0);
	p->r = (unsigned char)(p->r1 + r);
	p->g = (unsigned char)(p->g1 + g);
	p->b = (unsigned char)(p->b1 + b);
}

static void		ft_grad_x(t_points *p, int x)
{
	int	r;
	int	g;
	int	b;

	r = (double)(p->r2 - p->r1) / (double)(p->x - p->x0) * (double)(x - p->x0);
	g = (double)(p->g2 - p->g1) / (double)(p->x - p->x0) * (double)(x - p->x0);
	b = (double)(p->b2 - p->b1) / (double)(p->x - p->x0) * (double)(x - p->x0);
	p->r = (unsigned char)(p->r1 + r);
	p->g = (unsigned char)(p->g1 + g);
	p->b = (unsigned char)(p->b1 + b);
}

void			ft_grad(t_points *p, int x, int y, t_image *im)
{
	if (im->w > x && im->h > y && x > 0 && y > 0)
	{
		p->r1 = (p->p1_col & 0xFF);
		p->g1 = ((p->p1_col & 0xFF00) >> 8);
		p->b1 = ((p->p1_col & 0xFF0000) >> 16);
		p->r2 = (p->p2_col & 0xFF);
		p->g2 = ((p->p2_col & 0xFF00) >> 8);
		p->b2 = ((p->p2_col & 0xFF0000) >> 16);
		if (p->dy >= p->dx)
			ft_grad_y(p, y);
		else
			ft_grad_x(p, x);
		im->data[y * im->sizeline + x * 4] = p->r;
		im->data[y * im->sizeline + x * 4 + 1] = p->g;
		im->data[y * im->sizeline + x * 4 + 2] = p->b;
	}
}

void			ft_chooce_points(int i, int j, t_points *p, t_map **map)
{
	p->x = map[i][j].x;
	p->y = map[i][j].y;
	p->p2_col = map[i][j].color;
}
