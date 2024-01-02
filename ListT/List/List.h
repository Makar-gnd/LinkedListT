#pragma once
#include <iostream>
#include <exception>
#include <string>
#include <sstream>
#include <memory>
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
	void PushBack(const T& data);

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
	void PushFront(const T& data);

	/**
	* @brief Функция удаляющая последний элемент списка.
	*/
	void PopBack();

	/**
	@brief Конструктор списка через initializer_list.
	@param list Список.
	*/
	List(std::initializer_list<T> list);

	/**
	@brief Функция очистки списка
	*/
	void Clear();

	/**
	* @brief Перегрузка оператора для копирования.
	* @param other Список для копирования.
	* @return Скопированный список.
	*/
	List<T>& operator=(const List<T>& other);

	/**
	* @brief Перегрузка оператора для мува.
	* @param other Список для мува.
	* @return Мувнутый список.
	*/
	List<T>& operator=(List<T>&& other);

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

	/**
	* @brief Мув
	*/
	List<T>(List&& second) noexcept;

private:
	template<typename T>
	struct Node
	{
		T data;
		std::unique_ptr<Node<T>> pNext;
		/**
		* @brief Конструктор класса Node.
		* @param data Данные.
		* @param pNext Указатель на следующий элемент списка.
		*/
		Node(const T& data, Node<T>* pNext = nullptr) : data(data), pNext(pNext)
		{
		};
	};
	size_t size;
	std::unique_ptr<Node<T>> head;
};

template<typename T>
inline List<T>::List() : size(0), head(nullptr)
{
}

template<typename T>
inline List<T>::~List()
{
	Clear();
}

template<typename T>
inline void List<T>::PushBack(const T& data) 
{
	if (head == nullptr)
	{
		head = std::make_unique<Node<T>>(data);
	}
	else
	{
		auto current = this->head.get();
		while (current->pNext != nullptr)
		{
			current = current->pNext.get();
		}
		current->pNext = std::make_unique<Node<T>>(data);
	}
	size++;
}

template<typename T>
inline std::string List<T>::ToString() const noexcept
{
	std::stringstream buffer{};
	auto current = this->head.get();
	while (current != nullptr)
	{
		buffer << current->data;
		current = current->pNext.get();
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
		head = std::move(head->pNext);
		size--;
	}
}

template<typename T>
inline void List<T>::PushFront(const T& data) 
{
	if (head == nullptr)
	{
		head = std::make_unique<Node<T>>(data);
	}
	else
	{
		std::unique_ptr<Node<T>> newNode = std::make_unique<Node<T>>(data,
			head.release());
		head = std::move(newNode);
	}
	size++;
}

template<typename T>
inline void List<T>::PopBack()
{
	if (head == nullptr)
	{
		throw std::invalid_argument("Empty list!");
	}
	else
	{
		Node<T>* LastButOne = this->head.get();
		while (LastButOne->pNext->pNext != nullptr)
		{
			LastButOne = LastButOne->pNext.get();
		}
		LastButOne->pNext.reset();
		LastButOne->pNext = nullptr;
		size--;
	}
}

template<typename T>
inline List<T>::List(std::initializer_list<T> list) : List()
{
	for (auto& data : list)
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
inline List<T>& List<T>::operator=(const List& other)
{
	if (this != &other)
	{
		this->Clear();
		Node<T>* current = other.head.get();
		while (current != nullptr)
		{
			this->PushBack(current->data);
			current = current->pNext.get();
		}
	}
	return *this;
}


template<typename T>
inline List<T>& List<T>::operator=(List&& other)
{
	List<T> temp(other);
	std::swap(this->head, temp.head);
	std::swap(this->size, temp.size);
	return *this;
}



template<typename T>
inline bool List<T>::operator==(List<T>& list) noexcept
{
		return this->ToString() == list.ToString();
}

template<typename T>
inline bool List<T>::IsEmpty() noexcept
{
	return this->head == nullptr;
}

template<typename T>
inline List<T>::List(List&& second) noexcept
{
	std::swap(this->head, second.head);
	std::swap(this->size, second.size);
}

template<typename T>
inline List<T>::List(const List<T>& other) : List()
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
