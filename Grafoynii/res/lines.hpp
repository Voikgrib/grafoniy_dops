
//
// This library can draw lines between to points 
//

void drawLine(Vector2 <float> *vec1, Vector2 <float> *vec2);



void drawLine(Vector2 <float> *vec1, Vector2 <float> *vec2)
{
	Vector2 <int> vecInt1;
	Vector2 <int> vecInt2;

	vecInt1 = realToPixel(vec1);
	vecInt2 = realToPixel(vec2);

	setPixel(vecInt1.y, vecInt1.x, 0, 255, 0, 0);
	setPixel(vecInt2.y, vecInt2.x, 0, 255, 0, 0);

	float minX = 0;
	float minY = 0;
	float maxX = 0;
	float maxY = 0;

	if(vecInt1.y < vecInt2.y)
	{	
		minY = vecInt1.y;
		maxY = vecInt2.y;
	}
	else
	{
		maxY = vecInt1.y;
		minY = vecInt2.y;
	}

	if(vecInt1.x < vecInt2.x)
	{	
		minX = vecInt1.x;
		maxX = vecInt2.x;
	}
	else
	{
		maxX = vecInt1.x;
		minX = vecInt2.x;
	}

	if((vecInt2.x - vecInt1.x) * (vecInt2.y - vecInt1.y) > 0)
	{
		for(float i = minX; i < maxX; i++)
		{
			setPixel((minY + (((maxY - minY) / (maxX - minX)) * (i - minX))), i, 0, 255, 0, 0); 
		}
	}
	else
	{
		for(float i = minX; i < maxX; i++)
		{
			setPixel((minY + (((maxY - minY) / (maxX - minX)) * (i - minX))), maxX - (i - minX), 0, 0, 255, 0); 
		}

	}
}
