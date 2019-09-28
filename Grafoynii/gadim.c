
/* 1600 */

#include<stdio.h>

struct pixelSrtuct
{
	unsigned char b, g, r, a;
} screen[1600][900];

struct event
{
	char flags;
	char dx;
	char dy;
} mouseEvent;


int screenHig = 900;
int screenLen = 1600;

void updateScreen(FILE *file);
void setPixel(int i, int j, unsigned char b, unsigned char g, unsigned char r, unsigned char a);
void getMouseEvent(FILE *file);

int main()
{
	FILE *fileScreen = fopen("/dev/fb0", "w");
	/*FILE *fileMouse = fopen("/dev/input/mice", "r");*/
	FILE* fileMouse = NULL;
	int i = 0;
	int j = 0;

	int len = 20;
	int high = 20;

	int x = 200;
	int y = 200;	

	while(2+2 == 4)
	{
		fileMouse = fopen("/dev/input/mice", "r");
		getMouseEvent(fileMouse);
		x = x + (int) mouseEvent.dx;
		y = y + (int) mouseEvent.dy;
		fclose(fileMouse);

		j = 0;
		while(j < screenHig)
		{
			i = 0;

			while(i < screenLen)
			{
				if((i > x && i < (x + len)) && (j > y && j < (y + high)))
				{
					setPixel(i, j, 0, 0, 255, 0);
				}
				else
				{
					setPixel(i, j, 0, 0, 0, 0);
				}
				i++;
			}
			j++;
		}

		updateScreen(fileScreen);
	}

	fclose(fileScreen);
	/*fclose(fileMouse);i*/

	return 0;
}

void getMouseEvent(FILE *file)
{
	fscanf(file, "%c%c%c", &mouseEvent.flags, &mouseEvent.dx, &mouseEvent.dy);
}

void setPixel(int i, int j, unsigned char b, unsigned char g, unsigned char r, unsigned char a)
{
	screen[i][j].b = b;
	screen[i][j].g = g;
	screen[i][j].r = r;
	screen[i][j].a = a;
}

void updateScreen(FILE* file)
{
	int i = 0;
	int j = 0;


	while(j < screenHig)
	{
		i = 0;
		while(i < screenLen)
		{
			fprintf(file, "%c%c%c%c", screen[i][j].b, screen[i][j].g, screen[i][j].r, screen[i][j].a);
			i++;
		}
		j++;
	}
}
