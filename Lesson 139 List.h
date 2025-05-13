#pragma once
#include <stdexcept>
template<typename T>
class List
{
private:
	void Copy(const List& other)
	{
		if (other.head == nullptr)
		{
			head = nullptr;
			tail = nullptr;
			size = 0;
			return;
		}
		else
		{
			head = new Node{ other.head->data, nullptr };
			Node* current = head;
			Node* otherCurrent = other.head->next;
			while (otherCurrent != nullptr)
			{
				current->next = new Node{ otherCurrent->data, nullptr };
				current = current->next;
				otherCurrent = otherCurrent->next;
			}
			tail = current;
			size = other.size;
		}
	}

	struct Node
	{
		T data;
		Node* next;
	};

	Node* head;
	Node* tail;
	size_t size;

public:
	class Iterator
	{
	public:
		Iterator(Node* node) : node(node) {}
		bool operator!=(const Iterator& other) const 
		{ 
			return node != other.node; 
		}

		Iterator& operator++()
		{
			node = node->next;
			return *this;
		}
		Iterator operator++(int)
		{
			Iterator temp = *this;
			node = node->next;
			return temp;
		}

		T& operator*()
		{
			return node->data;
		}
	private:
		Node* node;
	};

	//Constructors
	List() : head(nullptr), tail(nullptr), size(0) {}
	List(const List& other) 
		: head(nullptr), tail(nullptr), size(0)
	{
		Copy(other);
	}
	List(List&& other) noexcept 
		: head(other.head), tail(other.tail), size(other.size)
	{
		other.head = nullptr;
		other.tail = nullptr;
		other.size = 0;
	}

	//Destructor
	~List()
	{
		Clear();
	}

	//Insert methods
	void PushBack(const T& value)
	{
		if (head == nullptr)
		{
			head = new Node{ value,nullptr };
			tail = head;
		}
		else
		{
			tail->next = new Node{ value,nullptr };
			tail = tail->next;
		}
		size++;
	}
	void PushFront(const T& value)
	{
		if (head == nullptr)
		{
			head = new Node{ value,nullptr };
			tail = head;
		}
		else if (head == tail)
		{
			Node* newNode = new Node{ value, head };
			head = newNode;
			tail= head->next;
		}
		else
		{
			Node* newNode = new Node{ value, head };
			head = newNode;
		}
		size++;
	}

	//Remove methods
	void PopBack()
	{
		if (head == nullptr)
		{
			return;
		}
		else if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			Node* previous = head;
			Node* current = head->next;

			while (current->next->next != nullptr)
			{
				previous = current;
				current = current->next;
			}

			delete current;
			previous->next = nullptr;
			tail = previous;
		}
		size--;
	}
	void PopFront()
	{
		if (head == nullptr)
		{
			return;
		}
		else if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			Node* newHead = head->next;
			delete head;
			head = newHead;
		}
		size--;
	}
	void Remove(const T& value)
	{
		Node* previous = nullptr;
		Node* current = head;
		while (current != nullptr )
		{
			if (current->data == value)
			{
				if (previous == nullptr)
				{
					head = head->next;
					if (head == nullptr)
					{
						tail = nullptr;
					}
				}
				else
				{
					previous->next = current->next;
					if (current==tail)
					{
						tail = previous;
					}
				}
				delete current;
				size--;
				return;
			}

			previous = current;
			current = current->next;
		}
	}
	void Clear()
	{
		while (head != nullptr)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		tail = nullptr;
		size = 0;
	}
	
	//Find methods
	bool Find(const T& value) const
	{
		if (head == nullptr)
		{
			return false;
		}

		Node* current = head;

		while (current != nullptr)
		{
			if (current->data == value)
			{
				return true;
			}
			current = current->next;
		}

		return false;
	}

	//Check size methods
	bool IsEmpty() const
	{
		return head == nullptr;
	}
	size_t Size() const
	{
		return size;
	}

	//Assignment operators
	List& operator=(const List& other)
	{
		if (this != &other)
		{
			Clear();
			Copy(other);
		}
		return *this;
	}
	List& operator=(List&& other) noexcept
	{
		if (this != &other)
		{
			Clear();
			head = other.head;
			tail = other.tail;
			size = other.size;
			other.head = nullptr;
			other.tail = nullptr;
			other.size = 0;
		}
		return *this;
	}

	//Index operator
	T& operator[](size_t index)
	{
		if (index <= size)
		{
			throw std::out_of_range("Index out of range");
		}

		Node* current = head;
		
		for (size_t i = 0; i < index; ++i)
		{
			current = current->next;
		}

		return current->data;
	}
	const T& operator[](size_t index) const
	{
		if (index <=  size)
		{
			throw std::out_of_range("Index out of range");
		}

		Node* current = head;

		for (size_t i = 0; i < index; ++i)
		{
			current = current->next;
		}

		return current->data;
	}

	//Extra methods
	//void Show() const
	//{
	//	if (head == nullptr)
	//	{
	//		std::cout << "List is empty\n";
	//	}
	//	else
	//	{
	//		Node* current = head;
	//		while (current != nullptr)
	//		{
	//			std::cout << current->data << " ";
	//			current = current->next;
	//		}
	//		std::cout << std::endl;
	//	}
	//}

	//Iterator methods
	Iterator Begin() { return Iterator(head); }
	Iterator End() { return Iterator(tail->next); }

};