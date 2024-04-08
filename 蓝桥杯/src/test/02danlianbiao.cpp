#include<iostream>
using namespace std;

struct ListNode
{
	int _val;
	ListNode* _next;
	ListNode(int val = -1) :_val(val), _next(nullptr)
	{}
};

class List
{
public:
	List()
	{
		_head = new ListNode();
	}
	~List()
	{
		ListNode* p = _head;
		while (p != nullptr)
		{
			_head = _head->_next;
			delete p;
			p = _head;
		}
	}

	void InsertTail(int val)
	{
		ListNode* p = _head;
		while (p->_next != nullptr)
		{
			p = p->_next;
		}
		p->_next = new ListNode(val);
	}

	void InsertHead(int val)
	{

		ListNode* s = new ListNode(val);
		s->_next = _head->_next;
		_head->_next = s;
	}

	void Remove(int val)
	{
		ListNode* p = _head;
		ListNode* q = _head->_next;
		while (p)
		{
			if (q->_val == val)
			{
				p->_next = q->_next;
				delete q;
				return;
			}
			else
			{
				p = q;

				q = q->_next;
			}
		}
	}

	void RemoveAll(int val)
	{
		ListNode* p = _head;
		ListNode* q = _head->_next;
		while (p != nullptr)
		{
			if (q != nullptr && q->_val == val)
			{
				p->_next = q->_next;
				delete q;
				if (!p->_next) return;
				q = p->_next;
			}
			else
			{
				p = q;
				if (q->_next)q = q->_next;
			}
		}
	}

	bool find(int val)
	{
		ListNode* p = _head->_next;
		while (p)
		{
			if (p->_val == val)
			{
				return true;
			}
			p = p->_next;
		}
		return false;
	}

	void Print()
	{
		ListNode* p = _head->_next;
		while (p != nullptr)
		{
			cout << p->_val << " ";
			p = p->_next;
		}
		cout << endl;
	}

	//单链表逆序
	void ReverseList()
	{
		ListNode* p = _head->_next;
		ListNode* last = nullptr;

		if (p->_next == nullptr)
		{
			return;
		}
		while (p != nullptr)
		{
			ListNode* q = p->_next;
			p->_next = last;
			last = p;
			p = q;
		}
		_head->_next = last;
	}

	//求倒数第k个节点
	int GetKNode(int n)
	{
		ListNode* p = _head->_next;
		while (--n > 0)
		{
			p = p->_next;
		}
		if (!p)return -1;
		ListNode* q = _head->_next;
		while (p->_next)
		{
			p = p->_next;
			q = q->_next;
		}
		return q->_val;
	}
private:
	ListNode* _head;
};

int main()
{
	List a;
	a.InsertTail(1);
	a.InsertTail(2);
	a.InsertTail(3);
	a.InsertTail(4);
	a.Print();
	a.InsertHead(10);
	a.Print();
	a.InsertTail(2);
	a.InsertTail(2);
	a.InsertTail(2);
	a.Remove(2);
	a.Print();
	a.RemoveAll(2);
	a.Print();
	cout << a.find(3) << endl;
	a.ReverseList();
	a.Print();
	cout << a.GetKNode(5) << endl;

	return 0;
}