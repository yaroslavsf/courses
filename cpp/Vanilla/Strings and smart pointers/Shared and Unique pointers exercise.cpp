#include <iostream>

template <class T>
class Qnique_ptr 
{
private:
	T* m_ptr;

public:
	Qnique_ptr(T*m_ptr = 0)
		:
		m_ptr{m_ptr}
	{ }
	~Qnique_ptr()
	{
		delete m_ptr;
	}
	
	T& operator*() const { return *m_ptr; }
	T* operator->() const noexcept
	{
		return m_ptr;
	}
	T* get() const
	{
		return m_ptr;
	}

	T* release() //забирает владение объектом.
	{
		T* tmp = m_ptr;
		m_ptr = nullptr;
		return tmp;
	}

	void reset(T* p)  //передаёт владение объектом
	{
		delete m_ptr;
		m_ptr = p;
	}

	Qnique_ptr(Qnique_ptr const& other) = delete;
	Qnique_ptr& operator=(Qnique_ptr const& other) = delete;
	Qnique_ptr& operator=(Qnique_ptr&& other) noexcept
	{
		reset(other.release());
		return *this;
	}
	Qnique_ptr(Qnique_ptr&& other) noexcept
		: m_ptr(other.release())
	{ }

//1) передача параметром в функцию
//2) передача в класс динамического массива
//3) плохая работа с разными контейнерами с++
//4) не правильно будет освобождаться память при malloc
};
template <class T>
class Shared_ptr
{
private:
	T* m_ptr;
	size_t* counter;
public:
	Shared_ptr()
		: m_ptr(nullptr),
		counter(nullptr)
	{}
	Shared_ptr(T* m_ptr)
		: m_ptr(m_ptr) 
	{
		if (m_ptr == nullptr) {
			return;
		}
		try {
			counter = new size_t(1);
		}
		catch (...) {
			delete m_ptr;
			throw;
		}
	}
	Shared_ptr(Shared_ptr const& other)
		: m_ptr(other.m_ptr),
		counter(other.counter) 
	{
		if (m_ptr == nullptr) 
		{
			return;
		}
		counter++;
	}
	~Shared_ptr() 
	{
		if (m_ptr == nullptr) 
		{
			return;
		}
		if (-- (* counter) == 0) 
		{
			delete counter;
			delete m_ptr;
		}
	}
	T& operator*() const { return *m_ptr; }
	T* operator->() const noexcept
	{
		return m_ptr;
	}
	void reset(T* p)  //передаёт владение объектом
	{
		delete m_ptr;
		m_ptr = p;
	}
};
int main()
{
	
	int* b = new int;
	*b = 5;
	
	std::cout << "b= "<< &b << '\n';
	
	Shared_ptr<int> s_p(b);
	
	std::cout << "s_p= "<<&s_p << '\n';

	
	return 0;
}