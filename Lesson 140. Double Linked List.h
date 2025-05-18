#pragma once
#include <utility>
#include <iostream>

template <typename T>
class List
{
private:
	struct Node
	{
		T data;
		Node* previous;
		Node* next;
	};

	Node* head;
	Node* tail;
	size_t size;
	
	void Copy(const List& other)
	{
		if (other.size == 0)
		{
			return;
		}
		head = new Node{ other.head->data, nullptr, nullptr };
		Node* current = head;
		Node* otherCurrent = other.head->next;
		while (otherCurrent != nullptr)
		{
			current->next = new Node{ otherCurrent->data, current, nullptr };
			current = current->next;
			otherCurrent = otherCurrent->next;
		}
		size = other.size;
	}
	void Move(List&& other) noexcept
	{
		head = other.head;
		tail = other.tail;
		size = other.size;

		other.head = nullptr;
		other.tail = nullptr;
		other.size = 0;
	} 
	void PopHead()
	{
		Node* temp = head;
		head = head->next;
		head->previous = nullptr;
		delete temp;
	}
	void PopTail()
	{
		Node* temp = tail;
		tail = tail->previous;
		tail->next = nullptr;
		delete temp;
	}
	void PopOnlyOneNode()
	{
		delete head;
		head = nullptr;
		tail = nullptr;
	}

#pragma region ITERATORS
public:
	class Iterator
	{
	private:
		Node* ptr;
	public:
		Iterator(Node* ptr)
			:ptr(ptr)
		{}

		T& operator*(){ return ptr->data; }
		T* operator->() { return &ptr->data; }
		Iterator& operator++() { ptr = ptr->next; return *this; }
		Iterator operator++(int) { Iterator temp(*this); ptr = ptr->next; return *this;	}
		Iterator& operator--() { ptr = ptr->previous; return *this; }
		Iterator operator--(int) { Iterator temp(*this); ptr = ptr->previous; return *this;}
		bool operator==(const Iterator other)const { return ptr == other.ptr; }
		bool operator!=(const Iterator other)const { return ptr != other.ptr; }
	};

	class ConstIterator
	{
	private:
		Node* ptr;
	public:
		ConstIterator(Node* ptr)
			:ptr(ptr)
		{}

		const T& operator*() { return ptr->data; }
		const T* operator->() { return &ptr->data; }
		ConstIterator& operator++() { ptr = ptr->next; return *this; }
		ConstIterator operator++(int) { ConstIterator temp(*this); ptr = ptr->next; return *this; }
		ConstIterator& operator--() { ptr = ptr->previous; return *this; }
		ConstIterator operator--(int) { ConstIterator temp(*this); ptr = ptr->previous; return *this; }
		bool operator==(const ConstIterator other)const { return ptr == other.ptr; }
		bool operator!=(const ConstIterator other)const { return ptr != other.ptr; }
	};
	
	class ReverseIterator
	{
	private:
		Node* ptr;
	public:
		ReverseIterator(Node* ptr)
			:ptr(ptr)
		{}

		T& operator*() { return ptr->data; }
		T* operator->() { return &ptr->data; }
		ReverseIterator& operator++() { ptr = ptr->previous; return *this; }
		ReverseIterator operator++(int) { ReverseIterator temp(*this); ptr = ptr->previous; return *this; }
		ReverseIterator& operator--() { ptr = ptr->next; return *this; }
		ReverseIterator operator--(int) { ReverseIterator temp(*this); ptr = ptr->next; return *this; }
		bool operator==(const ReverseIterator other)const { return ptr == other.ptr; }
		bool operator!=(const ReverseIterator other)const { return ptr != other.ptr; }
	};

	class ConstReverseIterator
	{
	private:
		Node* ptr;
	public:
		ConstReverseIterator(Node* ptr)
			:ptr(ptr)
		{}

		const T& operator*() { return ptr->data; }
		const T* operator->() { return &ptr->data; }
		ConstReverseIterator& operator++() { ptr = ptr->previous; return *this; }
		ConstReverseIterator operator++(int) { ConstReverseIterator temp(*this); ptr = ptr->previous; return *this; }
		ConstReverseIterator& operator--() { ptr = ptr->next; return *this; }
		ConstReverseIterator operator--(int) { ConstReverseIterator temp(*this); ptr = ptr->next; return *this; }
		bool operator==(const ConstReverseIterator other)const { return ptr == other.ptr; }
		bool operator!=(const ConstReverseIterator other)const { return ptr != other.ptr; }
	};

	Iterator Begin() { return Itarator(head); }
	ConstIterator CBegin() { return ConstItarator(head); }

	Iterator End() { return Itarator(nullptr); }
	ConstIterator CEnd() { return ConstItarator(nullptr); }
	
	Iterator RBegin() { return ReverseItarator(tail); }
	ConstIterator CRBegin() { return ConstReverseIterator(tail); }

	Iterator REnd() { return ReverseItarator(nullptr); }
	ConstIterator CREnd() { return ConstReverseIterator(nullptr); }
#pragma endregion

public:
	List<T>() 
		:head(nullptr), tail(nullptr), size(0)
	{}
	List<T>(const List& other)
		:head(nullptr), tail(nullptr), size(0) 
	{
		if (other.size != 0)
		{
			Copy(other);
		}
	}
	List<T>(List&& other) noexcept
	{
		Move(std::move(other));
	}

	~List<T>()
	{
		Clear();
	}

	List<T>& operator=(const List& other)
	{
		if (this != &other)
		{
			Clear();
			Copy(other);
		}
		return *this;
	}
	List<T>& operator=(List&& other) noexcept
	{
		if (this != &other)
		{
			Clear();
			Move(std::move(other));
		}
		return *this;
	}

	void PushBack(const T& value)
	{
		if (size == 0)
		{
			head = new Node{ value, nullptr, nullptr };
			tail = head;
		}
		else
		{
			tail->next = new Node{ value, tail, nullptr };
			tail = tail->next;
		}
		size++;
	}
	void PushFront(const T& value) 
	{
		if (size == 0)
		{
			head = new Node{ value, nullptr, nullptr };
			tail = head;
		}
		else
		{
			head = new Node{ value, tail, nullptr };
			head->next->previous=head;
		}
		size++;
	}

	void PopBack() 
	{
		if (size == 0)
		{
			return;
		}
		if (size == 1)
		{
			PopOnlyOneNode();
		}
		else
		{
			PopTail();
		}
		size--;
	}
	void PopFront() 
	{
		if (size == 0)
		{
			return;
		}
		if (size == 1)
		{
			PopOnlyOneNode();
		}
		else
		{
			PopHead();
		}
		size--;
	}

	int& Front() 
	{
		return head->data;
	}
	const int& Front() const
	{
		return head->data;
	}

	int& Back() 
	{
		return tail->data;
	}
	const int& Back() const
	{
		return tail->data;
	}

	void Remove(const T& value) 
	{
		Node* current = head;
		while (current != nullptr)
		{
			if (current->data == value)
			{
				if (head == current)
				{
					if (size == 1)
					{
						PopOnlyOneNode();
					}
					else
					{
						PopHead();
					}
				}
				else if (tail == current)
				{
					PopTail();
				}
				else
				{
					current->previous->next = current->next;
					current->next->previous = current->previous;
					delete current;
				}
				size--;
				return;
			}
			current = current->next;
		}
	}
	bool Find(const T& value)
	{
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

	void Reverse() 
	{
		tail = head;
		Node* current = head;
		Node* temp = nullptr;
		while (current != nullptr)
		{
			temp = current->previous;
			current->previous = current->next;
			current->next = temp;
			
			current = current->previous;
		}
		if (temp != nullptr)
		{
			head = temp->previous;
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

	bool IsEmpty() const 
	{
		return size == 0;
	}
	size_t Size() const 
	{
		return size;
	}

	void Show() const 
	{
		if (size == 0)
		{
			std::cout << "List is empty\n";
			return;
		}

		Node* current = head;

		while (current != nullptr)
		{
			std::cout << current->data << " ";
			current = current->next;
		}
		std::cout << "\n";
	}
};