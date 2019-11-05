
#include <iostream>
#include <stdio.h>
#include <unistd.h> 	
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include <stdlib.h>

// to do
// depth buffer 	(+) 
// light			(-)
//
// Bugs:
// object disapear outside the camera ?
//
// defines here

#define SCREEN_FILE 		"/dev/fb0"
#define MOUSE_FILE 			"/dev/input/mice"
#define SCREEN_LENGH 		1600
#define SCREEN_HIGH 		900
#define MAX_LINK_CUBE		36

#undef  PI
#define PI					3.14

#undef  BUFFER_N			
#define BUFFER_N			0.01

#undef  BUFFER_N_MAX			
#define BUFFER_N_MAX		100

// for tests // __m128

//#undef printf
//#define printf //

// structs here

struct pixelSrtuct
{
	unsigned char b, g, r, a;
} Screen[SCREEN_HIGH][SCREEN_LENGH];

float DepthBuffer[SCREEN_HIGH][SCREEN_LENGH];

struct event
{
	char flags;
	char dx;
	char dy;
} MouseEvent;

// my libs here 

#include "res/Vector2.hpp"
#include "res/Vector3.hpp"
#include "res/Vector4.hpp"
#include "res/realToPixel.hpp"
#include "res/screen.hpp"
#include "res/mouse.hpp"
#include "res/lines.hpp"
#include "res/triangle.hpp"
#include "res/Vertex.hpp"
#include "res/Matrix3.hpp"
#include "res/Matrix4.hpp"

Vector3 <float> LightSource(1, 2, 5);

int main()
{
	int screen_fd = open(SCREEN_FILE, O_WRONLY);
	int mouse_fd = open(MOUSE_FILE, O_RDONLY | O_NONBLOCK );

	Vector3 <float> dx(0, 0, 0);
	Vector3 <float> upVec(0, 1, 0);
	Vector3 <float> camPos(0, 0, -2);

	float angleO = PI/4;
	float angleF = 0;
	
	float sinO = sinf(angleO);
	float cosO = cosf(angleO);
	float sinF = sinf(angleF);
	float cosF = cosf(angleF);

	Vector3 <float> e3((cosO * sinF), sinO, (cosO * cosF));

	Vector3 <float> e1(&upVec, &e3); // 
	e1.normalize();
	Vector3 <float> e2(&e3 ,&e1);

	Matrix3f rotate(&e1, &e2, &e3);
	Matrix4f moveMat;
	moveMat.data[0][0] = 1;
	moveMat.data[1][1] = 1;
	moveMat.data[2][2] = 1;
	moveMat.data[3][3] = 1;
	moveMat.data[0][3] = 0;
	moveMat.data[1][3] = 2;
	moveMat.data[2][3] = 0;
	

	Matrix4f proect;
	proect.setProectionMatrix();

	Vector3 <float> tmpVec1;
	Vector3 <float> tmpVec2;
	Vector3 <float> tmpVec3;

	Vector3 <float> tmpVec1persp;
	Vector3 <float> tmpVec2persp;
	Vector3 <float> tmpVec3persp;

	Vector4 <float> tmpVec41;
	Vector4 <float> tmpVec42;
	Vector4 <float> tmpVec43;

	struct Vertex cube[8];
//*
	cube[0].position.setCoords( 0.3,  0.3,  0.3);
	cube[1].position.setCoords(-0.3,  0.3,  0.3);
	cube[2].position.setCoords( 0.3, -0.3,  0.3);
	cube[3].position.setCoords(-0.3, -0.3,  0.3);
	cube[4].position.setCoords( 0.3,  0.3, -0.3);
	cube[5].position.setCoords(-0.3,  0.3, -0.3);
	cube[6].position.setCoords( 0.3, -0.3, -0.3);
	cube[7].position.setCoords(-0.3, -0.3, -0.3);
//*/
/*
	cube[0].position.setCoords( 1.3,  0.3,  0.3);
	cube[1].position.setCoords( 0.7,  0.3,  0.3);
	cube[2].position.setCoords( 1.3, -0.3,  0.3);
	cube[3].position.setCoords( 0.7, -0.3,  0.3);
	cube[4].position.setCoords( 1.3,  0.3, -0.3);
	cube[5].position.setCoords( 0.7,  0.3, -0.3);
	cube[6].position.setCoords( 1.3, -0.3, -0.3);
	cube[7].position.setCoords( 0.7, -0.3, -0.3);
//*/
	int cubeLink [MAX_LINK_CUBE] = { 
										0, 1, 2,
										1, 2, 3,

										0, 4, 5,
										0, 5, 1,

										0, 4, 2,
										6, 4, 2,

										5, 4, 7,
										4, 6, 7,

										6, 2, 3,
										6, 3, 7,

										1, 3, 7,
										5, 7, 1
									};

	int a = 0;
	int b = 0;
	int c = 0;

	float c1 = ((float) (BUFFER_N_MAX + BUFFER_N)) / ((float) (BUFFER_N_MAX - BUFFER_N));
	float c2 = ((float) (2 * BUFFER_N_MAX * BUFFER_N)) / ((float) (BUFFER_N_MAX - BUFFER_N));
	float ci1 = 0; 
	float ci2 = 0; 
	float ci3 = 0;

	const float fov = 1;

	Vector2 <float> vec1fake(0, 0);
	Vector2 <float> vec2fake(0, 0);
	Vector2 <float> vec3fake(0, 0);


//	Vector2 <float> vec1fake((vec1->x * fov) / (vec1->z), (vec1->y * fov) / (vec1->z));
//	Vector2 <float> vec2fake((vec2->x * fov) / (vec2->z), (vec2->y * fov) / (vec2->z));
 


	while(2+2 == 4)
	{
		getMouseEvent(mouse_fd);
		dx.x = (((float) MouseEvent.dx ) / 255);
		dx.y = (((float) MouseEvent.dy ) / 255);

		angleO += dx.y;
		angleF += dx.x;

		if(angleO > PI / 2)
			angleO = 3.139999 / 2;
		if(angleO < -PI / 2)
			angleO = -3.139999 / 2;

		sinO = sinf(angleO);
		cosO = cosf(angleO);
		sinF = sinf(angleF);
		cosF = cosf(angleF);

		e3.setCoords((cosO * sinF), sinO, (cosO * cosF));
		e1 = upVec * e3;
		e1.normalize();
		e2 = e3 * e1;
		e2.normalize();
		e3.normalize();
		rotate.setByVec(&e1, &e2, &e3);

		camPos.y += 0.001;
		camPos.x += 0.001; // for test!

		clearScreen();
		for(int i = 0; i != 12; i++)
		{
			a = cubeLink[(i * 3) + 0];
			b = cubeLink[(i * 3) + 1];
			c = cubeLink[(i * 3) + 2];

			tmpVec1 = cube[a].position - camPos;
			tmpVec2 = cube[b].position - camPos;
			tmpVec3 = cube[c].position - camPos;

			tmpVec1.multiplyOnMatrix(&rotate);
			tmpVec2.multiplyOnMatrix(&rotate);
			tmpVec3.multiplyOnMatrix(&rotate);

			ci1 = c1 - (c2 / tmpVec1.z);
			ci2 = c1 - (c2 / tmpVec2.z);
			ci3 = c1 - (c2 / tmpVec3.z);

			if(-1 < ci1 && ci1 < 1 && -1 < ci2 && ci2 < 1 && -1 < ci3 && ci3 < 1)
			{
				vec1fake.setCoords((tmpVec1.x * fov) / (tmpVec1.z), (tmpVec1.y * fov) / (tmpVec1.z));
				vec2fake.setCoords((tmpVec2.x * fov) / (tmpVec2.z), (tmpVec2.y * fov) / (tmpVec2.z));
				vec3fake.setCoords((tmpVec3.x * fov) / (tmpVec3.z), (tmpVec3.y * fov) / (tmpVec3.z));

				drawTriangleGradient(&vec1fake, &vec2fake, &vec3fake, NULL, ci1, ci2, ci3);

				//drawLine(&vec1fake, &vec2fake, ci1, ci2);
				//drawLine(&vec1fake, &vec3fake, ci1, ci3);
				//drawLine(&vec2fake, &vec3fake, ci2, ci3);
			}
		}

		updateScreen(screen_fd);
	}

	close(mouse_fd);
	close(screen_fd);
	return 0;
}


