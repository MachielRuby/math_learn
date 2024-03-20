#pragma once
#include<iostream>
using namespace std;
#include<assert.h>

namespace Gan_string1
{
	class string
	{
		typedef char* iterator;
	public:
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy_s(_str, _size + 1, str);
		}

		void swap(string& s)
		{
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
			::swap(_str, s._str);
		}
		string(const string& s)
			:_str(nullptr),
			_size(0),
			_capacity(0)
		{
			string tmp(s._str);
			this->swap(tmp);
		}

		string& operator=(string s)
		{
			this->swap(s);
			return *this;
		}

		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}

		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}

		size_t size()
		{
			return _size;
		}

		size_t capacity()
		{
			return _capacity;
		}

		void Reserve(size_t capacity)
		{
			if (capacity > _capacity)
			{
				char* str = new char[capacity + 1];
				strcpy_s(str, strlen(_str) + 1, _str);
				delete[] _str;
				_str = str;
				_capacity = capacity;
			}
		}
		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				Reserve(_capacity * 2);

			}
			_str[_size++] = ch;
			_str[_size] = '\0';
		}

		void append(const char* str)
		{
			int len = strlen(str);
			if (_size + len >= _capacity)
			{
				Reserve(_size + len);
			}
			for (int i = _size; i < _size + len; i++)
			{
				_str[i] = str[i - _size];
			}
			_size += len;
			_str[_size] = '\0';

		}

		size_t find(char c, size_t pos = 0) const
		{
			// 从指定位置开始查找
			for (size_t i = pos; i < _size; ++i)
			{
				// 如果找到目标字符，则返回索引
				if (_str[i] == c)
				{
					return i;
				}
			}
			// 如果未找到目标字符，则返回 npos
			return 0;
		}

		size_t find(const char* str, size_t pos = 0) const
		{
			size_t subLen = strlen(str);
			size_t maxPos = _size - subLen;

			// 从指定位置开始查找
			for (size_t i = pos; i <= maxPos; ++i)
			{
				// 在主字符串中查找子字符串
				if (strcmp(_str + i, str) == 0)
				{
					return i; // 找到了，返回索引
				}
			}

			// 未找到，返回 npos
			return 0;
		}


		string& insert(size_t pos, char c)
		{
			assert(pos >= 0 && pos <= _size);
			if (_size == _capacity)
			{
				Reserve(_capacity * 2);
			}
			for (int i = _size; i > pos; i--)
			{
				_str[i] = _str[i - 1];
			}
			_str[pos] = c;
			_str[++_size] = '\0';
			return *this;
		}

		string& insert(size_t pos, const char* str)
		{
			size_t len = strlen(str);
			if (_size + len >= _capacity)
			{
				Reserve(_size + len);
			}
			// 将从 pos 位置开始的字符依次后移 len 个位置
			for (int i = _size; i >= (int)pos; i--)
			{
				_str[i + len] = _str[i];
			}
			// 将待插入的字符串复制到指定位置
			for (size_t i = 0; i < len; ++i)
			{
				_str[pos + i] = str[i];
			}
			_size += len; // 更新字符串的大小
			return *this;
		}

		string& erase(size_t pos, size_t len = 0)
		{
			// 计算实际要删除的字符数
			size_t count = min(len, _size - pos);

			// 将从 pos + count 位置开始的字符依次前移 count 个位置
			for (size_t i = pos; i < _size - count; ++i)
			{
				_str[i] = _str[i + count];
			}

			_size -= count; // 更新字符串的大小
			_str[_size] = '\0'; // 添加结尾标志

			return *this;
		}

		void resize(size_t n, char ch = '\0')
		{
			if (n > _size)
			{
				if (n > _capacity)
				{
					Reserve(n);
				}
				memset(_str + _size, ch, n - _size);
			}
			_size = n;
			_str[n] = '\0';

		}
		void clear()
		{
			_size = 0;
			_str[_size] = '\0';
		}

		const char* c_str() const
		{
			return _str;
		}



		bool empty() const
		{
			return _size == 0;
		}
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		string& operator+=(const char* str)
		{
			append(str);
			return *this;

		}
		string& operator+(char ch)
		{
			push_back(ch);
			return *this;
		}
		const char& operator[](size_t i) const
		{
			assert(i >= 0 && i < _size);
			return _str[i];
		}

		char& operator[](size_t i)
		{
			assert(i >= 0 && i < _size);
			return _str[i];
		}

		bool operator<(const string& s) const
		{
			// 比较字符串的长度
			if (_size < s._size)
			{
				return true;
			}
			else if (_size > s._size)
			{
				return false;
			}
			else // 如果长度相等，则按照字典序比较字符
			{
				for (size_t i = 0; i < _size; ++i)
				{
					if (_str[i] < s._str[i])
					{
						return true;
					}
					else if (_str[i] > s._str[i])
					{
						return false;
					}
				}
				// 如果所有字符都相同，则两个字符串相等，不小于
				return false;
			}
		}

		bool operator==(const string& s) const
		{
			// 比较字符串的长度
			if (_size != s._size)
			{
				return false; // 长度不同，直接返回false
			}

			// 逐个比较字符
			for (size_t i = 0; i < _size; ++i)
			{
				if (_str[i] != s._str[i])
				{
					return false; // 发现不同的字符，返回false
				}
			}

			// 所有字符都相同，返回true
			return true;
		}

		bool operator>(string& s)
		{
			return (s < *this && !(*this == s));
		}

		bool operator<=(string& s)
		{
			return !(*this > s);
		}
		bool operator>=(string& s)
		{
			return !(*this < s);
		}
		bool operator!=(string& s)
		{
			return !(*this == s);
		}



		friend ostream& operator<<(ostream& out, const string& s);
		friend istream& operator>>(istream& in, string& s);

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
	ostream& operator<<(ostream& out, const string& s)
	{
		for (size_t i = 0; i < s._size; i++)
		{
			out << s[i];
		}
		return out;
	}
	istream& operator>>(istream& in, string& s)
	{
		char buffer[1024]; // 创建一个缓冲区来存储输入
		in.getline(buffer, sizeof(buffer)); // 从输入流中读取一行数据并存储到缓冲区中

		delete[] s._str; // 删除之前的动态分配的内存
		s._str = new char[strlen(buffer) + 1]; // 分配足够的内存
		strcpy_s(s._str, strlen(buffer) + 1, buffer); // 复制数据到 _str 中

		s._size = strlen(s._str); // 更新字符串的大小
		s._capacity = s._size; // 更新字符串的容量

		return in;
	}
	void test01()
	{
		string s1("wori");
		cout << s1 << endl;
		s1.append("shabiwanyi");
		cout << s1 << endl;
		s1.resize(50, 'w');
		s1 += "wocao";
		cout << s1 << endl;
		s1.clear();
		cout << s1 << endl;
		//cin >> s1;
		//cout << s1 << endl;
		string s2("aocao");
		string s3("bacao");
		cout << s2.find('c') << endl;
		cout << s2.find("ao") << endl;
		cout << (s2 > s3) << endl;
		string s4("wirl");
		s4.erase(1, 3);
		s4.insert(1, 'c');
		cout << s4 << endl;
	}
}