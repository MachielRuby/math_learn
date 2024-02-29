#include <iostream>
#include <vector>
using namespace std;

// 高精度除法：A / b
vector<int> div(vector<int>& A, int b, int& remainder) {
	vector<int> C;
	remainder = 0;
	for (int i = 0; i < A.size(); i++) {
		remainder = remainder * 10 + A[i];
		C.push_back(remainder / b);
		remainder %= b;
	}
	return C;
}

int main() {
	string a;
	int b;
	cin >> a >> b;

	// 将字符串转换为数字向量
	vector<int> A;
	for (int i = 0; i < a.size(); i++) {
		A.push_back(a[i] - '0');
	}

	int remainder;
	vector<int> result = div(A, b, remainder);

	// 输出商
	bool leadingZeros = true;
	for (int i = 0; i < result.size(); i++) {
		if (result[i] != 0) {
			leadingZeros = false;
		}
		if (!leadingZeros) {
			cout << result[i];
		}
	}

	// 输出余数
	cout << endl << remainder << endl;

	return 0;
}
