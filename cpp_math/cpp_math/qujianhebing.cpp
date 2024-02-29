/*

// 将所有存在交集的区间合并
void merge(vector<PII> &segs)
{
	vector<PII> res;

	sort(segs.begin(), segs.end());

	int st = -2e9, ed = -2e9;
	for (auto seg : segs)
		if (ed < seg.first)
		{
			if (st != -2e9) res.push_back({st, ed});
			st = seg.first, ed = seg.second;
		}
		else ed = max(ed, seg.second);

	if (st != -2e9) res.push_back({st, ed});

	segs = res;
}


区间合并 [l,r]合并区间有所交集端点也算  [1,3]和[2,6]合并为区间[1,6]
*/

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

const int N = 100010;

int n;

// 定义一个pair类型p11，用于存储两个整数
typedef pair<int, int> p11;

// 合并重叠区间的函数
void merge(vector<p11>& segs)
{
	vector<p11> res; // 存储合并后的区间结果
	sort(segs.begin(), segs.end()); // 将区间按照左端点排序

	int st = -2e9, ed = -2e9; // 初始化起始和结束点为负无穷

	// 遍历排序后的区间
	for (auto seg : segs)
	{
		if (ed < seg.first) // 如果当前区间的左端点大于前一个区间的右端点，表示没有交集
		{
			if (st != -2e9) // 如果起始点不是初始值，说明前面有合法的区间
				res.push_back({ st, ed }); // 将前一个合法区间加入到结果中
			st = seg.first; // 更新起始点为当前区间的左端点
			ed = seg.second; // 更新结束点为当前区间的右端点
		}
		else // 如果有交集，则更新当前区间的右端点
			ed = max(ed, seg.second);
	}

	if (st != -2e9) // 最后一个区间也是合法的，需要加入结果中
		res.push_back({ st, ed });

	segs = res; // 更新原始区间为合并后的结果
}

int main()
{
	cin >> n; // 输入区间的个数
	vector<p11> segs; // 定义存储区间的向量

	// 循环读入每个区间的左右端点
	for (int i = 0; i < n; i++)
	{
		int l, r;
		cin >> l >> r;
		segs.push_back({ l, r }); // 将当前区间加入到向量中
	}

	merge(segs); // 调用合并函数，对区间进行合并

	cout << segs.size() << endl; // 输出合并后区间的个数
	return 0;
}
