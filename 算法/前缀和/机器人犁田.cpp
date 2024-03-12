#include<iostream>
using namespace std;
#include<vector>

int main()
{
    int X,Y,I;
    cin>>X>>Y>>I;
    vector<vector<int>> diff(X+2,vector<int>(Y+2,0));
    while(I--)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        diff[x1][y1]+=1;
        diff[x2+1][y1] -=1;
        diff[x1][y2+1]-=1;
        diff[x2+1][y2+1] +=1;
    }
    
    //计算前缀和
    for(int i = 1;i<=X;++i)
    {
        for(int j = 1;j<=Y;++j)
        {
            diff[i][j] += diff[i-1][j] + diff[i][j-1]-diff[i-1][j-1];
        }
    }
    int count = 0;
    for(int i = 1;i<=X;i++)
    {
        for(int j = 1;j<=Y;j++)
        {
            if(diff[i][j]>0)count++;
        }
    }
    cout<<count<<endl;
    return 0;
}