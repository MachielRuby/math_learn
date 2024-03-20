#pragma once
#include<vector>
#include<algorithm> // 包含算法头文件以访问std::swap

namespace Gan_priority_queue
{
	template<class T>
	struct less
	{
		bool operator()(const T& left, const T& right) const
		{
			return left < right;
		}
	};

	template<class T>
	struct greater
	{
		bool operator()(const T& left, const T& right) const
		{
			return left > right;
		}
	};

	template<class T, class Container = std::vector<T>, class Compare = less<T>>
	class priority_queue
	{
	public:
		priority_queue() : c(), Com() {}

		template<class Iterator>
		priority_queue(Iterator first, Iterator last) : c(first, last), Com()
		{
			int count = c.size();
			int root = (count - 2) / 2;
			for (; root >= 0; --root)
			{
				AdjustDown(root);
			}
		}

		void push(const T& data)
		{
			c.push_back(data);
			AdjustUp(c.size() - 1);
		}

		void pop()
		{
			if (empty())
				return;

			std::swap(c.front(), c.back());
			c.pop_back();
			AdjustDown(0);
		}

		size_t size() const
		{
			return c.size();
		}

		bool empty() const
		{
			return c.empty();
		}

		const T& top() const
		{
			return c.front();
		}

	private:
		void AdjustUp(int child)
		{
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				if (Com(c[parent], c[child]))
				{
					std::swap(c[child], c[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}

		void AdjustDown(int parent)
		{
			int child = 2 * parent + 1;
			while (child < c.size())
			{
				if (child + 1 < c.size() && Com(c[child], c[child + 1]))
				{
					++child;
				}
				if (Com(c[parent], c[child]))
				{
					std::swap(c[child], c[parent]);
					parent = child;
					child = 2 * parent + 1;
				}
				else
				{
					break;
				}
			}
		}

		Container c;
		Compare Com; // 比较器对象
	};
}
