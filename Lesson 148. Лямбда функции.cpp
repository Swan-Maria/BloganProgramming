/*
План уроку:
1) Про що буде урок?
2) Що таке функтор?
3) Що таке лямбда-функція?
// Лямбда-функція - це анонімна функція, яка може бути визначена в місці її використання
4) Де можуть використовуватися лямбда-функції?
5) Лямбда-функції без параметрів і повертаючого значення
6) Параметри лямбда-функцій
7) Повертаюче значення лямбда-функцій
8) Об'єкт для зберігання лямбда-функції
9) Узагальнені (шаблонні) лямбда-функції
10) Список захвату в лямбда-функції
11) Ключове слово mutable в лямбда-функції
12) Подяка
*/

#include <iostream>
#include <cmath>
// Функтор - це об'єкт, який може бути викликаний як функція

//class Sum
//{
//public:
//    int operator()(int a, int b) const
//    {
//		return a + b;
//    }
//};
//
//template<typename LambdaFunction>
//void Test(LambdaFunction function)
//{
//	//int arr[] = { 1, 2, 3, 4, 5 };
//	//function(arr, 5);
//	int sum = function(10, 20);
//	std::cout << "Sum: " << sum << std::endl;
//}
//
//template <typename T, typename Func>
//void ForAllElements(T* arr, size_t size, Func func)
//{
//	for (size_t i = 0; i < size; i++)
//	{
//		func(arr[i]);
//	}
//	std::cout << std::endl;
//}

//Список захвату в лямбда-функції
int globalVariable = 10;

class MyClass
{
public:
	static int staticClassField;
};

int MyClass::staticClassField = 20;

class LambdaRealization
{
private:
	int functionParameter;
public:
	LambdaRealization( int& functionParameter) 
		: functionParameter(functionParameter){}
	void operator()()
		{
		std::cout << "Function parameter = " << functionParameter << std::endl;
		functionParameter = 100;
		std::cout << "Function parameter = " << functionParameter << std::endl;
	}
};

void Func(int functionParameter)
{
	int localVariable = 234;	
	std::cout << "Func -> functionParameter = " << functionParameter << std::endl;
	auto lambda = [functionParameter]() mutable
		{
			std::cout << "Function parameter = " << functionParameter << std::endl;
			functionParameter = 100;
			std::cout << "Function parameter = " << functionParameter << std::endl;
		};
	lambda();
	std::cout << "Func -> functionParameter = " << functionParameter << std::endl;
}

//class NewMyClass
//{
//private:
//	int field1 = 10;
//	double	field2 = 20.23456;
//public:
//	void Method()
//	{
//		auto show = [this]()
//			{
//				std::cout << "field1 = " << field1 << std::endl;
//				std::cout << "field2 = " << field2 << std::endl;
//			};
//		show();
//	}
//};

int main()
{
	//// Функтор
    //int num1 = 10, num2 = 20;
	//int sum = Sum()(num1, num2);
	//// Лямбда-функція
    //// Синтаксис створення лямбда-функції:
    //// [Список_даних_для_захвату](Список_Параметрів){ Код_Функції }
    //// Лямбда-функція без параметрів і повертаючого значення
	//[]() {};// Компілятор під капотом створює клас з унікальним ім'ям, який реалізує перезавантаження оператору () і без параметрів.
	//int sum = [](int num1, int num2) { return num1 + num2; }(num1, num2);
	//std::cout << "Sum: " << sum << std::endl;

	//// Використання лямбда-функції
	//int arr[] = { 1, 2, 3, 4, 5 };
	//ForAllElements(arr, 5, [](int num) { return num; }); //виводиться 1 2 3 4 5
	//ForAllElements(arr, 5, [](int num) { return num * 2; }); //выводится 2 4 6 8 10

	////Лямбда-функції без параметрів і повертаючого значення
	//Test([]() { });

	//// Параметри лямбда-функцій
	//Test([](int arr[], size_t size) 
	//	{
	//		for (size_t i = 0; i < size; i++)
	//		{
	//			std::cout << arr[i] << "\n";
	//		}
	//	});

	//// Повертаюче значення лямбда-функцій
	//// [](parameters list) -> data_type{code}
	//Test([](int a, int b) -> int
	//	{
	//		std::cout << "Hello from lambda" << std::endl;
	//		return a + b;
	//	});

	////// Об'єкт для зберігання лямбда-функції
	////auto myLambda = []() {};
	////myLambda();
	//const size_t SIZE1 = 3;
	//int arr1[SIZE1] = { 1, 2, 3 };
	//const size_t SIZE2 = 3;
	//double arr2[SIZE2] = { 1, 2, 3 };
	//const size_t SIZE3 = 3;
	//char arr3[SIZE3] = { 1, 2, 3 };
	//auto showCube = [](int num) { std::cout << std::pow(num,3) << " "; };
	//auto showSqrt = [](int num) { std::cout << std::sqrt(num)  << " "; };
	//auto show = [](auto element) { std::cout << element << " "; };
	//ForAllElements(arr1, SIZE1, showCube);
	//ForAllElements(arr2, SIZE2, showCube);
	//ForAllElements(arr1, SIZE1, showSqrt);
	//ForAllElements(arr2, SIZE2, showSqrt);
	//ForAllElements(arr1, SIZE1, show);
	//ForAllElements(arr2, SIZE2, show);
	//ForAllElements(arr3, SIZE3, show);

	//////Список захвату в лямбда-функції
	//auto lambdaValue = [=]() //передает все внешние по значению
	//	{};
	//auto lambdaReference = [&]() //передает все внешние по ссылке
	//	{};
	//NewMyClass myObject;
	//myObject.Method();



    return 0;
}
