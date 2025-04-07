/// [+] 1. Что такое контейнер?
	/// Контейнер - это класс, который хранит в себе другие классы.
/// [+] 2. Какие бывают контейнеры?
/// [+] 3. Почему сначала vector? 
/// [+] 4. Схема роботы vector
	/// Все элементы вектора хранятся в одном непрерывном блоке памяти (масиве).
	/// Вектор имеет:
	/// размер, который равен количеству элементов в нем;
	/// и capacity (емкость), которая равна количеству элементов, которые 
	/// вектор может хранить в данный момент.
/// [+] 5. Конструкторы
/// [+] 6. Деструктор
/// [+] 7. Методы
/// [+] 8. Глобальные перегрузки операторов и функций
/// [+] 9. Псевдонимы контейнера
/// [+] 10. Использоваине собсвтенного класса в vector
/// [+] 11. Использование указателей в vector
/// [+] 12. Оценка операций по О-нотации
/// [+] 13. Специализация шаблонов типа bool
/// [+] 14. Цикл for по диапазону

#include <iostream>
#include <vector>

class Person
{
public:
	Person()									: age(1), name("Unknown")			{ std::cout << "Default constructor\n"; }
	Person(int age, const std::string& name)	: age(age), name(name)				{ std::cout << "2param constructor\n"; }
	Person(const Person& other)					: age(other.age), name(other.name)	{ std::cout << "Copy constructor\n"; }
	Person(Person&& other) noexcept				: age(other.age), name(other.name)	{ std::cout << "Move constructor\n"; }
	
	Person& operator=(const Person& other)		{ std::cout << "copy operator=\n"; age = other.age; name = other.name; return *this; }
	Person& operator=(Person&& other) noexcept	{ std::cout << "move operator=\n"; age = other.age; name = other.name; return *this; }
	
	~Person() { std::cout << "Destructor\n"; }
	void ShowInfo() const { std::cout << "(age = " << age << ", name = " << name << ")\n"; }
private:
	int age;
	std::string name;
};

void Show(const std::vector<int>& vector);

void AllConteiners();
void Constructors();
void Destructor();
void Methods();
void GlobalOperatorsAndFunctions();
void ContainerAliases();
void OwnClassInVector();
void PointersInContainer();
void ONotation();
void BoolSpecialization();
void ForLoop();

int main()
{
	//AllConteiners();
	//Constructors();
	//Destructor();
	//Methods();
	//GlobalOperatorsAndFunctions();
	//ContainerAliases();
	//OwnClassInVector();
	//PointersInContainer();
	//DNotation();
	//BoolSpecialization();
	//ForLoop();

	return 0;
}

void Show(const std::vector<int>& vector)
{
	std::cout << "--- VECTOR INFO ---\n";
	std::cout << "Elements: ";
	if (vector.empty())
		std::cout << "None";
	else
	{
		for (size_t i = 0; i < vector.size(); i++)
			std::cout << vector[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Size = " << vector.size() << std::endl;
	std::cout << "Capacity = " << vector.capacity() << std::endl;
	std::cout << "----------------------\n";
}

void AllConteiners()
{
	/*
	Контейнеры STL делятся на три основные категории :

		Последовательные (Sequence) контейнеры:
		1. [+] vector
		2. [ ] deque
		3. [ ] list
		4. [ ] forward_list
		5. [ ] array
		6. [ ] basic_string

		Ассоциативные (Associative) контейнеры:
		7. [ ] set
		8. [ ] multiset
		9. [ ] map
		10. [ ] multimap

		Неупорядоченные ассоциативные (Unordered Associative) контейнеры:
		11. [ ] unordered_set
		12. [ ] unordered_multiset
		13. [ ] unordered_map
		14. [ ] unordered_multimap

		Контейнерные адаптеры (Container Adapters):
		15. [ ] stack
		16. [ ] queue
		17. [ ] priority_queue

		18. В стандарте С++20 добавлен еще один особенный контейнер 
		span.
	*/
}

void Constructors()
{
	std::cout << "----- CONSTRUCTOR -----\n";

	// 1. Конструктор по умолчанию
	std::vector <int> v1;
	Show(v1);
	 // 2. Конструктор по умолчанию, который принимает пользовательский аллокатор
	std::allocator<int> myAllocator;
	std::vector<int> v2(myAllocator);
	Show(v2);

	// 3. Конструктор, который принимает std::initializer_list
	std::vector<int> v3{ 1,2,3,4,5,6,7,8,9,10 };
	Show(v3);

	// 4. Конструктор копии
	std::vector<int> v4(v3);
	Show(v4);

	// 5. Конструктор перемещения
	std::vector<int> v5(std::move(v4));
    Show(v4);
	Show(v5);

	// 6. Конструктор, который принимает количество элементов
	std::vector<int> v6(10);
	Show(v6);
	
	// 7. Конструктор, который принимает количество элементов и их значение
	std::vector<int> v7(3, 100);
	Show(v7);

	// 8. Конструктор, который принимает два интератора
	std::vector<int> v8(v5.begin(), v5.begin() + 4);
	Show(v8);
}

void Destructor()
{
	std::cout << "----- DESTRUCTOR -----\n";
	// У класса vector есть деструктор, в котором вся память под выделенные элементы на куче
	// автоматически освободжается/удаляется. Исчезает необходимость вызывать деструкктор явно.
	std::vector<Person> vector(2);
}

void Methods() 
{
    std::cout << "----- METHODS -----\n\n";
    std::vector<int> vector { 10, 20, 500, 5, 0 };

    // 1. front повертає посилання на перший елемент.
    std::cout << "vector[0] = " << vector.front() << std::endl;
    vector.front() = 100;
    std::cout << "vector[0] = " << vector.front() << std::endl;

    // 2. back повертає посилання на останній елемент.
    std::cout << "vector[4] = " << vector.back() << std::endl;
    vector.back() = 123;
    std::cout << "vector[4] = " << vector.back() << std::endl;

    // 3. data повертає вказівник на внутрішний масив контейнеру.
    int* ptr = vector.data();
    std::cout << "vector[2] = " << vector[2] << std::endl;

    // 4. operator[] повертає посилання на елемент за заданим індексом.
    std::cout << "vector[3] = " << vector[3] << std::endl;

    // 5. at - повертає посилання на елемент за заданим індексом. Кидає виключення 
    //         типу std::out_of_range, якщо індекс виходить за границі масиву.
    try
    {
        vector.at(100) = 1000;
    }
    catch (const std::out_of_range& exc)
    {
        std::cout << exc.what() << std::endl;
    }

    // 6. get_allocator - повертає алокатор, який прив'язаний до контейнера.
    auto allocator = vector.get_allocator();

    // 7. operator= - дозволяє переписувати вміст вектора новими значенями.
    vector = { 1, 2, 3, 4, 5 };         // std::initializer_list
    vector = std::vector<int>(18, 1);   // move =
    vector = vector;                    // copy =
        
    // 8. assign - дозволяє переписувати вміст вектора новими значенями.
    //              Схожий на оператор =, але має більше можливостей, бо може приймати
    //              більше одного параметру.
    vector.assign(5, 100);                          // 5 елементів, значення кожного 100
    vector.assign({ 1, 2, 3, 4, 5 });               // std::initializer_list
    vector.assign(vector.cbegin(), vector.cend());  // діапазон значень через значень
    
    // 9. begin - повертає ітератор на перший елемент контейнеру. Елемент можна міняти через ітератор.
    std::cout << "*vector.begin() = " << *vector.begin() << std::endl;
    *vector.begin() = 1000;
    std::cout << "*vector.begin() = " << *vector.begin() << std::endl;
    
    // 10. cbegin - повертає константний ітератор на перший елемент контейнеру. Елемент НЕ можне міняти через ітератор.
    std::cout << "*vector.cbegin() = " << *vector.cbegin() << std::endl;
    //*vector.cbegin() = 1000;
    
    // 11. end - повертає ітератор на кінець діапазону елементів. Кінець - це маступний елемент за останнім.
    //           Простими словами це мітке кінця послідовності елементів.
    for (auto iter = vector.begin(); iter != vector.end(); ++iter)
    {
        *iter *= 2;
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
    
    // 12. cend - повертає константний ітератор на кінець діапазону елементів.
    for (auto iter = vector.cbegin(); iter != vector.cend(); ++iter)
    {
        //iter *= 2;
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
    
    // 13. rbegin
    
    // 14. rend - повертає обернений ітератор на останній елемент контейнеру. Відмінність від begin наступна:
    //            якщо написати до ітератора, який повертає метод begin, то ітератор переміститься вправо,
    //            але якщо написати до ітератора, який повертає метод rbegin, то ітератор переміститься вліво.
    //            така же аналогія, як в rbegin до begin, тільки до методу end.
    for (auto iter = vector.rbegin(); iter != vector.rend(); ++iter)
    {
        *iter = 100;
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
    
    // 15. crbegin константний rbegin.
    
    // 16. crend константний rend.
    for (auto iter = vector.crbegin(); iter != vector.crend(); ++iter)
    {
        //*iter = 2;
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
    
    // 17. empty - повертає true, якщо вектор пустий.
    std::cout << "Vector is empty? " << (vector.empty() ? "Yes" : "No") << std::endl;
    
    // 18. size - повертає розмір вектору (кількість елементів, в яких є значення).
    std::cout << "Size = " << vector.size() << std::endl;
    
    // 19. capacity - повертає ємність вектору (кількість елементів, для яких в динамічній пам'яті виділене місце).
    std::cout << "Capacity = " << vector.capacity() << std::endl;
    
    // 20. max_size - повертає максимально можливу кількість елементів.
    std::cout << "Max size = " << vector.max_size() << std::endl;
    
    // 21. reverse - збільшує (резервує) об'єм ємності вектору.
    std::cout << "Capacity = " << vector.capacity() << std::endl;
    vector.reserve(101);
    std::cout << "Capacity = " << vector.capacity() << std::endl;
    
    // 22. shrink_to_fit - зменшує (скорочує) об'єм ємності вектору поближче до розміру.
    vector.shrink_to_fit();
    std::cout << "Capacity = " << vector.capacity() << std::endl;
    
    // 23. clear - очищає вектор, звільняючи пам'ять (викликаючи деструктори) елементів.
    vector.clear();
    std::cout << "Size = " << vector.size() << std::endl;
    std::cout << "Capacity = " << vector.capacity() << std::endl;
    std::cout << "Vector is empty? " << (vector.empty() ? "Yes" : "No") << std::endl;
    
    // 24. insert - вставляє нові значення у вектор в задане місце.
    vector = { 1, 2, 3, 4, 5 };
    vector.insert(vector.cbegin(), { 100, 200 }); // є 5 перезавантажень
    Show(vector);
    
    // 25. emplace - кращий варіант методу insert. Для методу insert значення мають бути створені
    //               в пам'яті ще до вставлення у вектор. А в emplace значення можна будувати прямо у векторі. Метод є варіативним шаблоном.
    vector.emplace(vector.cend(), 1000);
    Show(vector);
    
    // 26. push_back вставити новий елемент в кінець вектору.
    vector.push_back(-111);
    Show(vector);

    // 27. pop_back видалити кінцевий елемент з масиву.
    vector.pop_back();
    Show(vector);
    
    // 28. resize змінює розмір вектору (НЕ синість).
    // Якщо новий розмір менший за попередній, то вектор скорочується до нового розміру.
    // Якщо новий розмір більший за попередній, то у вектор додаються нові елементи зі значеннями.
    std::cout << "size = " << vector.size() << std::endl;
    std::cout << "Capacity = " << vector.capacity() << std::endl;
    Show(vector);
    vector.resize(2);
    Show(vector);
    vector.resize(20);
    Show(vector);
    
    // 29. swap поміняти вміст двох векторів (розмір та ємність)
    std::vector<int> vector1{ 1, 2, 3 };
    std::vector<int> vector2{ 5, 6, 7, 8, 9, 0 };
    Show(vector1);
    Show(vector2);
    vector1.swap(vector2);
    Show(vector1);
    Show(vector2);
    
    // 30. erase видалити елемент/діапазон значень із контейнеру.
    std::vector<int> evenNumbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    Show(evenNumbers);
    evenNumbers.erase(evenNumbers.cend() - 2); // видалити 9
    Show(evenNumbers);
    for (auto iter = evenNumbers.cbegin(); iter != evenNumbers.cend();) // видалити всі непарні значення
    {
        if (*iter % 2 != 0) // якщо число не парне
        {
            iter = evenNumbers.erase(iter);
        }
        else
        {
            ++iter;
        }
    }
    Show(evenNumbers);
    
    // 31. emplace_back - аналогічний до emplace, тільки вставляє в кінець (кращий аналог методу push_back).
    evenNumbers.emplace_back(10);
    evenNumbers.emplace_back(20);
    Show(evenNumbers);
}

void GlobalOperatorsAndFunctions()
{
    // 1. operator== - порівнює вміст контейнерів.
   //                  true якщо контейнери мають однаковий розмір
   //                  і всі їх елементи рівні між собою.
    std::vector<int> vec1 = { 1, 2, 3 };
    std::vector<int> vec2 = { 1, 2, 3 };
    std::vector<int> vec3 = { 1, 2, 3, 4 };
    std::vector<int> vec4 = { 1, 2, 5 };

    if (vec1 == vec2)
        std::cout << "vec1 == vec2\n";
    if (vec1 == vec3) // ні, бо розміри різні
        std::cout << "vec1 == vec3\n";
    if (vec1 == vec4) // ні, бо значення різні
        std::cout << "vec1 == vec4\n";

    // Оператори 2-6 убрані в стандарті С++20. Ви можете самі
    // догадатися, як вони працюють, якщо знаєте, як працює оператор==.
    // 2. operator!=
    // 3. operator<
    // 4. operator<=
    // 5. operator>
    // 6. operator>=
    
    // В стандарті С++20 замість операторів 1-6 появився оператор <=> .
    // Він продуктивніший. Оскільки я не показував його роботу окремо від вектору
    // то й тут його показувати не буду. Це діло за вами.
    // 7. operator==
    
    // 8. std::swap - міняє місцями вміст двох контейнерів. Це спеціалізація шаблону функції std::swap, яка викликає всередині метод vector::swap().
    
    // Ці фунції добавлені в С++20, тому їх оглядати не будемо. Вони видаляють елементи вектору так само,
    // як це робить метод erase.
    // 9. std::erase
    // 10. std::erase_if
}

void ContainerAliases()
{
    // Ці псевдоніми є в кожному контейнері:
   
    /*
    using value_type        = _Ty;
    using allocator_type    = Alloc;
    using pointer           = typename Alty_traits::pointer;
    using const_pointer     = typename Alty_traits::const_pointer;
    using reference         = _Ty&;
    using const_reference   = const _Ty&;
    using size_type         = typename Alty_traits::size_type;
    using difference_type   = typename Alty_traits::difference_type;
    */
   
    // Приклади:
    std::vector<int>::value_type value = 10;               // int value = 10;
    std::vector<int>::const_reference reference = value;   // const int& reference = value;
	std::vector<int>::pointer pointer = &value;            // int* pointer = &value;   // int* pointer = &value;
}

void OwnClassInVector() 
{
    std::vector<Person> people;
    people.push_back(Person());
    people[0].ShowInfo();

    std::cout << "-----------\n";
    
    people.emplace_back(25, "Demian");
    people[1].ShowInfo();
    
    std::cout << "-----------\n";
    
    people.resize(5);
    std::cout << "Size = " << people.size() << std::endl;
    
    std::cout << "-----------\n";
    people.reserve(100);
    
    std::cout << "-----------\n";
    
    for (auto iterator = people.cbegin(); iterator != people.cend(); ++iterator)
            iterator->ShowInfo();
}

void PointersInContainer()
{
    // Якщо ви хочете використовувати прості вказівники, як елементи контейнера, то
    // ви маєте пам'ятати, щоб перед їх знищенням в пам'яті треба звільняти пам'ять
    // на яку вони вказують (якщо вона звісно виділяється через них).
    
    // Розглянемо простий для розуміння приклад:

    std::cout << "-----------------------------\n";
    
    std::vector<Person*> people;
    
    for (int i = 0; i < 5; i++)
        people.push_back(new Person(i, "Demian"));
    
    std::cout << "People:\n";
    
    for (size_t i = 0; i < people.size(); i++)
    {
        std::cout << "\tPerson #" << i << ": ";
        people[i]->ShowInfo();
    }
   
    // Закоментуйте цей код і деструктори не будуть викликатися (а мають!):
    for (size_t i = 0; i < people.size(); i++)
        delete people[i];
   
    std::cout << "-----------------------------\n";

    // Щоб не мучатися з простими вказівниками, використовуйте розумні вказівники:
    std::vector<std::unique_ptr<Person>> people2;
    for (int i = 0; i < 5; i++)
    {
        people2.push_back(std::unique_ptr<Person>(new Person(i, "Demian"))); // Виправлено тут
    }
    std::cout << "People:\n";
    for (size_t i = 0; i < people2.size(); i++)
    {
        std::cout << "\tPerson #" << i << ": ";
        people2[i]->ShowInfo();
    }
}

void ONotation()
{
    /*
    Constructors:
        vector<T> v;                O(1)
        vector<T> v(n);             O(n)
        vector<T> v(n, value);      O(n)
        vector<T> v(begin, end);    O(n)
    
    Accessors:
        v[i];         O(1)
        v.at(i);      O(1)
        v.size();     O(1)
        v.empty();    O(1)
        v.begin();    O(1)
        v.end();      O(1)
        v.front();    O(1)
        v.back();     O(1)
        v.capacity(); O(1)
    
    Modifiers:
        v.push_back(value);         O(1) (Амортизована складність)
        v.pop_back();               O(1)
        v.insert(iterator, value);  O(n)
        v.erase(iterator);          O(n)
        v.erase(begin, end);        O(n)
   
    Підсумок:
        Вставка:        в кінець -> Амортизована O(1), в любе інше місце O(n)
        Доступ:         O(1)
        Видалення:      з кінця O(1), з любого іншого місяця O(n)
        Пошук:          O(n) 
    */
}

void BoolSpecialization()
{
    std::vector<bool> flags{ false, true, false, true }; // 0, 1, 0, 1

    for (size_t i = 0; i < flags.size(); i++)
        std::cout << flags[i] << " ";
    std::cout << std::endl;

    flags.flip();
    
    for (size_t i = 0; i < flags.size(); i++)
        std::cout << flags[i] << " ";
    std::cout << std::endl;
}

void ForLoop()
{
    std::vector<int> numbers{ 1, 10, 100, 1000, 100, 10, 1 };

    // По контейнеру можна пройтися завдяки оператору []:
    for (size_t i = 0; i < numbers.size(); i++)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;
    
    // Але не у всіх контейнерів є перезавантажений оператор[]. В такому
    // випадку можна скористатися ітераторами (вони є у всіх контейнерів):
    for (auto iter = numbers.begin(); iter != numbers.end(); ++iter)
        std::cout << *iter << " ";
    std::cout << std::endl;
    
    // Але код зверху виглядає громістким. Тому зі стандарту С++11 можна скористатися
    // циклом for по діапазону. Я вас з ним знайомив в уроці №35.
    for (auto number : numbers)
        std::cout << number << " ";
    std::cout << std::endl;
    // УВАГА: в рядку №552 замість ключового слова auto ставиться int. Якщо ви хочете
    //        працювати з класами, які громісткі, то краще писати auto& або const auto&.
    //        Я не використовую auto, коли назва типу проста. Наприклад тут я би написав
    //        for (int number: numbers) { ... }.
}
