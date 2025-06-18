#include<bits/stdc++.h>

#define fi first 
#define se second
#define all(x) x.begin(),x.end()
#define de(x) cerr << #x  << " : " << x << " | ";
#define deb(x) cerr << #x  << " : " << x << "\n";

using namespace std;
using pss = pair<string, string>;

int main(){
    int n;
    cin >> n;
    vector<pss>p(n);
    string tmp ;
    for(int i = 0;i < n;i ++){cin >> p[i].fi >> tmp >> p[i].se;}
    
    sort(all(p));

    vector<pss>ans;
    if (p[0].fi != "00:00:00") {
        ans.push_back({"00:00:00",p[0].fi});
    }

    for (int i = 0;i < n - 1;i++) {
        if (p[i].se != p[i + 1].fi) {
            ans.push_back({ p[i].se,p[i + 1].fi });
        }
    }
    if (p[n - 1].se != "23:59:59") {
        ans.push_back({p[n - 1].se, "23:59:59"});
    }
    int sz = ans.size();
    for (int i = 0;i < sz; i ++) {
        cout << ans[i].fi << " - " << ans[i].se << endl;
    }

    
    return 0;
}