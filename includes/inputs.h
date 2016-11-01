/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 14:24:25 by aljourda          #+#    #+#             */
/*   Updated: 2016/10/04 14:26:57 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTS_H
# define INPUTS_H

typedef struct	s_inputs
{
	int			left;
	int			right;
	int			up;
	int			down;
	int			run;
	int			sleft;
	int			sright;
	int			wall;
}				t_inputs;

int				key_hook_press(int keycode, void *param);
int				key_hook_release(int keycode, void *param);
int				exit_hook(void *param);

#endif
