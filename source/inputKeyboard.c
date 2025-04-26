/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputKeyboard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayke.gy <kaykegy@proton.me>               #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-26 04:21:04 by kayke.gy          #+#    #+#             */
/*   Updated: 2025-04-26 04:21:04 by kayke.gy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LibCKayke.h"

char keystate[256] = {0};

void	process_input(void) {
	char c;
	for(int i = 0; i < 256; i++) 
	{
		keystate[i] = 0;
	}
	while (read(STDIN_FILENO, &c, 1) > 0) 
	{
		//printf("key pressed: %c\n", c);
		unsigned char uc = (unsigned char)c;
		keystate[uc] = 1;
	}
}

int is_key_pressed(char key) {
	return keystate[(unsigned char)key];
}