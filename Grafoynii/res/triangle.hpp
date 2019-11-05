
//
// This library realise triangle create & draw
//

int drawTriangleGradient(Vector2 <float> *dot0, Vector2 <float> *dot1, Vector2 <float> *dot2, struct pixelSrtuct *colors, float z1, float z2, float z3);
int max(int a, int b, int c);
int min(int a, int b, int c);
float minf(float a, float b, float c);
float maxf(float a, float b, float c);

int drawTriangleGradient(Vector2 <float> *dot0, Vector2 <float> *dot1, Vector2 <float> *dot2, struct pixelSrtuct *colors, float z1, float z2, float z3)
{
	Vector2 <int> dotsInt[3];

	dotsInt[0] = realToPixel(dot0);
	dotsInt[1] = realToPixel(dot1);
	dotsInt[2] = realToPixel(dot2);

	Vector2 <int> dotsIntMax(max(dotsInt[0].x, dotsInt[1].x, dotsInt[2].x), max(dotsInt[0].y, dotsInt[1].y, dotsInt[2].y));
	Vector2 <int> dotsIntMin(min(dotsInt[0].x, dotsInt[1].x, dotsInt[2].x), min(dotsInt[0].y, dotsInt[1].y, dotsInt[2].y));

	float delta = 0;
	float delta1 = 0;
	float delta2 = 0;

	float d1 = 0; 
	float d2 = 0; 

	float i = 0;
	float j = 0;

	float minZ = minf(z1, z2, z3);
	float maxZ = maxf(z1, z2, z3);

	Vector2 <int> tmp;

	delta  = (dot1->x - dot0->x) * (dot2->y - dot0->y) - (dot2->x - dot0->x) * (dot1->y - dot0->y);

	//if(delta > 0)
	//	return 0;

	for(tmp.y = dotsIntMin.y; tmp.y < dotsIntMax.y; tmp.y++)
	{
		for(tmp.x = dotsIntMin.x; tmp.x < dotsIntMax.x; tmp.x++)
		{
			j = -1 + ((2 * ((float) tmp.x) + 1) / SCREEN_LENGH);
			i = -1 + ((2 * ((float) (SCREEN_HIGH - tmp.y)) + 1) / SCREEN_HIGH);			

			delta1 = (j - dot0->x)       * (dot2->y - dot0->y) - (dot2->x - dot0->x) * (i - dot0->y);
			delta2 = (j - dot0->x)       * (dot1->y - dot0->y) - (dot1->x - dot0->x) * (i - dot0->y);

			d1 = delta1 / delta;
			d2 = -delta2 / delta;

			if(!((1 - d1 - d2) < 0 || d1 < 0 || d2 < 0))
				setPixel(tmp.y, tmp.x, (z1 * (1 - d1 - d2) + z2 * d1 + z3 * d2) , d2 * 255, d1 * 255, (d1 + d2) * 255, 0); //draw
		}
	}
}


float minf(float a, float b, float c)
{
	//return a < b ? a : (b < c ? b : c);

	if(a <= b)	
	{
		if(a < c)
     	{	
			return a;
		}
	}
   	
	if(b <= a)
  	{
   		if(b < c)
    	{
	 		return b;
		}
	}

	if(c <= b)
	{
		if(c < a)
		{
			return c;
		}
	}

	return a;
}

float maxf(float a, float b, float c)
{
	//return a > b ? a : (b > c ? b : c);
	if(a > b)	
	{
		if(a >= c)
     	{	
			return a;
		}
	}
 	
	if(b >= a)
   	{
   		if(b > c)
    	{
	 		return b;
		}
	}
	
	if(c >= b)
	{
		if(c > a)
		{
			return c;
		}
	}


	return a;
}



int min(int a, int b, int c)
{
	//return a < b ? a : (b < c ? b : c);

	if(a <= b)	
	{
		if(a < c)
     	{	
			return a;
		}
	}
   	
	if(b <= a)
  	{
   		if(b < c)
    	{
	 		return b;
		}
	}

	if(c <= b)
	{
		if(c < a)
		{
			return c;
		}
	}

	return a;
}


int max(int a, int b, int c)
{
	//return a > b ? a : (b > c ? b : c);
	if(a > b)	
	{
		if(a >= c)
     	{	
			return a;
		}
	}
 	
	if(b >= a)
   	{
   		if(b > c)
    	{
	 		return b;
		}
	}
	
	if(c >= b)
	{
		if(c > a)
		{
			return c;
		}
	}


	return a;
}


