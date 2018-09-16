/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnqisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:51:44 by nnqisha           #+#    #+#             */
/*   Updated: 2018/09/16 16:37:01 by nnqisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf.h"

void	ft_free2d_double(double **st, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(st[i]);
		i++;
	}
	free(st);
}

int		main(int ac, char **av)
{
	t_wolf env;

	if (ac == 2)
	{
		if (open(av[1], O_RDONLY) == -1)
			ft_putstr("Error\n");
		else
		{
			get_lines(av[1], &env);
			alloc_memo(av[1], &env);
			init_env(&env);
			ft_asign_values(&env);
			while (env.running == 0)
			{
				draw_walls(&env);
				ft_event_handlers(&env);
				SDL_RenderPresent(env.renderer);
			}
			ft_free2d_double(env.worldmap, env.y);
		}
	}
	else
		ft_putstr("This piece of shit ain't working\n");
	return (0);
}
