
//
// This lib realize 4d vector
//

class Matrix4f;

template <typename typeOfData> 
class Vector4
{
	public:
	typeOfData x;
	typeOfData y;
	typeOfData z;
	typeOfData w;

	Vector4();
	Vector4(typeOfData newX, typeOfData newY, typeOfData newZ, typeOfData newW);
	Vector4<typeOfData>& operator= (const Vector4<typeOfData>& fromVec);
	void setCoords(typeOfData newX, typeOfData newY, typeOfData newZ, typeOfData newW);
	void from3Dto4D (const Vector3<typeOfData>& fromVec);
	//void setProection(const Vector3<typeOfData>& fromVec);
	void multiplyOnMatrix(Matrix4f *mat);

	template <typename typeOfData1> 
	friend const Vector4 <typeOfData1> operator-(const Vector4 <typeOfData1> &vec1, const Vector4 <typeOfData1> &vec2);

	template <typename typeOfData1> 
	friend const Vector4 <typeOfData1> operator+(const Vector4 <typeOfData1> &vec1, const Vector4 <typeOfData1> &vec2);
};

template <typename typeOfData> 
Vector4<typeOfData>::Vector4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}


template <typename typeOfData> 
Vector4<typeOfData>::Vector4(typeOfData newX, typeOfData newY, typeOfData newZ, typeOfData newW)
{
	x = newX;
	y = newY;
	z = newZ;
	w = newW;
}

template <typename typeOfData> 
Vector4<typeOfData>& Vector4<typeOfData>::operator= (const Vector4<typeOfData>& fromVec)
{
	x = fromVec.x;
	y = fromVec.y;
	z = fromVec.z;
	w = fromVec.w;
	
	return *this;
}

template <typename typeOfData> 
void Vector4<typeOfData>::setCoords(typeOfData newX, typeOfData newY, typeOfData newZ, typeOfData newW)
{
	x = newX;
	y = newY;
	z = newZ;
	w = newW;
}

template <typename typeOfData> 
void Vector4<typeOfData>::from3Dto4D (const Vector3<typeOfData>& fromVec)
{
	x = fromVec.x;
	y = fromVec.y;
	z = fromVec.z;
	w = 1;
}
/*
template <typename typeOfData>
void Vector4<typeOfData>::setProection(const Vector3<typeOfData>& fromVec)
{
	float ep = - (BUFFER_N / SCREEN_LENGH) * (fromVec.x / fromVec.z);
	float ny = - (BUFFER_N / SCREEN_HIGH) * (fromVec.y / fromVec.z);
	float c1 = (BUFFER_N_MAX - BUFFER_N) / (BUFFER_N_MAX + BUFFER_N);
	float c2 = 2 * BUFFER_N_MAX * BUFFER_N / (BUFFER_N_MAX - BUFFER_N);
	float ci = c1 * fromVec.z + c2;

	x = fromVec.z * ep;
	y = fromVec.z * ny;
	z = fromVec.z * ci;
	w = fromVec.z;
}
//*/
template <typename typeOfData1> 
const Vector4 <typeOfData1> operator-(const Vector4 <typeOfData1> &vec1, const Vector4 <typeOfData1> &vec2)
{
	return Vector4 <typeOfData1> 
	(
		vec1.x - vec2.x,
		vec1.y - vec2.y,
		vec1.z - vec2.z,
		vec1.w - vec2.w
	);
}

template <typename typeOfData1> 
const Vector4 <typeOfData1> operator+(const Vector4 <typeOfData1> &vec1, const Vector4 <typeOfData1> &vec2)
{
	return Vector4 <typeOfData1> 
	(
		vec1.x - vec2.x,
		vec1.y - vec2.y,
		vec1.z - vec2.z,
		vec1.w - vec2.w
	);
}









