/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnqisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 17:46:38 by nnqisha           #+#    #+#             */
/*   Updated: 2018/09/16 16:36:20 by nnqisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include "SDL2/SDL.h"
# include "../libft/libft.h"

# define WIN_HEIGHT 768
# define WIN_WIDTH 1024
# define MAP_WIDTH 24
# define MAP_HEIGHT 24

typedef	struct		s_wolf
{
	double			**worldmap;
	int				fd;
	int				x;
	int				y;
	int				row;
	int				fill_mapx;
	int				fill_mapy;
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		event;
	int				running;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			move_speed;
	double			rot_speed;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_y;
	double			delta_x;
	double			perp_wall_dist;
	double			rpx;
	double			rpy;
	double			old_dir_x;
	double			old_plane_x;
	double			time;
	double			old_time;
	double			frame_time;
	double			wallx;
	double			floor_x_wall;
	double			floor_y_wall;
	double			dist_player;
	double			cur_dist;
	double			cel;
	double			flo;
	int				draw_start;
	int				draw_end;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				side;
	int				hit;
	int				line_height;
	int				screen_x;
	int				down;
	int				up;
	char			*line;
	char			**stream;
}					t_wolf;

typedef struct		s_khalas
{
	int				r;
	int				g;
	int				b;
}					t_khalas;

int					init_env(t_wolf *env);
t_wolf				ft_asign_values(t_wolf *env);
t_wolf				*calc_distance(t_wolf *dist);
double				wall_distance(t_wolf *dist);
void				draw_walls(t_wolf *ray);
void				draw_floor_and_ceiling(t_wolf *instance);
void				draw(t_wolf *draw);
void				choose_color(t_wolf *color);
void				get_lines(char *str, t_wolf *a);
void				alloc_memo(char *str, t_wolf *a);
void				ft_event_handlers(t_wolf *env);
void				move_up(t_wolf *key_press);
void				move_down(t_wolf *key_press);
void				move_left(t_wolf *a);
void				move_right(t_wolf *a);
void				draw_floor_and_ceiling(t_wolf *instance);
void				df(t_wolf *instance);
void				draw(t_wolf *draw);
void				ray_length(t_wolf *len);
t_khalas			side_y(t_wolf *mywolf);
t_khalas			side_x(t_wolf *mywolf);
t_khalas			colourpick(t_wolf *mywolf);

#endif
