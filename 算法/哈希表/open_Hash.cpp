#include<iostream>
using namespace std;
#include<vector>

// 定义键值对结构体
struct Pair {
public:
	int key; // 键
	string val; // 值

	// 构造函数
	Pair(int key, string val) {
		this->key = key;
		this->val = val;
	}
};

// 开放寻址哈希表类
class HashOpenAddress {
private:
	int size; // 键值对数量
	int capacity = 4; // 初始容量
	const double loadThres = 2.0 / 3.0; // 触发扩容的负载因子阈值
	const int extendRadio = 2; // 扩容倍数
	vector<Pair*> buckets; // 存储键值对的桶数组
	Pair* TOMBSTONE = new Pair(-1, "-1"); // 删除标记

public:
	// 构造方法
	HashOpenAddress() : size(0), buckets(capacity, nullptr) {}

	// 析构方法
	~HashOpenAddress() {
		for (Pair* pair : buckets) {
			if (pair != nullptr && pair != TOMBSTONE) {
				delete pair;
			}
		}
		delete TOMBSTONE;
	}

	// 哈希函数
	int hashfunc(int key) {
		return key % capacity;
	}

	// 计算负载因子
	double loadFactor() {
		return static_cast<double>(size) / static_cast<double>(capacity);
	}

	// 查找键对应的桶索引
	int findBucket(int key) {
		int index = hashfunc(key);
		int firstTombstone = -1; // 记录首个删除标记的索引

		// 线性探测遇到空桶的跳出
		while (buckets[index] != nullptr) {
			// 遇到key返回对应的桶索引
			if (buckets[index]->key == key) {
				if (firstTombstone != -1) {
					// 遇到之前删除的标记移动到该索引处
					buckets[firstTombstone] = buckets[index];
					buckets[index] = TOMBSTONE;
					return firstTombstone; // 返回移动后的桶索引
				}
				return index;
			}
			// 记录首个删除标记的位置
			if (firstTombstone == -1 && buckets[index] == TOMBSTONE) {
				firstTombstone = index;
			}
			// 计算下一个索引
			index = (index + 1) % capacity;
		}
		// 若未找到key对应的桶索引，则返回首个删除标记的索引或当前索引
		return firstTombstone == -1 ? index : firstTombstone;
	}

	// 查询操作
	string get(int key) {
		// 搜索key对应的桶索引
		int index = findBucket(key);
		// 若找到则返回对应值
		if (buckets[index] != nullptr && buckets[index] != TOMBSTONE) {
			return buckets[index]->val;
		}
		return "";
	}

	// 添加操作
	void put(int key, string val) {
		// 若负载因子超过阈值，执行扩容
		if (loadFactor() > loadThres) {
			extend();
		}
		// 搜索 key 对应的桶索引
		int index = findBucket(key);
		// 若找到则更新值
		if (buckets[index] != nullptr && buckets[index] != TOMBSTONE) {
			buckets[index]->val = val;
			return;
		}
		// 若键值对不存在，则添加
		buckets[index] = new Pair(key, val);
		size++;
	}

	// 删除操作
	void remove(int key) {
		// 搜索 key 对应的桶索引
		int index = findBucket(key);
		// 若找到键值对，则用删除标记替换
		if (buckets[index] != nullptr && buckets[index] != TOMBSTONE) {
			delete buckets[index];
			buckets[index] = TOMBSTONE;
			size--;
		}
	}

	// 扩容哈希表
	void extend() {
		// 暂存原哈希表
		vector<Pair*> bucketsTmp = buckets;
		// 初始化扩容后的新哈希表
		capacity *= extendRadio;
		buckets = vector<Pair*>(capacity, nullptr);
		size = 0;
		// 将键值对从原哈希表搬运至新哈希表
		for (Pair* pair : bucketsTmp) {
			if (pair != nullptr && pair != TOMBSTONE) {
				put(pair->key, pair->val);
				delete pair;
			}
		}
	}

	// 打印哈希表
	void print() {
		for (Pair* pair : buckets) {
			if (pair == nullptr) {
				cout << "nullptr" << endl;
			}
			else if (pair == TOMBSTONE) {
				cout << "TOMBSTONE" << endl;
			}
			else {
				cout << pair->key << " -> " << pair->val << endl;
			}
		}
	}
};


//int main()
//{
//	HashOpenAddress m;
//	m.put(1, "wocao");
//	m.put(2, "wocao");
//	m.put(3, "wocao");
//	m.put(4, "wocao");
//	m.put(5, "wocao");
//
//	m.remove(2);
//	m.put(2, "woddscao");
//
//	m.print();
//	return 0;
//}

//四种hash算法设计
// === File: simple_hash.cpp ===
/* 加法哈希 */
int addHash(string key) {
	long long hash = 0;
	const int MODULUS = 1000000007;
	for (unsigned char c : key) {
		hash = (hash + (int)c) % MODULUS;
	}
	return (int)hash;
}
/* 乘法哈希 */
int mulHash(string key) {
	long long hash = 0;
	const int MODULUS = 1000000007;
	for (unsigned char c : key) {
		hash = (31 * hash + (int)c) % MODULUS;
	}
	return (int)hash;
}
/* 异或哈希 */
int xorHash(string key) {
	int hash = 0;
	const int MODULUS = 1000000007;
	for (unsigned char c : key) {
		hash ^= (int)c;
	}
	return hash & MODULUS;
}
/* 旋转哈希 */
int rotHash(string key) {
	long long hash = 0;
	const int MODULUS = 1000000007;
	for (unsigned char c : key) {
		hash = ((hash << 4) ^ (hash >> 28) ^ (int)c) % MODULUS;
	}
	return (int)hash;
}

int main()
{
	int num = 3;
	size_t hashNum = hash<int>()(num);
	cout << hashNum << endl;
	string str = "Hello 算法";
	size_t hashStr = hash<string>()(str);
	cout << hashStr << endl;
	return 0;
}