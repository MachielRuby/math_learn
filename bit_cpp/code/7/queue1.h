#pragma once
#include <iostream>
#include <deque> // 使用 deque 而不是 list

using namespace std;

namespace Gan_queue {
	template<class T>
	class queue {
	public:
		queue() = default; // 默认构造函数

		void push(const T& x) { _c.push_back(x); }

		void pop() {
			if (!empty()) { // 检查队列是否为空
				_c.pop_front();
			}
			else {
				cout << "Warning: Attempt to pop from an empty queue." << endl;
			}
		}

		T& back() {
			if (!empty()) {
				return _c.back();
			}
			else {
				throw runtime_error("Attempt to access back of an empty queue.");
			}
		}

		const T& back() const {
			if (!empty()) {
				return _c.back();
			}
			else {
				throw runtime_error("Attempt to access back of an empty queue.");
			}
		}

		T& front() {
			if (!empty()) {
				return _c.front();
			}
			else {
				throw runtime_error("Attempt to access front of an empty queue.");
			}
		}

		const T& front() const {
			if (!empty()) {
				return _c.front();
			}
			else {
				throw runtime_error("Attempt to access front of an empty queue.");
			}
		}

		size_t size() const { return _c.size(); }

		bool empty() const { return _c.empty(); }

	private:
		std::deque<T> _c; // 使用 deque 作为底层容器
	};
}
