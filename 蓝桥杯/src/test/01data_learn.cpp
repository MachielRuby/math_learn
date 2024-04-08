#include<iostream>
using namespace std;

class Array
{
public:
	Array(size_t capacity = 10) :
		_size(0),
		_capacity(capacity),
		_array(new int[capacity])
	{}
	~Array()
	{
		if (_array)
		{
			delete[] _array;
		}
		_array = nullptr;
	}
	void push_back(int val)
	{
		if (_size == _capacity)
		{
			expand(_capacity);
		}
		_array[_size++] = val;
	}

	int  pop_back()
	{
		if (_size == 0)
		{
			return -1;
		}
		return _array[--_size];
	}

	void insert(size_t pos, int val)
	{
		if (pos > _size)
		{
			return;
		}
		if (_size == _capacity)
		{
			expand(_capacity);
		}

		for (size_t i = _size; i > pos; i--)
		{
			_array[i] = _array[i - 1];
		}
		_array[pos] = val;
		_size++;
	}

	void erase(size_t pos)
	{
		if (pos >= _size) return;
		for (int i = pos; i < _size - 1; i++)
		{
			_array[i] = _array[i + 1];
		}
		_size--;
	}


	int find(int val)
	{
		for (int i = 0; i < _size; i++)
		{
			if (_array[i] == val)
			{
				return i;
			}
		}
		return -1;
	}
	void expand(size_t capaccity)
	{
		_capacity = (_capacity == 0) ? 2 : _capacity * 2;
		int* tmp = new int[_capacity * 2];
		memcpy(tmp, _array, sizeof(int) * _size);
		delete[]_array;
		_array = tmp;
	}

	void  print()
	{
		for (int i = 0; i < _size; i++)
		{
			cout << _array[i] << " ";
		}
		cout << endl;
	}
private:
	int* _array;
	size_t _size;
	size_t _capacity;
};


int main()
{
	Array a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.pop_back();
	cout << a.find(3) << endl;
	a.erase(1);
	a.print();


	return 0;
}