
// 
// This lib contain function to use screen buffer
//

void updateScreen(int fd);
void setPixel(int i, int j, unsigned char b, unsigned char g, unsigned char r, unsigned char a);



void setPixel(int i, int j, unsigned char b, unsigned char g, unsigned char r, unsigned char a)
{
	Screen[i][j].b = b;
	Screen[i][j].g = g;
	Screen[i][j].r = r;
	Screen[i][j].a = a;
}


void updateScreen(int fd)
{
//	int i = 0;
//	int j = 0;


//	while(j < SCREEN_HIGH)
//	{
//		i = 0;

//		while(i < SCREEN_LENGH)
//		{
			pwrite(fd, ((void*) &Screen), 4 * SCREEN_LENGH * SCREEN_HIGH, 0);
//			i++;
//		}
//		j++;
//	}
}
