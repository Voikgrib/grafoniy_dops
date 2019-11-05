
//
// This class realise matrix
//

template <typename typeOfData>
class Vector3;

class Matrix3f
{
	public:
	float data[3][3];


	Matrix3f(void);
	Matrix3f(float* dataNew);
	Matrix3f(Vector3 <float> *vec1, Vector3 <float> *vec2, Vector3 <float> *vec3);
	//void multiply(Vector3 <float>* vec);	

	void setByVec(Vector3 <float> *vec1, Vector3 <float> *vec2, Vector3 <float> *vec3);
};


void Matrix3f::setByVec(Vector3 <float> *vec1, Vector3 <float> *vec2, Vector3 <float> *vec3)
{
	data[0][0] = vec1->x;
	data[0][1] = vec1->y;
	data[0][2] = vec1->z;

	data[1][0] = vec2->x;
	data[1][1] = vec2->y;
	data[1][2] = vec2->z;

	data[2][0] = vec3->x;
	data[2][1] = vec3->y;
	data[2][2] = vec3->z;	
}

Matrix3f::Matrix3f(Vector3 <float> *vec1, Vector3 <float> *vec2, Vector3 <float> *vec3)
{
	//printf("vec1 = %f %f %f\n", vec1->x, vec1->y, vec1->z);
	data[0][0] = vec1->x;
	data[0][1] = vec1->y;
	data[0][2] = vec1->z;

	//printf("vec2 = %f %f %f\n", vec2->x, vec2->y, vec2->z);
	data[1][0] = vec2->x;
	data[1][1] = vec2->y;
	data[1][2] = vec2->z;

	//printf("vec3 = %f %f %f\n", vec3->x, vec3->y, vec3->z);
	data[2][0] = vec3->x;
	data[2][1] = vec3->y;
	data[2][2] = vec3->z;	

	/*printf("Matrix init:\n");
	printf("%f %f %f\n", data[0][0], data[0][1], data[0][2]);
	printf("%f %f %f\n", data[1][0], data[1][1], data[1][2]);
	printf("%f %f %f\n", data[2][0], data[2][1], data[2][2]);
	printf("end\n");*/
}

Matrix3f::Matrix3f(float* dataNew) // i am to lazy
{
	data[0][0] = dataNew[0];
	data[0][1] = dataNew[1];
	data[0][2] = dataNew[2];

	data[1][0] = dataNew[3];
	data[1][1] = dataNew[4];
	data[1][2] = dataNew[5];

	data[2][0] = dataNew[6];
	data[2][1] = dataNew[7];
	data[2][2] = dataNew[8];
}

Matrix3f::Matrix3f(void) // i am tooooo lazy
{
	data[0][0] = 0;
	data[0][1] = 0;
	data[0][2] = 0;

	data[1][0] = 0;
	data[1][1] = 0;
	data[1][2] = 0;

	data[2][0] = 0;
	data[2][1] = 0;
	data[2][2] = 0;
}


template <typename typeOfData> 
void Vector3<typeOfData>::multiplyOnMatrix(Matrix3f *mat)
{
	typeOfData tmpX = mat->data[0][0] * x + mat->data[0][1] * y + mat->data[0][2] * z;
	typeOfData tmpY = mat->data[1][0] * x + mat->data[1][1] * y + mat->data[1][2] * z;
	typeOfData tmpZ = mat->data[2][0] * x + mat->data[2][1] * y + mat->data[2][2] * z;

	x = tmpX;
	y = tmpY;
	z = tmpZ;	
}



