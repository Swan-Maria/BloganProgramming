// [+] Про що буде урок ?
// [+] Схема роботи
// [+] Параметри шаблонів
// [+] Псевдоніми - члени
// [ ] Конструктори
// [ ] Деструктор
// [ ] Оператор =
// [ ] Оператор []
// [ ] Методи
// [ ] Функції
// [ ] О - нотація
// [ ] Подяка

#include <iostream>
// Заголовкові файли бібліотеки STL:
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <array>
#include <stack>
#include <queue>
#include <set>
#include <map> // <- цей файл треба підключити для роботи std::map і std::multimap

#include "Lesson 161 STLTools.h"

int main()
{
#pragma region Конструткори
    {
		std::cout << "---------------------- Constructors ----------------------\n";

        // -------------------------------- Конструктори класу map ------------------------------------
        // 1. map()
        // 2. map(const map& other)
        // 3. map(map&& other)
        // 4. map(const Predicate& predicate)
        // 5. map(const Allocator& allocator)
        // 6. map(const Predicate& predicate, const Allocator& allocator)
        // 7. map(const map& other, const Allocator& allocator)
        // 8. map(map&& other, const Allocator& allocator)

        // 9. map(Iterator first, Iterator end)
        // 10. map(Iterator first, Iterator end, const Predicate& predicate)
        // 11. map(Iterator first, Iterator end, const Allocator& allocator)
        // 12. map(Iterator first, Iterator end, const Predicate& predicate, const Allocator& allocator)

        // 13. map(std::initializer_list list)
        // 14. map(std::initializer_list list, const Predicate& predicate)
        // 15. map(std::initializer_list list, const Allocator& allocator)
        // 16. map(std::initializer_list list, const Predicate& predicate, const Allocator& allocator)

        // -------------------------------- Конструктори класу  multi map ------------------------------------
        // 1.  multimap()
        // 2.  multimap(const multimap& other)
        // 3.  multimap(multimap&& other)
        // 4.  multimap(const Predicate& predicate)
        // 5.  multimap(const Allocator& allocator)
        // 6.  multimap(const Predicate& predicate, const Allocator& allocator)
        // 7.  multimap(const multimap& other, const Allocator& allocator)
        // 8.  multimap(multimap&& other, const Allocator& allocator)

        // 9.  multimap(Iterator first, Iterator end)
        // 10. multimap(Iterator first, Iterator end, const Predicate& predicate)
        // 11. multimap(Iterator first, Iterator end, const Allocator& allocator)
        // 12. multimap(Iterator first, Iterator end, const Predicate& predicate, const Allocator& allocator)

        // 13. multimap(std::initializer_list list)
        // 14. multimap(std::initializer_list list, const Predicate& predicate)
        // 15. multimap(std::initializer_list list, const Allocator& allocator)
        // 16. multimap(std::initializer_list list, const Predicate& predicate, const Allocator& allocator)

        // ----------------------------- Примеры -----------------------------

        std::map<int, std::string> empty; // Конструктор №1
        Show(empty);

        std::map<int, std::string> people = // Конструктор №13
        {
            { 25, "Demian" },
            { 26, "Anna" },
            { 20, "Vika" }
        };
        Show(people);

        std::map<int, std::string> copy(people); // Конструктор №2
        Show(copy);

        std::vector<std::pair<unsigned, std::string>> otherEmployees =
        {
            { 1, "Demian Blogan" },
            { 2, "Anna Taylor" },
            { 3, "Viktoria Cherenkova" }
        };

        std::map<int, std::string> employees(otherEmployees.cbegin(), otherEmployees.cend()); // Констру
        Show(employees);

        std::multimap<std::string, std::string> contacts =
        {
            { "Demian Blogan", "+380123456789" },
            { "Demian Blogan", "+380987654321" },

            { "Anna Taylor", "+380111222333" },

            { "Viktoria Cherenkova", "+380112233445" },
            { "Viktoria Cherenkova", "+380121212121" },
            { "Viktoria Cherenkova", "+380006543100" },
        };
        Show(contacts);
    }
 #pragma endregion

#pragma region Деструткори
    // За замовчуванням при додаванні нових елементів в любий контейнер, пам'ять під них виділяється на кучі
    // завдяки алокатору за замовчуванням - std::allocator. А в деструкторі цих контейнерів ця пам'ять автоматично
    // звільняється. Контейнери map і multimap - не виключення.
#pragma endregion

#pragma region Оператор =
    std::cout << "------------- operator= -------------\n";

    // Класи map і multimap мають перезавантажений оператор присвоєння:
    // 1. map& operator=(const map& other)
    // 2. map& operator=(map&& other)
    // 3. map& operator=(std::initializer_list list)

    // 1. multimap& operator=(const multimap& other)
    // 2. multimap& operator=(multimap&& other)
    // 3. multimap& operator=(std::initializer_list list)

    std::map<std::string, std::string> birthdays;
    Show(birthdays);

    std::map<std::string, std::string> birthdays;
    Show(birthdays);

    birthdays =
    {
        { "Demian Blogan", "24/12/1996" },
        { "Anna Taylor", "03/01/1986" },
        { "Victoria Cherenkova", "11/05/2000" },
    };
    Show(birthdays);

    std::map<std::string, std::string> copyBirthdays;
    Show(copyBirthdays);
    copyBirthdays = birthdays;
#pragma endregion

#pragma region Оператор []
    {
        std::cout << "-------------- operator[] --------------\n";
        // Доступ до елементів/значень класу map відбувається завдяки
        // оператору індексації, або завдяки методу at (про який розповім пізніше).

        // Ось прототипи цих методів:
        // 1. ValueType& map::operator[](const KeyType& key)
        // 2. ValueType& map::operator[](KeyType&& key)

        std::map<int, std::string> people =
        {
            { 25, "Demian" },
            { 26, "Anna" },
            { 20, "Vika" }
        };

        std::cout << "First value = [" << people[25] << "]\n";
        std::cout << "Second value = [" << people[26] << "]\n";
        std::cout << "Third value = [" << people[20] << "]\n";

        // Якщо ви укажете ключ, якого немає в контейнері, то контейнер СТВОРИТь новий елемент,
        // який буде мати цей ключ, а значення встановить завдяки конструктору за замовчуванням.

        std::cout << "Third value = [" << people[30] << "]\n";

        // Якщо зробити контейнер константним, то можна помітити,
        // що виклик цього оператора вже неможливий:

        const std::map<int, std::string> constPeople =
        {
            { 25, "Demian" },
            { 26, "Anna" },
            { 20, "Vika" }
        };

        // std::cout << "First value = [" << constPeople[25] << "]\n"; // помилка на етапі компіляції

        // Чому так? Тому що завдяки оператору [] ви можете міняти значення "значення":
        std::cout << "First value = [" << people[25] << "]\n"; // Demian
        people[25] = "David";
        std::cout << "First value = [" << people[25] << "]\n"; // David

        // Якщо зробити контейнер константним, то це треба заборонити. Тому const-версії цього оператора немає.
        // Зате є така версія в метода at:
        std::cout << "First value = [" << constPeople.at(25) << "]\n\n"; // Demian

        // А що з класом multimap? Оскільки його "значення" може бути набором значень, то у цього
        // класу немає ні перевантаженого оператора індексації, ні методу at. Як же тоді звертатися до
        // контейнера і міняти їх?

        // Варіант 1: завдяки ітераторам.
        // Варіант 2: завдяки методу find.

        // В розділі методів я покажу обидва варіанти.
    }

#pragma endregion

#pragma region  Методи
    {
        std::cout << "------------- Methods -------------\n";

        // 1. Allocator get_allocator() const noexcept
        //    Опис: повертає алокатор, який прив'язаний до контейнера.
        {
            std::map<int, double> map;

            auto allocator = map.get_allocator(); // auto = std::allocator<std::pair<const int, double>>
        }

        // 2. Value& at(const Key& key)
        //    Опис: повертає посилання на значення за указаним ключем. Якщо такого
        //    ключа не існує - кидає виключення std::out_of_range.
        {
            std::cout << "------- at -------\n";

            std::map<int, double> map;

            std::cout << map[3] << std::endl; // 0, бо індексатор створив новий елемент

            try
            {
                std::cout << map.at(5) << std::endl;
            }
            catch (const std::out_of_range& exc)
            {
                std::cout << exc.what() << "\n\n"; // invalid map<K, T> key
            }
        }

        // 3. Iterator begin() noexcept
        //    Опис: повертає ітератор/константний ітератор на перший елемент контейнера.

        // 4. Iterator end() noexcept
        //    Опис: повертає ітератор/константний ітератор на кінець контейнера.
        {
            std::cout << "------- begin & end -------\n";

            std::map<int, std::string> people =
            {
                { 25, "Demian" },
                { 26, "Anna" },
                { 20, "Vika" }
            };

            for (std::map<int, std::string>::iterator iter = people.begin(), end = people.end(); iter != end; ++iter)
            {
                const auto& key = iter->first;
                auto& value = iter->second;
                value += "++";
                std::cout << "[key = " << key << ", value = " << value << "]" << std::endl;
            }

            // Краще писати ось так:
            for (auto iter = people.begin(), end = people.end(); iter != end; ++iter)
            {
                const auto& key = iter->first;
                auto& value = iter->second;
                value += "--";
                std::cout << "[key = " << key << ", value = " << value << "]" << std::endl;
            }

            // А найкраще писати ось так:
            for (auto& element : people)
            {
                const auto& key = element.first;
                auto& value = element.second;
                value += "XXX";
                std::cout << "[key = " << key << ", value = " << value << "]" << std::endl;
            }
        }

        // 5. ConstIterator cbegin() const noexcept
        //    Опис: повертає константний ітератор на перший елемент контейнера.
        //
        // 6. ConstIterator cend() const noexcept
        //    Опис: повертає константний ітератор на кінець контейнера.

        {
            std::cout << "------- cbegin & cend -------\n";

            const std::map<int, std::string> people =
            {
                { 25, "Demian" },
                { 26, "Anna" },
                { 20, "Vika" }
            };

            for (std::map<int, std::string>::const_iterator iter = people.cbegin(), end = people.cend(); iter != end;++iter)
            {
                const auto& key = iter->first;
                auto& value = iter->second;
                //value += "+++";
                std::cout << "[key = " << key << ", value = " << value << "]" << std::endl;
            }

            // Краще писати ось так:
            for (auto iter = people.cbegin(), end = people.cend(); iter != end; ++iter)
            {
                const auto& key = iter->first;
                auto& value = iter->second;
                //value += "---";
                std::cout << "[key = " << key << ", value = " << value << "]" << std::endl;
            }

            // А найкраще писати ось так:
            for (const auto& element : people)
            {
                const auto& key = element.first;
                auto& value = element.second;
                // value += "XXX";
                std::cout << "[key = " << key << ", value = " << value << "]" << std::endl;
            }
        }


        // 7. ReverseIterator rbegin() noexcept
        //    Опис: повертає ітератор/константний ітератор на обернений перший елемент контейнера.
        //
        // 8. ReverseIterator rend() noexcept
        //    Опис: повертає реверсний ітератор на початок контейнера.
        {
            std::cout << "------- rbegin & rend -------\n";

            std::map<int, std::string> people =
            {
                { 25, "Demian" },
                { 26, "Anna" },
                { 20, "Vika" }
            };

            for (std::map<int, std::string>::reverse_iterator iter = people.rbegin(), end = people.rend(); iter != end; ++iter)
            {
                const auto& key = iter->first;
                auto& value = iter->second;
                value += "+++";
                std::cout << "[key = " << key << ", value = " << value << "]" << std::endl;
            }

            // Краще писати ось так:
            for (auto iter = people.rbegin(), end = people.rend(); iter != end; ++iter)
            {
                const auto& key = iter->first;
                auto& value = iter->second;
                value += "---";
                std::cout << "[key = " << key << ", value = " << value << "]" << std::endl;
            }

        }

        // 9. ConstReverseIterator crbegin() const noexcept
        //    Опис: повертає константний ітератор на обернений перший елемент контейнера.
        //
        // 10. ConstReverseIterator crend() const noexcept
        //    Опис: повертає константний ітератор на обернений кінець контейнера.
        {
            std::cout << "------- crbegin & crend -------\n";

            const std::map<int, std::string> people =
            {
                { 25, "Demian" },
                { 26, "Anna" },
                { 20, "Vika" }
            };

            for (std::map<int, std::string>::const_reverse_iterator iter = people.crbegin(), end = people.crend(); iter != end;++iter)
            {
                const auto& key = iter->first;
                auto& value = iter->second;
                //value += "+++";
                std::cout << "[key = " << key << ", value = " << value << "]" << std::endl;
            }

            // Краще писати ось так:
            for (auto iter = people.crbegin(), end = people.crend(); iter != end; ++iter)
            {
                const auto& key = iter->first;
                auto& value = iter->second;
                //value += "---";
                std::cout << "[key = " << key << ", value = " << value << "]" << std::endl;
            }
        }

        // 11. bool empty() const noexcept
        //    Опис: повертає true, якщо контейнер пустий.
        {
            std::cout << "------- empty -------\n";

            std::map<int, int> map1;
            std::multimap<int, int> multimap1;

            std::cout << (map1.empty() ? "map1 is empty" : "map1 isn't empty") << std::endl;
            std::cout << (multimap1.empty() ? "multimap1 is empty" : "multimap1 isn't empty") << std::endl;
        }

        // 12. size_t size() const noexcept
        //    Опис: повертає кількість елементів контейнера.
        {
            std::cout << "------- size -------\n";

            std::map<int, std::string> people =
            {
                { 25, "Demian" },
                { 26, "Anna" },
                { 20, "Vika" }
            };

            std::multimap<std::string, std::string> contacts =
            {
                { "Demian Blogan", "+380123456789" },
                { "Demian Blogan", "+380987654321" },
                { "Anna Taylor", "+380111223333" },

                { "Viktoria Cherenkova", "+380112233445" },
                { "Viktoria Cherenkova", "+380121212121" },
                { "Viktoria Cherenkova", "+380006543100" }
            };
            std::cout << "map has " << people.size() << " elements.\n"; // 3
            std::cout << "multimap has " << contacts.size() << " elements.\n"; // 6
        }

        // 13. size_t max_size() const noexcept
        //     Опис: повертає максимально допустимий розмір елементів у контейнері.
        {
            std::cout << "------- max_size -------\n";

            std::map<int, std::string> people;
            std::multimap<std::string, std::string> contacts;

            std::cout << "The map can have " << people.max_size() << " elements.\n";
            std::cout << "The multimap can have " << contacts.max_size() << " elements.\n";
        }

        // 14. void clear() noexcept
        //     Опис: очищає контейнер від елементів.
        {
            std::cout << "------- clear -------\n";

            std::map<int, std::string> people =
            {
                { 25, "Demian" },
                { 26, "Anna" },
                { 20, "Vika" }
            };

            people.clear();

            std::cout << (people.empty() ? "map is empty" : "map isn't empty") << std::endl;
        }

        // 15. std::pair<iterator, bool> insert(const std::pair<Key, Value>& value)
        // Опис: вставляє новий елемент в контейнер.
        {
            std::cout << "------- insert -------\n";

            std::map<int, std::string> map;
            map.insert(std::pair<int, std::string>(10, "Demian"));
            map.insert(std::pair<int, std::string>(5, "Olga"));
            map.insert(std::pair<int, std::string>(3, "Anna"));

            Show(map); // [key = 3, value = Anna]
            // [key = 5, value = Olga]
            // [key = 10, value = Demian]
        }

        // 16. template <typename... Args>
        //     std::pair<iterator, bool> emplace(Args&&... args)
        //     Опис: конструює новий елемент в контейнері.
        {
            std::cout << "------- emplace -------\n";

            std::map<int, std::string> map;
            map.emplace(10, "Demian");
            map.emplace(5, "Olga");
            map.emplace(3, "Anna");

            Show(map); // [key = 3, value = Anna]
            // [key = 5, value = Olga]
            // [key = 10, value = Demian]
        }

        // 17. template <typename... Args>
        //     iterator emplace_hint(const_iterator hint, Args&&... args)
        //     Опис: конструює новий елемент в контейнері, використовуючи ітератор як підказку того,
        //     біля якого місця вставити елемент.

        // 18. iterator erase(iterator position)
        //     size_t erase(const Key& key);
        //     Опис: видаляє елемент з контейнеру (по ітератору, або по ключу).
        {
            std::cout << "------- erase -------\n";

            std::map<int, std::string> people =
            {
                { 25, "Demian" },
                { 26, "Anna" },
                { 20, "Vika" }
            };

            people.erase(people.begin());
            people.erase(26);

            Show(people); // [key = 25, value = Demian]
        }

        // 19. void swap(std::map& other)
        //    Опис: міняє вміст двох контейнерів місцями.

        // 20. size_t count(const Key& key) const
        //    Опис: рахує кількість значень, які прив'язані до конкретного ключа. В контейнері std::map
        //          завжди повертає 0 (значить немає такого ключа), або 1 (значить ключ існує). В класі
        //          std::multimap повертає 0 (значить немає такого ключа) або любе число значень, які прив'язані
        //          до цього ключа.
        {
            std::cout << "------- count -------\n";

            std::multimap<std::string, int> cityTemperatures =
            {
                { "Rivne", 20 },
                { "Rivne", 15 },
                { "Rivne", 17 },

                { "Kiev", 13 },
                { "Kiev", 14 },
            };
            std::cout << "City Rivne has " << cityTemperatures.count("Rivne") << " temperatures.\n"; //3
            std::cout << "City Kiev has " << cityTemperatures.count("Kiev") << " temperatures.\n";   //2
        }

        // 21. iterator find(const Key& key)
        //     Опис: шукає елемент по заданому ключу. Якщо елемент існує, то повертає ітератор на нього.
        //     Інакше повертає ітератор end().
        {
            std::cout << "------- find -------\n";

            std::multimap<std::string, int> cityTemperatures =
            {
                { "Rivne", 20 },
                { "Rivne", 15 },
                { "Rivne", 17 },

                { "Kiev", 13 },
                { "Kiev", 14 },
            };

            auto findIterator = cityTemperatures.find("Rivne");
            if (findIterator != cityTemperatures.cend()) // true
            {
                std::cout << "Element Rivne exists.\n";
            }

            findIterator = cityTemperatures.find("Odessa");
            if (findIterator != cityTemperatures.cend()) // false
            {
                std::cout << "Element Odessa exists.\n";
            }

        }

        // 22. iterator lower_bound(const Key& key)
        //    Опис: повертає ітератор, який указує на ПЕРШИЙ елемент, який НЕ МЕНШИЙ за елемент за заданим ключем. 
        //    В контейнері std::map має мало сенсу, так як повертає або ітератор на елемент по ключу, або end(). 
        //    Використовується в основному в контейнері std::multimap для того, щоб отримати початковий елемент 
        //    діапазону елементів, які прив'язані до указаного ключа.

        // 23. iterator upper_bound(const Key& key)
        //    Опис: повертає ітератор, який указує на ПЕРШИЙ елемент, який БІЛЬШИЙ за елемент за заданим ключем. 
        //    В контейнері std::map має мало сенсу, так як повертає або ітератор на елемент який є наступним до того, 
        //    який указаний по ключу, або end(). Використовується в основному в контейнері std::multimap для того, 
        //    щоб отримати елемент, який свідчить про кінець діапазону елементів, які прив'язані до указаного ключа.

        // 24. std::pair<iterator, iterator> equal_range(const Key& key)
        //    Опис: повертає пару з двох ітераторів. Перший - це той, який повертає метод lower_bound. 
        //    Другий - це той, який повертає метод upper_bound. Використовується тоді, коли треба викликати 
        //    lower_bound і upper_bound. Працює швидше, чим виклик цих методів поокремо.
        {
            std::cout << "------- lower_bound & upper_bound & equal_range -------\n";

            std::multimap<std::string, int> cityTemperatures =
            {
                { "Rivne", 20 },
                { "Rivne", 15 },
                { "Rivne", 17 },

                { "Kiev", 13 },
                { "Kiev", 14 },
            };

            auto rivneBeginIter = cityTemperatures.lower_bound("Rivne");
            auto rivneEndIter = cityTemperatures.upper_bound("Rivne");

            if (rivneBeginIter == cityTemperatures.cend()) // false
            {
                std::cout << "Key Rivne doesn't exist.\n";
            }

            std::cout << "Temperatures: ";
            for (auto iter = rivneBeginIter; iter != rivneEndIter; ++iter)
            {
                std::cout << iter->second << " "; // 20 15 17
            }
            std::cout << std::endl;

            auto rivneIterRange = cityTemperatures.equal_range("Rivne");
            if (rivneIterRange.first == cityTemperatures.cend()) // false
            {
                std::cout << "Key Rivne doesn't exist.\n";
            }

            std::cout << "Temperatures: ";
            for (auto iter = rivneIterRange.first; iter != rivneIterRange.second; ++iter)
            {
                std::cout << iter->second << " "; // 20 15 17
            }
            std::cout << std::endl;
        }

        // 25. key_compare key_comp() const
        //     Опис: повертає функтор, який використовується для порівнювання ключів (завдяки якому сортується контейнер).

        // 26. value_compare value_comp() const
        //     Опис: повертає функтор, який використовується для порівнювання "значень" (в даному контексті пари із ключа і значення).
        {
            std::cout << "------- key_cmp & value_comp -------\n";

            std::multimap<std::string, int> cityTemperatures =
            {
                { "Rivne", 20 },
                { "Rivne", 15 },
                { "Rivne", 17 },

                { "Kiev", 13 },
                { "Kiev", 14 }
            };

            auto keyComparator = cityTemperatures.key_comp();
            auto valueComparator = cityTemperatures.value_comp();

            // keyComparator має перевантажений оператор виклику функції, який має наступний прототип:
            // bool operator(const std::string& left, const std::string& right) const
            //
            // valueComparator має перевантажений оператор виклику функції, який має наступний прототип:
            // bool operator(std::pair<const std::string, int>& left, std::pair<const std::string, int>& right) const
        }
    }
#pragma endregion

#pragma region Функції
    {
        // operator==
        // operator!= (видалений в C++20)
        // operator< (видалений в C++20)
        // operator<= (видалений в C++20)
        // operator> (видалений в C++20)
        // operator>= (добавлений в C++20)

        // В 10-й раз не хочу уже пояснювати, що означають ці оператори. Думаю, ви догадуєтеся,
        // що завдяки ним ви можете порівнювати вміст двох контейнерів.

        // Ну і так само є функція std::swap для контейнерів std::map і std::multimap, яка робить
        // аналогічну роботу до std::map::swap() і std::multimap::swap().
    }
#pragma endregion

    return 0;
}
