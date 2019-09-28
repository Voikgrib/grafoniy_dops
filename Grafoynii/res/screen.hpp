
// 
// This lib contain function to use screen buffer
//

void updateScreen(int fd);
void setPixel(int i, int j, unsigned char b, unsigned char g, unsigned char r, unsigned char a);



void setPixel(int i, int j, unsigned char b, unsigned char g, unsigned char r, unsigned char a)
{
	if(i < 0 || j < 0 || i >= SCREEN_HIGH || j >= SCREEN_LENGH)
		return;

	Screen[i][j].b = b;
	Screen[i][j].g = g;
	Screen[i][j].r = r;
	Screen[i][j].a = a;
}


void updateScreen(int fd)
{
	pwrite(fd, ((void*) &Screen), 4 * SCREEN_LENGH * SCREEN_HIGH, 0);
}

