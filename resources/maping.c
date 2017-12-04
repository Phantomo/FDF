/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhovnuv <ozhovnuv@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:32:18 by ozhovnuv          #+#    #+#             */
/*   Updated: 2017/03/01 18:45:12 by ozhovnuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static unsigned int		hex_to_dec(char *str)
{
	int		num;
	int		i;
	int		k;
	char	*hex;

	hex = (char*)malloc(sizeof(char) * 16);
	hex = "0123456789ABCDEF";
	i = -1;
	num = 0;
	while (str[++i])
	{
		k = 0;
		while (hex[k])
		{
			if (hex[k] == str[i] || (hex[k] + 32) == str[i])
			{
				num += pow(16, abs(i - 5)) * k;
				break ;
			}
			k++;
		}
	}
	return (num);
}

static unsigned int		pick_up_color(char *map)
{
	int		i;
	int		k;
	char	*color;

	color = (char*)malloc(sizeof(char) * 7);
	color[0] = '\0';
	i = 0;
	while (map[i] && map[i] != '\n' && map[i] != ' ' && map[i] != 'x')
		i++;
	k = 0;
	if (map[i++] == 'x')
	{
		while (map[i] && map[i] != ' ' && map[i] != '\n' && k < 6)
		{
			color[k++] = map[i];
			i++;
		}
		return (hex_to_dec(color));
	}
	return (16777215);
}

static void				cd_grid(t_map_inf *inf, char *map)
{
	int		i;
	int		k;
	int		j;

	inf->mp = (t_map_st **)malloc(sizeof(t_map_st *) * inf->rows);
	i = 0;
	while (i < inf->rows)
		inf->mp[i++] = (t_map_st *)malloc(sizeof(t_map_st) * inf->cols);
	i = -1;
	k = 0;
	j = 0;
	while (map[++i] && k < inf->rows)
	{
		if ((ft_isdigit(map[i]) == 1 || map[i] == '-') && (i == 0
			|| map[i - 1] == ' ' || map[i - 1] == '\n'))
		{
			fill_coord(inf, k, j, ft_atoi(map + i));
			inf->mp[k][j++].color = pick_up_color(map + i);
		}
		else if (map[i] == '\n')
		{
			k++;
			j = 0;
		}
	}
}

static char				*ft_read_map(t_map_inf *inf, int fd)
{
	char	*map;
	char	*temp;
	char	*line;

	inf->rows = 0;
	inf->cols = 0;
	while (get_next_line(fd, &line))
	{
		if (inf->rows == 0)
		{
			inf->cols = ft_amount_cols(line);
			map = ft_strjoin(line, "\n");
		}
		else if (inf->cols != ft_amount_cols(line))
			ft_error(0);
		else
		{
			temp = ft_strjoin(map, line);
			ft_memdel((void **)&(map));
			map = ft_strjoin(temp, "\n");
			ft_memdel((void **)&(temp));
		}
		inf->rows++;
	}
	return (map);
}

void					ft_mapping(int ac, char **av, t_map_inf *inf)
{
	int		fd;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
			ft_error(1);
		cd_grid(inf, ft_read_map(inf, fd));
		converte_to_isometric(inf);
		ft_move_map(inf);
	}
	else
		ft_error(2);
}
