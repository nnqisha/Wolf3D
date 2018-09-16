/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnqisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 14:53:37 by nnqisha           #+#    #+#             */
/*   Updated: 2018/09/16 16:39:56 by nnqisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf.h"

static void	set_col(t_khalas *mypik, int c1, int c2, int c3)
{
	mypik->r = c1;
	mypik->g = c2;
	mypik->b = c3;
}

t_khalas	colourpick(t_wolf *test)
{
	t_khalas mypik;

	mypik.r = 0xff;
	mypik.g = 0xd8;
	mypik.b = 0x00;
	if (test->side == 1)
	{
		if (test->ray_dir_y > 0)
			set_col(&mypik, 0x7f, 0xff, 0xd4);
		else
			set_col(&mypik, 0x00, 0xff, 0xff);
	}
	else if (test->side == 0)
	{
		if (test->ray_dir_x > 0)
			set_col(&mypik, 0x30, 0xd5, 0xc8);
		else
			set_col(&mypik, 0x98, 0xff, 0x98);
	}
	return (mypik);
}