/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayke.gy <kaykegy@proton.me>               #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-26 12:45:28 by kayke.gy          #+#    #+#             */
/*   Updated: 2025-04-26 12:45:28 by kayke.gy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LibCKayke.h"

t_player_pos_view init_pos_view(void)
{
	t_player_pos_view pos_view;
	pos_view.pos.x = 5;
	pos_view.pos.y = 5;
	pos_view.pos.z = 4 + EYE_HEIGHT;
	pos_view.view.psi = 0;
	pos_view.view.phi = 0;
	return (pos_view);
}

t_vector angles_to_vector(t_vector2 angles)
{
	t_vector res;
	res.x = cos(angles.psi) * cos(angles.phi);
	res.y = sin(angles.psi) * cos(angles.phi);
	res.z = sin(angles.phi);
	return (res);
}
t_vector vect_add(t_vector v1, t_vector v2)
{
	t_vector res;
	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	res.z = v1.z + v2.z;
	return (res);
}
t_vector vect_scale(float s, t_vector v)
{
	t_vector res = {
		s * v.x,
		s * v.y,
		s * v.z
	};
	return (res);
}

t_vector vect_sub(t_vector v1, t_vector v2)
{
	t_vector v3 = vect_scale(-1, v2);
	return (vect_add(v1, v3));
}

void vect_normalize(t_vector* v)
{
	float len = sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
	v->x /= len;
	v->y /= len;
	v->z /= len;
}