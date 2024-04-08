#include<iostream>
using namespace std;

class SeqStack
{
public:
	SeqStack(int size = 10) :_cap(size),
		_top(0)
	{
		_stack = new int[_cap];
	}
	~SeqStack()
	{
		delete[]_stack;
		_stack = nullptr;
	}
public:
	void push(int val)
	{
		if (_top == _cap)
		{
			expand(2 * _cap);
		}
		_stack[_top++] = val;
	}
	void pop()
	{
		if (_top == 0)
		{
			return;
		}
		else
		{
			_top--;
		}
	}
	bool empty() const
	{
		return _top == 0;
	}

	int size() const
	{
		return _top;
	}
	void expand(int cap)
	{
		int* tmp = new int[cap];
		memcpy(_stack, tmp, sizeof(int) * _top);
		delete[]_stack;
		_stack = tmp;
		_cap = cap;
	}
	int top()const
	{
		return _stack[_top - 1];
	}
private:
	int* _stack;
	int _top;
	int _cap;
};
int main()
{
	SeqStack s;
	int arr[] = { 1,3,5,7,9 };
	for (auto e : arr)
	{
		s.push(e);
	}
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
	return 0;
}