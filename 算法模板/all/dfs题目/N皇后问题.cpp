#include <iostream>
using namespace std;
using ll = long long;
const int N = 15;
int n,ans;
int vis[N][N]; //表示多少个皇后呗占用了

void dfs(int dep)
{
  if(dep==n+1)
  {
    ans ++;
    return ;
  }
  for(int i = 1;i<=n;i++)
  {
    if(vis[dep][i])continue;
    //修改状态
    for(int _i= 1;_i<=n;++_i)vis[_i][i]++;
    for(int _i = dep,_j = i;_i>=1&&_j>=1;--_i,--_j)vis[_i][_j]++;
    for(int _i = dep,_j = i;_i<=n&&_j>=1;++_i,--_j)vis[_i][_j]++;
    for(int _i = dep,_j = i;_i>=1&&_j<=n;--_i,++_j)vis[_i][_j]++;
    for(int _i = dep,_j = i;_i<=n&&_j<=n;++_i,++_j)vis[_i][_j]++;
    //恢复现场
    dfs(dep+1);
    for(int _i= 1;_i<=n;++_i)vis[_i][i]--;
    for(int _i = dep,_j = i;_i>=1&&_j>=1;--_i,--_j)vis[_i][_j]--;
    for(int _i = dep,_j = i;_i<=n&&_j>=1;++_i,--_j)vis[_i][_j]--;
    for(int _i = dep,_j = i;_i>=1&&_j<=n;--_i,++_j)vis[_i][_j]--;
    for(int _i = dep,_j = i;_i<=n&&_j<=n;++_i,++_j)vis[_i][_j]--;
  }
}
int main()
{
  // 请在此输入您的代码
  cin>>n;
  dfs(1);
  cout<<ans<<"\n";
  return 0;
}

//个人觉得好理解的
#include<iostream>
using namespace std;

const int N = 20;
int n;
bool col[N],dg[N],udg[N];
int count = 0;
void dfs(int u)
{
  if(u==n)
  {
    count++;
    return;
  }
  for(int i = 0;i<n;i++)
  {
    if(!col[i]&&!dg[u+i]&&!udg[n-u+i])
    {
      col[i] = dg[u+i] = udg[n-u+i] = true;
      dfs(u+1);
      col[i] = dg[u+i] = udg[n-u+i] = false;
      
    }
  }
}
int main()
{
  cin>>n;
  dfs(0);
  cout<<count<<endl;
  return 0;
}