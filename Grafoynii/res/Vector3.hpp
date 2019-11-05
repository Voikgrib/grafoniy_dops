
//
// This library realise 3d vector & some sheet with it
//

class Matrix3f;

template <typename typeOfData>
class Vector4;

template <typename typeOfData> 
class Vector3
{
	public:
	typeOfData x;
	typeOfData y;
	typeOfData z;

	Vector3();
	Vector3(typeOfData newX, typeOfData newY, typeOfData newZ);
	Vector3(Vector3 <typeOfData> *vec1, Vector3 <typeOfData> *vec2); // vec multiply init
	Vector3<typeOfData>& operator= (const Vector3<typeOfData>& fromVec);
	void setCoords(typeOfData newX, typeOfData newY, typeOfData newZ);
	void normalize(void);
	void multiplyOnMatrix(Matrix3f *mat);
	void sub(Vector3<typeOfData>* vec);
	void from4Dto3D(const Vector4<typeOfData> &fromVec);

	template <typename typeOfData1> 
    friend const Vector3 <typeOfData1> operator*(const Vector3 <typeOfData1> &vec1, const Vector3 <typeOfData1> &vec2);

	template <typename typeOfData1> 
	friend const Vector3 <typeOfData1> operator-(const Vector3 <typeOfData1> &vec1, const Vector3 <typeOfData1> &vec2);

	template <typename typeOfData1> 
	friend const Vector3 <typeOfData1> operator+(const Vector3 <typeOfData1> &vec1, const Vector3 <typeOfData1> &vec2);

};

template <typename typeOfData> 
void Vector3<typeOfData>::sub(Vector3<typeOfData>* vec)
{
	x -= vec->x;
	y -= vec->y;
	z -= vec->z;
}

template <typename typeOfData> 
void Vector3<typeOfData>::normalize(void)
{
	float k = sqrtf(x*x + y*y + z*z);
	x = x / k;
	y = y / k;
	z = z / k;
}

template <typename typeOfData> 
Vector3<typeOfData>::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}

template <typename typeOfData> 
Vector3<typeOfData>::Vector3(typeOfData newX, typeOfData newY, typeOfData newZ)
{
	x = newX;
	y = newY;
	z = newZ;
	//printf("construcror %f %f %f\n", x, y, z);
}

template <typename typeOfData> 
Vector3<typeOfData>& Vector3<typeOfData>::operator= (const Vector3<typeOfData>& fromVec)
{
	x = fromVec.x;
	y = fromVec.y;
	z = fromVec.z;
	
	return *this;
}

template <typename typeOfData> 
void Vector3<typeOfData>::setCoords(typeOfData newX, typeOfData newY, typeOfData newZ)
{
	x = newX;
	y = newY;
	z = newZ;
}

template <typename typeOfData> 
Vector3<typeOfData>::Vector3(Vector3 <typeOfData> *vec1, Vector3 <typeOfData> *vec2) // vec multiply init
{
	//printf("vec1 in init vector = %f %f %f\n", vec1->x, vec1->y, vec1->z);	
	//printf("vec2 in init vector = %f %f %f\n", vec2->x, vec2->y, vec2->z);
	//printf("preinit vector = %f %f %f\n", x, y, z);
	x = 0;
	y = 0;
	z = 0;
	x = (vec1->y * vec2->z) - (vec2->y * vec1->z);
	y = - (vec1->x * vec2->z) + (vec2->x * vec1->z);
	z = (vec1->x * vec2->y) - (vec2->x * vec1->y);

	//printf("init vector = %f %f %f\n", x, y, z);
}

template <typename typeOfData1> 
const Vector3 <typeOfData1> operator*(const Vector3 <typeOfData1> &vec1, const Vector3 <typeOfData1> &vec2)
{
	return Vector3 <typeOfData1>
	(
		((vec1.y * vec2.z) - (vec2.y * vec1.z)), 
		( - (vec1.x * vec2.z) + (vec2.x * vec1.z)),	
		((vec1.x * vec2.y) - (vec2.x * vec1.y))
	);

}

template <typename typeOfData1> 
const Vector3 <typeOfData1> operator-(const Vector3 <typeOfData1> &vec1, const Vector3 <typeOfData1> &vec2)
{
	return Vector3 <typeOfData1> 
	(
		vec1.x - vec2.x,
		vec1.y - vec2.y,
		vec1.z - vec2.z
	);
}

template <typename typeOfData1> 
const Vector3 <typeOfData1> operator+(const Vector3 <typeOfData1> &vec1, const Vector3 <typeOfData1> &vec2)
{
	return Vector3 <typeOfData1> 
	(
		vec1.x + vec2.x,
		vec1.y + vec2.y,
		vec1.z + vec2.z
	);
}

template <typename typeOfData> 
void Vector3<typeOfData>::from4Dto3D(const Vector4<typeOfData> &fromVec)
{
	if(fromVec.w != 0)
	{
		x = fromVec.x / fromVec.w;
		y = fromVec.y / fromVec.w;
		z = fromVec.z / fromVec.w;
	}
	else
	{
		x = 0;
		y = 0;
		z = 0;
	}
}




