
//
// This lib realize 4x4 float matrix
// 

template <typename typeOfData> 
class Vector4;

class Matrix4f
{
	public:
	float data[4][4];


	Matrix4f(void);
	Matrix4f(float* dataNew);
	Matrix4f(Vector4 <float> *vec1, Vector4 <float> *vec2, Vector4 <float> *vec3, Vector4 <float> *vec4);
	//void multiply(Vector4 <float>* vec);	

	void setByVec(Vector4 <float> *vec1, Vector4 <float> *vec2, Vector4 <float> *vec3, Vector4 <float> *vec4);

	void setProectionMatrix(void);
};

void Matrix4f::setProectionMatrix(void)
{
	float c1 = ((float) (BUFFER_N_MAX - BUFFER_N)) / ((float) (BUFFER_N_MAX + BUFFER_N));
	float c2 = ((float) (2 * BUFFER_N_MAX * BUFFER_N)) / ((float) (BUFFER_N_MAX - BUFFER_N));

	for(int i = 0; i != 4; i++)
		for(int j = 0; j != 4; j++)
			data[i][j] = 0;

	data[0][0] = ((float) (- BUFFER_N)) / ((float) SCREEN_LENGH);
	data[1][1] = ((float) (- BUFFER_N)) / ((float) SCREEN_HIGH);
	data[2][2] = c1;
	data[2][3] = c2;
	data[3][2] = 1;
	
	for(int i = 0; i != 4; i++)
	{
		for(int j = 0; j != 4; j++)
		{
			printf("%f\t", data[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	printf("\n");
}

//---===---===---===---//
//  WARNING COPYPASTE  //
//===---===---===---===//

void Matrix4f::setByVec(Vector4 <float> *vec1, Vector4 <float> *vec2, Vector4 <float> *vec3, Vector4 <float> *vec4)
{
	data[0][0] = vec1->x;
	data[0][1] = vec1->y;
	data[0][2] = vec1->z;
	data[0][3] = vec1->w;

	data[1][0] = vec2->x;
	data[1][1] = vec2->y;
	data[1][2] = vec2->z;
	data[1][3] = vec2->w;

	data[2][0] = vec3->x;
	data[2][1] = vec3->y;
	data[2][2] = vec3->z;	
	data[2][3] = vec3->w;	

	data[3][0] = vec4->x;
	data[3][1] = vec4->y;
	data[3][2] = vec4->z;	
	data[3][3] = vec4->w;	
}

Matrix4f::Matrix4f(Vector4 <float> *vec1, Vector4 <float> *vec2, Vector4 <float> *vec3, Vector4 <float> *vec4)
{
	data[0][0] = vec1->x;
	data[0][1] = vec1->y;
	data[0][2] = vec1->z;
	data[0][3] = vec1->w;

	data[1][0] = vec2->x;
	data[1][1] = vec2->y;
	data[1][2] = vec2->z;
	data[1][3] = vec2->w;

	data[2][0] = vec3->x;
	data[2][1] = vec3->y;
	data[2][2] = vec3->z;	
	data[2][3] = vec3->w;	

	data[3][0] = vec4->x;
	data[3][1] = vec4->y;
	data[3][2] = vec4->z;	
	data[3][3] = vec4->w;	
}

Matrix4f::Matrix4f(float* dataNew) // i am to lazy
{
	data[0][0] = dataNew[0 ];
	data[0][1] = dataNew[1 ];
	data[0][2] = dataNew[2 ];
	data[0][3] = dataNew[3 ];

	data[1][0] = dataNew[4 ];
	data[1][1] = dataNew[5 ];
	data[1][2] = dataNew[6 ];
	data[1][3] = dataNew[7 ];

	data[2][0] = dataNew[8 ];
	data[2][1] = dataNew[9 ];
	data[2][2] = dataNew[10];
	data[2][3] = dataNew[11];

	data[3][0] = dataNew[12];
	data[3][1] = dataNew[13];
	data[3][2] = dataNew[14];
	data[3][3] = dataNew[15];
}

Matrix4f::Matrix4f(void) 
{
	for(int i = 0; i != 4; i++)
		for(int j = 0; j != 4; j++)
			data[i][j] = 0;
}

template <typename typeOfData> 
void Vector4<typeOfData>::multiplyOnMatrix(Matrix4f *mat)
{
	typeOfData tmpX = mat->data[0][0] * x + mat->data[0][1] * y + mat->data[0][2] * z + mat->data[0][3] * w;
	typeOfData tmpY = mat->data[1][0] * x + mat->data[1][1] * y + mat->data[1][2] * z + mat->data[1][3] * w;
	typeOfData tmpZ = mat->data[2][0] * x + mat->data[2][1] * y + mat->data[2][2] * z + mat->data[2][3] * w;
	typeOfData tmpW = mat->data[3][0] * x + mat->data[3][1] * y + mat->data[3][2] * z + mat->data[3][3] * w;

	x = tmpX;
	y = tmpY;
	z = tmpZ;	
	w = tmpW;
}


