CC = gcc
CFLAGS = -Wall -lm
SRC = main.c draw.c init.c inputKeyboard.c player.c raycasting.c terminal.c vector.c
OUT = minecraft

all:
	$(CC) $(SRC) -o $(OUT) $(CFLAGS)

clean:
	rm -f $(OUT)