#include <iostream>
using namespace std;

template<class T>
class MyQueue {
private:
    T* data;        // 存储队列元素的数组
    int capacity;   // 队列容量
    int size;       // 当前队列中的元素数量
    int front;      // 队列的前端索引
    int rear;       // 队列的后端索引

    // 扩展队列容量
    void expand() {
        int newCapacity = capacity * 2;    // 扩容为当前容量的两倍
        T* newData = new T[newCapacity];   // 创建新的数组
        int j = 0;
        for (int i = front; i != rear; i = (i + 1) % capacity) {
            newData[j++] = data[i];         // 将原队列中的元素复制到新数组中
        }
        delete[] data;                      // 删除原数组
        data = newData;                     // 更新指针
        capacity = newCapacity;             // 更新容量
        front = 0;                          // 更新队列的前端索引
        rear = size;                        // 更新队列的后端索引
    }

public:
    // 构造函数
    MyQueue() : capacity(10), size(0), front(0), rear(0) {
        data = new T[capacity];
    }

    // 析构函数
    ~MyQueue() {
        delete[] data;
    }

    // 入队操作
    void enqueue(T val) {
        if (size == capacity - 1) {    // 如果队列已满，则扩展容量
            expand();
        }
        data[rear] = val;              // 将元素插入到队列的后端
        rear = (rear + 1) % capacity;  // 更新后端索引
        size++;                        // 更新队列元素数量
    }

    // 出队操作
    T dequeue() {
        if (isEmpty()) {
            cerr << "队列为空，无法出队" << endl;
            exit(1);
        }
        T val = data[front];            // 获取队列的前端元素
        front = (front + 1) % capacity; // 更新前端索引
        size--;                         // 更新队列元素数量
        return val;                     // 返回出队元素
    }

    // 获取队列的前端元素
    T frontValue() const {
        if (isEmpty()) {
            cerr << "队列为空，无法获取前端元素" << endl;
            exit(1);
        }
        return data[front];
    }

    // 判断队列是否为空
    bool isEmpty() const {
        return size == 0;
    }

    // 获取队列中的元素数量
    int getSize() const {
        return size;
    }
};

int main() {
    MyQueue<int> queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);

    cout << "Front element: " << queue.frontValue() << endl;

    while (!queue.isEmpty()) {
        cout << "Dequeued element: " << queue.dequeue() << endl;
    }

    return 0;
}
