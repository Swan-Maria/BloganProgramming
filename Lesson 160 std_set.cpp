// [+] Про що буде урок?
// [+] Що таке асоціативний контейнер?
// [+] Огляд файлів main.cpp і Person.h
// [+] Схема роботи класу set
// [+] Параметри шаблону set
// [+] Псевдоніми-члени set
// [+] Конструктори set
// [+] Деструктор set
// [+] Методи set
// [-] Функції set
// [-] Приклад використання set
// [-] O-нотація set
// [-] В чому суть класу std::multiset?
// [-] Різниця в методах
// [-] O-нотація multiset
// [-] Подяка

#include <iostream>

// Заголовкові файли контейнерів STL
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <array>
#include <stack>
#include <queue>
#include <set> // <- этот файл нужно подключить для работы с set и multiset

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
    // -------------------- Конструктори --------------------
    {
        // 1.  set()                                                 - конструктор за замовчуванням. Множина пуста.
        // 2.  set(const set<T>& other)                              - конструктор копії
        // 3.  set(const set<T>& other, const Allocator& allocator)  - конструктор копії + копіювання готового аллокатора
        // 4.  set(set<T>&& other)                                   - конструктор переміщення
        // 5.  set(set<T>&& other, const Allocator& allocator)       - конструктор переміщення + копіювання готового аллокатора

		// 6.  set(std::initializer_list<T> list)                                                         - копіювання списку ініціалізації
		// 7.  set(std::initializer_list<T> list, const Predicate& predicate)                             - копіювання списку ініціалізації + копіювання готового предикату
		// 8.  set(std::initializer_list<T> list, const Allocator& allocator)                             - копіювання списку ініціалізації + копіювання готового аллокатора
		// 9.  set(std::initializer_list<T> list, const Predicate& predicate, const Allocator& allocator) - копіювання списку ініціалізації + копіювання готового предикату + копіювання готового аллокатора

        // 10. set(const Predicate& predicate)                              - копіювання готового предикату. Множина пуста.
        // 11. set(const Allocator& allocator)                              - копіювання готового аллокатора. Множина пуста.
        // 12. set(const Predicate& predicate, const Allocator& allocator)  - копіювання готового предикату + копіювання готового аллокатора. Множина пуста.

        // 13. set(Iterator begin, Iterator end)                                                         - копіювання діапазону
        // 14. set(Iterator begin, Iterator end, const Predicate& predicate)                             - копіювання діапазону + копіювання готового предикату
        // 15. set(Iterator begin, Iterator end, const Allocator& allocator)                             - копіювання діапазону + копіювання готового аллокатора
        // 16. set(Iterator begin, Iterator end, const Predicate& predicate, const Allocator& allocator) - копіювання діапазону + копіювання готового предикату + копіювання готового аллокатора
    
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

	// --------------------- Деструктор ---------------------
	{
		// При знищенні об'єкта множини викликається його деструктор,
		// який в свою чергу викликає конструткор всіх елементів множини.
	}
	// ------------------------------------------------------

    // ----------------------- Методи -----------------------
    {
        // 1. std::set<T>& operator=(const std::set<T>& other)      - переписати вміст множини, скопіювавши значення з іншої множини
        // 1. std::set<T>& operator=(std::set<T>&& other)           - переписати вміст множини, перемістивши значення з іншої множини
        // 1. std::set<T>& operator=(std::initializer_list<T> list) - переписати вміст множини, скопіювавши значення з ініціалізуючого списку
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

        // 2. void swap( std::set<T>& other) - поміняти вміст двох множин між собою
        {
            std::set<int> set1{ 1, 2, 3, 4, 5 };
            std::set<int> set2{ 10, 20, 30 };

            Show(set1); // 1 2 3 4 5
            Show(set2); // 10 20 30

            set1.swap(set2);

            Show(set1); // 10 20 30
            Show(set2); // 1 2 3 4 5

        }

        // 3. std::set<T>::iterator begin()                         - повернути ітератор на початок множини (перший елемент)
        // 3. std::set<T>::const_iterator begin() const             - повернути константний ітератор на початок множини (перший елемент)

        // 4. std::set<T>::iterator end()                           - повернути ітератор на кінець множини (місце ЗА останнім елементом)
        // 4. std::set<T>::const_iterator end() const               - повернути константний ітератор на кінець множини (місце ЗА останнім елементом)

        // 5. std::set<T>::const_iterator cbegin() const            - повернути константний ітератор на початок множини (перший елемент)

		// 6. std::set<T>::const_iterator cend() const              - повернути константний ітератор на кінець множини (місце ЗА останнім елементом)

        // 7. std::set<T>::reverse_iterator rbegin()                - повернути обернений ітератор на початок множини (останній елемент)
		// 7. std::set<T>::const_reverse_iterator rbegin() const    - повернути константний обернений ітератор на початок множини (останній елемент)

        // 8. std::set<T>::reverse_iterator rend()                  - повернути обернений ітератор на кінець множини (місце ЗА останнім елементом)
		// 8. std::set<T>::const_reverse_iterator rend() const      - повернути константний обернений ітератор на кінець множини (місце ЗА останнім елементом)

		// 9. std::set<T>::const_reverse_iterator crbegin() const   - повернути константний обернений ітератор на початок множини (останній елемент)

		// 10. std::set<T>::const_reverse_iterator crend() const    - повернути константний обернений ітератор на кінець множини (місце ЗА останнім елементом)
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

        // 11. void clear() - очистити множину, викликавши деструктори для всіх елементів
        {
            std::set<int> set{ 1, 2, 3, 4, 5 };
            Show(set); // 1 2 3 4 5
            set.clear();
            Show(set); // empty
        }

        // 12. bool empty() const - повернути true, якщо множина не пуста. false - якщо інакше
        {
            std::set<int> set{ 1, 2, 3, 4, 5 };
            if (set.empty()) // false
                std::cout << "set is empty.\n";

            set.clear();
            if (set.empty()) // true
                std::cout << "set is empty.\n";
        }

        // 13. size_t count(const T& value) const - повернути кількість елементів, які рівні указаному значенню
        {
            std::set<int> set{ 1, 2, 3, 4, 5 };
            size_t amountOf100 = set.count(100);
            size_t amountOf5 = set.count(5);

            std::cout << "Amount of 100 = " << amountOf100 << std::endl; // Amount of 100 = 0
            std::cout << "Amount of 5 = " << amountOf5 << std::endl; // Amount of 5 = 1
        }

        // 14. void insert(std::initializer_list list) - вставити всі значення списку ініціалізації у множину
        // 14. std::set<T>::iterator insert(std::set<T>::const_iterator where, const T& value) - вставити значення як найближче до вказаного місця
        // 14. std::set<T>::iterator insert(std::set<T>::const_iterator where, T&& value) - вставити значення як найближче до вказаного місця
        // 14. void insert(Iterator begin, Iterator end) - вставити послідовність елементів в множину
        // 14. std::pair<std::set<T>::iterator, bool> insert(const T& value) - вставити значення в множину
        // 14. std::pair<std::set<T>::iterator, bool> insert(T&& value) - вставити значення в множину
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

        // 15. std::pair<std::set<T>::iterator, bool> emplace(Args&&... args) - конструює нове значення в множині
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

        // 16. std::set<T>::iterator emplace_hint(std::set<T>::const_iterator where, Args&&... args) - конструює нове
        {
            std::set<int> set{ 3, 2, 1, 4, 6 };

            set.emplace_hint(set.end(), 8);

            Show(set); // 1 2 3 4 6 8
        }

        // 17. std::set<T>::const_iterator find(const T& value) - шукає значення в множині. Якщо находить - повертає ітератор на нього, якщо ні - кінець множини.
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

        // 18. size_t size() - повертає розмір множини / кількість елементів в множині
        {
            std::set<int> set{ 1, 2, 3, 4, 5 };

            std::cout << set.size() << std::endl; // 5

            set.clear();

            std::cout << set.size() << std::endl; // 0
        }

        // 19. size_t max_size() - повертає максимальний розмір множини / максимальну кількість елементів в множині
        {
            std::set<int> set1;
            std::set<Person> set2;

            std::cout << set1.max_size() << std::endl; // 576460752303423487
            std::cout << set2.max_size() << std::endl; // 230584300921369395
        }

        // 20. size_t erase(const T& value) - видалити значення з множини
        // 20. std::set<T>::iterator erase(std::set<T>::const_iterator begin, std::set<T>::const_iterator end) - видалити значення з множини
        // 20. std::set<T>::iterator erase(std::set<T>::const_iterator where) - видалити значення по указаному ітератору
        {
            std::set<int> set{ 1, 2, 3, 4, 5 };

            set.erase(3);
            auto foundIter = set.find(4);
            set.erase(foundIter);

            Show(set); // 1 2 5
        }

        //21. std::set<T>::key_compare key_comp() - повертає функтор, який порівнює ключі(значення) в множині
        {
            std::set<int> set{ 1, 2, 3, 4, 5 };
            auto keyComparator = set.key_comp(); // auto = std::less<int>
        }

        //22. std::set<T>::value_compare value_comp() - повертає функтор, який порівнює значення в множині
        {
            std::set<int> set{ 1, 2, 3, 4, 5 };
            auto valueComparator = set.value_comp(); // auto = std::less<int>
        }

        // 23. std::set<T>::allocator_type get_allocator() - повертає аллокатор множини
        {
            std::set<int> set{ 1, 2, 3, 4, 5 };
            auto allocator = set.get_allocator(); // auto = std::allocator<int>
        }

        // 24. std::set<T>::iterator lower_bound(const T& value) - повертає ітератор на найближчий елемент до указаного значення
        {
            std::set<int> set{ 10, 20, 30, 40, 50 };
            auto lowerBoundIter = set.lower_bound(30);
            std::cout << *lowerBoundIter << std::endl; // 30
        }

        // 25. std::set<T>::iterator upper_bound(const T & value) - повертає ітератор на найближчий елемент після указаного значення
        {
            std::set<int> set{ 10, 20, 30, 40, 50 };
            auto upperBoundIter = set.upper_bound(30);
            std::cout << *upperBoundIter << std::endl; // 40
        }

		// 26. std::pair<std::set<T>::iterator, std::set<T>::iterator> equal_range(const T& value) - повертає пару ітераторів
        //                                                                                           Перший ітератор є ітератор на найближчий елемент до указаного значення, який не менше за значення.
        //                                                                                           Перший ітератор є ітератор на найближчий елемент до указаного значення, який більший за значення.
        {
            std::set<int> set{ 10, 20, 30, 40, 50 };
            auto equalRangeIterator = set.equal_range(30);
            std::cout << "lower bound of 30 = " << *equalRangeIterator.first << std::endl;  // 30
            std::cout << "upper bound of 30 = " << *equalRangeIterator.second << std::endl; // 40
        }
        std::cout << std::endl;
    }
    // ------------------------------------------------------

    // ----------------------- Функції ----------------------
    {  
        // 1. bool operator==(const std::set<T>& left, const std::set<T>& right) - порівнює дві множини на рівність                 
        // 2. bool operator!=(const std::set<T>& left, const std::set<T>& right) - порівнює дві множини на нерівність                   (видалений в C++20)
        // 3. bool operator>(const std::set<T>& left, const std::set<T>& right) - порівнює дві множини на знак "більше"                 (видалений в C++20)
        // 4. bool operator>=(const std::set<T>& left, const std::set<T>& right) - порівнює дві множини на знак "більше або дорівнює"   (видалений в C++20)
        // 5. bool operator<(const std::set<T>& left, const std::set<T>& right) - порівнює дві множини на знак "менше"                  (видалений в C++20)
		// 6. bool operator<=(const std::set<T>& left, const std::set<T>& right) - порівнює дві множини на знак "менше або дорівнює"    (видалений в C++20)
		// 7. **** operator<=>(const std::set<T>& left, const std::set<T>& right) - порівнює дві множини на тришарове порівняння        (добавлений в C++20)
        // 8. void swap(std::set<T>& left, std::set<T>& right) - міняє місцями елементи двох множин.
        // 9. size_t erase_if(std::set<T>& set, Predicate predicate) - видаляє всі елементи множини, які підходять предикату.           (добавлений в C++20)
    }
    // ------------------------------------------------------
    
    // -------------- Приклад використання set --------------
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
    // - Всі параметри шаблону класу такі ж, як і в std::set
    // - Всі псевдоніми-члени такі ж, як і в std::set
    // - Всі конструктори такі ж, як і в std::set
    // - Всі методи такі ж, як і в std::set
    // - Всі функції такі ж, як і в std::set

    // АЛЕ
    // деякі методи працюють по іншому. Розглянемо відмінність:

    // 1. Якщо кожний елемент контейнера std::multiset може містити однакові значення,
    //    то який тип має сам елемент? Як переміщуються ітератори?
    {
        std::multiset<int> multiset{ 1, 5, 1, 6, 1, 9, 5 };

        Show(multiset); // 1 1 1 5 5 6 9

        std::cout << *multiset.cbegin() << std::endl;
    }
        
    // 2. Метод erase видаляє не одне значення в елементі, а всі значення
    {
        std::multiset<int> multiset{ 1, 5, 1, 6, 1, 9, 5 };
        size_t deletedValuesCount = multiset.erase(1);

        std::cout << deletedValuesCount << " values are deleted.\n"; // 3
        Show(multiset); // 5 5 6 9
    }

    // 3. Метод count повертає уже різні значення, а не 1, як було в std::set
    {
        std::multiset<int> multiset{ 1, 5, 1, 6, 1, 9, 5 };
        Show(multiset); // 1 1 1 5 5 6 9

        size_t countOf1 = multiset.count(1);
        std::cout << "There are " << countOf1 << " 1s.\n"; // 3
    }

    // 4. Метод find повертає лише перше значення в елементі
    {
        std::multiset<int> multiset{ 1, 5, 1, 6, 1, 9, 5 };
        auto iter = multiset.find(1);

        Show(multiset); // 1 1 1 5 5 6 9
                        // ^
                        // |
                        // iter
    }

    // 5. Як же тоді добратися до інших значень елементу? От тут якраз в хід вступають
    //    методи lower_bound, upper_bound, або equal_range
    {
        std::multiset<int> multiset{ 1, 1, 1, 2, 3, 4, 4 };

        // Спробуємо дістати всі 1-ці:
        auto beginIterOf1 = multiset.lower_bound(1);
        auto endIterOf1 = multiset.upper_bound(1);

        for (auto iter = beginIterOf1; iter != endIterOf1; ++iter)
            std::cout << *iter << " "; // 1 1 1
        std::cout << std::endl;

        // Спробуємо дістати всі 4-ки:
        auto ItersRangeOf4 = multiset.equal_range(4);
        for (auto iter = ItersRangeOf4.first; iter != ItersRangeOf4.second; ++iter)
        {
            std::cout << *iter << " "; // 4 4
        }

        std::cout << std::endl;
    }
}
