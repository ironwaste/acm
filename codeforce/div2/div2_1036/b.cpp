// 看什么看,以为我厉害吗？
// 我只是戾气很重,不厉害只需要114514分钟就能变厉害了
// 而你我的朋友只需要2.5年就可以了
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
#define de(x) cerr << #x <<" "<<x <<" ";
#define deb(x) cerr << #x <<" "<<x <<endl;
using namespace std;

using pii = pair<int,int>;
using pll = pair<i64, i64>;


void solve() {
    i64 n;
    cin >> n;
    vector<i64>a(n);
    for (auto& x : a) { cin >> x; }
    i64 ans = 0, id = INT_MAX;
    auto amin = a;
    for (i64 i = 1;i < n;i ++) {
        if(amin[i - 1] <= a[i]) {
            amin[i] = amin[i - 1];
            if (id == INT_MAX) {
                id = i;
            }
        }
    }
    vector<i64>premin(n + 1, 0);
    partial_sum(all(amin), premin.begin() + 1);
    ans = premin.back();
    // de(id)deb(ans);
    i64 origin = ans;
    for (int j = 1;j < n;j++) {
        if (j > id) {
            ans = min(ans,origin - premin[n] + premin[j]);
        } else {
            ans = min(ans,origin- premin[n] + premin[j] + a[j]);
        }
    }
    cout << ans << endl;

}
//别人的答案，为什么，自己忽略了什么性质，或者说自己对于什么样的性质没有那么敏感。
// #include <bits/stdc++.h>

// int main() {
// 	using namespace std;
// 	ios_base::sync_with_stdio(false), cin.tie(nullptr);

// 	int T; cin >> T;
// 	while (T--) {
// 		int N; cin >> N;
// 		std::vector<int> A(N);
// 		for (auto& a : A) cin >> a;
// 		cout << A[0] + std::min(A[0], A[1]) << '\n';
// 	}

// 	return 0;
// }


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    // 2025.07.06——23:03:43
    // 2025.07.06——23:33:36 wa 2
    // 2025.07.06——23:37:32
    while (T--) {
        solve();
    }
    return 0;
}