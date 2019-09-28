
#include <iostream>
#include <stdio.h>
#include <unistd.h> 	
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include <stdlib.h>

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

#include "res/Vector2.hpp"
#include "res/realToPixel.hpp"
#include "res/screen.hpp"
#include "res/mouse.hpp"
#include "res/lines.hpp"

int main()
{
	int screen_fd = open(SCREEN_FILE, O_WRONLY);
	int mouse_fd = open(MOUSE_FILE, O_RDONLY | O_NONBLOCK );

	Vector2 <float> x1(0, 0);
	Vector2 <float> x2(-0.5, -0.7);
	Vector2 <float> dx(0, 0);


	int i = 0;
	int j = 0;

	int len = 20;
	int high = 20;

	dx.x = -0.5;
	dx.y = -0.7;	

	while(2+2 == 4)
	{
		getMouseEvent(mouse_fd);
		dx.x += (((float) MouseEvent.dx ) / 255);
		dx.y += (((float) MouseEvent.dy ) / 255);	
		x2 = dx;		

		//xInt.x = xInt.x + ((int) (MouseEvent.dx));
		//xInt.y = xInt.y + ((int) (MouseEvent.dy));
		
		//x2.x = -1 + ((2 * xInt.x + 1) / SCREEN_LENGH);
		//x2.y = -1 + ((2 * xInt.y + 1) / SCREEN_HIGH);

		//i = 0;
		/*while(i < SCREEN_HIGH)
		{
			j = 0;

			while(j < SCREEN_LENGH)
			{
				if((j > x && j < (x + len)) && (i > y && i < (y + high)))
				{
					setPixel(i, j, 0, 255, 255, 0);
				}
				else
				{
					setPixel(i, j, 0, 0, 0, 0);
				}

				j++;
			}

			i++;
		}*/
	
		drawLine(&x1, &x2);

		updateScreen(screen_fd);
	}

	close(mouse_fd);
	close(screen_fd);
	return 0;
}


