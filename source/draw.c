/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayke.gy <kaykegy@proton.me>               #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-26 15:04:15 by kayke.gy          #+#    #+#             */
/*   Updated: 2025-04-26 15:04:15 by kayke.gy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LibCKayke.h"

void draw_ascii(char** picture) {
    fflush(stdout);
    printf("\033[0;0H");
    for (int i = 0; i < Y_PIXELS; i++) {
        int current_color = 0;
        for (int j = 0; j < X_PIXELS; j++) {
            // printf("%c", picture[i][j]);
            if (picture[i][j] == 'o' && current_color != 32) {
                printf("\x1B[32m");
                current_color = 32;
            }
            else if (picture[i][j] != 'o' && current_color != 0) {
                printf("\x1B[0m");
                current_color = 0;
            }
            printf("%c", picture[i][j]);
        }
        printf("\x1B[0m\n");
    }
}