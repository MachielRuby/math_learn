#include<iostream>
using namespace std;
#include<iomanip>
#include<fstream>
#define _CRT_SECURE_WARNINGS
void test01()
{
	cout << "请输入一个字符串或者数字" << endl;
	char c = cin.peek();
	if (c >= '0' && c <= '9')
	{

		int num; cin >> num;
		cout << "输入的数字是: " << num << endl;

	}
	else
	{
		char buf[1024];
		cin >> buf;
		cout << "输入的字符串时: " << buf << endl;
	}
}


void test02()
{
	int num;
	while (1)
	{
		cin >> num;
		if (num >= 0 && num <= 10)
		{
			cout << "输入正确" << endl;
			break;
		}
		cout << "重写输入" << endl;
		//重置标志位
		cin.clear();
		//清空缓冲区
		cin.sync();

		char buf[1024];
		cin.getline(buf, 1024);

		//打印标志位
		cout << cin.fail() << endl;
	}
}

void test03()
{
	int num = 99;
	cout.width(20);//设置宽度
	cout.fill('*');//填充
	cout.setf(ios::left);//让数据在左边
	cout.unsetf(ios::dec);//卸载十进制
	cout.setf(ios::hex);//安装十六进制
	cout.setf(ios::showbase);//显示基数
	cout.unsetf(ios::hex);//卸载十六进制
	cout.setf(ios::oct);//安装八进制
	cout << num << endl;

}

void test04()
{
	double d = 2.01;
	cout << setiosflags(ios::fixed);
	cout << setprecision(10);
	cout << d << endl;
}
void test05()
{
	//定义流对象
	ofstream ofs;
	//打开文件以写的方式
	ofs.open("test.txt", ios::out | ios::trunc);
	//判断是否打开成功
	if (!ofs.is_open())
	{
		cout << "打开失败" << endl;
	}

	//5.写信息
	ofs << "姓名:悟空" << endl;
	ofs << "年龄:18" << endl;
	ofs << "身高:180cm" << endl;

	ofs.close();
}
//读文件
void test06()
{
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	if (ifs.is_open() == false)
	{
		cout << "打开失败" << endl;
	}
	//一行行读取
	char buf[1024] = { 0 };
	while (ifs >> buf)
	{
		cout << buf << endl;
	}
	//读文件
	while (!ifs.eof())//判断是否读完
	{
		ifs.getline(buf, sizeof(buf));
		cout << buf << endl;
	}
	//字符读取
	char c;
	while ((c = ifs.get()) != EOF)
	{
		cout << c;
	}
	ifs.close();

}
//二进制文件的读写
void test07()
{
	ofstream ofs;
	ofs.open("test.txt", ios::out | ios::trunc | ios::binary);
	if (!ofs.is_open())
	{
		cout << "打开失败" << endl;
	}
	//ofs << "傻逼万一" << endl;
	char buf[1024];
	cin >> buf;
	ofs.write(buf, sizeof(buf));
	ofs.close();
}

void test08()
{
	ifstream ifs;
	ifs.open("test.txt", ios::in | ios::binary);
	char buf[1024];
	ifs.read(buf, sizeof(buf));
	cout << "name" << buf << endl;
	ifs.close();
}
int main()
{
	test08();
	return 0;
}