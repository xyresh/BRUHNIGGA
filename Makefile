all:
	gcc main.c -o BRUHNIGGA `pkg-config --cflags --libs gtk+-2.0`
