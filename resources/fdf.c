/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhovnuv <ozhovnuv@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 10:52:40 by ozhovnuv          #+#    #+#             */
/*   Updated: 2017/03/01 18:21:22 by ozhovnuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static t_ses_win	*mlx_win_im_create(void)
{
	t_ses_win *wi;

	wi = (t_ses_win*)malloc(sizeof(t_ses_win));
	wi->h = 1000;
	wi->w = 1000;
	wi->mlx = mlx_init();
	wi->win = mlx_new_window(wi->mlx, wi->h, wi->w, "FDF");
	mlx_im_create(wi);
	return (wi);
}

void				mlx_im_create(t_ses_win *wi)
{
	wi->im = (t_image*)malloc(sizeof(t_image));
	wi->im->w = wi->h;
	wi->im->h = wi->h;
	wi->im->bpp = 32;
	wi->im->sizeline = wi->im->w * 4;
	wi->im->en = 0;
	wi->im->ini = mlx_new_image(wi->mlx, wi->im->w, wi->im->h);
	wi->im->data = mlx_get_data_addr(wi->im->ini, &(wi->im->bpp),
	&(wi->im->sizeline), &(wi->im->en));
}

void				ft_reboot_im(t_ses_win *wi, t_map_inf *inf)
{
	converte_to_isometric(inf);
	ft_move_map(inf);
	mlx_destroy_image(wi->mlx, wi->im->ini);
	mlx_im_create(wi);
	ft_print_map(wi->im, inf, inf->p);
	mlx_put_image_to_window(wi->mlx, wi->win, wi->im->ini, 0, 0);
}

static t_map_inf	*cr_start_inf_list(void)
{
	t_map_inf *inf;

	inf = (t_map_inf*)malloc(sizeof(t_map_inf));
	inf->alpha = 35;
	inf->beta = 45;
	inf->st_x = 0;
	inf->st_y = 0;
	inf->scale_z = 10;
	inf->scale_x = 10;
	inf->scale_y = 10;
	return (inf);
}

int					main(int ac, char **av)
{
	t_inf *all;

	all = (t_inf*)malloc(sizeof(t_inf));
	all->inf = cr_start_inf_list();
	ft_mapping(ac, av, all->inf);
	all->wi = mlx_win_im_create();
	ft_print_map(all->wi->im, all->inf, all->inf->p);
	mlx_put_image_to_window(all->wi->mlx, all->wi->win, all->wi->im->ini, 0, 0);
	mlx_hook(all->wi->win, 2, 5, ft_key_action, all);
	mlx_loop(all->wi->mlx);
}
