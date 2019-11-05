
//
// This library realize cube & interaction with it
//

#define MAX_CUBE_POINTS 	8
#define MAX_CUBE_LINES 		12


class Cube
{
	private:
	Vector3 <float> pozition;
	Vector3 <float> *points; 	// local coordinates
	Vector2 <int> 	lines[MAX_CUBE_LINES];

	public:
	Cube(Vector3 <float> pozition, float sizeOfBorder);
	Cube(Vector3 <float> pozition, Vector3 <float> *points);
	~Cube(void);



};


Cube::Cube(Vector3 <float> pozitionNew, Vector3 <float> *pointsNew)
{
	pozition = pozitionNew;
	points = pointsNew;
}

Cube::~Cube(void)
{
	return;	
}

#undef MAX_CUBE_POINTS
#undef MAX_CUBE_LINES


