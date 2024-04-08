#include<iostream>
using namespace std;
int n;
const int N = 1e5+5;
int a[N];

void down(int x)
{
  int smallest = x;
  if(2*x<=n && a[2*x]<a[smallest]) smallest = 2*x;
  if(2*x+1<=n && a[2*x+1]<a[smallest]) smallest = 2*x+1;
  if(smallest != x)
  {
    swap(a[smallest], a[x]);
    down(smallest);
  }
}

int main()
{
  cin >> n;
  for(int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }

  for(int i = n/2; i >= 1; i--) down(i);
  while(n >= 1)
  {
    cout << a[1] << " ";
    swap(a[1], a[n]);
    n--;
    down(1);
  }
  
  return 0;
}
