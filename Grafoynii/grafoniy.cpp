
#include <iostream>
#include <stdio.h>
#include <unistd.h> 	
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// defines here

#define SCREEN_FILE 		"/dev/fb0"
#define MOUSE_FILE 			"/dev/input/mice"
#define SCREEN_LENGH 		1600
#define SCREEN_HIGH 		900

// structs here

struct pixelSrtuct
{
	unsigned char b, g, r, a;
} Screen[SCREEN_HIGH][SCREEN_LENGH];

struct event
{
	char flags;
	char dx;
	char dy;
} MouseEvent;

// my libs here

#include "res/screen.hpp"
#include "res/mouse.hpp"

int main()
{
	int screen_fd = open(SCREEN_FILE, O_WRONLY);
	int mouse_fd = open(MOUSE_FILE, O_RDONLY | O_NONBLOCK );

	int i = 0;
	int j = 0;

	int len = 20;
	int high = 20;

	int x = 850;
	int y = 300;	

	while(2+2 == 4)
	{
		getMouseEvent(mouse_fd);
		x = x + ((int) (MouseEvent.dx));
		y = y + ((int) (MouseEvent.dy));
		//y++;

		i = 0;
		while(i < SCREEN_HIGH)
		{
			j = 0;

			while(j < SCREEN_LENGH)
			{
				if((j > x && j < (x + len)) && (i > y && i < (y + high)))
				{
					setPixel(i, j, 0, 0, 255, 0);
				}
				else
				{
					setPixel(i, j, 0, 255, 0, 0);
				}

				j++;
			}

			i++;
		}

		//screen_fd = open(SCREEN_FILE, O_WRONLY);
		updateScreen(screen_fd);
		//close(screen_fd);
	}

	close(mouse_fd);
	close(screen_fd);
	return 0;
}


