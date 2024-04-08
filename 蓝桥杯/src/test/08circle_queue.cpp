#include<iostream>
using namespace std;
class CircleQueue
{
public:
	CircleQueue(int _size = 2) :_size(0), _front(0), _rear(0), _cap(_size)
	{
		_data = new int[_cap];
	}
	~CircleQueue()
	{
		delete[]_data;
		_data = nullptr;
	}

	void push(int val)
	{
		if ((_rear + 1) % _cap == _front)
		{
			expand(2 * _cap);
		}
		_data[_rear] = val;
		_rear = (_rear + 1) % _cap;
		_size++;
	}
	void pop()
	{
		if (_front == _rear)
		{
			throw "this is empty()";
		}
		_front = (_front + 1) % _cap;
		_size--;
	}

	int front()const
	{
		if (_front == _rear)
		{
			throw "this is empty(*)";
		}
		return _data[_front];
	}

	int back()const
	{
		if (_front == _rear)
		{
			throw "this is empty()";
		}
		return _data[(_rear - 1 + _cap) % _cap];
	}

	bool empty()
	{
		return _front == _rear;
	}

private:

	void expand(int cap)
	{
		int* tmp = new int[cap];
		int i = 0;
		int j = _front;
		for (; j != _rear; i++, j = (j + 1) % _cap)
		{
			tmp[i] = _data[j];
		}
		delete[]_data;
		_data = tmp;
		_cap = cap;
		_front = 0;
		_rear = i;
	}
private:
	int* _data;
	int _front;
	int _rear;
	int _size;
	int _cap;
};
int main()
{
	CircleQueue q;
	q.push(2);
	q.push(3);
	q.push(4);
	cout << q.front() << endl;
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;


	return 0;
}