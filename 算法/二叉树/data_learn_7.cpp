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

		for (int i = (n - 2) / 2; i >= 0; i--)
		{
			AdjustUp(data_all->data, data_all->_size, i);
		}

		int end = n - 1;
		while (end > 0)
		{
			swap(&data_all->data[0], &data_all->data[end]);
			//再次选择小的
			AdjustUp(data_all->data, end, 0);
			--end;
		}

	}

	// 交换两个元素的值
	void swap(T* p1, T* p2) {
		T tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
	}

	//建立大堆
	void AdjustUp(T* array, int n, int root)
	{
		int parent = root;
		int child = 2 * parent + 1;
		while (child < n)
		{
			if (child + 1 < n && array[child] < array[child + 1])
			{
				++child;
			}
			if (array[parent] < array[child])
			{
				swap(&array[parent], &array[child]);
				parent = child;
				child = 2 * parent + 1;
			}
			else
			{
				break;
			}
		}
	}
	void HeapPush(T x)
	{
		if (data_all->_size == data_all->_capacity)
		{
			data_all->_capacity *= 2;
			T* new_data = new T[data_all->_capacity];
			memcpy(new_data, data_all->data, sizeof(T) * data_all->_size);
			delete[] data_all->data;
			data_all->data = new_data;
			data_all->_capacity = data_all->_capacity;
		}
		data_all->data[data_all->_size++] = x;
		AdjustUp(data_all->data, data_all->_size, data_all->_size - 1);
	}

	//删除堆顶元素
	void deleteTop()
	{
		if (data_all->_size == 0)return;
		data_all->data[0] = data_all->data[--data_all->_size];
		AdjustUp(data_all->data, data_all->_size, 0);
	}
	//输出堆顶数据
	T HeapTop()
	{
		return data_all->data[0];
	}
	// 输出堆的内容
	void printHeap() {
		cout << "Heap contents: ";
		for (int i = 0; i < data_all->_size; ++i) {
			cout << data_all->data[i] << " ";
		}
		cout << endl;
	}


	//向上调整
private:
	HeapData* data_all; // 堆数据指针
};

int main() {
	int nums[] = { 1,2,3,4,5,7,6 };
	Heap heap(7, nums); // 创建一个使用给定数组的堆
	heap.HeapPush(10);
	heap.deleteTop();
	heap.deleteTop();

	heap.printHeap(); // 输出堆的内容
	cout << heap.HeapTop() << endl;
	return 0;
}
