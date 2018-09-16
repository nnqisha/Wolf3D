/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnqisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:18:36 by nnqisha           #+#    #+#             */
/*   Updated: 2018/09/16 16:38:35 by nnqisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf.h"

void	move_up(t_wolf *key_press)
{
	if (key_press->worldmap[(int)key_press->pos_y][(int)(key_press->pos_x
		+ key_press->dir_x * key_press->move_speed)] == 0)
		key_press->pos_x += key_press->dir_x;
	if (key_press->worldmap[(int)(key_press->pos_y + key_press->dir_y
		* key_press->move_speed)][(int)(key_press->pos_x)] == 0)
		key_press->pos_y += key_press->dir_y;
}

void	move_down(t_wolf *key_press)
{
	if (key_press->worldmap[(int)key_press->pos_y][(int)(key_press->pos_x
		- key_press->dir_x * key_press->move_speed)] == 0)
		key_press->pos_x -= key_press->dir_x;
	if (key_press->worldmap[(int)(key_press->pos_y - key_press->dir_y
		* key_press->move_speed)][(int)key_press->pos_x] == 0)
		key_press->pos_y -= key_press->dir_y;
}

void	move_left(t_wolf *a)
{
	a->old_dir_x = a->dir_x;
	a->dir_x = a->dir_x * cos(a->rot_speed) - a->dir_y * sin(a->rot_speed);
	a->dir_y = a->old_dir_x * sin(a->rot_speed) +
		a->dir_y * cos(a->rot_speed);
	a->old_plane_x = a->plane_x;
	a->plane_x = a->plane_x * cos(a->rot_speed) - a->plane_y *
		sin(a->rot_speed);
	a->plane_y = a->old_plane_x * sin(a->rot_speed) + a->plane_y *
		cos(a->rot_speed);
}

void	move_right(t_wolf *a)
{
	a->old_dir_x = a->dir_x;
	a->dir_x = a->dir_x * cos(-a->rot_speed) - a->dir_y *
		sin(-a->rot_speed);
	a->dir_y = a->old_dir_x * sin(-a->rot_speed) + a->dir_y *
		cos(-a->rot_speed);
	a->old_plane_x = a->plane_x;
	a->plane_x = a->plane_x * cos(-a->rot_speed) - a->plane_y *
		sin(-a->rot_speed);
	a->plane_y = a->old_plane_x * sin(-a->rot_speed) + a->plane_y *
		cos(-a->rot_speed);
}
