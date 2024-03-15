#include <iostream>
#include <cstring> // 用于 memcpy 函数
using namespace std;

#define _CRT_SECURE_WARNINGS

typedef int T;

// 堆数据结构
struct HeapData {
	T* data; // 数据数组指针
	int _size; // 堆的当前大小
	int _capacity; // 堆的容量
};

class Heap {
public:
	// 构造函数
	// n: 数组的大小
	// array: 初始化堆所用的数组指针
	Heap(int n = 10, T* array = nullptr) {
		// 初始化 HeapData 结构
		data_all = new HeapData;
		data_all->data = new T[n]; // 为数据数组分配内存
		memcpy(data_all->data, array, sizeof(T) * n); // 将数组元素复制到数据数组中
		data_all->_size = n; // 设置堆的大小
		data_all->_capacity = n; // 设置堆的容量

		// 构建堆
		for (int i = (n - 2) / 2; i >= 0; i--) {
			AdjustDown(data_all->data, data_all->_size, i);
		}
	}

	// 交换两个元素的值
	void swap(T* p1, T* p2) {
		T tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
	}

	// 从给定的索引开始向下调整堆
	void AdjustDown(T* array, int n, int root) {
		int parent = root;
		int child = parent * 2 + 1;
		while (child < n) {
			// 找出较小的孩子
			if (child + 1 < n && array[child + 1] < array[child]) {
				++child;
			}
			// 如果孩子小于父节点，则交换它们的值
			if (array[parent] > array[child]) {
				swap(&array[child], &array[parent]);
				parent = child;
				child = parent * 2 + 1;
			}
			else {
				break;
			}
		}
	}

	// 输出堆的内容
	void printHeap() {
		cout << "Heap contents: ";
		for (int i = 0; i < data_all->_size; ++i) {
			cout << data_all->data[i] << " ";
		}
		cout << endl;
	}

private:
	HeapData* data_all; // 堆数据指针
};

int main() {
	int nums[] = { 1,2,3,4,5,7,6 };
	Heap heap(7, nums); // 创建一个使用给定数组的堆
	heap.printHeap(); // 输出堆的内容
	return 0;
}
