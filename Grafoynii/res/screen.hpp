
// 
// This lib contain function to use screen buffer
//

void updateScreen(int fd);
void clearScreen(void);
void setPixel(int i, int j, float z, unsigned char b, unsigned char g, unsigned char r, unsigned char a);



void setPixel(int i, int j, float z, unsigned char b, unsigned char g, unsigned char r, unsigned char a)
{
	if(i < 0 || j < 0 || i >= SCREEN_HIGH || j >= SCREEN_LENGH)
		return;

	if(DepthBuffer[i][j] > z)
	{
		Screen[i][j].b = b;
		Screen[i][j].g = g;
		Screen[i][j].r = r;
		Screen[i][j].a = a;
		DepthBuffer[i][j] = z;
	}
}

void clearScreen(void)
{
	for(int i = 0; i != SCREEN_HIGH; i++)
	{
		for(int j = 0; j != SCREEN_LENGH; j++)
		{
			Screen[i][j].b = 0;
			Screen[i][j].g = 0;
			Screen[i][j].r = 0;
			Screen[i][j].a = 0;			
			DepthBuffer[i][j] = 1;
		}
	}
}


void updateScreen(int fd)
{
	pwrite(fd, ((void*) &Screen), 4 * SCREEN_LENGH * SCREEN_HIGH, 0);
}

