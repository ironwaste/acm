#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
int main (void){
    while(cin>>k){
        int n=1,m=1,p=m+n;
        while(p<=k){m=n,n=p,p=m+n;}
        printf("m=%d\nn=%d",m,n);
    }
    return 0;
}

