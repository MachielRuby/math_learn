#include<iostream>
using namespace std;
typedef int T;
struct ListNode
{
	T val;
	ListNode* next;
	ListNode(T _val) :val(_val), next(nullptr) {}
};
class SeqList
{
public:
	SeqList(T val = -1) :head(new ListNode(val))
	{

	}
	~SeqList()
	{
		ListNode* p = head;
		while (p)
		{
			ListNode* temp = p;
			p = p->next;
			delete temp;
		}
	}


	void print()
	{
		if (!head->next)return;
		ListNode* p = head->next;
		while (p)
		{
			cout << "val = " << p->val << endl;
			p = p->next;
		}
	}
	void insertBack(T val)
	{
		ListNode* newNode = new ListNode(val);
		ListNode* p = head;
		while (p->next)
		{
			p = p->next;
		}
		p->next = newNode;
	}

	void insertFront(T val)
	{
		ListNode* newNode = new ListNode(val);
		ListNode* p = head;
		newNode->next = p->next;
		p->next = newNode;

	}

	void popBack()
	{
		if (!head->next)return;
		ListNode* p = head->next;
		ListNode* q = head;
		while (p->next)
		{
			p = p->next;
			q = q->next;
		}
		delete p;
		p = nullptr;
		q->next = nullptr;
	}
	void popFront()
	{
		ListNode* q = head->next;
		head->next = q->next;
		delete q;
	}
private:
	ListNode* head;
};
int main()
{
	SeqList list;
	list.insertBack(10);
	list.insertBack(20);
	list.insertBack(30);
	list.insertBack(40);
	list.insertFront(50);
	list.popBack();
	list.popFront();
	list.print();


	return 0;
}