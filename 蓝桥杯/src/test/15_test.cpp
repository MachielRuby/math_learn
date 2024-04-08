#include<iostream>
using namespace std;

//int main()
//{
//	//写一句代码在内存0x0018ff44处写一个4字节的10
//	//int* const& p = (int*)0x0018ff444; //&& 右值引用 现在是左值
//	//cout << p << endl;
//	//int a = 100, & ref_a = a; ref_a = 101;
//	//cout << ref_a << endl;
//
//	//int a = 10;
//	//int* p = &a;
//	// const int*& q = p;
//
//	 //const 修饰的值不能在修改
//	 //const修饰的可以不初始化
//	 //不叫常量叫常变量
//	//const常量名字的地方，都被常量的初始化替换了
//
//	//const int a = 20;//被改了
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
c++的引用，引用和指针的区别
1、左值引用和右值引用
2、引用的实例

引用是一种更安全的指针。
1、引用是必须初始化的，指针可以不初始化
*/


//int main()
//{
//	//int a = 10;
//	//int* p = &a; //右 = 左
//	//*p = 20;
//	////20
//	//int& b = a;
//	//b = 30; //自动解引用
//	////30 说明属于同一块内存
//
//	int array[6] = {};
//	int* p = array;
//	int(&q)[6] = array;
//	cout << sizeof(array) << endl;
//	cout << sizeof(p) << endl;
//	cout << sizeof(q) << endl;
//	int a = 10;//左值，有内存有名字，值可以修改
//
//	//c11提供了右值引用
//	int&& c = 20; //20是右值，没内存没名字
//	// int temp = 20; temp->b
//	const int& b = 20;//指令查看
//	return 0;
//}

//const修饰的出现的错误
/*
1、常量不能再作为左值 <= 直接修改常量的值
2、不能把常量的地址泄露给一个普通指针或者普通引用变量

const和一级指针的结合
const int*p
int const*p
int * const p
const int * const p
const语言规范：修饰离他最近的类型
const int* p = &a; => *p = 20 p = &b;
可以任意指向不同的int类型的内存，
但是不可以通过指针间接3修改内存的值
int*const p = &a; => p=&b *p = 20;
这个指针p是常量不能再指向其他清内存，可以通过解引用修改指向的值
*/

/*
总结const和指针的类型转换公式：
int* <= const int* 错误的
const int* <= int* 正确的

int** <= const int** 错误的
const int** <= int** 错误的

int** <= int*const* 错的的
int*const* <=int** 可以的
*/



#if 0
int main()
{
	int* q1 = nullptr;
	int* const q2 = nullptr;
	cout << typeid(q1).name() << endl;
	cout << typeid(q2).name() << endl;
	// const如果右边没有*，const不参与类型
	int a = 10;
	int* p1 = &a;
	const int* p2 = &a; //const int* <= int*
	int* const p3 = &a; //int* <= int*
	int* p4 = p3; //int* 《= int*
	const int a = 10;
	//int* p = &a;  int* <= const int* error
	return 0;
}
#endif 

#if 0
//const和二级指针的结合
int main()
{
	int a = 10;
	int* p = &a; //加入const 解决
	//const int* * q = &p; // const int** <= int** 错误的
	const int* const* q = &p; // const int** <= int** 错误的
	//让*q不可能赋值就行,常量地址就无法泄露
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
//默认值从右向左给
int sum(int a = 10, int b = 20)
{
	return a + b;
}

int main()
{
	int ret = sum(10); //调用默认值速度增长少一句指令
	return 0;
}
#endif



/*
C++ OOP对象 OOP编程 this指针
c:各种的函数的定义 struct
C++:类 =》实体的抽象类型
OOP四大特征：抽象封装继承多态
访问·限定符：public private protected
*/
#if 0
const int NAME_LEN = 20;
class Goods
{
public: //提供接口
	void init(char* name, double price, int amount);
	void show();
	void setName(char* name); //省略
private://属性一般私有
	char  _name[NAME_LEN];
	double _price;
	int _amount;
};
int main()
{	//对象内存的大小，只跟成员类有关
	Goods good;
	return 0;
}
#endif



/*
类的各种成员 - 成员方法/变量
普通的成员方法
1、属于类的作用域
2、调用该方法，需要依赖一个对象
3、可以任意访问对象的私有成员变量  protected 继承 public private

静态成员变量：内部声明 类外定义
静态成员方法：没this指针的
普通方法
常成员方法:只读的成员方法
*/

//指向类成员的指针
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
//	//指向成员方法的指针
//	//void(*pfunc)() = &Test::func; errno
//	void(Test:: * pfunc)() = &Test::func; //指针间接调用
//	(a.*pfunc)();
//
//	//如何定义函数指针指向类的静态成员
//	static void(*pfunc1)() = &Test::static_func;
//	(*pfunc1)();
//	return 0;
//}

/*
c++函数模板
模板的意义：对类型也可以进行参数化就

函数模板
模板的实例化
模板函数

模板类型参数
模板非类型参数 都是常量，只能使用，不能修改

模板的实参推演:根据用户传入的类型，来推导出类型--
模板的特例化
模板函数、模板的特例化、非模板函数的重载关系
*/
//定义一个模板参数列表

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
bool compare(T a, T b)//一个模板函数
{
	cout << "template <T>" << endl;
	return a > b;
}

template<>
bool compare<const char*>(const char* a, const char* b);
//针对compare函数模板，提供const char * 类型的特例化版本
//template<>
//bool compare<const char*>(const char* a, const char* b)
//{
//	cout << "template compare" << endl;
//	return a > b;
//}
//告诉编译器指定类型 的模板实例化
template bool compare<int>(int, int);
template bool compare<double>(double, double);
int main()
{
	//函数的调用点
	compare<int>(10, 20);
	//函数模板的实参推演 模板本身不编译 否则会und
	//模板代码都是放在头文件中，直接include包含
	compare(20, 30);
	compare<int>(30, 40.5);
	compare("wocao", "shjabi");
	return 0;
}
#endif


/*
类模板=》实例化

*/
#if 0
template<typename T>
class Stack //模板名称 + 类型参数列表= 类名称
{
public:
	//构造· 和析构函数不用加《T》其他需要
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


	void push(const T& val)//入栈操作
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

	//顺序栈二倍方式扩容
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
容器
allocator空间配置器
template <class _Alloc>
class vector<bool, _Alloc>;
allocator做四件事情 内存开辟释放 对象构造析构
*/


//定义容器的空间配置器和c++标准的allocator实现一样
template<typename T>
class Allocator
{
public:
	T* allocate(size_t size)//负责内存开辟
	{
		return (T*)malloc(sizeof(T) * size);
	}
	void deallocate(void* p)//内存释放
	{
		free(p);
	}
	void construct(T* p, const T& val)//负责对象构造
	{
		new (p) T(val);//定位new
	}
	void destroy(T* p)//负责对象析构
	{
		p->~T();
	}


};
/*容器底层开辟释放都通过allocator*/
template<typename T, typename Alloc = Allocator<T>>
class vector
{
public:
	vector(int size = 10)
	{
		//需要把内存开辟和对象构造分开处理
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
			_allocator.destroy(p);//把_first指向的数组有效释放
		}
		_allocator.deallocate(_first);//释放堆上的数组内存
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
	Alloc _allocator;//定义容器的空间配置对象

	/*void expand()//效率可能低
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
	vector<Test>vec; //十次构造和析构

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
运算符重载：成员方法，全局方法
内存池 进程池 线程池  连接池 对象池
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
	//产生一个QueueItem的对象池(1000个QueueItem节点)
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
	QueueItem* _front;//指向头节点
	QueueItem* _rear;//指向队尾
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
/*迭代器失效的问题
1、迭代器为什么会失效？
a.当容器调用erase方法后，当前位置到容器末尾的所有迭代器都失效
b.当容器调用insert方法后，当前位置到容器末尾元素的所有迭代器全部都失效了
		迭代器依然有效  迭代器全部失效

		insert来说，如果引起容器内存扩容
		原来容器的所有的迭代器就全部失效了
首元素 -> 插入点/删除点 ->末尾元素
c:insert来说，如果引起容器内存扩容
	原来容器的所有的迭代器就全部失效了
d:不同容器的迭代器是不能进行比较运算的
2.迭代器失效了以后，问题该怎么解决？
对插入/删除点的迭代器进行更新操作
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

	//把vec容器中的所有偶数都删掉
	//auto it = vec.begin();
	//cout << endl;
	//while (it != vec.end())
	//{
	//	if (*it % 2 == 0)
	//	{
	//		//cout << *it << endl;
	//		//迭代器前期的失效的问题，第一次调用erase后，迭代器it就失效了
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
容器
allocator空间配置器
template <class _Alloc>
class vector<bool, _Alloc>;
allocator做四件事情 内存开辟释放 对象构造析构
*/


//定义容器的空间配置器和c++标准的allocator实现一样
template<typename T>
class Allocator
{
public:
	T* allocate(size_t size)//负责内存开辟
	{
		return (T*)malloc(sizeof(T) * size);
	}
	void deallocate(void* p)//内存释放
	{
		free(p);
	}
	void construct(T* p, const T& val)//负责对象构造
	{
		new (p) T(val);//定位new
	}
	void destroy(T* p)//负责对象析构
	{
		p->~T();
	}


};
/*容器底层开辟释放都通过allocator*/
template<typename T, typename Alloc = Allocator<T>>
class vector
{
public:
	vector(int size = 10)
	{
		//需要把内存开辟和对象构造分开处理
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
			_allocator.destroy(p);//把_first指向的数组有效释放
		}
		_allocator.deallocate(_first);//释放堆上的数组内存
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
	Alloc _allocator;//定义容器的空间配置对象

	/*void expand()//效率可能低
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
	vector<Test>vec; //十次构造和析构

	vec.push_back(t1);
	vec.push_back(t2);
	vec.push_back(t3);
	cout << " -----------------" << endl;
	vec.pop_back();
	cout << " -----------------" << endl;


	return 0;
}
