
第一节课：
//全缺省
void func(int a = 10,int b = 20, int c = 30)
{

}
//半缺省
void func2(int a,int b = 10,int c = 20)
{

} //必须要传一个至少 缺省的不能在中间

函数重载：自己了解 与编译链接有关 函数取名不同
预处理：头文件展开/宏替换/条件编译/去掉注释
编译：检查语法生成汇编代码
汇编：汇编代码转成 二进制的 机器码
链接：将两个目标文件链接到一起

c与c++不同：c++函数修饰名规则 所以extern "C"  {}

//引用
引用取别名,变量的访问权限可以缩小不能放大。
int i = 0;
double db = i;//隐式转换
const double&rd = i;

临时变量有常性
int count() 
{
    static int n = 0;
    n++;
    return n;
}
const &r1 = count();
引用不能改变引用的对象
inline 等于在具体位置添加了代码，内置的

typeid(变量).name()输出变量类型

C11：范围for(auto variable:variables )
推荐void*p  = nullptr;NULL在某种程度上等价于0

内存对齐：
class A
{
public:
	void f1() {}
private:
	int _a;
	char _ch;
};
大小是8
  
没有成员变量的大小为1：1个字节不是为了存数据，而是占位表示数据存在
对象钟存储成员变量不存储成员函数？一个类实例n个对象，每个对象都可以存储不同的值，但是调用函数时同一个
如果·存放成员函数，而函数时一样的，就浪费了空间

//类和对象
void Print()
{
    cout<<_year<<"-"<<_month...
}
处理：
void Print(Date*this)
{
    cout<<this->_year..
}

this:谁调用这个成员函数，this就指向谁

class A{
    public:
    void print()
    {
        cout<<_a<<endl;
    }
    void show()
    {

    }
    private:
    int _a;
}
A*p = nullptr;
p->Print();奔溃
p->show();正常
// 成员函数存在公共的代码段所以p->show不会去p指向的对象上找
//访问成员函数才回去找
A a;如果有传参构造函数也可以使用，编译器生成的
a.print(); --->a.print(&a);

//编译器
不写编译器默认写 写了编译器不写
Date d1;
Date d2(d1);拷贝构造
 Date(const Date&d)
 {

 }

 d1 == d2; --> d1.operator==(d2)
 d1 > d2; ---> d1.operator>(d2)

 void f()const //void f(const Date*this)
 explicit防止隐式转换

 static:
1、不存在对象，存在于静态区
2、没有this指针 类名::func()调用
3、不能访问非静态成

void operator<<(ostream&out,const Date&d)
{}
cout<<d1 // operator><<(cout,d1);


//内存管理
new 申请空间加构造函数 +申请失败抛出1异常
malloc申请空间 + 失败不报错
delete 删除空间+析构函数
free 删除空间
operator new
operator delete


//简单的vector

#include<iostream>
using namespace std;
#include<assert.h>
namespace stack
{
	template<class T>
	class stack
	{
	public:
		stack(size_t capacity = 2) :_a(new T[capacity]),
			_size(0),
			_capacity(capacity)
		{

		}
		~stack()
		{
			delete[] _a;
		}
		T& operator[](size_t i)
		{
			assert(i < _size);
			return _a[i];
		}

		void push(T x)
		{
			if (_size == _capacity)
			{
				size_t newcapacity = _capacity * 2;
				T* tmp = new T[newcapacity];
				for (size_t i = 0; i < _size; i++)
				{
					tmp[i] = std::move(_a[i]); // 使用std::move，假设T支持移动语义
				}
				delete[] _a;
				_a = tmp;
				_capacity = newcapacity;
			}
			_a[_size] = std::move(x); // 同样假设T支持移动语义
			_size++;
		}

		size_t size()
		{
			return _size;
		}
	private:
		T* _a;
		size_t _size;
		size_t _capacity;
	};
}

int main()
{
	stack::stack<int> a;
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << endl;
	}

	return 0;
}

string:
const char*str = s1.c_str()
char str1[] = "中国"
str1[3] = -7

string::npos size_t npos = -1;
s1.find("wocao")!=string::npos

substr(开始，结束默认npos)

cin>>s; 换行或者空格
getline(cin,s);//换行
reverse(s1.begin(),s1.end())