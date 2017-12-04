/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhovnuv <ozhovnuv@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 11:00:57 by ozhovnuv          #+#    #+#             */
/*   Updated: 2017/03/01 18:23:57 by ozhovnuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define SIN(x) sin(x * M_PI/180)
# define COS(x) cos(x * M_PI/180)
# define ANGEL 5
# include <libft.h>
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct		s_image
{
	void			*ini;
	int				h;
	int				w;
	char			*data;
	int				bpp;
	int				sizeline;
	int				en;
}					t_image;

typedef struct		s_ses_win
{
	void			*mlx;
	void			*win;
	int				h;
	int				w;
	t_image			*im;
}					t_ses_win;

typedef struct		s_points
{
	int				x0;
	int				y0;
	int				x;
	int				y;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				d;
	int				d1;
	int				d2;
	unsigned int	p1_col;
	unsigned int	p2_col;
	unsigned char	r1;
	unsigned char	r2;
	unsigned char	g1;
	unsigned char	g2;
	unsigned char	b1;
	unsigned char	b2;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_points;

typedef struct		s_map
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_map;

typedef struct		s_map_st
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_map_st;

typedef struct		s_map_inf
{
	int				cols;
	int				rows;
	int				max_x;
	int				max_y;
	int				min_x;
	int				min_y;
	int				scale_x;
	int				scale_y;
	int				scale_z;
	int				st_x;
	int				st_y;
	int				alpha;
	int				beta;
	t_map_st		**mp;
	t_map			**p;
}					t_map_inf;

typedef struct		s_inf
{
	t_map_inf		*inf;
	t_ses_win		*wi;
}					t_inf;

void				ft_grad(t_points *p, int x, int y, t_image *im);
void				ft_line(t_image *im, t_points *p);
void				ft_paint_by_x(t_image *im, t_points *p);
void				ft_paint_by_y(t_image *im, t_points *p);
int					destroy_ses(int keycode, t_image *im, t_ses_win *wi);
void				pix_to_im(t_points *p, t_image *im, int x, int y);
void				sea_win_create(t_ses_win *mlx);
void				ft_mapping(int ac, char **av, t_map_inf *inf);
void				ft_print_map(t_image *im, t_map_inf *inf, t_map **map);
void				converte_to_isometric(t_map_inf *inf);
void				mlx_im_create(t_ses_win *wi);
void				ft_move_map(t_map_inf *inf);
int					ft_key_action(int keycode, t_inf *all);
void				ft_reboot_im(t_ses_win *wi, t_map_inf *inf);
void				ft_grad(t_points *p, int x, int y, t_image *im);
void				ft_chooce_points(int i, int j, t_points *p, t_map **map);
void				ft_pix_to_im(t_points *p, t_image *im, int x, int y);
void				fill_coord(t_map_inf *inf, int k, int j, int z);
void				ft_error(int err_msg);
void				ft_picks_of_map(t_map_inf *inf);
void				ft_zoom(t_map_inf *inf, t_map_st *mp, t_map *p);
int					ft_amount_cols(char *str);

#endif
