/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayke.gy <kaykegy@proton.me>               #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-26 04:25:09 by kayke.gy          #+#    #+#             */
/*   Updated: 2025-04-26 04:25:09 by kayke.gy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "LibCKayke.h"


char** init_picture(void)
{
    char** picture = malloc(sizeof(char*) * Y_PIXELS);
    for (int i = 0; i < Y_PIXELS; i++)
    {
        picture[i] = malloc(sizeof(char) * X_PIXELS);
    }
    return picture;
}

char*** init_blocks()
{
	char*** block = malloc(sizeof(char**) * Z_BLOCKS);
	for (int i = 0; i < Z_BLOCKS; i++)
	{
		block[i] = malloc(sizeof(char*) * Y_BLOCKS);
		for (int j = 0; j < Y_BLOCKS; j++)
		{
			block[i][j] = malloc(sizeof(char) * X_BLOCKS);
			for (int k = 0; k < X_BLOCKS; k++)
			{
				block[i][j][k] = ' ';
			}
		}
	}
	return (block);
}

t_vector** init_directions(t_vector2 view)
{
	view.psi -= VIEW_HEIGHT/2.0;
	t_vector screen_down = angles_to_vector(view);
	view.psi += VIEW_HEIGHT;
	t_vector screen_up = angles_to_vector(view);
	view.psi -= VIEW_HEIGHT/2.0;
	view.phi -= VIEW_WIDTH/2.0;
	t_vector screen_left = angles_to_vector(view);
	view.phi += VIEW_WIDTH;
	t_vector screen_right = angles_to_vector(view);
	view.phi -= VIEW_WIDTH/2.0;

	t_vector screen_mid_vert = vect_scale(0.5, vect_add(screen_up, screen_down));
	t_vector screen_mid_hor = vect_scale(0.5, vect_add(screen_left, screen_right));
    t_vector mid_to_left = vect_sub(screen_left, screen_mid_hor);
    t_vector mid_to_up = vect_sub(screen_up, screen_mid_vert);

	t_vector** dir = malloc(sizeof(t_vector*) * Y_PIXELS);
	for (int i = 0; i < Y_PIXELS; i++)
	{
		dir[i] = malloc(sizeof(t_vector) * X_PIXELS);
	}
	for (int y_pix = 0; y_pix < Y_PIXELS; y_pix++)
	{
		for (int x_pix = 0; x_pix < X_PIXELS; x_pix++)
		{
			t_vector tmp = vect_add(vect_add(screen_mid_hor, mid_to_left), mid_to_up);
			tmp = vect_sub(tmp, vect_scale(((float)x_pix / (X_PIXELS - 1)) * 2, mid_to_left));
			tmp = vect_sub(tmp, vect_scale(((float)y_pix / (Y_PIXELS - 1)) * 2, mid_to_up));
			vect_normalize(&tmp);
			dir[y_pix][x_pix] = tmp;
		}
	}
	return (dir);
}