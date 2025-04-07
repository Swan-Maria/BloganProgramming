// [+] ��� �� ���� ����?
// [+] �� ���� ������������ ���������?
// [+] ����� ����� main.cpp � Person.h
// [+] ����� ������ ����� set
// [+] ��������� ������� set
// [+] ���������-����� set
// [+] ������������ set
// [+] ���������� set
// [+] ������ set
// [-] ������� set
// [-] ������� ������������ set
// [-] O-������� set
// [-] � ���� ���� ����� std::multiset?
// [-] г����� � �������
// [-] O-������� multiset
// [-] ������

#include <iostream>

// ���������� ����� ���������� STL
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <array>
#include <stack>
#include <queue>
#include <set> // <- ���� ���� ����� ���������� ��� ������ � set � multiset

#include "Lesson 160 Person.h"

template <typename T, typename Comparator>
void Show(const std::set<T, Comparator>& set)
{
	if (set.empty())
	{
		std::cout << "empty\n";
		return;
	}

    std::cout << " ";
	for (const T& element : set)
		std::cout << element << " ";
    std::cout << std::endl;
}

template <typename T, typename Comparator>
void Show(const std::multiset<T, Comparator>& set)
{
    if (set.empty())
    {
        std::cout << "empty" << std::endl;
        return;
    }

    std::cout << " ";
    for (const T& element : set)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

void SetExample();
void MultisetExample();

int main()
{
    SetExample();
    MultisetExample();
    return 0;
}

void SetExample()
{
    // -------------------- ������������ --------------------
    {
        // 1.  set()                                                 - ����������� �� �������������. ������� �����.
        // 2.  set(const set<T>& other)                              - ����������� ��ﳿ
        // 3.  set(const set<T>& other, const Allocator& allocator)  - ����������� ��ﳿ + ��������� �������� ����������
        // 4.  set(set<T>&& other)                                   - ����������� ����������
        // 5.  set(set<T>&& other, const Allocator& allocator)       - ����������� ���������� + ��������� �������� ����������

		// 6.  set(std::initializer_list<T> list)                                                         - ��������� ������ �����������
		// 7.  set(std::initializer_list<T> list, const Predicate& predicate)                             - ��������� ������ ����������� + ��������� �������� ���������
		// 8.  set(std::initializer_list<T> list, const Allocator& allocator)                             - ��������� ������ ����������� + ��������� �������� ����������
		// 9.  set(std::initializer_list<T> list, const Predicate& predicate, const Allocator& allocator) - ��������� ������ ����������� + ��������� �������� ��������� + ��������� �������� ����������

        // 10. set(const Predicate& predicate)                              - ��������� �������� ���������. ������� �����.
        // 11. set(const Allocator& allocator)                              - ��������� �������� ����������. ������� �����.
        // 12. set(const Predicate& predicate, const Allocator& allocator)  - ��������� �������� ��������� + ��������� �������� ����������. ������� �����.

        // 13. set(Iterator begin, Iterator end)                                                         - ��������� ��������
        // 14. set(Iterator begin, Iterator end, const Predicate& predicate)                             - ��������� �������� + ��������� �������� ���������
        // 15. set(Iterator begin, Iterator end, const Allocator& allocator)                             - ��������� �������� + ��������� �������� ����������
        // 16. set(Iterator begin, Iterator end, const Predicate& predicate, const Allocator& allocator) - ��������� �������� + ��������� �������� ��������� + ��������� �������� ����������
    
        std::set<int> set2 = { 10, 1, 9, 2, 3, 6 };
        Show(set2); // 1 2 3 6 9 10

        std::set<int, std::greater<int>> set3 = { 10, 1, 9, 2, 3, 6 };
        Show(set3); // 10 9 6 3 2 1

        auto lambdaComp = [](int value1, int value2) { return value1 > value2; };
        std::set<int, decltype(lambdaComp)> set4({ 1, 2, 3, 4, 5 }, lambdaComp);
        Show(set4); // 5 4 3 2 1

        std::vector<int> vector = { 100, 5, 200, 3 };
        std::set<int> set5(vector.cbegin(), vector.cend());
        Show(set5); // 3 5 100 200

        std::cout << std::endl;
    }
    // ------------------------------------------------------

	// --------------------- ���������� ---------------------
	{
		// ��� ������� ��'���� ������� ����������� ���� ����������,
		// ���� � ���� ����� ������� ����������� ��� �������� �������.
	}
	// ------------------------------------------------------

    // ----------------------- ������ -----------------------
    {
        // 1. std::set<T>& operator=(const std::set<T>& other)      - ���������� ���� �������, ���������� �������� � ���� �������
        // 1. std::set<T>& operator=(std::set<T>&& other)           - ���������� ���� �������, ����������� �������� � ���� �������
        // 1. std::set<T>& operator=(std::initializer_list<T> list) - ���������� ���� �������, ���������� �������� � ������������� ������
        {
            std::set<int> set;

            set = { 10, 2, 33, 4, 50 };
            Show(set); // 10 2 33 4 50

            set = std::set<int>{ 70, 1, 100, -4 };
            Show(set); // 70 1 100 -4

            std::set<int> otherSet{ 100, 200, 300 };
            set = otherSet;
            Show(set); // 100 200 300
        }

        // 2. void swap( std::set<T>& other) - ������� ���� ���� ������ �� �����
        {
            std::set<int> set1{ 1, 2, 3, 4, 5 };
            std::set<int> set2{ 10, 20, 30 };

            Show(set1); // 1 2 3 4 5
            Show(set2); // 10 20 30

            set1.swap(set2);

            Show(set1); // 10 20 30
            Show(set2); // 1 2 3 4 5

        }

        // 3. std::set<T>::iterator begin()                         - ��������� �������� �� ������� ������� (������ �������)
        // 3. std::set<T>::const_iterator begin() const             - ��������� ����������� �������� �� ������� ������� (������ �������)

        // 4. std::set<T>::iterator end()                           - ��������� �������� �� ����� ������� (���� �� ������� ���������)
        // 4. std::set<T>::const_iterator end() const               - ��������� ����������� �������� �� ����� ������� (���� �� ������� ���������)

        // 5. std::set<T>::const_iterator cbegin() const            - ��������� ����������� �������� �� ������� ������� (������ �������)

		// 6. std::set<T>::const_iterator cend() const              - ��������� ����������� �������� �� ����� ������� (���� �� ������� ���������)

        // 7. std::set<T>::reverse_iterator rbegin()                - ��������� ��������� �������� �� ������� ������� (������� �������)
		// 7. std::set<T>::const_reverse_iterator rbegin() const    - ��������� ����������� ��������� �������� �� ������� ������� (������� �������)

        // 8. std::set<T>::reverse_iterator rend()                  - ��������� ��������� �������� �� ����� ������� (���� �� ������� ���������)
		// 8. std::set<T>::const_reverse_iterator rend() const      - ��������� ����������� ��������� �������� �� ����� ������� (���� �� ������� ���������)

		// 9. std::set<T>::const_reverse_iterator crbegin() const   - ��������� ����������� ��������� �������� �� ������� ������� (������� �������)

		// 10. std::set<T>::const_reverse_iterator crend() const    - ��������� ����������� ��������� �������� �� ����� ������� (���� �� ������� ���������)
        {
            std::set<int> set{ 100, 1, 200, 2, 300 };

            for (std::set<int>::iterator iterator = set.begin(), end = set.end(); iterator != end; ++iterator)
            {
                //*iterator *= 100;
                std::cout << *iterator << " "; // 1 2 100 200 300
            }
            std::cout << std::endl;

            for (std::set<int>::reverse_iterator iterator = set.rbegin(), end = set.rend(); iterator != end; ++iterator)
            {
                //*iterator *= 100;
                std::cout << *iterator << " "; // 300 200 100 2 1
            }
            std::cout << std::endl;
        
        }

        // 11. void clear() - �������� �������, ���������� ����������� ��� ��� ��������
        {
            std::set<int> set{ 1, 2, 3, 4, 5 };
            Show(set); // 1 2 3 4 5
            set.clear();
            Show(set); // empty
        }

        // 12. bool empty() const - ��������� true, ���� ������� �� �����. false - ���� ������
        {
            std::set<int> set{ 1, 2, 3, 4, 5 };
            if (set.empty()) // false
                std::cout << "set is empty.\n";

            set.clear();
            if (set.empty()) // true
                std::cout << "set is empty.\n";
        }

        // 13. size_t count(const T& value) const - ��������� ������� ��������, �� ��� ��������� ��������
        {
            std::set<int> set{ 1, 2, 3, 4, 5 };
            size_t amountOf100 = set.count(100);
            size_t amountOf5 = set.count(5);

            std::cout << "Amount of 100 = " << amountOf100 << std::endl; // Amount of 100 = 0
            std::cout << "Amount of 5 = " << amountOf5 << std::endl; // Amount of 5 = 1
        }

        // 14. void insert(std::initializer_list list) - �������� �� �������� ������ ����������� � �������
        // 14. std::set<T>::iterator insert(std::set<T>::const_iterator where, const T& value) - �������� �������� �� ��������� �� ��������� ����
        // 14. std::set<T>::iterator insert(std::set<T>::const_iterator where, T&& value) - �������� �������� �� ��������� �� ��������� ����
        // 14. void insert(Iterator begin, Iterator end) - �������� ����������� �������� � �������
        // 14. std::pair<std::set<T>::iterator, bool> insert(const T& value) - �������� �������� � �������
        // 14. std::pair<std::set<T>::iterator, bool> insert(T&& value) - �������� �������� � �������
        {
            std::set<int> set{ 1, 2, 3, 4, 5 };
            Show(set);        // 1 2 3 4 5
            set.insert(10);
            set.insert(50);
            Show(set);        // 1 2 3 4 5 10 50

            set.insert({ 100, 200, 300 });
            Show(set);        // 1 2 3 4 5 10 50 100 200 300

            std::pair<std::set<int>::iterator, bool> insertResult = set.insert(10);

            if (insertResult.second == false)
            {
                std::cout << "Value already exists in container.\n";
            }
            else
            {
                std::cout << "Value is inserted in container.\n";
                std::cout << "Here it is: " << *insertResult.first << std::endl;
            }
        }

        // 15. std::pair<std::set<T>::iterator, bool> emplace(Args&&... args) - ��������� ���� �������� � ������
        {
            std::set<Person> people
            {
                Person(25, "Demian"),
                Person(26, "Anya"),
                Person(20, "Victoria")
            };

            Show(people);  
            // [Name: Anya, Age: 26]
            // [Name: Demian, Age: 25]
            // [Name: Victoria, Age: 20]

            people.insert(Person(30, "David"));

            Show(people);
            // [Name: Anya, Age: 26]
            // [Name: Demian, Age: 25]
            // [Name: Victoria, Age: 20]

            people.insert(Person(30, "David"));
        
            Show(people);
            // [Name: Anya, Age: 26]
            // [Name: David, Age: 35]
            // [Name: Demian, Age: 25]
            // [Name: Victoria, Age: 20]

            people.emplace(8, "Clementine");
        
            Show(people);
            // [Name: Anya, Age: 26]
            // [Name: Clementine, Age: 35]
            // [Name:David, Age : 35]
            // [Name:Demian, Age : 25]
            // [Name: Victoria, Age: 20]
        }

        // 16. std::set<T>::iterator emplace_hint(std::set<T>::const_iterator where, Args&&... args) - ��������� ����
        {
            std::set<int> set{ 3, 2, 1, 4, 6 };

            set.emplace_hint(set.end(), 8);

            Show(set); // 1 2 3 4 6 8
        }

        // 17. std::set<T>::const_iterator find(const T& value) - ���� �������� � ������. ���� �������� - ������� �������� �� �����, ���� � - ����� �������.
        {
            std::set<int> set{ 1, 2, 3, 4, 5 };

            auto foundIterator = set.find(3);
            if (foundIterator != set.cend()) // true
            {
                std::cout << "Container has value 3.\n";
            }

            foundIterator = set.find(10); // false
            if (foundIterator != set.cend())
            {
                std::cout << "Container has value 10.\n";
            }
        }

        // 18. size_t size() - ������� ����� ������� / ������� �������� � ������
        {
            std::set<int> set{ 1, 2, 3, 4, 5 };

            std::cout << set.size() << std::endl; // 5

            set.clear();

            std::cout << set.size() << std::endl; // 0
        }

        // 19. size_t max_size() - ������� ������������ ����� ������� / ����������� ������� �������� � ������
        {
            std::set<int> set1;
            std::set<Person> set2;

            std::cout << set1.max_size() << std::endl; // 576460752303423487
            std::cout << set2.max_size() << std::endl; // 230584300921369395
        }

        // 20. size_t erase(const T& value) - �������� �������� � �������
        // 20. std::set<T>::iterator erase(std::set<T>::const_iterator begin, std::set<T>::const_iterator end) - �������� �������� � �������
        // 20. std::set<T>::iterator erase(std::set<T>::const_iterator where) - �������� �������� �� ��������� ���������
        {
            std::set<int> set{ 1, 2, 3, 4, 5 };

            set.erase(3);
            auto foundIter = set.find(4);
            set.erase(foundIter);

            Show(set); // 1 2 5
        }

        //21. std::set<T>::key_compare key_comp() - ������� �������, ���� ������� �����(��������) � ������
        {
            std::set<int> set{ 1, 2, 3, 4, 5 };
            auto keyComparator = set.key_comp(); // auto = std::less<int>
        }

        //22. std::set<T>::value_compare value_comp() - ������� �������, ���� ������� �������� � ������
        {
            std::set<int> set{ 1, 2, 3, 4, 5 };
            auto valueComparator = set.value_comp(); // auto = std::less<int>
        }

        // 23. std::set<T>::allocator_type get_allocator() - ������� ��������� �������
        {
            std::set<int> set{ 1, 2, 3, 4, 5 };
            auto allocator = set.get_allocator(); // auto = std::allocator<int>
        }

        // 24. std::set<T>::iterator lower_bound(const T& value) - ������� �������� �� ���������� ������� �� ��������� ��������
        {
            std::set<int> set{ 10, 20, 30, 40, 50 };
            auto lowerBoundIter = set.lower_bound(30);
            std::cout << *lowerBoundIter << std::endl; // 30
        }

        // 25. std::set<T>::iterator upper_bound(const T & value) - ������� �������� �� ���������� ������� ���� ��������� ��������
        {
            std::set<int> set{ 10, 20, 30, 40, 50 };
            auto upperBoundIter = set.upper_bound(30);
            std::cout << *upperBoundIter << std::endl; // 40
        }

		// 26. std::pair<std::set<T>::iterator, std::set<T>::iterator> equal_range(const T& value) - ������� ���� ���������
        //                                                                                           ������ �������� � �������� �� ���������� ������� �� ��������� ��������, ���� �� ����� �� ��������.
        //                                                                                           ������ �������� � �������� �� ���������� ������� �� ��������� ��������, ���� ������ �� ��������.
        {
            std::set<int> set{ 10, 20, 30, 40, 50 };
            auto equalRangeIterator = set.equal_range(30);
            std::cout << "lower bound of 30 = " << *equalRangeIterator.first << std::endl;  // 30
            std::cout << "upper bound of 30 = " << *equalRangeIterator.second << std::endl; // 40
        }
        std::cout << std::endl;
    }
    // ------------------------------------------------------

    // ----------------------- ������� ----------------------
    {  
        // 1. bool operator==(const std::set<T>& left, const std::set<T>& right) - ������� �� ������� �� ������                 
        // 2. bool operator!=(const std::set<T>& left, const std::set<T>& right) - ������� �� ������� �� ��������                   (��������� � C++20)
        // 3. bool operator>(const std::set<T>& left, const std::set<T>& right) - ������� �� ������� �� ���� "�����"                 (��������� � C++20)
        // 4. bool operator>=(const std::set<T>& left, const std::set<T>& right) - ������� �� ������� �� ���� "����� ��� �������"   (��������� � C++20)
        // 5. bool operator<(const std::set<T>& left, const std::set<T>& right) - ������� �� ������� �� ���� "�����"                  (��������� � C++20)
		// 6. bool operator<=(const std::set<T>& left, const std::set<T>& right) - ������� �� ������� �� ���� "����� ��� �������"    (��������� � C++20)
		// 7. **** operator<=>(const std::set<T>& left, const std::set<T>& right) - ������� �� ������� �� ��������� ���������        (���������� � C++20)
        // 8. void swap(std::set<T>& left, std::set<T>& right) - ���� ������ �������� ���� ������.
        // 9. size_t erase_if(std::set<T>& set, Predicate predicate) - ������� �� �������� �������, �� �������� ���������.           (���������� � C++20)
    }
    // ------------------------------------------------------
    
    // -------------- ������� ������������ set --------------
    {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));

        std::vector<int> numbers(100);
        for (size_t i = 0; i < numbers.size(); i++)
        {
            numbers[i] = rand() % 100;
        }

        std::set<int> uniqueNumbers(numbers.cbegin(), numbers.cend());
        for (int number : uniqueNumbers)
        {
            std::cout << number << " ";
        }

        std::cout << std::endl;
    }
    // ------------------------------------------------------

}

void MultisetExample()
{
    // - �� ��������� ������� ����� ��� �, �� � � std::set
    // - �� ���������-����� ��� �, �� � � std::set
    // - �� ������������ ��� �, �� � � std::set
    // - �� ������ ��� �, �� � � std::set
    // - �� ������� ��� �, �� � � std::set

    // ���
    // ���� ������ �������� �� ������. ���������� ��������:

    // 1. ���� ������ ������� ���������� std::multiset ���� ������ ������� ��������,
    //    �� ���� ��� �� ��� �������? �� ������������ ���������?
    {
        std::multiset<int> multiset{ 1, 5, 1, 6, 1, 9, 5 };

        Show(multiset); // 1 1 1 5 5 6 9

        std::cout << *multiset.cbegin() << std::endl;
    }
        
    // 2. ����� erase ������� �� ���� �������� � �������, � �� ��������
    {
        std::multiset<int> multiset{ 1, 5, 1, 6, 1, 9, 5 };
        size_t deletedValuesCount = multiset.erase(1);

        std::cout << deletedValuesCount << " values are deleted.\n"; // 3
        Show(multiset); // 5 5 6 9
    }

    // 3. ����� count ������� ��� ��� ��������, � �� 1, �� ���� � std::set
    {
        std::multiset<int> multiset{ 1, 5, 1, 6, 1, 9, 5 };
        Show(multiset); // 1 1 1 5 5 6 9

        size_t countOf1 = multiset.count(1);
        std::cout << "There are " << countOf1 << " 1s.\n"; // 3
    }

    // 4. ����� find ������� ���� ����� �������� � �������
    {
        std::multiset<int> multiset{ 1, 5, 1, 6, 1, 9, 5 };
        auto iter = multiset.find(1);

        Show(multiset); // 1 1 1 5 5 6 9
                        // ^
                        // |
                        // iter
    }

    // 5. �� �� ��� ��������� �� ����� ������� ��������? �� ��� ����� � ��� ���������
    //    ������ lower_bound, upper_bound, ��� equal_range
    {
        std::multiset<int> multiset{ 1, 1, 1, 2, 3, 4, 4 };

        // �������� ������ �� 1-��:
        auto beginIterOf1 = multiset.lower_bound(1);
        auto endIterOf1 = multiset.upper_bound(1);

        for (auto iter = beginIterOf1; iter != endIterOf1; ++iter)
            std::cout << *iter << " "; // 1 1 1
        std::cout << std::endl;

        // �������� ������ �� 4-��:
        auto ItersRangeOf4 = multiset.equal_range(4);
        for (auto iter = ItersRangeOf4.first; iter != ItersRangeOf4.second; ++iter)
        {
            std::cout << *iter << " "; // 4 4
        }

        std::cout << std::endl;
    }
}
