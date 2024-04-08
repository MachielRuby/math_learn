#include<iostream>
using namespace std;

#include<functional>
//优先级队列
class PriorityQueue
{
public:
	using Comp = function<bool(int, int)>;
	PriorityQueue(int cap = 20, Comp comp = greater<int>())
		:_size(0),
		_cap(cap),
		_comp(comp)
	{
		_data = new int[_cap];
	}

	PriorityQueue(Comp comp = greater<int>())
		:_size(0),
		_cap(20),
		_comp(comp)
	{
		_data = new int[_cap];
	}
	~PriorityQueue()
	{
		delete[]_data;
		_data = nullptr;
	}
public:
	void push(int val)
	{
		if (_size == _cap)
		{
			int* p = new int[2 * _cap];
			memcpy(p, _data, sizeof(int) * _cap);
			delete[]_data;
			_data = p;
			_cap *= 2;
		}
		if (_size == 0)
		{
			_data[_size] = val;
		}
		else
		{
			siftup(_size, val);
		}
		_size++;
	}

	void pop()
	{
		if (_size == 0)
		{
			throw "this is empty";
		}
		_size--;
		if (_size > 0)
		{
			siftdown(0, _data[_size]);
		}
	}

	bool empty()
	{
		return _size == 0;
	}
	int top()
	{
		if (_size == 0)throw "this is empty";
		return _data[0];
	}
	int size() const
	{
		return _size;
	}
private:
	void siftup(int i, int val)
	{
		while (i > 0)
		{
			int father = (i - 1) / 2;
			if (_comp(val, _data[father]))
			{
				_data[i] = _data[father];
				i = father;
			}
			else
			{
				break;
			}
		}
		_data[i] = val;
	}
	//向下调整
	void siftdown(int i, int val)
	{
		while (i < _size / 2)
		{
			int child = 2 * i + 1; //第i个节点的左子节点
			if (child + 1 < _size && _comp(_data[child + 1], _data[child]))
			{
				child = child + 1;
			}
			if (_comp(_data[child], val))
			{
				_data[i] = _data[child];
				i = child;
			}
			else
			{
				break;//满足堆性质
			}
		}
		_data[i] = val;
	}

private:
	int* _data;
	int _size;// 元素个数
	int _cap;//内存大小
	Comp _comp;//比较器大小

};

int main()
{
	PriorityQueue que([](int a, int b) {return a < b; });
	srand(time(NULL));
	for (int i = 0; i < 20; i++)
	{
		que.push(rand() % 100);
	}
	while (!que.empty())
	{
		cout << que.top() << " ";
		que.pop();
	}
	cout << endl;

	return 0;
}