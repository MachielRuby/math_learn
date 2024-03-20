﻿#include <iostream>
#include <cassert>
#include <algorithm> // for std::swap
#include <string>

namespace Gan_vector1
{
	template<class T>
	class vector
	{
		typedef T* iterator;
		typedef const T* const_iterator;


	public:
		// 构造函数
		vector() : _start(nullptr), _finish(nullptr), _endOfStorage(nullptr) {}

		vector(int n, const T& value = T()) : _start(nullptr), _finish(nullptr), _endOfStorage(nullptr)
		{
			reserve(n);
			while (n--) {
				push_back(value);
			}
		}

		template<class InputIterator>
		vector(InputIterator first, InputIterator last) : _start(nullptr), _finish(nullptr), _endOfStorage(nullptr)
		{
			reserve(last - first);
			while (first != last) {
				push_back(*first);
				++first;
			}
		}

		vector(const vector<T>& v) : _start(nullptr), _finish(nullptr), _endOfStorage(nullptr)
		{
			reserve(v.capacity());
			iterator it = begin();
			const_iterator vit = v.cbegin();
			while (vit != v.cend())
			{
				*it++ = *vit++;
			}
		}

		// 析构函数
		~vector()
		{
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;
		}

		// 拷贝赋值运算符
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}

		// 容量相关操作
		size_t size() const { return _finish - _start; }
		size_t capacity() const { return _endOfStorage - _start; }
		bool empty() const { return _start == _finish; }

		// 修改容器大小
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t oldSize = size();
				T* tmp = new T[n];
				if (_start)
				{
					for (size_t i = 0; i < oldSize; ++i)
						tmp[i] = _start[i];
				}
				_start = tmp;
				_finish = _start + oldSize;
				_endOfStorage = _start + n;
			}
		}

		void resize(size_t n, const T& value = T())
		{
			if (n <= size())
			{
				_finish = _start + n;
				return;
			}
			if (n > capacity())
				reserve(n);
			iterator it = _finish;
			_finish = _start + n;
			while (it != _finish)
				*it++ = value;
		}

		// 访问元素
		T& operator[](size_t pos) { return _start[pos]; }
		const T& operator[](size_t pos) const { return _start[pos]; }

		// 修改元素
		void push_back(const T& x) { insert(end(), x); }
		void pop_back() { erase(--end()); }

		// 交换两个向量
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endOfStorage, v._endOfStorage);
		}

		// 插入元素
		iterator insert(iterator pos, const T& x)
		{
			assert(pos <= _finish);
			if (_finish == _endOfStorage)
			{
				size_t newCapacity = (capacity() == 0) ? 1 : capacity() * 2;
				reserve(newCapacity);
				pos = _start + size();
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
			return pos;
		}

		// 删除元素
		iterator erase(iterator pos)
		{
			assert(pos < _finish);
			iterator begin = pos + 1;
			while (begin != _finish)
			{
				*(begin - 1) = *begin;
				++begin;
			}
			--_finish;
			return pos;
		}


		// 迭代器相关操作
		iterator begin() { return _start; }
		iterator end() { return _finish; }
		const_iterator cbegin() const { return _start; }
		const_iterator cend() const { return _finish; }

	private:
		T* _start;
		T* _finish;
		T* _endOfStorage; // 指向存储容量的尾
	};
	void test()
	{
		Gan_vector1::vector<std::string> v;
		v.push_back("1111");
		v.push_back("2222");
		v.push_back("3333");
		v.insert(v.begin(), "wori");
		v.erase(v.begin() + 1);
		for (auto s : v)
		{
			std::cout << s << std::endl;
		}
	}
} // namespace Gan_vector1
