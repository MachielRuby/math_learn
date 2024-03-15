#include<iostream>
using namespace std;
typedef int T;
struct ListNode
{
	ListNode* prev, * next;
	T val;
	ListNode(T val) :val(val), prev(nullptr), next(nullptr) {}
};

class SeqList
{
public:
	SeqList() :head(new ListNode(-1))
	{

	}
	~SeqList()
	{
		ListNode* p = head;
		while (head)
		{
			p = head;
			head = head->next;
			delete p;
			p = nullptr;
		}
		head = nullptr;
	}
	void print()
	{
		if (!head->next)return;
		ListNode* p = head->next;
		while (p)
		{
			cout << "val  = " << p->val << endl;
			p = p->next;
		}
	}
	void PushBack(T val)
	{
		ListNode* newNode = new ListNode(val);
		ListNode* p = head;
		while (p->next)
		{
			p = p->next;
		}
		p->next = newNode;
		newNode->prev = p;
	}

	void PushHead(T val)
	{
		ListNode* newNode = new ListNode(val);
		ListNode* p = head;
		newNode->next = p->next;
		p->next = newNode;
		newNode->next->prev = newNode;
		newNode->prev = p;
	}

	void PopBack()
	{
		if (!head->next)return;
		ListNode* p = head->next;
		ListNode* q = head;
		while (p->next)
		{
			p = p->next;
			q = q->next;
		}
		q->next = nullptr;
		delete p;
	}
	void PopHead()
	{
		if (!head->next)return;
		ListNode* p = head;
		ListNode* q = head->next;
		if (q->next)
		{
			p->next = q->next;
			q->next->prev = p;
			q->prev = nullptr;
			q->next = nullptr;
			delete q;
		}
		else
		{
			p->next = nullptr;
			q->prev = nullptr;
			delete q;
		}
	}

	ListNode* find(T val)
	{
		if (head->next == nullptr)return nullptr;

		ListNode* p = head->next;
		while (p)
		{
			if (p->val == val)
			{
				return p;
			}
			p = p->next;
		}
		return nullptr;
	}
private:
	ListNode* head;
};

int main()
{
	SeqList list;
	list.PushBack(10);
	list.PushBack(20);
	list.PushBack(30);
	list.PushHead(10);
	list.PushHead(130);
	list.PushHead(120);
	list.PushBack(30);
	list.PushBack(30);

	list.PopBack();
	list.PopHead();
	list.print();
	ListNode* q = list.find(20);
	while (q)
	{
		cout << "q = " << q->val << endl;
		q = q->next;
	}
	return 0;
}