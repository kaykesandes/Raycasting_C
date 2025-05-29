CC = gcc
CFLAGS = -Wall -lm
SRC = source/main.c source/draw.c source/init.c source/inputKeyboard.c source/player.c source/raycasting.c source/terminal.c source/vector.c
OUT = minecraft

all:
	$(CC) $(SRC) -o $(OUT) $(CFLAGS)

clean:
	rm -f $(OUT)