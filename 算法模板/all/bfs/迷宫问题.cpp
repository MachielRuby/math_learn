5 5 
1 0 1 1 0
1 1 0 1 1 
0 1 0 1 1
1 1 1 1 1
1 0 0 0 1
1 1 5 5 
8


#include <iostream>
using namespace std;
#include<cstring>
#include<queue>
int n,m;
const int N = 200;
int g[N][N];
int d[N][N];
typedef pair<int,int> pll;
queue<pll> que;
int bfs(int x1,int y1,int x2,int y2)
{
  memset(d,-1,sizeof d);
  d[x1][y1] = 0;
  int dx[4] = {-1,0,1,0};
  int dy[4] = {0,1,0,-1};
  que.push({x1,y1});
  while(!que.empty())
  {
    auto t = que.front();
    que.pop();
    for(int i = 0;i<4;i++)
    {
      int x = t.first+dx[i],y = t.second+dy[i];
      if(x>=1&&x<=n&&y>=1&&y<=m&&g[x][y]==1&&d[x][y]==-1)
      {
        d[x][y] = d[t.first][t.second]+1;
        que.push({x,y});
        if(x==x2&&y==y2)return d[x2][y2];
      }
    }
  }
  return -1;
}
int main()
{
  // 请在此输入您的代码
  cin>>n>>m;
  for(int i = 1;i<=n;i++)
  {
    for(int j = 1;j<=m;j++)
    {
      cin>>g[i][j];
    }
  }
  int x1,y1,x2,y2;
  cin>>x1>>y1>>x2>>y2;
  cout<<bfs(x1,y1,x2,y2)<<endl;
  return 0;
}