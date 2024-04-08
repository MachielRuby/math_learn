#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int a[N];
static int _size = 0;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void push(int x) {
    a[++_size] = x;
    int i = _size;
    while (i > 1 && a[i] < a[i / 2]) {
        swap(a[i], a[i / 2]);
        i /= 2;
    }
}

void down(int i) {
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= _size && a[left] < a[smallest])
        smallest = left;
    if (right <= _size && a[right] < a[smallest])
        smallest = right;

    if (smallest != i) {
        swap(a[i], a[smallest]);
        down(smallest);
    }
}

int remove() {
    if (_size == 0) {
        cout << "empty" << endl;
        return -1;  // Indicate an error
    }
    int root = a[1];
    a[1] = a[_size--];
    down(1);
    return root;
}

void print(int k) {
    if (_size < k) {
        cout << "Not enough elements" << endl;
        return;
    }

    for (int i = 0; i < k; i++) {
        cout << remove() << " ";
    }
    cout << endl;
}

void min() {
    if (_size > 0)
        cout << a[1] << endl;
    else
        cout << "empty" << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (s == "push") {
            int x;
            cin >> x;
            push(x);
        } else if (s == "print") {
            int k;
            cin >> k;
            print(k);
        } else if (s == "remove") {
            remove();
        } else if (s == "min") {
            min();
        }
    }
    return 0;
}
