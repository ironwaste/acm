#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int a[1000001];    
int tree[1000001];   
int n,m;
int lowbit(int x)
{
    return x&(-x);
}
void update(int x,int v)
{
    while(x<=n)
    {
        if(tree[x]>v)
          tree[x]=v;
         else
          return;     
        x+=lowbit(x);  
    }
}
int getmin(int x,int y)
{
    int now=y;
    int maxl=2147483647;
    while(now>=x)
    {
        if(now-lowbit(now)>x)
        {
           maxl=min(maxl,tree[now]);
           now-=lowbit(now);
        }
        else
         {
             maxl=min(maxl,a[now]);
             --now;
         }
    }
    return maxl;
}
int main()
{
    memset(tree,127,sizeof(tree));
    cin>>n>>m;
    int x,y;
    //n++;
    for(int i=1;i<=n;++i)
     {
         cin>>a[i];
         update(i,a[i]);
     }
    for(;m>0;--m)
    {
        cin>>x>>y;
        cout<<getmin(x,y)<<' ';
    }
    return 0; 
}
