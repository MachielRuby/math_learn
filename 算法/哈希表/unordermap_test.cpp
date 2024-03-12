#include<iostream>
using namespace std;
#include<map>
#include <unordered_map>

void test01()
{
	unordered_map<int, string>map;
	map[1] = "shabi";
	map[2] = "wocao";

	string name = map[1];
	cout << name << endl;

	map.erase(1);
	for (auto kv : map)
	{
		cout << kv.first << " " << kv.second << endl;
	}

	for (auto iter = map.begin(); iter != map.end(); iter++)
	{
		cout << iter->first << " " << iter->second << endl;
	}
}


//简单实现
struct Pair
{
public:
	int key;
	string val;
	Pair(int key, string val)
	{
		this->key = key;
		this->val = val;
	}
};
//基于数组实现的哈希表
class  ArrayHashMap
{
private:
	vector<Pair*>buckets;
public:
	ArrayHashMap()
	{
		buckets = vector<Pair*>(100);//初始化数组一百个桶
	}
	~ArrayHashMap()
	{
		//释放内存
		for (const auto& bucket : buckets)
		{
			delete bucket;
		}
		buckets.clear();
	}
	//哈希函数
	int hashFunc(int key)
	{
		int index = key % 100;
		return index;
	}
	//查询操作
	string get(int key)
	{
		int index = hashFunc(key);
		Pair* pair = buckets[index];
		if (pair == nullptr)
		{
			return "";
		}
		return pair->val;
	}

	void put(int key, string val)
	{
		Pair* pair = new Pair(key, val);
		int index = hashFunc(key);
		buckets[index] = pair;
	}

	//删除操作
	void remove(int key)
	{
		int index = hashFunc(key);
		//释放内存
		delete buckets[index];
		buckets[index] = nullptr;
	}

	//获取所有键值对
	vector<Pair*>pairSet()
	{
		vector<Pair*>pairSet;
		for (Pair* pair : buckets)
		{
			if (pair != nullptr)
			{
				pairSet.push_back(pair);
			}
		}
		return pairSet;
	}

	//获取所有键
	vector<int>keySet()
	{
		vector<int>keySet;
		for (Pair* pair : buckets)
		{
			if (pair != nullptr)
			{
				keySet.push_back(pair->key);
			}
		}
		return keySet;
	}

	//获取所有值
	vector<string>valueSet()
	{
		vector<string>valueSet;
		for (Pair* pair : buckets)
		{
			if (pair != nullptr)
			{
				valueSet.push_back(pair->val);
			}
		}
		return valueSet;
	}

	//打印哈希表
	void print()
	{
		for (Pair* kv : pairSet())
		{
			cout << kv->key << " -> " << kv->val << endl;
		}
	}

};
int main()
{
	test01();
	ArrayHashMap map;
	map.put(1, "wocao");
	map.put(2, "wori");
	map.put(3, "nice");
	map.print();

	return 0;
}