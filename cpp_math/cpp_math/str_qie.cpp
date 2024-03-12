#include<iostream>
#include<string>
using namespace std;

void test() {
	string s;
	cin >> s; // 读入字符串
	int count = 0;
	size_t pos = 0; // 查找起始位置

	// 循环使用find从当前pos位置开始查找"wocao"
	while ((pos = s.find("wocao", pos)) != string::npos) {
		count++; // 找到"wocao"，计数器加一
		pos += strlen("wocao"); // 更新pos位置，以跳过当前找到的"wocao"
	}

	cout << count << endl; // 输出"wocao"出现的次数
}

void test1()
{
	char str[] = "apple, orange, banana, peach";
	char* token;
	char* context = NULL;

	// 获取第一个令牌
	token = strtok_s(str, ", ", &context);

	// 继续获取其他的令牌
	while (token != NULL) {
		printf("%s\n", token);
		token = strtok_s(NULL, ", ", &context);
	}

}
int main() {
	test1();
	return 0;
}
