/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayke.gy <kaykegy@proton.me>               #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-26 17:09:28 by kayke.gy          #+#    #+#             */
/*   Updated: 2025-04-26 17:09:28 by kayke.gy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LibCKayke.h"

int main(void)
{
	init_terminal();
	char** picture = init_picture();
	char*** blocks = init_blocks();
	for(int x = 0; x < X_BLOCKS; x++)
	{
		for(int y = 0; y < Y_BLOCKS; y++)
		{
			for(int z = 0; z < 4; z++)
			{
				blocks[z][y][x] = '@';
			}
		}
	}
	t_player_pos_view posview = init_pos_view();
	while (1) {
        process_input();
        if (is_key_pressed('q')) {
            exit(0);
        }
        update_pos_view(&posview, blocks);
        t_vector current_block = get_current_block(posview, blocks);
        int have_current_block = !ray_outside(current_block);
        int current_block_x = current_block.x;
        int current_block_y = current_block.y;
        int current_block_z = current_block.z;
        char current_block_c;
        int removed = 0;
        if (have_current_block) {
            current_block_c = blocks[current_block_z][current_block_y][current_block_x];
            blocks[current_block_z][current_block_y][current_block_x] = 'o';
            if (is_key_pressed('x')) {
                removed = 1;
                blocks[current_block_z][current_block_y][current_block_x] = ' ';
            }

            if (is_key_pressed(' ')) {
                place_block(current_block, blocks, '@');
            }
        }

        get_picture(picture, posview, blocks);
        if (have_current_block && !removed) {
            blocks[current_block_z][current_block_y][current_block_x] = current_block_c;
        }
        draw_ascii(picture);
        usleep(20000);
    }
	restore_terminal();	
	return (0);
}