#include<iostream>
using namespace std;


struct Node
{
	Node(int data = 0)
		:_data(data),
		_next(nullptr),
		_pre(nullptr)
	{}
	int _data;
	Node* _next;
	Node* _pre;
};

class DoubleCircleLink
{
public:
	DoubleCircleLink()
	{
		_head = new Node();
		_head->_next = _head;
		_head->_pre = _head;
	}

	~DoubleCircleLink()
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
	void InsertHead(int val)
	{
		Node* node = new Node(val);
		node->_next = _head->_next;
		node->_pre = _head;
		_head->_next->_pre = node;
		_head->_next = node;
	}
	//尾插
	void InsertTail(int val)
	{
		Node* node = new Node(val);
		Node* p = _head->_pre;
		node->_pre = p;
		p->_next = node;
		node->_next = _head;
		_head->_pre = node;

	}

	void Remove(int val)
	{
		Node* p = _head->_next;
		while (p != _head)
		{
			if (p->_data == val)
			{
				p->_pre->_next = p->_next;
				p->_next->_pre = p->_pre;
				delete p;
				return;
			}
			else
			{
				p = p->_next;
			}
		}
	}

	bool find(int val)
	{
		Node* p = _head->_next;
		while (p != _head)
		{
			if (p->_data == val)
			{
				return true;
			}
			else
			{
				p = p->_next;
			}
		}
	}

	void show()
	{
		Node* p = _head->_next;
		while (p->_next != _head)
		{
			cout << p->_data << " ";
			p = p->_next;
		}
		cout << endl;
	}
private:
	Node* _head;
};

int main()
{
	DoubleCircleLink a;
	a.InsertTail(10);
	a.InsertTail(20);
	a.InsertTail(30);
	a.InsertTail(40);
	a.InsertTail(50);
	cout << a.find(20) << endl;
	a.show();

	return 0;
}