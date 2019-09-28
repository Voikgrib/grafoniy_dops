
//
// This lib realize 2d vector
//

template <typename typeOfData> 
class Vector2
{
	public:
	typeOfData x;
	typeOfData y;

	Vector2();
	Vector2(typeOfData newX, typeOfData newY);
	Vector2<typeOfData>& operator= (const Vector2<typeOfData>& fromVec);
};

template <typename typeOfData> 
Vector2<typeOfData>::Vector2()
{
	x = 0;
	y = 0;
}


template <typename typeOfData> 
Vector2<typeOfData>::Vector2(typeOfData newX, typeOfData newY)
{
	x = newX;
	y = newY;
}

template <typename typeOfData> 
Vector2<typeOfData>& Vector2<typeOfData>::operator= (const Vector2<typeOfData>& fromVec)
{
	x = fromVec.x;
	y = fromVec.y;
	
	return *this;
}


