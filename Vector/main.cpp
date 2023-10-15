#include <iostream>
using namespace std;

template<typename T>
class Iterator
{
public:
	Iterator() : _ptr(nullptr)
	{

	}

	Iterator(T* ptr) : _ptr(ptr)
	{

	}

	Iterator& operator++()
	{
		_ptr++;
		return *this;
	}

	Iterator operator++(int)
	{
		Iterator temp = *this;
		_ptr++;
		return temp;
	}

	Iterator operator+(const int count)
	{
		Iterator temp = *this;
		temp._ptr += count;
		return temp;
	}

	Iterator operator-(const int count)
	{
		Iterator temp = *this;
		temp._ptr -= count;
		return temp;
	}

	bool operator==(const Iterator& iter)
	{
		return _ptr == iter._ptr;
	}

	bool operator!=(const Iterator& iter)
	{
		return _ptr != iter._ptr;
	}

	T& operator*()
	{
		return *_ptr;
	}

public:
	T* _ptr;

};

template <typename T>
class Vector
{
public:
	Vector() : _data(nullptr), _size(0), _capacity(0)
	{

	}

	~Vector()
	{
		if (_data != nullptr)
			delete[] _data;
	}

	void push_back(const T& val)
	{
		if (_size == _capacity)
		{
			// 증설 작업
			int newCapacity = static_cast<int>(_capacity * 1.5);
			if (newCapacity == _capacity)
				newCapacity++;

			reserve(newCapacity);
		}
		_data[_size++] = val;
	}

	void pop_back()
	{
		_size--;
	}

	void reserve(int cap)
	{
		_capacity = cap;

		T* newData = new T[_capacity];

		for (int i = 0; i < _size; i++)
		{
			newData[i] = _data[i];
		}

		if (_data)
			delete[] _data;

		_data = newData;
	}

	T& operator[](const int pos){ return _data[pos]; }



	int size() { return _size; }
	int capacity() { return _capacity; }

public:
	typedef Iterator<T> iterator;

	iterator begin() { return iterator(&_data[0]); }
	iterator end() { return begin() + _size; }


private:
	T* _data;
	int _size;
	int _capacity;
};


int main()
{
	Vector<int> v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i + 1);
		cout << v[i] << endl;
	}

	for (Vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << (*it)<< endl;
	}
	
	return 0;
}