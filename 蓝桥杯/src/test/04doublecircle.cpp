#include<iostream>
using namespace std;


struct Node
{
	Node(int data = 0) :
		_data(data),
		_next(nullptr),
		_pre(nullptr)
	{}
	int _data;
	Node* _next;
	Node* _pre;
};

class DoubleLink
{
public:
	DoubleLink()
	{
		_head = new Node();
	}

	~DoubleLink()
	{
		Node* p = _head;
		while (p != nullptr)
		{
			_head = _head->_next;
			delete p;
			p = _head;
		}
	}
public:
	//头插法
	void InsertHead(int val)
	{
		Node* node = new Node(val);
		node->_next = _head->_next;
		node->_pre = _head;
		if (_head->_next != nullptr) //防止后面是空的
		{
			node->_next->_pre = node;
		}
		_head->_next = node;
	}

	void InsertTail(int val)
	{
		Node* node = new Node(val);
		Node* p = _head;
		while (p->_next != nullptr)
		{
			p = p->_next;
		}
		node->_pre = p;
		p->_next = node;
	}

	void Remove(int val)
	{
		Node* p = _head;
		while (p != nullptr)
		{
			if (p->_data == val)
			{
				p->_pre->_next = p->_next;
				if (p->_next != nullptr)p->_next->_pre = p->_pre;
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
		Node* p = _head;
		while (p != nullptr)
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
		return false;
	}

	void show()
	{
		Node* p = _head->_next;
		while (p != nullptr)
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
	DoubleLink a;
	a.InsertHead(10);
	a.InsertHead(20);
	a.InsertHead(30);
	a.InsertHead(40);
	a.show();
	a.Remove(20);
	a.show();
	cout << a.find(30) << endl;
	return 0;
}