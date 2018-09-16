/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnqisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:52:21 by nnqisha           #+#    #+#             */
/*   Updated: 2018/09/11 14:21:37 by nnqisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf.h"

t_khalas		mycolorpik(t_wolf *mywolf);

void		draw_line(t_wolf *lines, int x)
{
	int		y;

	y = lines->draw_start;
	while (++y <= lines->draw_end)
	{
		SDL_RenderDrawPoint(lines->renderer, x, y);
	}
}
/*
void		draw_floor_and_ceiling(t_wolf *instance)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (++x <= WIN_WIDTH)
	{
		y = 0;
		while (++y <= WIN_HEIGHT)
		{
			if (++y <= WIN_HEIGHT / 2)
			{
				SDL_SetRenderDrawColor(instance->renderer, 0, 0xDD, 0xFF, 0xFF);
				SDL_RenderDrawPoint(instance->renderer, x, y);
			}
			else
			{
				SDL_SetRenderDrawColor(instance->renderer, 0xFF, 0, 0xFF, 0xFF);
				SDL_RenderDrawPoint(instance->renderer, x, y);
			}
		}
	}
}
*/
void		wall_draw(t_wolf *ray)
{
	int		y;

	t_khalas myc;

	myc = mycolorpik(ray);

	y = -1;
	ray->cel = (WIN_HEIGHT / 2.0) - WIN_HEIGHT / ray->perp_wall_dist;
	ray->flo = WIN_HEIGHT - ray->cel;
	while (++y < WIN_HEIGHT)
	{
		if (y < ray->cel)
		{
			SDL_SetRenderDrawColor(ray->renderer, 0, 0xDD, 0xFF, 0xFF);
			SDL_RenderDrawPoint(ray->renderer, ray->screen_x, y);
		}
		else if (y >= ray->cel && y < ray->flo)
		{
			// choose_color(ray);
			SDL_SetRenderDrawColor(ray->renderer, myc.r, myc.b, myc.g, 0xFF);
			SDL_RenderDrawPoint(ray->renderer, ray->screen_x, y);
		}
		else
		{
			SDL_SetRenderDrawColor(ray->renderer, 0xFF, 0, 0xFF, 0xFF);
			SDL_RenderDrawPoint(ray->renderer, ray->screen_x, y);
		}
	}
}

void		draw_walls(t_wolf *ray)
{
	int		y;

	ray->screen_x = -1;
	while (++ray->screen_x < WIN_WIDTH)
	{
		ray->side = 0;
		ray->camera_x = 2 * ray->screen_x / (double)WIN_WIDTH - 1;
		ray->rpx = ray->pos_x;
		ray->rpy = ray->pos_y;
		ray->ray_dir_x = ray->dir_x + ray->plane_x * ray->camera_x;
		ray->ray_dir_y = ray->dir_y + ray->plane_y * ray->camera_x;
		ray->map_x = (int)ray->rpx;
		ray->map_y = (int)ray->rpy;
		ray_length(ray);
		calc_distance(ray);
		ray->perp_wall_dist = wall_distance(ray);
		ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
		ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
		if (ray->draw_start < 0)
			ray->draw_start = 0;
		ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
		if (ray->draw_end >= WIN_HEIGHT)
			ray->draw_end = WIN_HEIGHT - 1;
		wall_draw(ray);
	}
}

t_khalas		mycolorpik(t_wolf *mywolf)
{
	t_khalas	mycolors;
	if (mywolf->side == 1)
	{
		if (mywolf->ray_dir_y > 0)
		{
			mycolors.r = 0x3b;
			mycolors.g = 0xFF;
			mycolors.b = 0x9a;
		}
		else
		{
			mycolors.r = 0xc6;
			mycolors.g = 0x32;
			mycolors.b = 0x32;
		}
	}
	else if (mywolf->side == 0)
	{
		if (mywolf->ray_dir_x > 0)
		{
			mycolors.r = 0x84;
			mycolors.g = 0x24;
			mycolors.b = 0x5b;
		}
		else
		{
			mycolors.r = 0x5b;
			mycolors.g = 0x84;
			mycolors.b = 0x84;
		}
	}
	return (mycolors);
}

/*
void		choose_color(t_wolf *color)
{
	if (color->worldmap[color->map_x][color->map_y] == 1)
		SDL_SetRenderDrawColor(color->renderer, 0xFF, 0, 0, 0xFF);
	else if (color->worldmap[color->map_x][color->map_y] == 2)
		SDL_SetRenderDrawColor(color->renderer, 0, 0xFF, 0, 0xFF);
	else if (color->worldmap[color->map_x][color->map_y] == 3)
		SDL_SetRenderDrawColor(color->renderer, 0, 0, 0xFF, 0xFF);
	else if (color->worldmap[color->map_x][color->map_y] == 4)
		SDL_SetRenderDrawColor(color->renderer, 0xFF, 0xFF, 0, 0xFF);
	else if (color->worldmap[color->map_x][color->map_y] == 5)
		SDL_SetRenderDrawColor(color->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	else
		SDL_SetRenderDrawColor(color->renderer, 0x88, 0x88, 0x88, 0xFF);
}*/
