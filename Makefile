interface:
	gcc main.c -o UI `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0` -lm