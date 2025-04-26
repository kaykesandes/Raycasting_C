/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayke.gy <kaykegy@proton.me>               #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-26 14:49:42 by kayke.gy          #+#    #+#             */
/*   Updated: 2025-04-26 14:49:42 by kayke.gy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LibCKayke.h"

int ray_outside(t_vector pos)
{
	if (pos.x >= X_BLOCKS || pos.y >= Y_BLOCKS || pos.z >= Z_BLOCKS || pos.x < 0 || pos.y < 0 || pos.z < 0)
		return (1);
	return (0);
}

int on_block_border(t_vector pos)
{
	int cnt = 0;
	if (fabsf(pos.x - round(pos.x)) < BLOCK_BORDER_SIZE)
		cnt++;
	if (fabsf(pos.y - round(pos.y)) < BLOCK_BORDER_SIZE)
		cnt++;
	if (fabsf(pos.z - round(pos.z)) < BLOCK_BORDER_SIZE)
		cnt++;
	if (cnt >= 2)
		return (1);
	return (0);
}

char raytrace(t_vector pos, t_vector dir, char*** blocks) {
    float eps = 0.01;
    while (!ray_outside(pos)) {
        char c = blocks[(int)pos.z][(int)pos.y][(int)pos.x];
        if (c != ' ') {
            if (on_block_border(pos)) {
                return '-';
            }
            else {
                return c;
            }
        }
        float dist = 2;
        if (dir.x > eps) {
            dist = min(dist, ((int)(pos.x + 1) - pos.x) / dir.x);
        }
        else if (dir.x < -eps) {
            dist = min(dist, ((int)pos.x - pos.x) / dir.x);
        }
        if (dir.y > eps) {
            dist = min(dist, ((int)(pos.y + 1) - pos.y) / dir.y);
        }
        else if (dir.y < -eps) {
            dist = min(dist, ((int)pos.y - pos.y) / dir.y);
        }
        if (dir.z > eps) {
            dist = min(dist, ((int)(pos.z + 1) - pos.z) / dir.z);
        }
        else if (dir.z < -eps) {
            dist = min(dist, ((int)pos.z - pos.z) / dir.z);
		}
        pos = vect_add(pos, vect_scale(dist + eps, dir));
    }
    return ' ';
}

char** get_picture(char** picture, t_player_pos_view posview, char*** blocks)
{
	t_vector** directions = init_directions(posview.view);
	for (int y = 0; y < Y_PIXELS; y++)
	{
		for (int x = 0; x < X_PIXELS; x++)
		{
			picture[y][x] = raytrace(posview.pos, directions[y][x], blocks);
		}
	}
}