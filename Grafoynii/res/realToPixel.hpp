
//
// This library convert real coordonates of screen (float from -1 to 1 (x,y)) to pixel (int from 0 to 1600 (x) from 0 to 900 (y))
//

Vector2 <int> realToPixel(Vector2 <float> *vec);
Vector2 <float> pixelToReal(Vector2 <int> *vec);


Vector2 <int> realToPixel(Vector2 <float> *vec)
{
	Vector2 <int> ret;

	ret.x = ((SCREEN_LENGH / 2) * (vec->x + 1) - 1);
	ret.y = SCREEN_HIGH - ((SCREEN_HIGH / 2) * (vec->y + 1) - 1) + 1;

	return ret;
}

Vector2 <float> pixelToReal(Vector2 <int> *vec) // NT
{
	Vector2 <float> ret;

	ret.x = -1 + ((2 * vec->x + 1) / SCREEN_LENGH);
	ret.y = -1 + ((2 * vec->y + 1) / SCREEN_HIGH);

	return ret;
}

