/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_distance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnqisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:51:39 by nnqisha           #+#    #+#             */
/*   Updated: 2018/09/11 12:46:28 by nnqisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf.h"

void	ray_length(t_wolf *len)
{
	len->delta_x = sqrt(1 + (len->ray_dir_y * len->ray_dir_y) /
			(len->ray_dir_x * len->ray_dir_x));
		len->delta_y = sqrt(1 + (len->ray_dir_x * len->ray_dir_x) /
			(len->ray_dir_y * len->ray_dir_y));
}

t_wolf	*calc_distance(t_wolf *dist)
{
	if (dist->ray_dir_x < 0)
	{
		dist->step_x = -1;
		dist->side_dist_x = (dist->pos_x - dist->map_x) * dist->delta_x;
	}
	else
	{
		dist->step_x = 1;
		dist->side_dist_x = (dist->map_x + 1.0 - dist->pos_x) * dist->delta_x;
	}
	if (dist->ray_dir_y < 0)
	{
		dist->step_y = -1;
		dist->side_dist_y = (dist->pos_y - dist->map_y) * dist->delta_y;
	}
	else
	{
		dist->step_y = 1;
		dist->side_dist_y = (dist->map_y + 1.0 - dist->pos_y) * dist->delta_y;
	}
	return (dist);
}

static	int	inbounds(t_wolf *dist)
{
	if (dist->map_x > 0 && dist->map_x < dist->x)
		if (dist->map_y > 0 && dist->map_y < dist->y)
			return (1);
	return (0);
}

double		wall_distance(t_wolf *dist)
{
	dist->hit = 0;
	while (dist->hit == 0)
	{
		if (dist->side_dist_x < dist->side_dist_y)
		{
			dist->side_dist_x += dist->delta_x;
			dist->map_x += dist->step_x;
			dist->side = 0;
		}
		else
		{
			dist->side_dist_y += dist->delta_y;
			dist->map_y += dist->step_y;
			dist->side = 1;
		}
		if (!inbounds(dist) || dist->worldmap[dist->map_y][dist->map_x] > 0)
			dist->hit = 1;
	}
	if (dist->side == 0)
		dist->perp_wall_dist = (dist->map_x - dist->rpx +
				(1 - dist->step_x) / 2) / dist->ray_dir_x;
	else
		dist->perp_wall_dist = (dist->map_y - dist->rpy +
				(1 - dist->step_y) / 2) / dist->ray_dir_y;
	return (dist->perp_wall_dist);
}
