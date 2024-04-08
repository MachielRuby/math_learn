#include<iostream>
using namespace std;


int main()
{
	long long n;
	cin >> n;
	int count = 0;
	long long div = 100;
	long long sum = 0;
	while (n > 0)
	{
		n = n / div;
		if (n >= 0 && n <= 9)
		{
			count += n;
		}
		else
		{
			count += 9;
		}
		if (n > 0)
		{
			n *= div;
		}
		div = div * 10;

	}
	sum = count * 100;
	cout << sum << endl;
	return 0;
}