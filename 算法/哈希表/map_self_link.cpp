#include<iostream>
using namespace std;
#include<vector>

//简单实现 链表哈希
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
class HashMapChaining
{
private:
	int size;//键值对数量
	int capacity;//哈希表容量
	double loadThres; //触发扩容的负载因子
	int extendRadio;//扩容倍数
	vector<vector<Pair*>>buckets; //桶数组
public:
	//构造方法
	HashMapChaining() :size(0), capacity(4), loadThres(2.0 / 3.0), extendRadio(2)
	{
		buckets.resize(capacity);
	}
	//析构函数释放内存
	~HashMapChaining()
	{
		for (auto& bucket : buckets)
		{
			for (Pair* pair : bucket)
			{
				delete pair;
			}
		}
		buckets.clear();

	}

	//哈希函数
	int hashfunc(int key)
	{
		return key % capacity;
	}
	//负载因子
	double loadFactor()
	{
		return (double)size / (double)capacity;
	}


	//查询操作
	string get(int key)
	{
		int index = hashfunc(key);
		for (Pair* pair : buckets[index])
		{
			if (pair->key == key)
			{
				return pair->val;
			}
		}
		return "";
	}

	//扩容
	void extend()
	{
		//暂存原来的
		vector<vector<Pair*>>bucketsTmp = buckets;
		//初始化扩容后的
		capacity *= extendRadio;
		buckets.clear();
		buckets.resize(capacity);
		size = 0;
		for (auto& bucket : bucketsTmp)
		{
			for (Pair* pair : bucket)
			{
				put(pair->key, pair->val);
				//释放内存
				delete pair;
			}
		}
	}
	//添加操作
	void put(int key, string val)
	{
		if (loadFactor() > loadThres)
		{
			extend();
		}

		int index = hashfunc(key);
		//遍历桶
		for (Pair* pair : buckets[index])
		{
			if (pair->key == key)
			{
				pair->val = val;
				return;
			}
		}
		//如果没有就添加到尾
		buckets[index].push_back(new Pair(key, val));
		size++;
	}

	//删除操作
	void remove(int key)
	{
		int index = hashfunc(key);
		auto& bucket = buckets[index];
		for (int i = 0; i < bucket.size(); i++)
		{
			if (bucket[i]->key == key)
			{
				Pair* tmp = bucket[i];
				bucket.erase(bucket.begin() + i);//删除键值对
				delete tmp;
				size--;
				return;
			}
		}
	}
	//打印
	void print()
	{
		for (auto& bucket : buckets)
		{
			for (Pair* pair : bucket)
			{
				cout << pair->key << " -> " << pair->val << endl;
			}
		}
	}
};

int main()
{
	HashMapChaining a;
	a.put(1, "shabi");
	a.put(2, "蓝徽枚");
	a.put(3, "蓝徽枚");
	a.put(4, "蓝徽枚");
	a.put(5, "蓝徽枚");

	string name = a.get(1);
	cout << "name = " << name << endl;
	a.print();
	return 0;
}