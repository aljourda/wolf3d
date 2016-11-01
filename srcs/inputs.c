/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 14:29:30 by aljourda          #+#    #+#             */
/*   Updated: 2016/10/04 14:29:53 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int				exit_hook(void *param)
{
	param = 0;
	ft_use_env(0);
	exit(1);
}

void			input_action(t_env *env)
{
	if (env->inputs.left == 1)
		cam_left(&(env->cam), 0.03);
	if (env->inputs.right == 1)
		cam_right(&(env->cam), 0.03);
	if (env->inputs.up == 1)
		cam_forward(&(env->cam), &(env->map), 0.04 * (env->inputs.run + 1));
	if (env->inputs.down == 1)
		cam_backward(&(env->cam), &(env->map), 0.04 * (env->inputs.run + 1));
	if (env->inputs.sleft == 1)
	{
		cam_left(&(env->cam), 1.57);
		cam_forward(&(env->cam), &(env->map), 0.04 * (env->inputs.run + 1));
		cam_left(&(env->cam), -1.57);
	}
	if (env->inputs.sright == 1)
	{
		cam_right(&(env->cam), 1.57);
		cam_forward(&(env->cam), &(env->map), 0.04 * (env->inputs.run + 1));
		cam_right(&(env->cam), -1.57);
	}
}

static void		key_hook_press_cam(t_env *env, int keycode)
{
	if (env != 0 && keycode == 69)
		cam_init(&(env->cam), 1, 1);
	if (env != 0 && keycode == 78)
		cam_init(&(env->cam), -1, 1);
}

int				key_hook_press(int keycode, void *param)
{
	t_env		*env;

	env = ft_use_env(-1);
	param = 0;
	if (keycode == 53)
		exit_hook(param);
	if (env != 0 && keycode == 126)
		env->inputs.up = 1;
	if (env != 0 && keycode == 125)
		env->inputs.down = 1;
	if (env != 0 && keycode == 123)
		env->inputs.left = 1;
	if (env != 0 && keycode == 124)
		env->inputs.right = 1;
	if (env != 0 && keycode == 7)
		env->inputs.wall = 1;
	if (env != 0 && keycode == 257)
		env->inputs.run = 1;
	if (env != 0 && keycode == 0)
		env->inputs.sleft = 1;
	if (env != 0 && keycode == 2)
		env->inputs.sright = 1;
	key_hook_press_cam(env, keycode);
	return (0);
}

int				key_hook_release(int keycode, void *param)
{
	t_env		*env;

	env = ft_use_env(-1);
	param = 0;
	if (env != 0 && keycode == 126)
		env->inputs.up = 0;
	if (env != 0 && keycode == 125)
		env->inputs.down = 0;
	if (env != 0 && keycode == 123)
		env->inputs.left = 0;
	if (env != 0 && keycode == 124)
		env->inputs.right = 0;
	if (env != 0 && keycode == 257)
		env->inputs.run = 0;
	if (env != 0 && keycode == 7)
		env->inputs.wall = 0;
	if (env != 0 && keycode == 0)
		env->inputs.sleft = 0;
	if (env != 0 && keycode == 2)
		env->inputs.sright = 0;
	return (0);
}
