#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//2. 内存生长方向(小端模式)
void test02() {
	int num = 0xaabbccdd;
	unsigned char* p = reinterpret_cast<unsigned char*>(&num);

	std::cout << std::hex << static_cast<int>(*p) << std::endl; // 输出第一个字节的值
	std::cout << std::hex << static_cast<int>(*(p + 1)) << std::endl; // 输出第二个字节的值
	std::cout << std::hex << static_cast<int>(*(p + 2)) << std::endl; // 输出第三个字节的值
	std::cout << std::hex << static_cast<int>(*(p + 3)) << std::endl; // 输出第四个字节的值

	std::cout << "Addresses:" << std::endl;
	std::cout << static_cast<void*>(p) << std::endl; // 输出第一个字节的地址
	std::cout << static_cast<void*>(p + 1) << std::endl; // 输出第二个字节的地址
	std::cout << static_cast<void*>(p + 2) << std::endl; // 输出第三个字节的地址
	std::cout << static_cast<void*>(p + 3) << std::endl; // 输出第四个字节的地址
}

void test03()
{
	char buf[1024] = { 0 };
	const char* str = "helloworld@itcast.com";
	sscanf(str, "%[^@]", buf); // 将@之前的内容读入buf中
	printf("%s\n", buf);

	// 查找@的位置
	const char* at_position = strstr(str, "@");
	if (at_position != NULL) {
		// 计算@的位置
		size_t at_index = at_position - str;
		// 将@后面的内容拷贝到另一个缓冲区
		char domain[1024] = { 0 };
		memcpy(domain, str + at_index + 1, strlen(str) - at_index);
		printf("%s\n", domain);
	}
}

void test04()
{
	char buf[1024] = { 0 };
	char part1[1024] = { 0 };
	char part2[1024] = { 0 };

	sscanf("helloworld@itcast.com", "%[^@]@%s", part1, part2);
	printf("Part 1: %s\n", part1);
	printf("Part 2: %s\n", part2);
}

void test5()
{
	const char* str = "123abcd$myname@000qwe";
	char buf[1024] = { 0 };
	sscanf(str, "%*[^$]$%[^@]", buf);
	printf("%s\n", buf);
}

#pragma pack(4)

typedef struct _STUDENT {
	int a;
	char b;
	double c;
	float d;
}Student;

typedef struct _STUDENT2 {
	char a;
	Student b;
	double c;
}Student2;

void test6() {

	//Student
	//a从偏移量0位置开始存储
	//b从4位置开始存储
	//c从8位置开始存储
	//d从12位置开存储
	//所以Student内部对齐之后的大小为20 ，整体对齐，整体为最大类型的整数倍 也就是8的整数倍 为24

	printf("sizeof Student:%d\n", sizeof(Student));

	//Student2 
	//a从偏移量为0位置开始 
	//b从偏移量为Student内部最大成员整数倍开始，也就是8开始
	//c从8的整数倍地方开始,也就是32开始
	//所以结构体Sutdnet2内部对齐之后的大小为：40 ， 由于结构体中最大成员为8，必须为8的整数倍 所以大小为40
	printf("sizeof Student2:%d\n", sizeof(Student2));
}


void test7()
{
	FILE* fp = fopen("./text.txt", "w");
	char buf[1024];
	for (int i = 0; i < 5; i++)
	{
		scanf("%s", &buf);
		fputs(buf, fp);
		fputs("\n", fp); // 添加换行符
	}
	fclose(fp);
	FILE* fp1 = fopen("./text.txt", "r");
	while (fgets(buf, 1024, fp1))
	{
		printf("buf = %s", buf);
	}
}

void call_back1(int a)
{
	cout << "a = " << a << endl;
}
void call_back2(int a)
{
	cout << "a = " << a << endl;
}

void call_back(void(*p)(int))
{
	p(10);
}



// 定义回调函数对象
class CallbackObject {
public:
	void operator()(int value) const {
		std::cout << "Callback object called with value: " << value << std::endl;
	}
};

// 接受回调函数对象的函数
void performOperation(int data, const CallbackObject& callback) {
	// 执行一些操作
	// 操作完成后调用回调函数对象
	callback(data);
}
int main()
{
	/*char buf[1024];
	strcpy(buf, "hello world");
	cout << buf << endl;*/
	//test7();
	//call_back(call_back1);
	CallbackObject callbackobject;
	performOperation(43, callbackobject);
	return 0;
}