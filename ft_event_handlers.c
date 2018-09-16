/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_handlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnqisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:17:08 by nnqisha           #+#    #+#             */
/*   Updated: 2018/09/10 18:18:01 by nnqisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf.h"

void	ft_event_handlers(t_wolf *env)
{
	env->screen_x = 0;
	env->move_speed = 1.5;
	env->rot_speed = 0.17;
	while (SDL_PollEvent(&env->event))
	{
		if (env->event.type == SDL_QUIT)
			env->running = 1;
		if (env->event.type == SDL_KEYDOWN)
		{
			if (env->event.key.keysym.sym == SDLK_ESCAPE)
				env->running = 1;
			if (env->event.key.keysym.sym == SDLK_UP ||
					env->event.key.keysym.sym == SDLK_w)
				move_up(env);
			if (env->event.key.keysym.sym == SDLK_DOWN ||
					env->event.key.keysym.sym == SDLK_s)
				move_down(env);
			if (env->event.key.keysym.sym == SDLK_RIGHT ||
					env->event.key.keysym.sym == SDLK_d)
				move_right(env);
			if (env->event.key.keysym.sym == SDLK_LEFT ||
					env->event.key.keysym.sym == SDLK_a)
				move_left(env);
		}
	}
}
