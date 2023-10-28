#pragma once
#include <iostream>
#include <exception>
#include <string>
#include <sstream>

template<typename T>
class List
{
public:
	/**
	@brief  конструктор класса List.
	*/
	List();

	/**
	* @brief Деструктор
	*/
	~List();

	/**
	@brief Функция добавляющая элемент в конец списка.
	@param data Данные добавляемые в список.
	*/
	void PushBack(T data) noexcept;

	/*
	@brief Функция создающая строку из списка
	*/
	std::string ToString() const noexcept;

	/**
	@brief Функция удаляющая элемент с начала списка.
	*/
	void PopFront();

	/**
	@brief Функция добавляющая элемент в начало списка.
	@param data Данные добавляемые в список.
	*/
	void PushFront(T data) noexcept;

	/**
	@brief Конструктор списка через initializer_list.
	@param list Список.
	*/
	List(std::initializer_list<T> list);

	/**
	@brief Функция очистки списка
	*/
	void Clear();

	/*
	* @brief Перегрузка оператора для копирования.
	* @param other Список для копирования.
	* @return Скопированный список.
	*/
	List<T> operator=(const List<T>& other) noexcept;

	/**
	@brief Функция удаляющая элемент с конца списка.
	*/
	void PopBack();

	/*
	* @brief Переопределение оператора сравнения.
	* @param list Список с которым сравниваем.
	* @return this->ToString() == list.ToString().
	*/
	bool operator==(List<T>& list) noexcept;

	/**
	* @brief Проверка наличия элементов в списке.
	* @return true Если список пустой.
	*/
	bool IsEmpty() noexcept;

	/**
	* @brief Конструктор копирования
	*/
	List<T>(const List<T>& other);

	/*
	* @brief Мув
	*/
	List(List&& second) noexcept;
private:
	template<typename T>
	struct Node
	{
		T data;
		Node* pNext;
		/*
		* @brief Конструктор класса Node.
		* @param data Данные.
		* @param pNext Указатель на следующий элемент списка.
		*/
		Node(const T data, Node<T>* pNext = nullptr) : data(data), pNext(pNext)
		{
		};
	};
	size_t size;
	Node<T>* head;
};

template<typename T>
inline List<T>::List()
{
	size = 0;
	head = nullptr;
}

template<typename T>
inline List<T>::~List()
{
	Clear();
}

template<typename T>
inline void List<T>::PushBack(T data) noexcept
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	size++;
}

template<typename T>
inline std::string List<T>::ToString() const noexcept
{
	std::stringstream buffer{};
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		buffer << current->data;
		current = current->pNext;
	}
	return buffer.str();
}

template<typename T>
inline void List<T>::PopFront()
{
	if (head == nullptr)
	{
		throw std::invalid_argument("Список пуст!");
	}
	else
	{
		auto temp = head;
		head = head->pNext;
		delete temp;
		size--;
	}
}

template<typename T>
inline void List<T>::PushFront(T data) noexcept
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		head = new Node<T>(data, head);
	}
	size++;
}

template<typename T>
inline List<T>::List(std::initializer_list<T> list)
{
	for (auto data : list)
	{
		this->PushBack(data);
	}
}

template<typename T>
inline void List<T>::Clear()
{
	while (size > 0)
	{
		PopFront();
	}
}

template<typename T>
inline List<T> List<T>::operator=(const List& other) noexcept
{
	if (this != &other)
	{
		if (!this->IsEmpty())
		{
			this->Clear();
		}
		Node<T>* current = other.head;
		while (current != nullptr)
		{
			this->PushBack(current->data);
			current = current->pNext;
		}
	}
	return *this;
}

template<typename T>
inline void List<T>::PopBack()
{
	if (head == nullptr)
	{
		throw std::invalid_argument("Список пуст!");
	}
	else
	{
		Node<T>* LastButOne = this->head;
		while (LastButOne->pNext->pNext != nullptr)
		{
			LastButOne = LastButOne->pNext;
		}
		delete LastButOne->pNext;
		LastButOne->pNext = nullptr;
		size--;
	}
}

template<typename T>
inline bool List<T>::operator==(List<T>& list) noexcept
{
	if (this->ToString() == list.ToString())
	{
		return true;
	}
}

template<typename T>
inline bool List<T>::IsEmpty() noexcept
{
	if (this->head != nullptr)
	{
		return false;
	}
}

template<typename T>
inline List<T>::List(List&& second) noexcept
{
	std::swap(this->head, second.head);
}

template<typename T>
inline List<T>::List(const List<T>& other) :size(0), head(nullptr)
{
	Node<T>* _pNext = nullptr;
	for (Node<T>* _node = other.head; _node != nullptr; _node = _node->pNext)
	{
		Node<T>* item = new Node(_node->data);
		if (!head)
		{
			head = item;
		}
		else
		{
			_pNext->pNext = item;
		}
		_pNext = item;
		size++;
	};
}
