#include<iostream>
using namespace std;
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<set>

void test()
{

	string strs[] = { "xigua","葡萄","爱情" };
	map<string, int>countmap;
	for (auto& str : strs)
	{
		map<string, int>::iterator ret = countmap.find(str);
		if (ret != countmap.end())
		{
			ret->second++;
		}
		else
		{
			countmap.insert(make_pair(str, 1));
		}
	}
	countmap["xiangjiao"] = 2; //插入
	countmap["xiangjiao"] = 100;

	for (auto& e : countmap)
	{
		cout << e.first << " " << e.second << endl;
	}

	std::map<std::string, std::string> dict;
	dict.insert(make_pair("sort", "排序"));
	dict["string"];
	dict["string"] = "字符串";
	dict["left"] = "左边";

	for (auto& e : dict)
	{
		cout << e.first << " " << e.second << endl;
	}
}

void test01() {
	multiset<int> ms;

	ms.insert(10);
	ms.insert(20);
	ms.insert(10);
	ms.insert(30);

	// 输出 multiset 中的元素
	for (const auto& num : ms) {
		cout << num << " ";
	}
	cout << endl;

	set<int>ms1;

	ms1.insert(10);
	ms1.insert(20);
	ms1.insert(10);
	ms1.insert(30);

	for (const auto& num : ms1) {
		cout << num << " ";
	}
	cout << endl;
}

int main()
{
	test01();
	return 0;
}