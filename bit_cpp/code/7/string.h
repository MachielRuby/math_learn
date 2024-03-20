#pragma once
#include<assert.h>
#include<string.h>
#include<iostream>
using namespace std;
namespace Gan_string
{
	class string
	{
	public:
		friend ostream& operator<<(ostream& out, const string& s);
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}

		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[(strlen(str) + 1)];
			strcpy_s(_str, strlen(str) + 1, str);
		}

		string(const string& s) :_str(nullptr),
			_size(0),
			_capacity(0)
		{
			string tmp(s._str);
			this->swap(tmp);
		}

		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);

		}
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		size_t  size() const
		{
			return _size;
		}

		size_t capacity()const
		{
			return _capacity;
		}

		char& operator[](size_t i)
		{
			assert(i < _size);
			return _str[i];
		}



		const char* c_str()
		{
			return _str;
		}

		void push_back(char ch)
		{
			if (_size + 1 > _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
				reserve(newcapacity);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			strcpy_s(_str + _size, strlen(str) + 1, str);
			_size += len;
		}


		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* newstr = new char[n + 1];
				strcpy_s(newstr, strlen(_str) + 1, _str);
				delete[] _str;
				_str = newstr;
				_capacity = n;
			}
		}

		int find(const char* str, size_t pos = 0)
		{
			char* p = strstr(_str, str);
			if (p == nullptr)
			{
				return -1;
			}
			else
			{
				return p - _str;
			}
		}


		void insert(size_t pos, const char* str)
		{
			assert(pos < _size);
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			int end = _size;
			while (end >= pos)
			{
				_str[end + len] = _str[end];
				--end;
			}
			for (size_t i = 0; i < len; i++)
			{
				_str[pos + i] = str[i];
			}
			_size += len;
		}


		void erase(size_t pos, size_t len = 2 ^ 32 - 1)
		{
			if (len > _size - pos)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				size_t i = pos + len;
				while (i <= _size)
				{
					_str[i - len] = _str[i];
					++i;
				}
				_size -= len;
			}
		}

		string& operator+(const char* str)
		{
			this->append(str);
			return *this;
		}
		string& operator+(const char ch)
		{
			this->push_back(ch);
			return *this;
		}


		string& operator+=(const char* str) // => 
		{
			this->append(str);
			return *this;
		}
		string& operator+=(const char ch)
		{
			this->push_back(ch);
			return *this;
		}


		bool operator<(const string& s)
		{
			int ret = strcmp(_str, s._str);
			return ret < 0;
		}
		bool operator=(const string& s)
		{
			int ret = strcmp(_str, s._str);
			return ret == 0;
		}
		bool operator>(const string& s)
		{
			return !((*this < s) && (*this = s));
		}
	private:
		char* _str; //动态字符串
		size_t _size; // 字符串大小
		size_t _capacity; //字符串容量
	};
	ostream& operator<<(ostream& out, const string& s)
	{
		out << s._str << endl;
		return out;
	}
	void test()
	{
		string s("hello");
		s += "wori";
		string::iterator it = s.begin();
		while (it != s.end())
		{
			std::cout << *it << std::endl;
			it++;
		}
		string s1("zzz");
		string s2("aaa");
		cout << (s1 > s2) << endl;
		cout << s1 << endl;
		string s3(s2);
		cout << s3 << endl;
		s1.insert(1, "wocao");
		cout << s1 << endl;
		s1.erase(1, 3);
		cout << s1 << endl;

	}
}