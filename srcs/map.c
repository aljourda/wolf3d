/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 14:58:15 by aljourda          #+#    #+#             */
/*   Updated: 2016/10/04 14:58:36 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map.h>

void			map_init(t_map *map)
{
	int			i;
	static int	smap[] = {
		0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
		0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
		0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
		0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x02,
		0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x02,
		0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x00, 0x02,
		0x02, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0xFF, 0x00, 0x00, 0x02,
		0x02, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x02,
		0x02, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x02,
		0x02, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
		0x02, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x01, 0x01, 0x01, 0xFF, 0xFF, 0x02,
		0x02, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x02,
		0x02, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x02,
		0x02, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x02,
		0x02, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
		0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
		0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
		0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02
	};

	i = -1;
	while (++i < (MAP_WIDTH * MAP_HEIGHT))
		map->data[i] = smap[i];
}

int				map_get(t_map *map, int x, int y)
{
	int		pos;

	if (map != 0 && x < MAP_WIDTH)
	{
		pos = x + (y * MAP_WIDTH);
		if (pos >= 0 && pos < (MAP_WIDTH * MAP_HEIGHT))
		{
			return (map->data[pos]);
		}
	}
	return (0xffffff);
}

int				map_color(int side)
{
	if (side == 1)
		return (0xBCA9F5);
	if (side == 2)
		return (0xA9F5A9);
	if (side == 3)
		return (0x81DAF5);
	return (0xF2F5A9);
}