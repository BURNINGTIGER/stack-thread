#include <iostream>
#include <stdexcept>
#include <algorithm>

template <typename T>

class stack

{

public:

	void swap(stack<T>&);//noexcept;

	stack();//noexcept;

	~stack();//noexcept;

	stack(const stack<T>&);//strong;

	stack<T>& operator=(stack<T> const& other);//strong;

	size_t count() const;//noexcept;

	void push(T const &);//strong;

	void pop();//strong;
	
	T top();//strong;

	bool empty() const;//noexcept;

	void printall() const;//strong;

	void print();//noexcept;

private:

	T * array_;

	size_t array_size_;

	size_t count_;

};

template <typename T>
void stack<T>::swap(stack<T>& other)
{
	std::swap(array_, other.array_);
	std::swap(array_size_, other.array_size_);
	std::swap(count_, other.count_);
}

template <typename T>
stack<T>::stack()
{
	array_size_ = 0;
	count_ = 0;
	array_ = nullptr;
}

template <typename T>
stack<T>::~stack()
{
	count_ = 0;
	array_size_ = 0;
	delete[] array_;
}

template<typename T>
stack<T>::stack(const stack<T>& other) {
	array_size_ = other.array_size_;
	count_ = other.count_;
	array_ = new T[count_];
	std::copy(other.array_, other.array_ + count_, array_);
}

template<typename T>
stack<T>& stack<T>::operator=(stack<T> const& other)
{
	if (this != &other) 
	{
		stack(other).swap(*this);
	}
	return *this;
}

template <typename T>
void stack<T>::push(T const & value)
{
	if (array_size_ == 0)
	{
		array_size_ = 1;
		array_ = new T[array_size_];
	}
	if (array_size_ == count_)
	{
		array_size_ = array_size_ * 2;
		T * new_array = new T[array_size_]();
		std::copy(array_, array_ + count_, new_array);
		delete[] array_;
		array_ = new_array;
	}
	array_[count_++] = value;
}


template <typename T>
void stack<T>::pop()
{
	if (empty())
	{
		throw std::logic_error( "Stack is empty!");
	}
	else
		count_--;
}

template <typename T>
T stack<T>::top()
{
	if (empty())
	{
		throw std::logic_error( "Stack is empty!");
	}
	return array_[count_ - 1];
}

template <typename T>
bool stack<T>::empty() const 
{
	return (count_ == 0);
}

template <typename T>
size_t stack<T>::count() const
{
	return(count_);
}

template<typename T>
void stack<T>::printall() const
{
	for (int i = 0; i < count_; i++)
		std::cout << array_[i];
}

template<typename T>
void stack<T>::print()
{
	std::cout << array_[count_ - 1];
}
