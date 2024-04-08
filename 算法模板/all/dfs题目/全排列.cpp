#include <iostream>
using namespace std;
int n;
const int N = 10;
bool st[N];
int a[N];


void dfs(int u)
{
  if(u==n)
  {
    for(int i = 0;i<n;i++)
    {
      cout<<a[i];
    }
    cout<<endl;
    return ;
  }
  for(int i = 1;i<=n;i++)
  {
    if(!st[i])
    {
      a[u] = i;
      st[i] = true;
      dfs(u+1);
      st[i] = false;
    }
  }
}
int main()
{
  // 请在此输入您的代码
  string s;
  cin>>s;
  n = s.length();
  dfs(0);
  return 0;
}