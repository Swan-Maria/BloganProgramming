#include <iostream>
#include <string>

/*
* Хеш-таблиця це абстрактна структура даних, яка швидко надає дані по ключу 
* незалежно від кількості даних. Швидко це зазвичай 0(1). 

* Хеш-функція -  це функція, яка приймає ключ і перетворює його в значення
* завдяки певному алгоритму.

* Колізія - це ситуація, коли хоча б два ключа претендують на один індексю

* Методи вірішення колізії:
* 1. Метод відкритої адресації
* 2. Метод ланцюжків

* Властивості хорошої хеш-функції:
* 1. Детермінізм - для одного і того самого ключа завжди видається одне і те саме значення
* 2. Рівномірність - функція для кожного ключа має видавати інше значення. В ідеалі це не можливо,
				   * бо кількість елементів в теорії може бути безкінечна, але до цього треба прагнути.
* 3. Ефективність - функція має швидкл рахувати значення з ключу.
* 4. Обмеженість - функція має видавати індекси, які будуть находитися в межах таблиці.

*/

template <typename Key, typename Value>
class HashTable
{
private:
	struct Node
	{
		Key key;
		Value value;
		std::unique_ptr<Node> next;
	};

	size_t m_size;
	Node** m_table;

	size_t HashFunction(const Key& key) const
	{
		return std::hash<Key>()(key) % m_size;
	}

public:
	HashTable(size_t size = 10;)
		: m_size(size)
		, m_table(new Node*[size]{})
	{	}

	HashTable(const HashTable&) = delete;
	HashTable& operator=(const HashTable&) = delete;
	
	~HashTable()
	{
		Clear();
		delete[] m_table;
	}

	void Insert(const Key& key, const Value& value)
	{
		size_t index = HashTable(key);
		Node*& node m_table[intdex]; //m_table[intdex] поветрає Node*
		while (node != nullptr)
		{
			if (node->key == key)
			{
				node->value = value;
				return;
			}
			node = node->next.get();
		}
		node = new Node{ key, value, std::unique_ptr<Node>(nullptr) }
	}

	const Value& Search(const Key& key) const
	{
		size_t index = HashTable(key);
		Node*& node m_table[intdex]; //m_table[intdex] поветрає Node*
		while (node != nullptr)
		{
			if (node->key == key)
			{
				return node->value;
			}
			node = node->next.get();
		}
		throw std::out_of_range("Key wasn`t found in hash table");
	}

	bool Remove(const Key& key)
	{
		size_t index = HashTable(key);
		Node*& node m_table[intdex]; //m_table[intdex] поветрає Node*
		if (node == nullptr)
		{
			return false;
		}
		//If key of the first Node eq key:
		if (node->key == key)
		{
			std::unique_ptr<Node> temp(std::move(node->next));
			delete node;
			node = temp.release();
			return true;
		}
		//else
		Node* prev = node;
		Node* curr = node->next.get();
		while (curr != nullptr)
		{
			if (curr->key==key)
			{
				std::unique_ptr<Node> temp(std::move(curr->next));
				prev->next = std::move(temp);
				delete curr;
				return true;
			}
			prev = curr;
			curr = curr->next.get();
		}
		return false;
	}

	void Clear()
	{
		for (size_t i = 0; i < m_size; i++)
		{
			while(m_table[i] != nullptr)
			{
				std::unique_ptr<Node> temp(std::move(m_table[i]->next));
				delete m_table[i];
				m_table[i] = temp.release();
			}
		}
	}
};

template <typename Key, typename Value>
void ShowValue(const HashTable<Key, Value>& table, const Key& key)
{
	try
	{
		std::string findValue = table.Search(key);
		std::cout << key << ": [" << findValue << "]\n";
	}
	catch (const std::out_of_range& exc)
	{
		std::cout << exc.what() << std::endl;
	}
}

int main()
{
	HashTable<std::string, std::string> dictionary;
	dictionary.Insert("Frog", "This os frog.");
	dictionary.Insert("Cat", "This os cat.");
	dictionary.Insert("Dog", "This os Dog.");
	ShowValue<std::string, std::string>(dictionary, "Dog");
	if (!dictionary.Remove("Dog"))
	{
		std::cout << "Key doesn`t exit.\n";
	}
	ShowValue<std::string, std::string>(dictionary, "Dog");
	ShowValue<std::string, std::string>(dictionary, "Frog");
	dictionary.Clear();
	ShowValue<std::string, std::string>(dictionary, "Frog");
}