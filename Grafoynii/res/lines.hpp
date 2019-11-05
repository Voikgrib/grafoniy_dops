
//
// This library can draw lines between to points 
//

void drawLine(Vector2 <float> *vec1, Vector2 <float> *vec2, float z1, float z2);
//void drawLine3d(Vector3 <float> *vec1, Vector3 <float> *vec2);


void drawLine(Vector2 <float> *vec1, Vector2 <float> *vec2, float z1, float z2)
{
	Vector2 <int> vecInt1;
	Vector2 <int> vecInt2;

	vecInt1 = realToPixel(vec1);
	vecInt2 = realToPixel(vec2);

	setPixel(vecInt1.y, vecInt1.x, 0, 0, 255, 0, 0);
	setPixel(vecInt2.y, vecInt2.x, 0, 0, 255, 0, 0);

	float minX = 0;
	float minY = 0;
	float maxX = 0;
	float maxY = 0;

	float minZ = 0;

	if(z1 < z2)
		minZ = z1;
	else
		minZ = z2;

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

	if((vecInt2.x - vecInt1.x) * (vecInt2.y - vecInt1.y) < 0)
	{
		if(abs(vecInt2.x - vecInt1.x) > abs(vecInt2.y - vecInt1.y))
			for(int i = minX; i < maxX; i++)
			{
				setPixel((minY + (((maxY - minY) / (maxX - minX)) * (i - minX))), maxX - (i - minX), minZ, 255, 255, 0, 0); 
			}
		else
			for(int i = minY; i < maxY; i++)
			{
				setPixel(maxY - (i - minY), (minX + (((maxX - minX) / (maxY - minY)) * (i - minY))), minZ, 255, 255, 0, 0); 
			}		
	}
	else
	{
		if(abs(vecInt2.x - vecInt1.x) > abs(vecInt2.y - vecInt1.y))
			for(int i = minX; i < maxX; i++)
			{
				setPixel((minY + (((maxY - minY) / (maxX - minX)) * (i - minX))), i, minZ, 255, 255, 0, 0); 
			}
		else
			for(int i = minY; i < maxY; i++)
			{
				setPixel(i, (minX + (((maxX - minX) / (maxY - minY)) * (i - minY))), minZ, 255, 255, 0, 0); 
			}
	}
}


/*
void drawLine3d(Vector3 <float> *vec1, Vector3 <float> *vec2)
{
	const float fov = 1;

	Vector2 <float> vec1fake((vec1->x * fov) / (vec1->z), (vec1->y * fov) / (vec1->z));
	Vector2 <float> vec2fake((vec2->x * fov) / (vec2->z), (vec2->y * fov) / (vec2->z));

	drawLine(&vec1fake, &vec2fake);
}
*/
