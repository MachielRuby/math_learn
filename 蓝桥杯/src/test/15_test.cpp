#include<iostream>
using namespace std;

//int main()
//{
//	//дһ��������ڴ�0x0018ff44��дһ��4�ֽڵ�10
//	//int* const& p = (int*)0x0018ff444; //&& ��ֵ���� ��������ֵ
//	//cout << p << endl;
//	//int a = 100, & ref_a = a; ref_a = 101;
//	//cout << ref_a << endl;
//
//	//int a = 10;
//	//int* p = &a;
//	// const int*& q = p;
//
//	 //const ���ε�ֵ�������޸�
//	 //const���εĿ��Բ���ʼ��
//	 //���г����г�����
//	//const�������ֵĵط������������ĳ�ʼ���滻��
//
//	//const int a = 20;//������
//	//int array[20] = {};
//	//int* p = (int*)&a;
//	//*p = 30;
//	//cout << *p << endl;
//
//	//int b = 20;
//	//const int a1 = b;
//	//int* q = (int*)&a1;
//	//*q = 100;
//	//cout << *q << endl;
//
//#if 0
//	void func(int a) {}
//	void func(const int a) {}
//#endif
//	int a = 10;
//	const int b = 10;
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	return 0;
//} 

/*
c++�����ã����ú�ָ�������
1����ֵ���ú���ֵ����
2�����õ�ʵ��

������һ�ָ���ȫ��ָ�롣
1�������Ǳ����ʼ���ģ�ָ����Բ���ʼ��
*/


//int main()
//{
//	//int a = 10;
//	//int* p = &a; //�� = ��
//	//*p = 20;
//	////20
//	//int& b = a;
//	//b = 30; //�Զ�������
//	////30 ˵������ͬһ���ڴ�
//
//	int array[6] = {};
//	int* p = array;
//	int(&q)[6] = array;
//	cout << sizeof(array) << endl;
//	cout << sizeof(p) << endl;
//	cout << sizeof(q) << endl;
//	int a = 10;//��ֵ�����ڴ������֣�ֵ�����޸�
//
//	//c11�ṩ����ֵ����
//	int&& c = 20; //20����ֵ��û�ڴ�û����
//	// int temp = 20; temp->b
//	const int& b = 20;//ָ��鿴
//	return 0;
//}

//const���εĳ��ֵĴ���
/*
1��������������Ϊ��ֵ <= ֱ���޸ĳ�����ֵ
2�����ܰѳ����ĵ�ַй¶��һ����ָͨ�������ͨ���ñ���

const��һ��ָ��Ľ��
const int*p
int const*p
int * const p
const int * const p
const���Թ淶�������������������
const int* p = &a; => *p = 20 p = &b;
��������ָ��ͬ��int���͵��ڴ棬
���ǲ�����ͨ��ָ����3�޸��ڴ��ֵ
int*const p = &a; => p=&b *p = 20;
���ָ��p�ǳ���������ָ���������ڴ棬����ͨ���������޸�ָ���ֵ
*/

/*
�ܽ�const��ָ�������ת����ʽ��
int* <= const int* �����
const int* <= int* ��ȷ��

int** <= const int** �����
const int** <= int** �����

int** <= int*const* ��ĵ�
int*const* <=int** ���Ե�
*/



#if 0
int main()
{
	int* q1 = nullptr;
	int* const q2 = nullptr;
	cout << typeid(q1).name() << endl;
	cout << typeid(q2).name() << endl;
	// const����ұ�û��*��const����������
	int a = 10;
	int* p1 = &a;
	const int* p2 = &a; //const int* <= int*
	int* const p3 = &a; //int* <= int*
	int* p4 = p3; //int* ��= int*
	const int a = 10;
	//int* p = &a;  int* <= const int* error
	return 0;
}
#endif 

#if 0
//const�Ͷ���ָ��Ľ��
int main()
{
	int a = 10;
	int* p = &a; //����const ���
	//const int* * q = &p; // const int** <= int** �����
	const int* const* q = &p; // const int** <= int** �����
	//��*q�����ܸ�ֵ����,������ַ���޷�й¶
	/*
	const int*       *q = &p;
	 *q <=> p
	  const int b = 20;
	  *q = &b;
	*/

	return 0;
}
#endif

#if 0
int main()
{
	int a = 10;
	int* p = &a;
	int* const* q = &p;//int* const* <= int**  const* <= *
	//int a = 10;
	//int* const p = &a; //int*<=int*
	//int* q = p;

	//int a = 10;
	//const int* p = &a; // const int* <= int*
	////int* q = p; //int* <= const int *  *q = 20 //err
	return 0;
}
#endif
#if 0 
//Ĭ��ֵ���������
int sum(int a = 10, int b = 20)
{
	return a + b;
}

int main()
{
	int ret = sum(10); //����Ĭ��ֵ�ٶ�������һ��ָ��
	return 0;
}
#endif



/*
C++ OOP���� OOP��� thisָ��
c:���ֵĺ����Ķ��� struct
C++:�� =��ʵ��ĳ�������
OOP�Ĵ������������װ�̳ж�̬
���ʡ��޶�����public private protected
*/
#if 0
const int NAME_LEN = 20;
class Goods
{
public: //�ṩ�ӿ�
	void init(char* name, double price, int amount);
	void show();
	void setName(char* name); //ʡ��
private://����һ��˽��
	char  _name[NAME_LEN];
	double _price;
	int _amount;
};
int main()
{	//�����ڴ�Ĵ�С��ֻ����Ա���й�
	Goods good;
	return 0;
}
#endif



/*
��ĸ��ֳ�Ա - ��Ա����/����
��ͨ�ĳ�Ա����
1���������������
2�����ø÷�������Ҫ����һ������
3������������ʶ����˽�г�Ա����  protected �̳� public private

��̬��Ա�������ڲ����� ���ⶨ��
��̬��Ա������ûthisָ���
��ͨ����
����Ա����:ֻ���ĳ�Ա����
*/

//ָ�����Ա��ָ��
//class Test
//{
//public:
//	void func() { cout << "call Test::func" << endl; }
//	static void static_func() { cout << "Test::static_func" << endl; }
//	int ma;
//};
//
//int main()
//{
//	//int a = 10;int *p=&a;*p =30;
//	//int* p = &Test::ma; error
//	int Test::* p = &Test::ma;
//	Test a;
//	a.*p = 20;
//	cout << a.*p << endl;
//	Test b;
//	b.ma = 10;
//	cout << b.ma << endl;
//	Test* p2 = new Test();
//	delete  p2;
//
//	//ָ���Ա������ָ��
//	//void(*pfunc)() = &Test::func; errno
//	void(Test:: * pfunc)() = &Test::func; //ָ���ӵ���
//	(a.*pfunc)();
//
//	//��ζ��庯��ָ��ָ����ľ�̬��Ա
//	static void(*pfunc1)() = &Test::static_func;
//	(*pfunc1)();
//	return 0;
//}

/*
c++����ģ��
ģ������壺������Ҳ���Խ��в�������

����ģ��
ģ���ʵ����
ģ�庯��

ģ�����Ͳ���
ģ������Ͳ��� ���ǳ�����ֻ��ʹ�ã������޸�

ģ���ʵ������:�����û���������ͣ����Ƶ�������--
ģ���������
ģ�庯����ģ�������������ģ�庯�������ع�ϵ
*/
//����һ��ģ������б�

#if 0
template<typename T, int SIZE>
void sort(T* arr)
{
	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = 0; j < SIZE - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}

	}


}
int main()
{
	int arr[] = { 12,5,7,89 ,35 };
	const int size = sizeof(arr) / sizeof(arr[0]);
	sort<int, size>(arr);
	for (auto e : arr)
	{
		cout << e << " ";
	}
	return 0;
}
#endif 

#if 0
#include"template_use.h"
template<typename T>
bool compare(T a, T b);
template<typename T>
bool compare(T a, T b)//һ��ģ�庯��
{
	cout << "template <T>" << endl;
	return a > b;
}

template<>
bool compare<const char*>(const char* a, const char* b);
//���compare����ģ�壬�ṩconst char * ���͵��������汾
//template<>
//bool compare<const char*>(const char* a, const char* b)
//{
//	cout << "template compare" << endl;
//	return a > b;
//}
//���߱�����ָ������ ��ģ��ʵ����
template bool compare<int>(int, int);
template bool compare<double>(double, double);
int main()
{
	//�����ĵ��õ�
	compare<int>(10, 20);
	//����ģ���ʵ������ ģ�屾������ �����und
	//ģ����붼�Ƿ���ͷ�ļ��У�ֱ��include����
	compare(20, 30);
	compare<int>(30, 40.5);
	compare("wocao", "shjabi");
	return 0;
}
#endif


/*
��ģ��=��ʵ����

*/
#if 0
template<typename T>
class Stack //ģ������ + ���Ͳ����б�= ������
{
public:
	//���졤 �������������üӡ�T��������Ҫ
	Stack(int size = 10)
		:_stack(new T[size]),
		_top(0),
		_size(size)
	{}
	~Stack()
	{
		delete[]_stack;
		_stack = nullptr;
	}
	Stack(const Stack<T>& stack)
		:_top(_stack._top),
		_size(_stack._size)
	{
		_stack = new T[_size];
		for (int i = 0; i < _top; i++)
		{
			_stack[i] = stack._stack[i];
		}
	}
	Stack<T>& operator=(const Stack<T>& stack)
	{
		if (this == &stack)
		{
			return *this;
		}
		Stack<T> s(stack);
		::swap(_top, s._top);
		::swap(_size, s._size);
		::swap(_stack, s._stack);
		return *this;
	}


	void push(const T& val)//��ջ����
	{
		if (full())
			expand();
		_stack[_top++] = val;
	}
	void pop()
	{
		if (empty())return;
		--_top;
	}
	T top() const
	{
		if (empty())throw "this is empty";
		return _stack[_top - 1];
	}
	bool full()const
	{
		return _top == _size;
	}
	bool empty() const
	{
		return _top == 0;
	}

private:
	T* _stack;
	int _top;
	int _size;

	//˳��ջ������ʽ����
	void expand()
	{
		T* tmp = new T[_size * 2];
		for (int i = 0; i < _top; i++)
		{
			tmp[i] = _stack[i];
		}
		delete[]_stack;
		_stack = tmp;
		_size = 2 * _size;
	}
};

int main()
{
	Stack<char>s;
	s.push('a');
	s.push('b');
	s.push('c');
	s.push('d');
	s.push('e');
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}

	return 0;
}
#endif


/*
����
allocator�ռ�������
template <class _Alloc>
class vector<bool, _Alloc>;
allocator���ļ����� �ڴ濪���ͷ� ����������
*/


//���������Ŀռ���������c++��׼��allocatorʵ��һ��
template<typename T>
class Allocator
{
public:
	T* allocate(size_t size)//�����ڴ濪��
	{
		return (T*)malloc(sizeof(T) * size);
	}
	void deallocate(void* p)//�ڴ��ͷ�
	{
		free(p);
	}
	void construct(T* p, const T& val)//���������
	{
		new (p) T(val);//��λnew
	}
	void destroy(T* p)//�����������
	{
		p->~T();
	}


};
/*�����ײ㿪���ͷŶ�ͨ��allocator*/
template<typename T, typename Alloc = Allocator<T>>
class vector
{
public:
	vector(int size = 10)
	{
		//��Ҫ���ڴ濪�ٺͶ�����ֿ�����
		//_first = new T[size];
		_first = _allocator.allocate(size);
		_last = _first;
		_end = _first + size;
	}
	~vector()
	{
		//delete[]_first;
		for (T* p = _first; p != _last; ++p)
		{
			_allocator.destroy(p);//��_firstָ���������Ч�ͷ�
		}
		_allocator.deallocate(_first);//�ͷŶ��ϵ������ڴ�
		_first = _last = _end = nullptr;
	}

	vector(const vector<T>& rhs)
	{
		int  size = rhs._end - rhs._first;
		//_first = new T[size];
		_first = _allocator.allocate(size);
		int len = rhs._last - rhs._first;
		for (int i = 0; i < len; i++)
		{
			//_first[i] = rhs._first[i];
			_allocator.construct(_first + i, rhs._first[i]);
		}
		_last = _first + len;
		_end = _first + size;
	}
	vector<T>& operator=(const vector<T>& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}
		/*vector<T>tmp(rhs);
		::swap(_first, tmp._first);
		::swap(_last, tmp._last);
		::swap(_end, tmp._end);
		return *this;*/
		//delete[]_first;
		for (T* p = _first; p != _last; p++)
		{
			_allocator.deallocate(p);
		}
		_allocator.deallocate(_first);
		int  size = rhs._end - rhs._first;
		//_first = new T[size];
		_first = _allocator.allocate(size);
		int len = rhs._last - rhs._first;
		for (int i = 0; i < len; i++)
		{
			//_first[i] = rhs._first[i];
			_allocator.construct(_first + i, rhs._first[i]);
		}
		_last = _first + len;
		_end = _first + size;
		return *this;
	}

	void push_back(const T& val)
	{
		if (full())
		{
			expand();
		}
		//*_last++ = val;
		_allocator.construct(_last, val);
		_last++;
	}

	void pop_back()
	{
		if (empty())
		{
			return;
		}
		//--_last;
		--_last;
		_allocator.destroy(_last);
	}
	T back()const
	{
		return *(_last - 1);
	}
	bool full()const
	{
		return _last == _end;
	}
	bool empty()const
	{
		return _last == _first;
	}
	int size() const { return _last - _first; }
private:
	T* _first;
	T* _last;
	T* _end;
	Alloc _allocator;//���������Ŀռ����ö���

	/*void expand()//Ч�ʿ��ܵ�
	{
		int size = _end - _first;
		vector<T>vec(2 * size);
		for (int i = 0; i < size; i++)
		{
			vec.push_back(*(_first + i));
		}
		::swap(_first, vec._first);
		::swap(_end, vec._end);
		::swap(_last, vec._last);
	}*/
	void expand() {
		int size = _end - _first;
		//T* newFirst = new T[2 * size];
		T* newFirst = _allocator.allocate(2 * size);
		for (int i = 0; i < size; i++)
		{
			_allocator.construct(newFirst + i, _first[i]);
		}
		//std::copy(_first, _last, newFirst);
		//delete[] _first;
		for (T* p = _first; p != _last; ++p)
		{
			_allocator.destroy(p);

		}
		_allocator.deallocate(_first);
		_first = newFirst;
		_last = _first + size;
		_end = _first + 2 * size;
	}
};

class Test
{
public:
	Test() { cout << "Test()" << endl; }
	~Test() { cout << "~Test()" << endl; }
	Test(const Test&) { cout << "test(const test&)" << endl; }
};
#if 0
int main()
{
	Test t1, t2, t3;
	cout << " -----------------" << endl;
	vector<Test>vec; //ʮ�ι��������

	vec.push_back(t1);
	vec.push_back(t2);
	vec.push_back(t3);
	cout << " -----------------" << endl;
	vec.pop_back();
	cout << " -----------------" << endl;


	return 0;
}
#endif
//int main()
//{
//	vector<int> vec;
//	for (int i = 0; i < 20; i++)
//	{
//		vec.push_back(rand() % 100);
//	}
//	while (!vec.empty())
//	{
//		cout << vec.back() << " ";
//		vec.pop_back();
//	}
//
//	return 0;
//}


/*
��������أ���Ա������ȫ�ַ���
�ڴ�� ���̳� �̳߳�  ���ӳ� �����
*/
#if 0
template<typename T>
class Queue
{
public:
	Queue()
	{
		_front = _rear = new QueueItem();
	}
	~Queue()
	{
		QueueItem* cur = _front;
		while (cur != nullptr)
		{
			_front = _front->_next;
			delete cur;
			cur = _front;
		}
	}

	void push(const T& val)
	{
		QueueItem* item = new QueueItem(val);
		_rear->_next = item;
		_rear = item;
	}

	void pop()
	{
		if (empty())
		{
			return;
		}
		QueueItem* first = _front->_next;
		_front->_next = first->_next;
		if (_front->_next == nullptr)
		{
			_rear = _front;
		}
		delete first;
	}

	T front()const
	{
		return _front->_next->_data;
	}

	bool empty() const
	{
		return _front == _rear;
	}

private:
	//����һ��QueueItem�Ķ����(1000��QueueItem�ڵ�)
	struct QueueItem {
		QueueItem(T data = T()) : _data(data), _next(nullptr) {}
		void* operator new(size_t size)
		{
			if (_itemPool == nullptr)
			{
				_itemPool = (QueueItem*)new char[POOL_ITEM_SIZE * sizeof(QueueItem)];
				QueueItem* p = _itemPool;
				for (; p < _itemPool + POOL_ITEM_SIZE - 1; ++p)
				{
					p->_next = p + 1;
				}
				p->_next = nullptr;
			}
			QueueItem* p = _itemPool;
			_itemPool = _itemPool->_next;
			return p;
		}
		void operator delete(void* ptr)
		{
			QueueItem* p = (QueueItem*)ptr;
			p->_next = _itemPool;
			_itemPool = p;

		}

		T _data;
		QueueItem* _next;
		static QueueItem* _itemPool;
		static const int POOL_ITEM_SIZE = 1000;
	};
	QueueItem* _front;//ָ��ͷ�ڵ�
	QueueItem* _rear;//ָ���β
};
template<typename T>
typename Queue<T>::QueueItem* Queue<T>::QueueItem::_itemPool = nullptr;

int main()
{
	Queue<int>que;
	for (int i = 0; i < 1000; i++)
	{
		que.push(i);
		cout << que.front() << " ";
		que.pop();
	}
	return 0;
}
#endif

//#include<vector>
/*������ʧЧ������
1��������Ϊʲô��ʧЧ��
a.����������erase�����󣬵�ǰλ�õ�����ĩβ�����е�������ʧЧ
b.����������insert�����󣬵�ǰλ�õ�����ĩβԪ�ص����е�����ȫ����ʧЧ��
		��������Ȼ��Ч  ������ȫ��ʧЧ

		insert��˵��������������ڴ�����
		ԭ�����������еĵ�������ȫ��ʧЧ��
��Ԫ�� -> �����/ɾ���� ->ĩβԪ��
c:insert��˵��������������ڴ�����
	ԭ�����������еĵ�������ȫ��ʧЧ��
d:��ͬ�����ĵ������ǲ��ܽ��бȽ������
2.������ʧЧ���Ժ��������ô�����
�Բ���/ɾ����ĵ��������и��²���
*/
#if 0
int main()
{
	std::vector<int>vec;
	for (int i = 0; i < 10; i++)
	{
		vec.push_back(rand() % 100 + 1);
	}
	for (auto e : vec)
	{
		cout << e << " ";
	}
	auto it = vec.begin();
	for (; it != vec.end(); ++it)
	{
		if (*it % 2 == 0)
		{
			it = vec.insert(it, *it - 1);
			++it;
			//break;
		}
	}

	//��vec�����е�����ż����ɾ��
	//auto it = vec.begin();
	//cout << endl;
	//while (it != vec.end())
	//{
	//	if (*it % 2 == 0)
	//	{
	//		//cout << *it << endl;
	//		//������ǰ�ڵ�ʧЧ�����⣬��һ�ε���erase�󣬵�����it��ʧЧ��
	//		it = vec.erase(it); // insert(it,val) erase(it)
	//		//break;
	//	}
	//	else
	//	{
	//		++it;
	//	}
	//}
	for (auto e : vec)
	{
		cout << e << " ";
	}
}
#endif

/*
����
allocator�ռ�������
template <class _Alloc>
class vector<bool, _Alloc>;
allocator���ļ����� �ڴ濪���ͷ� ����������
*/


//���������Ŀռ���������c++��׼��allocatorʵ��һ��
template<typename T>
class Allocator
{
public:
	T* allocate(size_t size)//�����ڴ濪��
	{
		return (T*)malloc(sizeof(T) * size);
	}
	void deallocate(void* p)//�ڴ��ͷ�
	{
		free(p);
	}
	void construct(T* p, const T& val)//���������
	{
		new (p) T(val);//��λnew
	}
	void destroy(T* p)//�����������
	{
		p->~T();
	}


};
/*�����ײ㿪���ͷŶ�ͨ��allocator*/
template<typename T, typename Alloc = Allocator<T>>
class vector
{
public:
	vector(int size = 10)
	{
		//��Ҫ���ڴ濪�ٺͶ�����ֿ�����
		//_first = new T[size];
		_first = _allocator.allocate(size);
		_last = _first;
		_end = _first + size;
	}
	~vector()
	{
		//delete[]_first;
		for (T* p = _first; p != _last; ++p)
		{
			_allocator.destroy(p);//��_firstָ���������Ч�ͷ�
		}
		_allocator.deallocate(_first);//�ͷŶ��ϵ������ڴ�
		_first = _last = _end = nullptr;
	}

	vector(const vector<T>& rhs)
	{
		int  size = rhs._end - rhs._first;
		//_first = new T[size];
		_first = _allocator.allocate(size);
		int len = rhs._last - rhs._first;
		for (int i = 0; i < len; i++)
		{
			//_first[i] = rhs._first[i];
			_allocator.construct(_first + i, rhs._first[i]);
		}
		_last = _first + len;
		_end = _first + size;
	}
	vector<T>& operator=(const vector<T>& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}
		/*vector<T>tmp(rhs);
		::swap(_first, tmp._first);
		::swap(_last, tmp._last);
		::swap(_end, tmp._end);
		return *this;*/
		//delete[]_first;
		for (T* p = _first; p != _last; p++)
		{
			_allocator.deallocate(p);
		}
		_allocator.deallocate(_first);
		int  size = rhs._end - rhs._first;
		//_first = new T[size];
		_first = _allocator.allocate(size);
		int len = rhs._last - rhs._first;
		for (int i = 0; i < len; i++)
		{
			//_first[i] = rhs._first[i];
			_allocator.construct(_first + i, rhs._first[i]);
		}
		_last = _first + len;
		_end = _first + size;
		return *this;
	}

	void push_back(const T& val)
	{
		if (full())
		{
			expand();
		}
		//*_last++ = val;
		_allocator.construct(_last, val);
		_last++;
	}

	void pop_back()
	{
		if (empty())
		{
			return;
		}
		//--_last;
		--_last;
		_allocator.destroy(_last);
	}
	T back()const
	{
		return *(_last - 1);
	}
	bool full()const
	{
		return _last == _end;
	}
	bool empty()const
	{
		return _last == _first;
	}
	int size() const { return _last - _first; }
private:
	T* _first;
	T* _last;
	T* _end;
	Alloc _allocator;//���������Ŀռ����ö���

	/*void expand()//Ч�ʿ��ܵ�
	{
		int size = _end - _first;
		vector<T>vec(2 * size);
		for (int i = 0; i < size; i++)
		{
			vec.push_back(*(_first + i));
		}
		::swap(_first, vec._first);
		::swap(_end, vec._end);
		::swap(_last, vec._last);
	}*/
	void expand() {
		int size = _end - _first;
		//T* newFirst = new T[2 * size];
		T* newFirst = _allocator.allocate(2 * size);
		for (int i = 0; i < size; i++)
		{
			_allocator.construct(newFirst + i, _first[i]);
		}
		//std::copy(_first, _last, newFirst);
		//delete[] _first;
		for (T* p = _first; p != _last; ++p)
		{
			_allocator.destroy(p);

		}
		_allocator.deallocate(_first);
		_first = newFirst;
		_last = _first + size;
		_end = _first + 2 * size;
	}
};

class Test
{
public:
	Test() { cout << "Test()" << endl; }
	~Test() { cout << "~Test()" << endl; }
	Test(const Test&) { cout << "test(const test&)" << endl; }
};

int main()
{
	Test t1, t2, t3;
	cout << " -----------------" << endl;
	vector<Test>vec; //ʮ�ι��������

	vec.push_back(t1);
	vec.push_back(t2);
	vec.push_back(t3);
	cout << " -----------------" << endl;
	vec.pop_back();
	cout << " -----------------" << endl;


	return 0;
}
