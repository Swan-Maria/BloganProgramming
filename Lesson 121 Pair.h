#pragma once

template <typename T1, typename T2>
class Pair
{
private:
	T1 object1;
	T2 object2;
public:
	Pair(const T1& object1, const T2& object2);
	T1& GetObject1() ;
	T2& GetObject2() ;
};

template<typename T1, typename T2>
inline Pair<T1, T2>::Pair(const T1& object1, const T2& object2)
	:object1(object1), object2(object2) {}

template<typename T1, typename T2>
inline T1& Pair<T1, T2>::GetObject1() 
{
	return object1;
};

template<typename T1, typename T2>
inline T2& Pair<T1, T2>::GetObject2() 
{
	return object2;
};