#include<iostream>
using namespace std;


enum State
{
	STATE_UNUSE,//never used
	STATE_USING,//is using
	STATE_DEL, //once used
};
//桶的类型
struct Bucket
{
	Bucket(int key = 0, State state = STATE_UNUSE)
		:_key(key),
		_state(state)
	{}
	int _key; //存储的数据
	State _state; //桶的当前状态
};

class HashTable
{
public:
	HashTable(int size = _primes[0], double loadFactor = 0.75)
		:_useBucketNum(0),
		_loadFactor(loadFactor),
		_primeIdx(0)
	{
		//用户传入的size调整到最近的比较大的素数
		if (size != _primes[0])
		{
			for (; _primeIdx < PRIME_SIZE; _primeIdx++)
			{
				if (_primes[_primeIdx] >= size)
					break;
			}
			//用户传入的值过大
			if (_primeIdx == PRIME_SIZE)
			{
				_primeIdx--;
			}
		}
		_tableSize = _primes[_primeIdx];
		_table = new Bucket[_tableSize];
	}
	~HashTable()
	{
		delete[]_table;
		_table = nullptr;
	}

public:
	bool insert(int key)
	{
		//考虑扩容
		double factor = _useBucketNum * 1.0 / _tableSize;
		cout << "factor = " << factor << endl;
		if (factor > _loadFactor)
		{
			//开始扩容
			expand();
		}
		int idx = key % _tableSize;
		int i = idx;
		do
		{
			if (_table[i]._state != STATE_USING)
			{
				_table[i]._state = STATE_USING;
				_table[i]._key = key;
				_useBucketNum++;
				return true;
			}
			i = (i + 1) % _tableSize;
		} while (i != idx);
		return false;
	}

	bool erase(int key)
	{
		int idx = key % _tableSize;
		int i = idx;
		do
		{
			if (_table[i]._state == STATE_USING && _table[i]._key == key)
			{
				_table[i]._state = STATE_DEL;
				_useBucketNum--;
			}
			i = (i + 1) % _tableSize;
		} while (_table[i]._state != STATE_UNUSE && i != idx);
		return true;
	}

	bool find(int key)
	{
		int idx = key % _tableSize;
		int i = idx;
		do
		{
			if (_table[i]._state == STATE_USING && _table[i]._key == key)
			{
				return true;
			}
			i = (i + 1) % _tableSize;
		} while (_table[i]._state != STATE_UNUSE && i != idx);
		return false;
	}
private:
	void expand()
	{
		++_primeIdx;
		if (PRIME_SIZE == _primeIdx)
		{
			throw "is too large";
		}
		Bucket* newTable = new Bucket[_primes[_primeIdx]];
		for (int i = 0; i < _tableSize; i++)
		{
			if (_table[i]._state == STATE_USING)
			{
				int idx = _table[i]._key % _primes[_primeIdx];
				int k = idx;
				do
				{
					if (newTable[k]._state != STATE_USING)
					{
						newTable[k]._state = STATE_USING;
						newTable[k]._key = _table[i]._key;
						break;
					}
					k = (k + 1) % _primes[_primeIdx];
				} while (k != idx);
			}
		}
		delete[]_table;
		_table = newTable;
		_tableSize = _primes[_primeIdx];
	}
private:
	Bucket* _table; //指向动态开启的哈希表
	int _tableSize;//哈希表的当前的长度
	int _useBucketNum;//已经使用的桶的个数
	double _loadFactor; //哈希表的装载因子

	static const int PRIME_SIZE = 10; //素数表的大小
	static int _primes[PRIME_SIZE];//素数表
	int _primeIdx;//当前使用的素数的下标
};
int HashTable::_primes[PRIME_SIZE] = { 3, 7, 23, 47, 97, 251, 443, 911, 1471, 42773 };

int main()
{
	HashTable htable;
	htable.insert(21);
	htable.insert(34);
	htable.insert(14);
	htable.insert(14);
	htable.insert(14);
	htable.insert(14);
	htable.insert(14);

	htable.insert(15);
	cout << htable.find(15) << endl;
	htable.erase(15);
	htable.erase(14);

	htable.erase(15);


	cout << htable.find(15) << endl;
	cout << htable.find(14) << endl;
	cout << htable.find(14) << endl;



	return 0;
}