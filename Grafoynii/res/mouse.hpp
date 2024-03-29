
//
// This lib realise mouse input 
//

void getMouseEvent(int fd)
{
	char tmp[3];

	if(read(fd, &tmp, 3) == 3)
	{
		MouseEvent.flags = tmp[0];
		MouseEvent.dx = tmp[1];
		MouseEvent.dy = tmp[2]; // to prevent invertation
	}
	else
	{
		MouseEvent.flags = 0;
		MouseEvent.dx = 0;
		MouseEvent.dy = 0;
	}
}
