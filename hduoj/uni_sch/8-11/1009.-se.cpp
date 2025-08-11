#include<bits/stdc++.h>
#include<climits>


#define all(x) x.begin(),x.end()
#define pb(x) push_back(x)
#define i64 long long
#define fi first
#define se second

#define endl '\n'
#define mod3 998244353
#define mod7 1000000007
#define all(x) x.begin(),x.end()
#define de(x) std::cerr << #x <<" "<<x <<" ";
#define deb(x) std::cerr << #x <<" "<<x <<endl;
// using namespace std;
using i128 = __int128_t;

// 补题——题目链接:https://acm.hdu.edu.cn/contest/problem?cid=1179&pid=1009
// 网址：https://acm.hdu.edu.cn/contest/view-code?cid=1179&rid=4542&from=rank
// 2025.08.11——18:35:28
/*
 *
 *
 *
*/

namespace fastio{
    struct reader{
    	template<typename T>reader&operator>>(T&x){
    		char c=getchar();short f=1;
    		while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}
    		x=0;while(c>='0'&&c<='9'){
    			x=(x<<1)+(x<<3)+(c^48);
    			c=getchar();
    		}x*=f;return *this;
    	}
    }cin;
    
    struct writer {
        template<typename T>writer&operator<<(T x){
    		if(x==0)return putchar('0'),*this;
    		if(x<0)putchar('-'),x=-x;
    		static int sta[45];int top=0;
    		while(x)sta[++top]=x%10,x/=10;
    		while(top)putchar(sta[top]+'0'),--top;
    		return*this;
    	}
    }cout;
};
// #define cin fastio::cin
// #define cout fastio::cout

void solve(){
    i128 n, w;
    i64 x;
    std::cin >> x;
    deb(x);
    n = x;
    std::cin >> x;
    w = x;
    std::cout << "n   : ";fastio::cout << n;
    std::cout << endl;
    
    std::cout << "w   : ";fastio::cout << w;
    std::cout<< endl;
    // i128 ans = (i128) (1 + n) * n/2;
    i128 ans = 0;
    for (i128 i = n, n2, d, cnt,p = 0;i >= w;i = n2) {
        d = i / w;
        n2 = i - d;
        std::cout << "d    : ";fastio::cout << d;
        std::cout << endl;
        std::cout << "n2   : ";fastio::cout << n2;
        std::cout<< endl;
        cnt = 1;
        if (n2 > d * w - 1) {
            n2 = (i - n2 + w - 1) / d; 
            cnt = (i - n2) / d;
        }
        // cnt--;
        i128 diff = 0;
        diff += (p + p * p)/ 2;
        std::cout << "diff : ";fastio::cout << diff;
        std::cout << endl;

        diff += (cnt * (cnt + 1) * (2 * p + 1))/ 2;
        std::cout << "diff : ";fastio::cout << diff;
        std::cout << endl;
        diff += (cnt * (cnt + 1) * (2 * cnt + 1)) / 6;
        std::cout << "diff : ";fastio::cout << diff;
        std::cout << endl;
        
        p = p + d * cnt;
        
        std::cout << "p    : ";fastio::cout << p;
        std::cout << endl;
    }
    fastio::cout << ans;
    // cout << endl;


}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    i128 T = 1;
    fastio::cin >> T;
    std::cout << "T :  ";fastio::cout << T;
    std::cout << endl;
    while (T--) {
        solve();
    }
    return 0;
}