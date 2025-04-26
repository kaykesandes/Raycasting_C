/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayke.gy <kaykegy@proton.me>               #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-26 16:55:56 by kayke.gy          #+#    #+#             */
/*   Updated: 2025-04-26 16:55:56 by kayke.gy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LibCKayke.h"

void update_pos_view(t_player_pos_view* posview, char*** blocks)
{
	float move_eps = 0.30;
	float tilt_eps = 0.1;
	int x = (int)posview->pos.x, y = (int)posview->pos.y;
	int z = (int)posview->pos.z - EYE_HEIGHT + 0.01;
	if (blocks[z][y][x] != ' ')
	    posview->pos.z += 1;
	z = (int)posview->pos.z - EYE_HEIGHT - 0.01;
	if (blocks[z][y][x] != ' ')
	    posview->pos.z -= 1;

	if (is_key_pressed('w'))
	    posview->view.psi += tilt_eps;
	if (is_key_pressed('s'))
	    posview->view.psi -= tilt_eps;
	if (is_key_pressed('d'))
	    posview->view.phi += tilt_eps;
	if (is_key_pressed('a'))
	    posview->view.phi -= tilt_eps;
	t_vector direction = angles_to_vector(posview->view);	
	if (is_key_pressed('i'))
	{
		posview->pos.x += direction.x * move_eps;
		posview->pos.y += direction.y * move_eps;
	}
	if (is_key_pressed('k'))
	{
		posview->pos.x -= direction.x * move_eps;
		posview->pos.y -= direction.y * move_eps;
	}
	if (is_key_pressed('j'))
	{
		posview->pos.x += direction.y * move_eps;
		posview->pos.y -= direction.x * move_eps;
	}
	if (is_key_pressed('l'))
	{
		posview->pos.x -= direction.y * move_eps;
		posview->pos.y += direction.x * move_eps;
	}
}

void place_block(t_vector pos, char*** blocks, char block)
{
	int x = (int)pos.x, y = (int)pos.y, z = (int)pos.z;
	float dists[6];
	dists[0] = fabsf(x+1 - pos.x);
	dists[1] = fabsf(pos.x -x);
	dists[2] = fabsf(y+1 - pos.y);
	dists[3] = fabsf(pos.y -y);
	dists[4] = fabsf(z+1 - pos.z);
	dists[5] = fabsf(pos.z -z);
	int min = 0;
	float min_dist = dists[0];
	for (int i = 1; i < 6; i++)
	{
		if (dists[i] < min_dist)
		{
			min = i;
			min_dist = dists[i];
		}
	}
	switch (min)
	{
	case 0:
		blocks[z][y][x+1] = block;
		break;
	case 1:
		blocks[z][y][x-1] = block;
		break;
	case 2:
		blocks[z][y+1][x] = block;
		break;
	case 3:
		blocks[z][y-1][x] = block;
		break;
	case 4:
		blocks[z+1][y][x] = block;
		break;
	case 5:
		blocks[z-1][y][x] = block;
		break;
	default:
		break;
	}
}

t_vector get_current_block(t_player_pos_view posview, char*** blocks) {
    t_vector pos = posview.pos;
    t_vector dir = angles_to_vector(posview.view);
    float eps = 0.01;
    while (!ray_outside(pos)) {
        char c = blocks[(int)pos.z][(int)pos.y][(int)pos.x];
        if (c != ' ') {
            return pos;
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
    return pos;
}