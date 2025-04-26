/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayke.gy <kaykegy@proton.me>               #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-26 04:09:22 by kayke.gy          #+#    #+#             */
/*   Updated: 2025-04-26 04:09:22 by kayke.gy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LibCKayke.h"

void	init_terminal(void)
{
	tcgetattr(STDIN_FILENO, &g_old_termios);
	g_new_termios = g_old_termios;
	g_new_termios.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &g_new_termios);
	fcntl(STDIN_FILENO, F_SETFL, fcntl(STDIN_FILENO, F_GETFL) | O_NONBLOCK);
	fflush(stdout);
};

void	restore_terminal(void)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &g_old_termios);
	printf("terminal restore\n");
};