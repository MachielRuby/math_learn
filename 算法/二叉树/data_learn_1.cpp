#include<iostream>
using namespace std;


template<class T>
class SeqList
{
public:
	SeqList(size_t capacity = 10) :_size(0), _capacity(capacity), _array(new T[_capacity])
	{
	}
	~SeqList()
	{
		delete[] _array;
		_array = nullptr;
	}

	void print()
	{
		if (_array == nullptr)
		{
			cout << "数据为空" << endl;
			return;
		}
		for (int i = 0; i < _size; i++)
		{
			cout << "数据是： " << _array[i] << endl;
		}
	}

	void CheckCapacity()
	{
		if ((_size == _capacity))
		{
			size_t new_Capacity = _capacity * 2;
			//开辟新的空间
			T* _tmp = new T[new_Capacity];
			if (!_tmp)
			{
				cout << "开辟失败" << endl;
				return;
			}
			_capacity = new_Capacity;
			cout << "开辟空间为: " << _capacity << endl;

			for (int i = 0; i < _size; i++)
			{
				_tmp[i] = _array[i];
			}
			delete[] _array;
			_array = _tmp;
		}
	}

	//加入元素
	void PushBack(T x)
	{
		_array[_size++] = x;
		CheckCapacity();

	}
	//加入元素头部
	void PushFront(T x)
	{
		for (int i = _size; i > 0; i--)
		{
			_array[i] = _array[i - 1];
		}
		_array[0] = x;
		_size++;
		CheckCapacity();
	}

	void BackPop()
	{
		_size--;
	}

	void FrontPop()
	{
		for (int i = 0; i < _size; i++)
		{
			_array[i] = _array[i + 1];
		}
		_size--;
	}

	int Find(T x)
	{
		for (int i = 0; i < _size; i++)
		{
			if (_array[i] == x)
			{
				return i + 1;
			}
		}
		return -1;
	}
	size_t getSize()
	{
		return _size;
	}
	size_t getCapacity()
	{
		return _capacity;
	}


	int remove(size_t pos)
	{
		if (pos > _size)return -1;
		int c = _array[pos];
		for (int i = pos; i < _size; i++)
		{
			_array[i] = _array[i + 1];
		}
		_size--;
		return c;
	}




private:
	size_t _size;
	size_t _capacity;
	T* _array;
};

int main()
{
	SeqList<int>list1(5);
	list1.PushBack(1);
	list1.PushBack(2);
	list1.PushBack(1);
	list1.PushBack(1);
	list1.PushBack(1);
	list1.PushBack(1);
	list1.PushBack(1);
	list1.PushBack(1);
	list1.PushFront(10);
	list1.PushFront(2);
	list1.FrontPop();
	cout << list1.Find(5) << endl;
	cout << list1.Find(10) << endl;
	//cout << list1.remove(2) << endl;





	list1.print();
	return 0;
}