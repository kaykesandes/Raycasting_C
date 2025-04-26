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
	char** picutre = malloc(sizeof(char*) * Y_PIXELS);
	for (int i = 0; i < Y_PIXELS; i++)
	{
		picutre[i] = malloc(sizeof(char) * X_PIXELS);
	}
}

char*** init_block()
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