/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 14:13:17 by aljourda          #+#    #+#             */
/*   Updated: 2016/10/05 15:27:22 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

t_env			*ft_use_env(int action)
{
	static t_env		*env;

	if (action == 1 || action == 2 || action == 3)
	{
		env = (t_env*)ft_memalloc(sizeof(t_env));
		if (env != 0)
		{
			env->width = 1200;
			env->height = env->width * 9 / 16;
			env->mlx_ptr = mlx_init();
			env->win_ptr = mlx_new_window(env->mlx_ptr, env->width,
				env->height, "Wolf3D");
			env->img = mlx_new_image(env->mlx_ptr, env->width, env->height);
			map_init(&(env->map));
			cam_init(&(env->cam), 66, 0);
		}
		else
			action = 0;
	}
	if (action == 0 && env != 0)
	{
		ft_memdel((void**)&(env));
	}
	return (env);
}

void			img_put_px(t_env *env, unsigned long color, int x, int y)
{
	env->tmp[y * env->sl + x * env->bpp / 8] = (color & 0xFF);
	env->tmp[y * env->sl + x * env->bpp / 8 + 1] = (color & 0xFF00) >> 8;
	env->tmp[y * env->sl + x * env->bpp / 8 + 2] = (color & 0xFF0000) >> 16;
}

static void		vertical_draw(t_env *env, int x)
{
	double	cur_pos;
	int		color;
	int		y;

	y = 0;
	while (y < env->height - 1)
	{
		color = 0xB0E0E6;
		if (y > env->height / 2)
			color = 0x095228;
		img_put_px(env, color, x, y);
		y++;
	}
	cur_pos = (double)x / (double)env->width;
	ray_init(&(env->ray), &(env->cam), cur_pos);
	ray_side_dist(&(env->ray));
	ray_dda(&(env->ray), &(env->map), !env->inputs.wall);
	ray_display(env, &(env->ray), x, env->height);
}

int				expose_hook(void *param)
{
	t_env		*env;
	int			x;

	env = ft_use_env(-1);
	param = 0;
	if (env)
	{
		env->tmp = mlx_get_data_addr(env->img, &env->bpp, &env->sl, &env->edn);
		x = 0;
		while (x < env->width)
		{
			vertical_draw(env, x);
			x++;
		}
		input_action(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img, 0, 0);
	}
	return (0);
}

int				main(int argc, char **argv)
{
	t_env		*env;

	env = 0;
	if (argc == 1 && argv)
	{
		env = ft_use_env(1);
		if (env != 0 && env->mlx_ptr != 0)
		{
			mlx_hook(env->win_ptr, 2, 1, key_hook_press, 0);
			mlx_hook(env->win_ptr, 3, 2, key_hook_release, 0);
			mlx_hook(env->win_ptr, 17, 0, exit_hook, 0);
			mlx_expose_hook(env->win_ptr, expose_hook, 0);
			mlx_loop_hook(env->mlx_ptr, expose_hook, 0);
			mlx_loop(env->mlx_ptr);
		}
	}
	ft_putstr("Usage : wolf3d\n");
	ft_use_env(0);
	return (0);
}
