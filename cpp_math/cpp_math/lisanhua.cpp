/*
vector<int> alls; // 存储所有待离散化的值
sort(alls.begin(), alls.end()); // 将所有值排序
alls.erase(unique(alls.begin(), alls.end()), alls.end());   // 去掉重复元素
*/
#include<iostream>
using namespace std;
#include<algorithm>

#include<vector>

// 定义一个pair类型p11，用于存储两个整数
typedef pair<int, int> p11;

const int N = 300010;
int n, m;
int a[N], s[N]; // 声明数组a和s

vector<int> alls; // 存储所有待离散化的值
vector<p11> adds, querry; // 声明两个向量adds和querry，用于存储添加和查询操作

// 二分查找函数，用于查找元素x在alls中的位置
int find(int x)
{
	int l = 0, r = alls.size() - 1;
	while (l < r)
	{
		int mid = l + r >> 1;
		if (alls[mid] >= x)
			r = mid;
		else
			l = mid + 1;
	}
	return l; // 返回x在alls中的位置
}

vector<int>::iterator unique(vector<int>& a)
{
	int j = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (!i || a[i] != a[i - 1])
			a[j++] = a[i];
		//a[0]-a[j-1]所有a不重的数
	}
	return a.begin() + j;
}



int main()
{
	cin >> n >> m; // 输入n和m的值
	for (int i = 0; i < n; i++)
	{
		int x, c;
		cin >> x >> c; // 输入添加操作的x和c的值
		adds.push_back({ x, c }); // 将x和c作为一对加入到adds向量中
		alls.push_back(x); // 将x加入到alls向量中
	}

	for (int i = 0; i < m; i++)
	{
		int l, r;
		cin >> l >> r; // 输入查询操作的l和r的值
		querry.push_back({ l, r }); // 将l和r作为一对加入到querry向量中
		alls.push_back(l); // 将l加入到alls向量中
		alls.push_back(r); // 将r加入到alls向量中
	}

	//去重
	sort(alls.begin(), alls.end()); // 将alls向量中的所有值排序
	alls.erase(unique(alls.begin(), alls.end()), alls.end()); // 去掉alls向量中的重复元素

	// 处理添加操作
	for (auto item : adds)
	{
		int x = find(item.first); // 查找item的第一个元素在alls中的位置
		a[x] += item.second; // 将item的第二个元素加到对应位置的a数组中
	}

	// 预处理
	for (int i = 0; i <= alls.size(); i++)
	{
		s[i] = s[i - 1] + a[i]; // 计算前缀和数组s4
	}

	// 处理查询操作
	for (auto item : querry)
	{
		int l = find(item.first); // 查找item的第一个元素在alls中的位置
		int r = find(item.second); // 查找item的第二个元素在alls中的位置
		cout << s[r] - s[l - 1] << endl; // 输出查询结果
	}
	return 0;
}


/*
Input:
3 2
1 5 1为5
3 7 3为7
6 3
2 5 2到5为5
1 7
输出
7
15
Explanation:
- 添加操作：有3次添加操作，分别为 (1, 5), (3, 7), (6, 3)
- 查询操作：有2次查询操作，分别为查询区间 (2, 5) 和 (1, 7)

Output:
11  // 查询区间 (2, 5) 中的结果为前缀和 s[5] - s[1] = a[5] + a[4] - (a[1] + a[0]) = 3 + 7 - (5) = 11
15  // 查询区间 (1, 7) 中的结果为前缀和 s[7] - s[0] = a[7] + a[6] - (0) = 3 + 7 - (0) = 15


*/