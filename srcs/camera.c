/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 14:35:19 by aljourda          #+#    #+#             */
/*   Updated: 2016/10/05 15:30:21 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <camera.h>
#include <math.h>

void			cam_init(t_cam *cam, double fov, int onlyfov)
{
	if (onlyfov == 0)
	{
		cam->pos_x = 2;
		cam->pos_y = 2;
		cam->fov = 0;
	}
	cam->fov += fov;
	if (cam->fov < 10)
		cam->fov = 10;
	if (cam->fov > 170)
		cam->fov = 170;
	cam->dir_x = 1;
	cam->dir_y = 0;
	cam->delta_x = 0;
	cam->delta_y = tan((cam->fov * 3.14 / 180.0) / 2);
}

void			cam_forward(t_cam *cam, t_map *map, double speed)
{
	int x;
	int y;

	x = (int)(cam->pos_x + cam->dir_x * speed);
	y = (int)(cam->pos_y + cam->dir_y * speed);
	if (map_get(map, x, (int)cam->pos_y) == 0
		&& map_get(map, (int)cam->pos_x, y) == 0)
	{
		cam->pos_x += cam->dir_x * speed;
		cam->pos_y += cam->dir_y * speed;
	}
}

void			cam_backward(t_cam *cam, t_map *map, double speed)
{
	int x;
	int y;

	x = (int)(cam->pos_x - cam->dir_x * speed);
	y = (int)(cam->pos_y - cam->dir_y * speed);
	if (map_get(map, x, (int)cam->pos_y) == 0
		&& map_get(map, (int)cam->pos_x, y) == 0)
	{
		cam->pos_x -= cam->dir_x * speed;
		cam->pos_y -= cam->dir_y * speed;
	}
}

void			cam_right(t_cam *cam, double speed)
{
	double dir_x;
	double delta_x;

	dir_x = cam->dir_x;
	delta_x = cam->delta_x;
	cam->dir_x = cam->dir_x * cos(speed) - cam->dir_y * sin(speed);
	cam->dir_y = dir_x * sin(speed) + cam->dir_y * cos(speed);
	cam->delta_x = cam->delta_x * cos(speed) - cam->delta_y * sin(speed);
	cam->delta_y = delta_x * sin(speed) + cam->delta_y * cos(speed);
}

void			cam_left(t_cam *cam, double speed)
{
	double dir_x;
	double delta_x;

	dir_x = cam->dir_x;
	delta_x = cam->delta_x;
	cam->dir_x = cam->dir_x * cos(-speed) - cam->dir_y * sin(-speed);
	cam->dir_y = dir_x * sin(-speed) + cam->dir_y * cos(-speed);
	cam->delta_x = cam->delta_x * cos(-speed) - cam->delta_y * sin(-speed);
	cam->delta_y = delta_x * sin(-speed) + cam->delta_y * cos(-speed);
}
