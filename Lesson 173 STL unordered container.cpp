#include <iostream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>

/*
* ������ unordered ���������� (map, multimap, set, multiset) � �++14 �������
* ----------------------------------------------------------------------------
* begin
* cbegin
* end
* cend
* clear
* empty
* count
* insert
* emplace
* emplace_hint
* upper_bound
* lower_bound
* equal_bound
* erase
* find
* max_size
* reserve
* size
* get_allocator
* key_eq
* swap
* operator=
* -----------------------------------------------------------------------------
* map �� ���������:
* st
* operator[]
* -----------------------------------------------------------------------------
* bucket - ������ ����, ������� ������, �� ��� ���� �����������
* bucket_count - ������� �������� � �������
* bucket_size - ���� ������� ������� �������� � �������
* hash_function 
* load_factor 
* max_bucket_count
* max_load_factor
* rehash
*/

//hash - �� ���������, ��� � ���������.

class Person
{
private:
	std::string name;
	int age;
public:
	Person(const std::string& name, int age)
		: name(name), age(age) {
	}

	std::string GetName() const { return name; }
	int GetAge()const { return age; }

	bool operator==(const Person& other) const
	{
		return name == other.name && age == other.age;
	}
};

namespace std
{
	template<>
	struct  hash<Person>
	{
		size_t operator()(const Person& p) const
		{
			return hash<string>()(p.GetName()) ^ hash<int>()(p.GetAge());
		}
	};
}

void HashTest()
{
	std::unordered_map<Person, int> ageMap;
	Person demian("Demian Blogan", 26);
	Person clementina("Clementina Wolder", 20);
	ageMap[demian] = 30;
	ageMap[clementina] = 25;
}

int main()
{

}