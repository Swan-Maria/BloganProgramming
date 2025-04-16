#pragma once
#define _NODISCARD [[nodiscard]]

template <class T>
struct auto_ptr_ref
{
	T* reference;
	explicit auto_ptr_ref(T* other) : reference(other) {}
};

template <class T>
class auto_ptr
{
private:
#pragma region Поля
	T* pointer;
#pragma endregion
public:
#pragma region Псевдоніми
	using element_type = T;
#pragma endregion 

#pragma region Конструтори
	explicit auto_ptr(T* ptr = nullptr) noexcept : pointer(ptr) {}
	auto_ptr(auto_ptr& other) noexcept : pointer(other.release()) {}
	auto_ptr(auto_ptr_ref<T> other) noexcept
	{
		T* ptr = other.reference();
		other.reference() = nullptr;
		pointer = ptr;
	}
	template <class _Other>
	auto_ptr(auto_ptr<_Other>& other) noexcept : pointer(other.release()) {}
#pragma endregion

#pragma region Деструтори
	~auto_ptr() noexcept { delete pointer; }
#pragma endregion 

#pragma region Методи
	_NODISCARD T* get() const noexcept { return pointer; }
	T* release() noexcept
	{
		T* temp = pointer;
		pointer = nullptr;
		return temp;
	}
	void reset(T* ptr = nullptr) noexcept
	{
		if (pointer != ptr)
		{
			delete pointer;
		}
		pointer = ptr;
	}
#pragma endregion 

#pragma region Перезавантажені оператори
	template <class OtherT>
	operator auto_ptr<OtherT>() noexcept{return auto_ptr<OtherT>(*this);}
	
	template <class OtherT>
	operator auto_ptr_ref<OtherT>() noexcept
	{
		OtherT* temp = pointer;
		auto_ptr_ref<OtherT> result(temp);
		pointer = nullptr;
		return result;
	}

	template <class OtherT>
	auto_ptr& operator=(auto_ptr<OtherT>& other) noexcept
	{
		reset(other.release());
		return *this;
	}

	auto_ptr& operator=(auto_ptr& other) noexcept
	{
		reset(other.release());
		return *this;
	}

	auto_ptr& operator=(auto_ptr_ref<T> other) noexcept
	{
		T* ptr = other.reference;
		other.reference = 0;
		reset(ptr);
		return *this;
	}

	_NODISCARD T& operator*() const noexcept
	{
#if _ITERATOR_DEBUG_LEVEL == 2
		_STL_VERIFY(pointer, "auto_ptr not dereferenceable");
#endif
		return *get();
	}

	_NODISCARD T* operator->() const noexcept
	{
#if _ITERATOR_DEBUG_LEVEL == 2
		_STL_VERIFY(pointer, "auto_ptr not dereferenceable");
#endif
		return get();
	}
#pragma endregion 

};

//Спеціалізація шаблону для типу void
template <>
class auto_ptr<void>
{
public:
	using element_type = void;
};