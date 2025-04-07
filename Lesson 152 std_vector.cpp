/// [+] 1. ��� ����� ���������?
	/// ��������� - ��� �����, ������� ������ � ���� ������ ������.
/// [+] 2. ����� ������ ����������?
/// [+] 3. ������ ������� vector? 
/// [+] 4. ����� ������ vector
	/// ��� �������� ������� �������� � ����� ����������� ����� ������ (������).
	/// ������ �����:
	/// ������, ������� ����� ���������� ��������� � ���;
	/// � capacity (�������), ������� ����� ���������� ���������, ������� 
	/// ������ ����� ������� � ������ ������.
/// [+] 5. ������������
/// [+] 6. ����������
/// [+] 7. ������
/// [+] 8. ���������� ���������� ���������� � �������
/// [+] 9. ���������� ����������
/// [+] 10. ������������� ������������ ������ � vector
/// [+] 11. ������������� ���������� � vector
/// [+] 12. ������ �������� �� �-�������
/// [+] 13. ������������� �������� ���� bool
/// [+] 14. ���� for �� ���������

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
	���������� STL ������� �� ��� �������� ��������� :

		���������������� (Sequence) ����������:
		1. [+] vector
		2. [ ] deque
		3. [ ] list
		4. [ ] forward_list
		5. [ ] array
		6. [ ] basic_string

		������������� (Associative) ����������:
		7. [ ] set
		8. [ ] multiset
		9. [ ] map
		10. [ ] multimap

		��������������� ������������� (Unordered Associative) ����������:
		11. [ ] unordered_set
		12. [ ] unordered_multiset
		13. [ ] unordered_map
		14. [ ] unordered_multimap

		������������ �������� (Container Adapters):
		15. [ ] stack
		16. [ ] queue
		17. [ ] priority_queue

		18. � ��������� �++20 �������� ��� ���� ��������� ��������� 
		span.
	*/
}

void Constructors()
{
	std::cout << "----- CONSTRUCTOR -----\n";

	// 1. ����������� �� ���������
	std::vector <int> v1;
	Show(v1);
	 // 2. ����������� �� ���������, ������� ��������� ���������������� ���������
	std::allocator<int> myAllocator;
	std::vector<int> v2(myAllocator);
	Show(v2);

	// 3. �����������, ������� ��������� std::initializer_list
	std::vector<int> v3{ 1,2,3,4,5,6,7,8,9,10 };
	Show(v3);

	// 4. ����������� �����
	std::vector<int> v4(v3);
	Show(v4);

	// 5. ����������� �����������
	std::vector<int> v5(std::move(v4));
    Show(v4);
	Show(v5);

	// 6. �����������, ������� ��������� ���������� ���������
	std::vector<int> v6(10);
	Show(v6);
	
	// 7. �����������, ������� ��������� ���������� ��������� � �� ��������
	std::vector<int> v7(3, 100);
	Show(v7);

	// 8. �����������, ������� ��������� ��� ����������
	std::vector<int> v8(v5.begin(), v5.begin() + 4);
	Show(v8);
}

void Destructor()
{
	std::cout << "----- DESTRUCTOR -----\n";
	// � ������ vector ���� ����������, � ������� ��� ������ ��� ���������� �������� �� ����
	// ������������� �������������/���������. �������� ������������� �������� ����������� ����.
	std::vector<Person> vector(2);
}

void Methods() 
{
    std::cout << "----- METHODS -----\n\n";
    std::vector<int> vector { 10, 20, 500, 5, 0 };

    // 1. front ������� ��������� �� ������ �������.
    std::cout << "vector[0] = " << vector.front() << std::endl;
    vector.front() = 100;
    std::cout << "vector[0] = " << vector.front() << std::endl;

    // 2. back ������� ��������� �� ������� �������.
    std::cout << "vector[4] = " << vector.back() << std::endl;
    vector.back() = 123;
    std::cout << "vector[4] = " << vector.back() << std::endl;

    // 3. data ������� �������� �� ��������� ����� ����������.
    int* ptr = vector.data();
    std::cout << "vector[2] = " << vector[2] << std::endl;

    // 4. operator[] ������� ��������� �� ������� �� ������� ��������.
    std::cout << "vector[3] = " << vector[3] << std::endl;

    // 5. at - ������� ��������� �� ������� �� ������� ��������. ���� ���������� 
    //         ���� std::out_of_range, ���� ������ �������� �� ������� ������.
    try
    {
        vector.at(100) = 1000;
    }
    catch (const std::out_of_range& exc)
    {
        std::cout << exc.what() << std::endl;
    }

    // 6. get_allocator - ������� ��������, ���� ����'������ �� ����������.
    auto allocator = vector.get_allocator();

    // 7. operator= - �������� ������������ ���� ������� ������ ���������.
    vector = { 1, 2, 3, 4, 5 };         // std::initializer_list
    vector = std::vector<int>(18, 1);   // move =
    vector = vector;                    // copy =
        
    // 8. assign - �������� ������������ ���� ������� ������ ���������.
    //              ������ �� �������� =, ��� �� ����� �����������, �� ���� ��������
    //              ����� ������ ���������.
    vector.assign(5, 100);                          // 5 ��������, �������� ������� 100
    vector.assign({ 1, 2, 3, 4, 5 });               // std::initializer_list
    vector.assign(vector.cbegin(), vector.cend());  // ������� ������� ����� �������
    
    // 9. begin - ������� �������� �� ������ ������� ����������. ������� ����� ����� ����� ��������.
    std::cout << "*vector.begin() = " << *vector.begin() << std::endl;
    *vector.begin() = 1000;
    std::cout << "*vector.begin() = " << *vector.begin() << std::endl;
    
    // 10. cbegin - ������� ����������� �������� �� ������ ������� ����������. ������� �� ����� ����� ����� ��������.
    std::cout << "*vector.cbegin() = " << *vector.cbegin() << std::endl;
    //*vector.cbegin() = 1000;
    
    // 11. end - ������� �������� �� ����� �������� ��������. ʳ���� - �� ��������� ������� �� �������.
    //           �������� ������� �� ���� ���� ����������� ��������.
    for (auto iter = vector.begin(); iter != vector.end(); ++iter)
    {
        *iter *= 2;
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
    
    // 12. cend - ������� ����������� �������� �� ����� �������� ��������.
    for (auto iter = vector.cbegin(); iter != vector.cend(); ++iter)
    {
        //iter *= 2;
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
    
    // 13. rbegin
    
    // 14. rend - ������� ��������� �������� �� ������� ������� ����������. ³������� �� begin ��������:
    //            ���� �������� �� ���������, ���� ������� ����� begin, �� �������� ������������ ������,
    //            ��� ���� �������� �� ���������, ���� ������� ����� rbegin, �� �������� ������������ ����.
    //            ���� �� �������, �� � rbegin �� begin, ����� �� ������ end.
    for (auto iter = vector.rbegin(); iter != vector.rend(); ++iter)
    {
        *iter = 100;
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
    
    // 15. crbegin ����������� rbegin.
    
    // 16. crend ����������� rend.
    for (auto iter = vector.crbegin(); iter != vector.crend(); ++iter)
    {
        //*iter = 2;
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
    
    // 17. empty - ������� true, ���� ������ ������.
    std::cout << "Vector is empty? " << (vector.empty() ? "Yes" : "No") << std::endl;
    
    // 18. size - ������� ����� ������� (������� ��������, � ���� � ��������).
    std::cout << "Size = " << vector.size() << std::endl;
    
    // 19. capacity - ������� ������ ������� (������� ��������, ��� ���� � �������� ���'�� ������� ����).
    std::cout << "Capacity = " << vector.capacity() << std::endl;
    
    // 20. max_size - ������� ����������� ������� ������� ��������.
    std::cout << "Max size = " << vector.max_size() << std::endl;
    
    // 21. reverse - ������ (�������) ��'�� ������ �������.
    std::cout << "Capacity = " << vector.capacity() << std::endl;
    vector.reserve(101);
    std::cout << "Capacity = " << vector.capacity() << std::endl;
    
    // 22. shrink_to_fit - ������ (�������) ��'�� ������ ������� �������� �� ������.
    vector.shrink_to_fit();
    std::cout << "Capacity = " << vector.capacity() << std::endl;
    
    // 23. clear - ����� ������, ��������� ���'��� (���������� �����������) ��������.
    vector.clear();
    std::cout << "Size = " << vector.size() << std::endl;
    std::cout << "Capacity = " << vector.capacity() << std::endl;
    std::cout << "Vector is empty? " << (vector.empty() ? "Yes" : "No") << std::endl;
    
    // 24. insert - �������� ��� �������� � ������ � ������ ����.
    vector = { 1, 2, 3, 4, 5 };
    vector.insert(vector.cbegin(), { 100, 200 }); // � 5 ���������������
    Show(vector);
    
    // 25. emplace - ������ ������ ������ insert. ��� ������ insert �������� ����� ���� �������
    //               � ���'�� �� �� ���������� � ������. � � emplace �������� ����� �������� ����� � ������. ����� � ���������� ��������.
    vector.emplace(vector.cend(), 1000);
    Show(vector);
    
    // 26. push_back �������� ����� ������� � ����� �������.
    vector.push_back(-111);
    Show(vector);

    // 27. pop_back �������� ������� ������� � ������.
    vector.pop_back();
    Show(vector);
    
    // 28. resize ����� ����� ������� (�� ������).
    // ���� ����� ����� ������ �� ���������, �� ������ ����������� �� ������ ������.
    // ���� ����� ����� ������ �� ���������, �� � ������ ��������� ��� �������� � ����������.
    std::cout << "size = " << vector.size() << std::endl;
    std::cout << "Capacity = " << vector.capacity() << std::endl;
    Show(vector);
    vector.resize(2);
    Show(vector);
    vector.resize(20);
    Show(vector);
    
    // 29. swap ������� ���� ���� ������� (����� �� ������)
    std::vector<int> vector1{ 1, 2, 3 };
    std::vector<int> vector2{ 5, 6, 7, 8, 9, 0 };
    Show(vector1);
    Show(vector2);
    vector1.swap(vector2);
    Show(vector1);
    Show(vector2);
    
    // 30. erase �������� �������/������� ������� �� ����������.
    std::vector<int> evenNumbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    Show(evenNumbers);
    evenNumbers.erase(evenNumbers.cend() - 2); // �������� 9
    Show(evenNumbers);
    for (auto iter = evenNumbers.cbegin(); iter != evenNumbers.cend();) // �������� �� ������ ��������
    {
        if (*iter % 2 != 0) // ���� ����� �� �����
        {
            iter = evenNumbers.erase(iter);
        }
        else
        {
            ++iter;
        }
    }
    Show(evenNumbers);
    
    // 31. emplace_back - ���������� �� emplace, ����� �������� � ����� (������ ������ ������ push_back).
    evenNumbers.emplace_back(10);
    evenNumbers.emplace_back(20);
    Show(evenNumbers);
}

void GlobalOperatorsAndFunctions()
{
    // 1. operator== - ������� ���� ����������.
   //                  true ���� ���������� ����� ��������� �����
   //                  � �� �� �������� ��� �� �����.
    std::vector<int> vec1 = { 1, 2, 3 };
    std::vector<int> vec2 = { 1, 2, 3 };
    std::vector<int> vec3 = { 1, 2, 3, 4 };
    std::vector<int> vec4 = { 1, 2, 5 };

    if (vec1 == vec2)
        std::cout << "vec1 == vec2\n";
    if (vec1 == vec3) // �, �� ������ ���
        std::cout << "vec1 == vec3\n";
    if (vec1 == vec4) // �, �� �������� ���
        std::cout << "vec1 == vec4\n";

    // ��������� 2-6 ����� � �������� �++20. �� ������ ���
    // ����������, �� ���� ��������, ���� �����, �� ������ ��������==.
    // 2. operator!=
    // 3. operator<
    // 4. operator<=
    // 5. operator>
    // 6. operator>=
    
    // � �������� �++20 ������ ��������� 1-6 �������� �������� <=> .
    // ³� �������������. ������� � �� ��������� ���� ������ ������ �� �������
    // �� � ��� ���� ���������� �� ����. �� ��� �� ����.
    // 7. operator==
    
    // 8. std::swap - ���� ������ ���� ���� ����������. �� ������������ ������� ������� std::swap, ��� ������� �������� ����� vector::swap().
    
    // ֳ ������ �������� � �++20, ���� �� �������� �� ������. ���� ��������� �������� ������� ��� ����,
    // �� �� ������ ����� erase.
    // 9. std::erase
    // 10. std::erase_if
}

void ContainerAliases()
{
    // ֳ ��������� � � ������� ���������:
   
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
   
    // ��������:
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
    // ���� �� ������ ��������������� ����� ���������, �� �������� ����������, ��
    // �� ���� ���'�����, ��� ����� �� ��������� � ���'�� ����� �������� ���'���
    // �� ��� ���� �������� (���� ���� ����� ���������� ����� ���).
    
    // ���������� ������� ��� �������� �������:

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
   
    // ������������ ��� ��� � ����������� �� ������ ����������� (� �����!):
    for (size_t i = 0; i < people.size(); i++)
        delete people[i];
   
    std::cout << "-----------------------------\n";

    // ��� �� �������� � �������� �����������, �������������� ������ ���������:
    std::vector<std::unique_ptr<Person>> people2;
    for (int i = 0; i < 5; i++)
    {
        people2.push_back(std::unique_ptr<Person>(new Person(i, "Demian"))); // ���������� ���
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
        v.push_back(value);         O(1) (������������ ���������)
        v.pop_back();               O(1)
        v.insert(iterator, value);  O(n)
        v.erase(iterator);          O(n)
        v.erase(begin, end);        O(n)
   
    ϳ������:
        �������:        � ����� -> ������������ O(1), � ���� ���� ���� O(n)
        ������:         O(1)
        ���������:      � ���� O(1), � ������ ������ ����� O(n)
        �����:          O(n) 
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

    // �� ���������� ����� �������� ������� ��������� []:
    for (size_t i = 0; i < numbers.size(); i++)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;
    
    // ��� �� � ��� ���������� � ���������������� ��������[]. � ������
    // ������� ����� ������������ ����������� (���� � � ��� ����������):
    for (auto iter = numbers.begin(); iter != numbers.end(); ++iter)
        std::cout << *iter << " ";
    std::cout << std::endl;
    
    // ��� ��� ������ ������� ���������. ���� � ��������� �++11 ����� ������������
    // ������ for �� ��������. � ��� � ��� �������� � ����� �35.
    for (auto number : numbers)
        std::cout << number << " ";
    std::cout << std::endl;
    // �����: � ����� �552 ������ ��������� ����� auto ��������� int. ���� �� ������
    //        ��������� � �������, �� �������, �� ����� ������ auto& ��� const auto&.
    //        � �� ������������ auto, ���� ����� ���� ������. ��������� ��� � �� �������
    //        for (int number: numbers) { ... }.
}
