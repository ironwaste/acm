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
// 2025.08.11——22:01:03 wa 了？？？？
// 2025.08.11——23:29:51 accpted 
/*
 *
 * 太多小细节了，导致有的地方乘了但是又有的地方没乘导致最后结果不对。。。
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
    
    fastio::cin >> n >> w;
    
    i128 ans = (1 + n) * n;
    i128 diff = 0;

    for (i128 i = n, n2, l, d, cnt;i >= w;i = n2) {
        d = i / w;
        n2 = i - d;

        cnt = 1;
        // i64 dd = d,ww = w;
        // i64 nn2 = n2;
        if (n2 > d * w - 1) {
            cnt = i - (w * d) + d;
            cnt /= d;
            // cnt = (i - d * w + 1) / d + ((i - d * w + 1) % d != 0);
            n2 = i - cnt * d;
        }
        
        

        ans += cnt * (i128(1) + n) * n;
        l = n - i;
        // std::cout << "l    :";fastio::cout << l;
        // std::cout << endl;
        // std::cout << "d    :";fastio::cout << d;
        // std::cout << endl;
        // std::cout << "cnt  :";fastio::cout << cnt;
        // std::cout << endl;
        // std::cout << "n2   :";fastio::cout << n2;
        // std::cout << endl;
        diff += (cnt * (cnt + 1) * (d + 2 * d * l)) / 2;
        diff += (cnt * (cnt + 1) * (2 * cnt + 1) * d * d)/ 6;
        diff += (l * l + l) * cnt;
        // std::cout << "diff :";fastio::cout << diff;
        // std::cout << endl;    
    }

    ans -= diff;
    ans /= 2;
    fastio::cout << ans;
    std::cout << endl;
}

int main(){
    i64 T = 1;
    std::cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

/*
错误样例：
647437158128 86262761032

*/