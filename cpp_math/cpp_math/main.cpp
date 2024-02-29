#include<iostream>
using namespace std;
#include<vector>
void quick_Sort(vector<int>& nums, int l, int r)
{
	if (l >= r)return;
	int x = nums[l], i = l - 1, j = r + 1;
	while (i < j)
	{
		do i++; while (nums[i] < x);
		do j--; while (nums[j] > x);
		if (i < j)swap(nums[i], nums[j]);
	}
	quick_Sort(nums, l, j);
	quick_Sort(nums, j + 1, r);
}
void print_vector(vector<int> a)
{
	for (auto ch : a)
	{
		cout << ch << " ";
	}
	cout << endl;
}



int main(int argc, char* argv[])
{
	vector<int>a = { 1,3,4,5,1,2,0 };
	quick_Sort(a, 0, a.size() - 1);
	print_vector(a);
	return 0;
}