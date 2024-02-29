#include<iostream>
using namespace std;
#include<vector>

// C = A*b
vector<int>mul(vector<int>& a, int b)
{
	vector<int>C;
	int t = 0;
	for (int i = 0; i < a.size() || t; i++)
	{
		if (i < a.size())t += a[i] * b;
		C.push_back(t % 10);
		t /= 10;
	}
	return C;
}

int main()
{
	string a;
	int b;
	cin >> a >> b;
	vector<int>A;
	for (int i = 0; i < a.size(); i++)
	{
		A.push_back(a[i] - '0');
	}
	auto C = mul(A, b);
	for (int i = C.size() - 1; i >= 0; i--)
	{
		cout << C[i];
	}
	cout << endl;
	return 0;
}


