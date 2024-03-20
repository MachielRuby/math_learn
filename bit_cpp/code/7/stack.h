#pragma once
#include<vector>
#include<iostream>
using namespace std;

namespace Gan_stack {
	template<class T>
	class stack {
	public:
		stack() {}
		void push(const T& x) { _c.push_back(x); }
		T pop() {
			if (!empty()) {
				T topElement = _c.back(); // 先保存栈顶元素
				_c.pop_back();            // 然后弹出
				return topElement;        // 返回保存的栈顶元素
			}
			throw std::runtime_error("Pop from empty stack"); // 或者处理空栈的情况
		}
		T& top() { return _c.back(); }
		const T& top() const { return _c.back(); }
		size_t size() const { return _c.size(); }
		bool empty() const { return _c.empty(); }

	private:
		std::vector<T> _c;
	};

	inline void test() {
		stack<int> s;
		s.push(1);
		s.push(2);
		s.push(3);
		s.push(4);

		while (!s.empty()) {
			std::cout << s.pop() << std::endl;
		}
	}
}
