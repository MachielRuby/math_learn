#include<iostream>
using namespace std;

class CircleLink
{
public:
	CircleLink()
	{
		_head = new Node();
		_tail = _head;
		_head->_next = _head;
	}
	~CircleLink()
	{
		Node* p = _head->_next;
		while (p != _head)
		{
			_head->_next = p->_next;
			delete p;
			p = _head->_next;
		}
		delete _head;
	}

	//尾插法
	void InsertTail(int val)
	{
		Node* node = new Node(val);
		node->_next = _tail->_next;
		_tail->_next = node;
		_tail = node;
	}

	void InsertHead(int val)
	{
		Node* node = new Node(val);
		node->_next = _head->_next;
		_head->_next = node;
		if (node->_next == _head)
		{
			_tail = node;
		}
	}

	//删除节点
	void Remove(int val)
	{
		Node* head = _head;
		Node* q = head;
		Node* p = head->_next;

		while (p != head)
		{
			if (p->_data == val)
			{
				q->_next = p->_next;
				delete p;
				if (q->_next == head)
				{
					_tail = q;
				}
				return;
			}
			else
			{
				q = p;
				p = p->_next;
			}
		}
	}

	bool find(int val)
	{
		Node* p = _head->_next;
		while (p != _head)
		{
			if (val == p->_data)return true;
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
		while (p != _head)
		{
			cout << p->_data << " ";
			p = p->_next;
		}
		cout << endl;
	}


private:
	struct Node
	{
		Node(int data = 0) :_data(data), _next(nullptr) {}
		int _data;
		Node* _next;
	};
	Node* _head;//指向头节点
	Node* _tail;//指向末尾节点

};



int main()
{
	CircleLink a;
	a.InsertHead(10);
	a.InsertHead(20);
	a.InsertHead(40);
	a.InsertHead(30);
	a.show();
	;
	return 0;
}