#include <iostream>
#include <memory>

class MyClass
{
public:
	void Method()
	{
		std::cout << "MyClass::Method()" << std::endl;
	}
	MyClass()
	{
		std::cout << "Constructor MyClass" << std::endl;
	}
	~MyClass()
	{
		std::cout << "Destructor MyClass" << std::endl;
	}
};

void MyDeleterF(int* ptr)
{
	std::cout << "MyDeleterF" << std::endl;
	delete ptr;
}

struct MyDeleterC
{
	void operator()(int* ptr)
	{
		std::cout << "MyDeleterC" << std::endl;
		delete ptr;
	}
};

void Show(const std::unique_ptr<int>& ptr)
{
	std::cout << *ptr << std::endl;
}

void ShowAndDelete(std::unique_ptr<int> ptr)
{
	std::cout << *ptr << std::endl;
}

int* CreateArray1()
{
	std::cout << "Enter size of array:";
	size_t size;
	std::cin >> size;
	return new int[size];
}

std::unique_ptr<int[]> CreateArray2()
{
	std::cout << "Enter size of array:";
	size_t size;
	std::cin >> size;
	std::unique_ptr<int[]> arr{ new int[size] };
	return arr;
}


int main()
{

#pragma region Конструторы
	{
		std::unique_ptr<int> ptr1; 
		std::unique_ptr<int> ptr2 { nullptr }; 
		std::unique_ptr<int> ptr3 { new int{5} }; 
		std::unique_ptr<int, void(*)(int*)>ptr4{ new int{ 5 }, MyDeleterF };
		std::unique_ptr<int, MyDeleterC>ptr5{ new int{ 5 }, MyDeleterC()};
		std::unique_ptr<int> ptr7 { std::move(ptr2) };
		std::unique_ptr<int>();
	}
#pragma endregion

# pragma region Перегрузка операторов
	{
		std::unique_ptr<MyClass> ptr{ new MyClass{} };
		std::unique_ptr<MyClass> ptr2;
		ptr.operator->();
		ptr.operator*();
		ptr.operator bool();
		ptr.operator=(nullptr);
		ptr2.operator=(std::move(ptr));
	}
#pragma endregion

# pragma region Методы
	{
		std::unique_ptr<MyClass> ptr1{ new MyClass{} };
		std::unique_ptr<MyClass> ptr2;
		ptr1.get();
		ptr1.get()->Method();
		ptr1.get_deleter();
		ptr1.reset();
		ptr1.release();
		ptr1.swap(ptr2);
	}
#pragma endregion

#pragma region Масивы
	{
		std::unique_ptr<int[]> arr{ new int[5] { 1, 2, 3, 4, 5 } };
		arr.get()[0] = 10;
		for (int i = 0; i < 5; ++i)
		{
			std::cout << arr.get()[i] << std::endl;
		}
		arr.get_deleter();
		arr.reset();
		arr.release();
		arr.swap(arr);
		arr.operator bool();
		arr.operator=(nullptr);
		arr.operator=(std::move(arr));
		arr.operator[](0);
	}
#pragma endregion

#pragma region Відправлення та повернення з функції
	{
		std::unique_ptr<int> ptr1{ new int{5} };
		Show(ptr1);
		ShowAndDelete(std::move(ptr1));
		std::unique_ptr<int[]> ptr2{ CreateArray1() };
		std::unique_ptr<int[]> ptr2{ CreateArray2() };

	}
#pragma endregion
	return 0;
}