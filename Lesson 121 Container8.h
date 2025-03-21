#pragma once

template <typename T>
class Container8
{
private:
	T arr[8];
public:
	Container8() 
		:arr{}
	{}
	T& operator[](size_t index);
	const T& operator[](size_t index)const;
};

template<typename T>
inline T& Container8<T>::operator[](size_t index)
{
	return arr[index];
}

template<typename T>
inline const T& Container8<T>::operator[](size_t index) const
{
	return arr[index];
}


///--------------------------------------------------------------

template <>
class Container8<bool>
{
private:
	unsigned char arr;
public:
	Container8();
	/*	:arr{}
	{}*/
	bool operator[](size_t index);
	/*{
		return (arr >> index)&1;
	}*/
	const bool operator[](size_t index)const;
	/*{
		return (arr >> index) & 1;
	}*/
};


Container8<bool>::Container8()
	:arr{}
{}

inline bool Container8<bool>::operator[](size_t index)
{
	return (arr >> index) & 1;
}

inline const bool Container8<bool>::operator[](size_t index) const
{
	return (arr >> index) & 1;
}