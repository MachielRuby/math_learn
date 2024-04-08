#include<iostream>
using namespace std;
#include<vector>
int main()
{
	vector<int> vec{ 12,78,90,12,33,22,22 };

	//定义数组位图
	int max = vec[0];
	for (int i = 0; i < vec.size(); i++)
	{
		if (max < vec[i])
		{
			max = vec[i];
		}
	}
	int* bitmap = new int[max / 32 + 1]();

	/*
	new int[max / 32 + 1]：这将动态分配一个整数数组，但不会初始化数组中的元素。数组中的元素将有未定义的值，
	这意味着它们可能包含任何随机值。

	new int[max / 32 + 1]()：这同样会动态分配一个整数数组，
	但括号 () 会导致数组中的所有元素初始化为默认值，对于整数类型，这意味着它们都被初始化为 0
	*/
	unique_ptr<int>ptr(bitmap); //栈上指针自动释放开辟的内存

	//找到第一个重复的数字
	for (auto key : vec)
	{
		int index = key / 32;
		int offset = key % 32;
		//取key对应的位的值
		if (0 == (bitmap[index] & (1 << offset)))
		{
			//表示key没有出现过
			bitmap[index] |= (1 << offset);
		}
		else
		{
			cout << "重复出现key = " << key << endl;
			return 0;
		}
	}
	return 0;
}