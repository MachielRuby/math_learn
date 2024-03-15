#include<iostream>
using namespace std;


//可以优化去掉——
template<class T>
class My_stack
{
public:

	My_stack() :_size(0), _capacity(5), _top(-1), data(new T[_capacity]) {}
	~My_stack()
	{
		delete[] data;
		data = nullptr;
	}

	void Checkcapacity()
	{
		if (_size == _capacity)
		{
			_capacity *= 2;
			cout << "扩容为" << _capacity << endl;
			T* tmp = new T[_capacity];
			for (int i = 0; i < _size; i++)
			{
				tmp[i] = data[i];
			}
			delete[]data;
			data = tmp;
			tmp = nullptr;
		}
	}
	void push(T val)
	{
		data[++_top] = val;
		_size++;
		Checkcapacity();
	}

	int size()
	{
		return _size;
	}
	int capacity()
	{
		return _capacity;
	}

	int top()
	{
		return data[_top];
	}

	int pop()
	{
		if (_size == 0) {
			cout << "Stack is empty!" << endl;
			return -1; // 返回一个默认值表示栈为空
		}
		int del = data[_top]; // 保存即将被弹出的元素
		_top--; // 将栈顶指针向下移动一个位置
		_size--; // 栈的大小减少
		return del; // 返回弹出的元素
	}

private:
	int _size;
	int _capacity;
	T* data;
	int _top;
};
int main()
{
	My_stack<int>list;
	list.push(1);
	list.push(2);
	list.push(3);
	list.push(4);
	list.push(4);
	list.push(4);

	cout << list.top() << endl;
	cout << list.pop() << endl;
	while (list.size() > 0)
	{
		cout << list.pop() << endl;
	}




	return 0;
}