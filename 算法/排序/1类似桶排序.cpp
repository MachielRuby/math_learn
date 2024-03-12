#include<iostream>
using namespace std;


int main()
{
    int q[10];
    int n = 10;
    int i = 0;
    int count[43] = {0};
    while(n--)
    {
        cin>>q[i];
        count[(q[i]%42)]++;
        i++;
    }
    int count_all = 0;
    for(int i = 0;i<43;i++)
    {
        if(count[i]>0)count_all++;
    }
    cout<<count_all<<endl;
    
    return 0;
}