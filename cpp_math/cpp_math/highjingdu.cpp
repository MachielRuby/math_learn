#include<iostream>
using namespace std;
#include<vector>

const int N = 1e6 + 10;

vector<int> add(vector<int>& A, vector<int>& B)
{
	vector<int>C;
	int t = 0;
	for (int i = 0; i < A.size(); i++)
	{
		if (i < A.size()) t += A[i];
		if (i < B.size()) t += B[i];
		C.push_back(t % 10);
		t /= 10;
	}
	if (t == 1)
	{
		C.push_back(1);
	}

	return C;
}

int main()
{
	string a, b;
	vector<int>A, B;

	cin >> a >> b; //a = "123456"
	for (int i = a.size() - 1; i >= 0; i--)
	{
		A.push_back(a[i] - '0');// 6 5 4 3 2 1
	}
	for (int i = b.size() - 1; i >= 0; i--)
	{
		B.push_back(b[i] - '0');
	}
	auto C = add(A, B);
	for (int i = C.size() - 1; i >= 0; i--)
	{
		cout << C[i];
	}
	cout << endl;
	return 0;
}