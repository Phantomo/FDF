/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhovnuv <ozhovnuv@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:28:31 by ozhovnuv          #+#    #+#             */
/*   Updated: 2017/02/28 18:16:52 by ozhovnuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	ft_key_action_s(int keycode, t_inf *all)
{
	if (keycode == 69)
	{
		all->inf->scale_x += 1;
		all->inf->scale_y += 1;
		all->inf->scale_z += 1;
		ft_reboot_im(all->wi, all->inf);
	}
	else if (keycode == 78 && all->inf->scale_x > 0)
	{
		all->inf->scale_x -= 1;
		all->inf->scale_y -= 1;
		all->inf->scale_z -= 1;
		ft_reboot_im(all->wi, all->inf);
	}
	else if (keycode == 126)
	{
		all->inf->alpha += ANGEL;
		ft_reboot_im(all->wi, all->inf);
	}
	return (0);
}

int			ft_key_action(int keycode, t_inf *all)
{
	if (keycode == 53)
	{
		mlx_destroy_image(all->wi->mlx, all->wi->im->ini);
		mlx_destroy_window(all->wi->mlx, all->wi->win);
	}
	else if (keycode == 123)
	{
		all->inf->beta -= ANGEL;
		ft_reboot_im(all->wi, all->inf);
	}
	else if (keycode == 125)
	{
		all->inf->alpha -= ANGEL;
		ft_reboot_im(all->wi, all->inf);
	}
	else if (keycode == 124)
	{
		all->inf->beta += ANGEL;
		ft_reboot_im(all->wi, all->inf);
	}
	else
		return (ft_key_action_s(keycode, all));
	return (0);
}
