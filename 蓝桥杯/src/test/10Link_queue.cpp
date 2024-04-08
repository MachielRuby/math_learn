#include<iostream>
using namespace std;

struct Node
{
	int _data;
	Node* _next;
	Node* _pre;
	Node(int data = -1) :_data(data), _next(nullptr), _pre(nullptr)
	{}
};
class LinkQueue
{
public:

	LinkQueue()
	{
		_head = new Node();
		_head->_next = _head;
		_head->_pre = _head;
	}

	~LinkQueue()
	{
		Node* p = _head->_next;
		while (p != _head)
		{
			_head->_next = p->_next;
			p->_next->_pre = _head;
			delete p;
			p = _head->_next;
		}
		delete _head;
		_head = nullptr;
	}
public:
	void push(int val)
	{
		Node* node = new Node(val);
		node->_next = _head;
		node->_pre = _head->_pre;
		_head->_pre->_next = node;
		_head->_pre = node;
	}

	void pop()
	{
		Node* p = _head->_next;
		_head->_next = p->_next;
		p->_next->_pre = _head;
		delete p;
	}
	//获取头元素
	int front()const
	{
		if (_head->_next == _head)
		{
			throw "this is empty";
		}
		return _head->_next->_data;
	}

	//获取队尾元素
	int back()const
	{
		if (_head->_next == _head)
		{
			throw "this is empty()";
		}
		return _head->_pre->_data;
	}
	//判空
	bool empty() const
	{
		return _head->_next == _head;
	}

private:
	Node* _head;
};


int main()
{
	LinkQueue a;
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	a.push(5);
	while (!a.empty())
	{
		cout << a.front() << " ";
		a.pop();
	}
	cout << endl;

	return 0;
}