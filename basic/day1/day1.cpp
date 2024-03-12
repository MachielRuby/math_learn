cin.peek()//获取输流的下一个字符进行判断

例子：
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


cin.clear()//重置标志位输入错误
exampel:
     while (!(cin >> num)) {
        cin.clear(); // 清除失败的状态标志
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略错误输入直到下一个换行符
        cout << "Invalid input. Please enter an integer: ";
    }


部分功能：
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


设置小数位数：
头文件iomanip
void test04()
{
	double d = 2.01;
	cout << setiosflags(ios::fixed);
	cout << setprecision(10);
	cout << d << endl;
}