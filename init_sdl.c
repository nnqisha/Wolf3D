/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnqisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:19:49 by nnqisha           #+#    #+#             */
/*   Updated: 2018/09/10 18:31:04 by nnqisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf.h"

int	init_env(t_wolf *env)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		return (1);
	env->window = SDL_CreateWindow("NNQISHA_WOLF", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT, 0);
	if (env->window == NULL)
	{
		SDL_Quit();
		return (1);
	}
	env->renderer = SDL_CreateRenderer(env->window, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (env->renderer == NULL)
	{
		SDL_DestroyWindow(env->window);
		SDL_Quit();
		return (1);
	}
	return (0);
}

t_wolf	ft_asign_values(t_wolf *env)
{
	env->pos_x = env->x / 2;
	env->pos_y = env->y / 2;
	env->dir_x = -1;
	env->dir_y = 0;
	env->plane_x = 0;
	env->plane_y = 0.66;
	env->time = 0;
	env->old_time = 0;
	return (*env);
}
