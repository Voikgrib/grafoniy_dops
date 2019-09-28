
#include <stdio.h>
#include <unistd.h> 	
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


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

void updateScreen(int fd);
void setPixel(int i, int j, unsigned char b, unsigned char g, unsigned char r, unsigned char a);
void getMouseEvent(int fd);

int main()
{
	int screen_fd = open("/dev/fb0", O_WRONLY | O_NONBLOCK);
	int mouse_fd = open("/dev/input/mice", O_RDONLY | O_NONBLOCK );
	
	if(mouse_fd == -1)
	{
		printf("!!! Can't open mice file !!!");
		return -1;
	}

	//FILE *fileMouse = fopen("/dev/input/mice", "rb");
	//FILE* fileMouse = NULL;
	int i = 0;
	int j = 0;

	int len = 20;
	int high = 20;

	int x = 850;
	int y = 300;	

	while(2+2 == 4)
	{
		getMouseEvent(mouse_fd);
		x = x + (int) mouseEvent.dx;
		y = y + (int) mouseEvent.dy;

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

		updateScreen(screen_fd);

	}

	close(screen_fd);
	close(mouse_fd);
	//fclose(fileMouse);

	return 0;
}

void getMouseEvent(int fd)
{
	char tmp[3];

	if(read(fd, &tmp, 3) != -1)
	{
		mouseEvent.flags = tmp[0];
		mouseEvent.dx = tmp[1];
		mouseEvent.dy = tmp[2];
	}
}

void setPixel(int i, int j, unsigned char b, unsigned char g, unsigned char r, unsigned char a)
{
	screen[i][j].b = b;
	screen[i][j].g = g;
	screen[i][j].r = r;
	screen[i][j].a = a;
}

void updateScreen(int fd)
{
	int i = 0;
	int j = 0;


	while(j < screenHig)
	{
		i = 0;

		while(i < screenLen)
		{
			write(fd, ((void*) &screen[i][j]), 4);
			i++;
		}
		j++;
	}
}
