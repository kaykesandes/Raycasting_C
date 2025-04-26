/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LibCKayke.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayke.gy <kaykegy@proton.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 03:50:15 by kayke.gy          #+#    #+#             */
/*   Updated: 2025/04/26 03:50:15 by kayke.gy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCKAYKE_H
#define LIBCKAYKE_H

#include <unistd.h>
#ifndef _USECONDS_T
typedef unsigned int useconds_t;
#endif
#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>
#include <termios.h>
#include <stdlib.h>
#include <math.h>


#define Y_PIXELS 180
#define X_PIXELS 900
#define Z_BLOCKS 10
#define Y_BLOCKS 20
#define EYE_HEIGHT 1.5
#define X_BLOCKS 20
#define VIEW_HEIGHT 0.7
#define VIEW_WIDTH 1
#define BLOCK_BORDER_SIZE 0.05

static struct termios g_old_termios;
static struct termios g_new_termios;
static char keystate[256] = {0};

typedef struct s_vector
{
    float x;
    float y;
    float z;
} t_vector;

typedef struct s_vector2
{
    float psi;
    float phi;
} t_vector2;

typedef struct s_player_pos_view
{
    t_vector pos;
    t_vector2 view;
} t_player_pos_view;

ssize_t read(int fd, void *buf, size_t count);
int usleep(useconds_t usec);
int fcntl(int fd, int cmd, ...);
int printf(const char *format, ...);
int fflush(FILE *stream);
int tcgetattr(int fd, struct termios *termios_p);
int tcsetattr(int fd, int optional_actions, const struct termios *termios_p);
void *malloc(size_t size);
void free(void *ptr);
void exit(int status);
double cos(double x);
double sin(double x);
double sqrt(double x);
double fabs(double x);

struct s_aiocb
{
    int aio_fildes;
    int aio_offset;
    int aio_buf;
    int aio_nbytes;
    int aio_reqprio;
    int aio_sigevent;
    int aio_lio_opcode;
};

#endif