/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhovnuv <ozhovnuv@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 18:56:07 by ozhovnuv          #+#    #+#             */
/*   Updated: 2017/02/27 19:03:04 by ozhovnuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int			ft_amount_cols(char *str)
{
	int i;
	int cols;

	cols = 0;
	i = 0;
	while (*(str + i))
	{
		if ((ft_isdigit(str[i]) == 1 || str[i] == '-') && (i == 0
			|| str[i - 1] == ' '))
			cols++;
		i++;
	}
	return (cols);
}

static void	ft_rotate(t_map_inf *inf, t_map *p)
{
	int y;
	int x;

	y = p->y;
	p->y = y * COS(inf->alpha) + p->z * SIN(inf->alpha);
	p->z = y * (-SIN(inf->alpha)) + p->z * COS(inf->alpha);
	x = p->x;
	p->x = COS(inf->beta) * x - SIN(inf->beta) * p->z;
}

void		converte_to_isometric(t_map_inf *inf)
{
	int i;
	int j;

	if (inf->p == NULL)
	{
		inf->p = (t_map **)malloc(sizeof(t_map *) * inf->rows);
		i = 0;
		while (i < inf->rows)
			inf->p[i++] = (t_map *)malloc(sizeof(t_map) * inf->cols);
	}
	i = 0;
	while (i < inf->rows)
	{
		j = 0;
		while (j < inf->cols)
		{
			ft_zoom(inf, &(inf->mp[i][j]), &(inf->p[i][j]));
			ft_rotate(inf, &(inf->p[i][j]));
			j++;
		}
		i++;
	}
}
