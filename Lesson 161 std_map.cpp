// [+] ��� �� ���� ���� ?
// [+] ����� ������
// [+] ��������� �������
// [+] ��������� - �����
// [ ] ������������
// [ ] ����������
// [ ] �������� =
// [ ] �������� []
// [ ] ������
// [ ] �������
// [ ] � - �������
// [ ] ������

#include <iostream>
// ���������� ����� �������� STL:
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <array>
#include <stack>
#include <queue>
#include <set>
#include <map> // <- ��� ���� ����� ��������� ��� ������ std::map � std::multimap

#include "Lesson 161 STLTools.h"

int main()
{
#pragma region ������������
    {
		std::cout << "---------------------- Constructors ----------------------\n";

        // -------------------------------- ������������ ����� map ------------------------------------
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

        // -------------------------------- ������������ �����  multi map ------------------------------------
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

        // ----------------------------- ������� -----------------------------

        std::map<int, std::string> empty; // ����������� �1
        Show(empty);

        std::map<int, std::string> people = // ����������� �13
        {
            { 25, "Demian" },
            { 26, "Anna" },
            { 20, "Vika" }
        };
        Show(people);

        std::map<int, std::string> copy(people); // ����������� �2
        Show(copy);

        std::vector<std::pair<unsigned, std::string>> otherEmployees =
        {
            { 1, "Demian Blogan" },
            { 2, "Anna Taylor" },
            { 3, "Viktoria Cherenkova" }
        };

        std::map<int, std::string> employees(otherEmployees.cbegin(), otherEmployees.cend()); // �������
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

#pragma region �����������
    // �� ������������� ��� �������� ����� �������� � ����� ���������, ���'��� �� ��� ���������� �� ����
    // ������� ��������� �� ������������� - std::allocator. � � ���������� ��� ���������� �� ���'��� �����������
    // �����������. ���������� map � multimap - �� ����������.
#pragma endregion

#pragma region �������� =
    std::cout << "------------- operator= -------------\n";

    // ����� map � multimap ����� ���������������� �������� ���������:
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

#pragma region �������� []
    {
        std::cout << "-------------- operator[] --------------\n";
        // ������ �� ��������/������� ����� map ���������� �������
        // ��������� ����������, ��� ������� ������ at (��� ���� ������� �����).

        // ��� ��������� ��� ������:
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

        // ���� �� ������� ����, ����� ���� � ���������, �� ��������� �������� ����� �������,
        // ���� ���� ���� ��� ����, � �������� ���������� ������� ������������ �� �������������.

        std::cout << "Third value = [" << people[30] << "]\n";

        // ���� ������� ��������� �����������, �� ����� �������,
        // �� ������ ����� ��������� ��� ����������:

        const std::map<int, std::string> constPeople =
        {
            { 25, "Demian" },
            { 26, "Anna" },
            { 20, "Vika" }
        };

        // std::cout << "First value = [" << constPeople[25] << "]\n"; // ������� �� ���� ���������

        // ���� ���? ���� �� ������� ��������� [] �� ������ ����� �������� "��������":
        std::cout << "First value = [" << people[25] << "]\n"; // Demian
        people[25] = "David";
        std::cout << "First value = [" << people[25] << "]\n"; // David

        // ���� ������� ��������� �����������, �� �� ����� ����������. ���� const-���� ����� ��������� ����.
        // ���� � ���� ����� � ������ at:
        std::cout << "First value = [" << constPeople.at(25) << "]\n\n"; // Demian

        // � �� � ������ multimap? ������� ���� "��������" ���� ���� ������� �������, �� � �����
        // ����� ���� � ��������������� ��������� ����������, � ������ at. �� �� ��� ���������� ��
        // ���������� � ����� ��?

        // ������ 1: ������� ����������.
        // ������ 2: ������� ������ find.

        // � ����� ������ � ������ ������ �������.
    }

#pragma endregion

#pragma region  ������
    {
        std::cout << "------------- Methods -------------\n";

        // 1. Allocator get_allocator() const noexcept
        //    ����: ������� ��������, ���� ����'������ �� ����������.
        {
            std::map<int, double> map;

            auto allocator = map.get_allocator(); // auto = std::allocator<std::pair<const int, double>>
        }

        // 2. Value& at(const Key& key)
        //    ����: ������� ��������� �� �������� �� �������� ������. ���� ������
        //    ����� �� ���� - ���� ���������� std::out_of_range.
        {
            std::cout << "------- at -------\n";

            std::map<int, double> map;

            std::cout << map[3] << std::endl; // 0, �� ���������� ������� ����� �������

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
        //    ����: ������� ��������/����������� �������� �� ������ ������� ����������.

        // 4. Iterator end() noexcept
        //    ����: ������� ��������/����������� �������� �� ����� ����������.
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

            // ����� ������ ��� ���:
            for (auto iter = people.begin(), end = people.end(); iter != end; ++iter)
            {
                const auto& key = iter->first;
                auto& value = iter->second;
                value += "--";
                std::cout << "[key = " << key << ", value = " << value << "]" << std::endl;
            }

            // � �������� ������ ��� ���:
            for (auto& element : people)
            {
                const auto& key = element.first;
                auto& value = element.second;
                value += "XXX";
                std::cout << "[key = " << key << ", value = " << value << "]" << std::endl;
            }
        }

        // 5. ConstIterator cbegin() const noexcept
        //    ����: ������� ����������� �������� �� ������ ������� ����������.
        //
        // 6. ConstIterator cend() const noexcept
        //    ����: ������� ����������� �������� �� ����� ����������.

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

            // ����� ������ ��� ���:
            for (auto iter = people.cbegin(), end = people.cend(); iter != end; ++iter)
            {
                const auto& key = iter->first;
                auto& value = iter->second;
                //value += "---";
                std::cout << "[key = " << key << ", value = " << value << "]" << std::endl;
            }

            // � �������� ������ ��� ���:
            for (const auto& element : people)
            {
                const auto& key = element.first;
                auto& value = element.second;
                // value += "XXX";
                std::cout << "[key = " << key << ", value = " << value << "]" << std::endl;
            }
        }


        // 7. ReverseIterator rbegin() noexcept
        //    ����: ������� ��������/����������� �������� �� ��������� ������ ������� ����������.
        //
        // 8. ReverseIterator rend() noexcept
        //    ����: ������� ��������� �������� �� ������� ����������.
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

            // ����� ������ ��� ���:
            for (auto iter = people.rbegin(), end = people.rend(); iter != end; ++iter)
            {
                const auto& key = iter->first;
                auto& value = iter->second;
                value += "---";
                std::cout << "[key = " << key << ", value = " << value << "]" << std::endl;
            }

        }

        // 9. ConstReverseIterator crbegin() const noexcept
        //    ����: ������� ����������� �������� �� ��������� ������ ������� ����������.
        //
        // 10. ConstReverseIterator crend() const noexcept
        //    ����: ������� ����������� �������� �� ��������� ����� ����������.
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

            // ����� ������ ��� ���:
            for (auto iter = people.crbegin(), end = people.crend(); iter != end; ++iter)
            {
                const auto& key = iter->first;
                auto& value = iter->second;
                //value += "---";
                std::cout << "[key = " << key << ", value = " << value << "]" << std::endl;
            }
        }

        // 11. bool empty() const noexcept
        //    ����: ������� true, ���� ��������� ������.
        {
            std::cout << "------- empty -------\n";

            std::map<int, int> map1;
            std::multimap<int, int> multimap1;

            std::cout << (map1.empty() ? "map1 is empty" : "map1 isn't empty") << std::endl;
            std::cout << (multimap1.empty() ? "multimap1 is empty" : "multimap1 isn't empty") << std::endl;
        }

        // 12. size_t size() const noexcept
        //    ����: ������� ������� �������� ����������.
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
        //     ����: ������� ����������� ���������� ����� �������� � ���������.
        {
            std::cout << "------- max_size -------\n";

            std::map<int, std::string> people;
            std::multimap<std::string, std::string> contacts;

            std::cout << "The map can have " << people.max_size() << " elements.\n";
            std::cout << "The multimap can have " << contacts.max_size() << " elements.\n";
        }

        // 14. void clear() noexcept
        //     ����: ����� ��������� �� ��������.
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
        // ����: �������� ����� ������� � ���������.
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
        //     ����: ��������� ����� ������� � ���������.
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
        //     ����: ��������� ����� ������� � ���������, �������������� �������� �� ������� ����,
        //     ��� ����� ���� �������� �������.

        // 18. iterator erase(iterator position)
        //     size_t erase(const Key& key);
        //     ����: ������� ������� � ���������� (�� ���������, ��� �� �����).
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
        //    ����: ���� ���� ���� ���������� ������.

        // 20. size_t count(const Key& key) const
        //    ����: ���� ������� �������, �� ����'���� �� ����������� �����. � ��������� std::map
        //          ������ ������� 0 (������� ���� ������ �����), ��� 1 (������� ���� ����). � ����
        //          std::multimap ������� 0 (������� ���� ������ �����) ��� ���� ����� �������, �� ����'����
        //          �� ����� �����.
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
        //     ����: ���� ������� �� �������� �����. ���� ������� ����, �� ������� �������� �� �����.
        //     ������ ������� �������� end().
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
        //    ����: ������� ��������, ���� ����� �� ������ �������, ���� �� ������ �� ������� �� ������� ������. 
        //    � ��������� std::map �� ���� �����, ��� �� ������� ��� �������� �� ������� �� �����, ��� end(). 
        //    ��������������� � ��������� � ��������� std::multimap ��� ����, ��� �������� ���������� ������� 
        //    �������� ��������, �� ����'���� �� ��������� �����.

        // 23. iterator upper_bound(const Key& key)
        //    ����: ������� ��������, ���� ����� �� ������ �������, ���� ������� �� ������� �� ������� ������. 
        //    � ��������� std::map �� ���� �����, ��� �� ������� ��� �������� �� ������� ���� � ��������� �� ����, 
        //    ���� �������� �� �����, ��� end(). ��������������� � ��������� � ��������� std::multimap ��� ����, 
        //    ��� �������� �������, ���� ������� ��� ����� �������� ��������, �� ����'���� �� ��������� �����.

        // 24. std::pair<iterator, iterator> equal_range(const Key& key)
        //    ����: ������� ���� � ���� ���������. ������ - �� ���, ���� ������� ����� lower_bound. 
        //    ������ - �� ���, ���� ������� ����� upper_bound. ��������������� ���, ���� ����� ��������� 
        //    lower_bound � upper_bound. ������ ������, ��� ������ ��� ������ ��������.
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
        //     ����: ������� �������, ���� ��������������� ��� ����������� ������ (������� ����� ��������� ���������).

        // 26. value_compare value_comp() const
        //     ����: ������� �������, ���� ��������������� ��� ����������� "�������" (� ������ �������� ���� �� ����� � ��������).
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

            // keyComparator �� �������������� �������� ������� �������, ���� �� ��������� ��������:
            // bool operator(const std::string& left, const std::string& right) const
            //
            // valueComparator �� �������������� �������� ������� �������, ���� �� ��������� ��������:
            // bool operator(std::pair<const std::string, int>& left, std::pair<const std::string, int>& right) const
        }
    }
#pragma endregion

#pragma region �������
    {
        // operator==
        // operator!= (��������� � C++20)
        // operator< (��������� � C++20)
        // operator<= (��������� � C++20)
        // operator> (��������� � C++20)
        // operator>= (���������� � C++20)

        // � 10-� ��� �� ���� ��� ����������, �� ��������� �� ���������. �����, �� ����������,
        // �� ������� ��� �� ������ ���������� ���� ���� ����������.

        // �� � ��� ���� � ������� std::swap ��� ���������� std::map � std::multimap, ��� ������
        // ��������� ������ �� std::map::swap() � std::multimap::swap().
    }
#pragma endregion

    return 0;
}
