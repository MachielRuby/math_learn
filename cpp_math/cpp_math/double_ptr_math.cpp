#include<iostream>
using namespace std;

/*
算法模板
for(int i = 0,j = 0;i<n;i++)
{
	while(j<i&&check(i,j))j++;//采用朴素算法优化到O（n)
}
*/

//int main()
//{
//	char str[1000];
//	gets_s(str);
//	int n = strlen(str);
//	for (int i = 0; i < n; i++)
//	{
//		int j = i;
//		while (j < n && str[j] != ' ')j++;
//		for (int k = i; k < j; k++)cout << str[k];
//		cout << endl;
//		i = j;
//	}
//	return 0;
//}
/*
最长连续数字
暴力算法
for(int i = 0;i<n;i++)
{
	for(int j = 0;j<=i;j++)
	{
		if(check(j,i)
		{
			res = max(res,i-j+1);
		}
	}
}


for(int i = 0,j = 0;i<n;i++)
{
	while(j<=i&&check(j,i))j++;
	res = max(res,j-i+1);
}
朴素做法

*/

const int N = 100010;

int n;
int a[N];
int s[N];

int main()
{
	// 声明一个变量n，用于存储输入数组的大小
	cin >> n;

	// 循环读取n个整数，并将它们存储在数组a中
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	// 声明一个变量res，用于存储最终结果，初始化为0
	int res = 0;

	// 循环遍历数组a
	for (int i = 0, j = 0; i < n; i++)
	{
		// 将数组a中当前元素a[i]作为索引，在数组s中对应位置计数加1
		s[a[i]]++;

		// 如果当前元素a[i]已经出现过（即计数大于1），则进入循环
		while (s[a[i]] > 1)
		{
			// 将数组a中元素a[j]的计数减1，并将j向后移动一位
			s[a[j]]--;
			j++;
		}

		// 更新最终结果res为当前最大值，即当前子序列的长度与之前最大长度的比较
		res = max(res, i - j + 1);
	}

	// 输出最终结果res
	cout << res << endl;

	return 0;
}

