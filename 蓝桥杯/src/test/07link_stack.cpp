#include<iostream>
using namespace std;

struct Node
{
	int _data;
	Node* _next;
	Node(int data = 0) :_data(data),
		_next(nullptr)
	{}
};

class Link_stack
{
public:
	Link_stack() :_size(0)
	{
		_head = new Node;
	}
	~Link_stack()
	{
		Node* p = _head;
		while (p != nullptr)
		{
			_head = _head->_next;
			delete p;
			p = _head;
		}
	}

	void push(int val)
	{
		Node* node = new Node(val);
		node->_next = _head->_next;
		_head->_next = node;
		_size++;
	}
	void pop()
	{
		if (!_head->_next) return;
		Node* p = _head->_next;
		_head->_next = p->_next;
		delete p;
		_size--;
	}

	int top()const
	{
		if (_head->_next == nullptr)return -1;
		return _head->_next->_data;
	}
	bool empty()const
	{
		if (_head->_next == nullptr)return true;
		return false;
	}
	int size()const
	{
		return _size;
	}
	void show()
	{
		Node* p = _head->_next;
		while (p)
		{
			cout << p->_data << " ";
			p = p->_next;
		}
		cout << endl;
	}
private:
	Node* _head;
	int _size;
};
int main()
{
	Link_stack a;
	a.push(1);
	a.push(12);
	a.push(13);
	a.push(14);
	a.push(1);
	a.show();
	return 0;
}