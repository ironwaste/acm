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
#define yes "DUI DE"
#define no "BUDUI BUDUI"
#define yesno "DUI DUI DUIMA"
#define oyes " O DUI DE"
#define ono "O BUDUI BUDUI"
// #define oyesno "DUI DUI DUIMA"



using namespace std;


void solve() {
    string s;
    cin >> s;
    s = ' ' + s;
    int n = s.size();
    vector<vector<i64> >pdpy(n + 10,vector<i64>(3,0));
    auto sdpy = pdpy;
    vector<vector<i64> >pdpn(n + 10,vector<i64>(2,0));
    auto sdpn = pdpn;
    for (int i = 1;i <= n;i++) {
        if (s[i] == 'Y') {
            pdpy[i][0] = pdpy[i-1][0] + 1;
            pdpy[i][2] = pdpy[i - 1][2];
            pdpy[i][1] = pdpy[i - 1][1];
        } else if (s[i] == 'E') {
            pdpy[i][1] = pdpy[i-1][1] + pdpy[i - 1][0];
            pdpy[i][2] = pdpy[i - 1][2];
            pdpy[i][0] = pdpy[i-1][0];
        } else if (s[i] == 'S') {
            pdpy[i][2] = pdpy[i-1][2] + pdpy[i - 1][1];
            pdpy[i][1] = pdpy[i - 1][1];
            pdpy[i][0] = pdpy[i-1][0];
        } else {
            pdpy[i][2] = pdpy[i - 1][2];
            pdpy[i][1] = pdpy[i - 1][1];
            pdpy[i][0] = pdpy[i - 1][0];
        }
        if (s[i] == 'N') {
            pdpn[i][0] = pdpn[i - 1][0] + 1;
            pdpn[i][1] = pdpn[i - 1][1];
        } else if (s[i] == 'O') {
            pdpn[i][0] = pdpn[i - 1][0];
            pdpn[i][1] = pdpn[i-1][1] + pdpn[i - 1][0];
        } else {
            pdpn[i][0] = pdpn[i - 1][0];
            pdpn[i][1] = pdpn[i - 1][1];
        }
    }

    for (int i = n;i;i--) {
        if (s[i] == 'Y') {
            sdpy[i][0] = sdpy[i + 1][0] + sdpy[i + 1][1];
            sdpy[i][2] = sdpy[i + 1][2];
            sdpy[i][1] = sdpy[i + 1][1];
        } else if (s[i] == 'E') {
            sdpy[i][1] = sdpy[i + 1][1] + sdpy[i + 1][2];
            sdpy[i][2] = sdpy[i + 1][2];
            sdpy[i][0] = sdpy[i + 1][0];
        } else if (s[i] == 'S') {
            sdpy[i][2] = sdpy[i + 1][2] + 1;
            sdpy[i][1] = sdpy[i + 1][1];
            sdpy[i][0] = sdpy[i + 1][0];
        } else {
            sdpy[i][2] = sdpy[i + 1][2];
            sdpy[i][1] = sdpy[i + 1][1];
            sdpy[i][0] = sdpy[i + 1][0];
        }

        if (s[i] == 'N') {
            sdpn[i][0] = sdpn[i + 1][1] + sdpn[i + 1][0];
            sdpn[i][1] = sdpn[i + 1][1];
        } else if (s[i] == 'O') {
            sdpn[i][1] = sdpn[i + 1][1] + 1;
            sdpn[i][0] = sdpn[i + 1][0];
        } else {
            sdpn[i][1] = sdpn[i + 1][1];
            sdpn[i][0] = sdpn[i + 1][0];
        }

    }
    // int sit = 0;
    // 0 yes 多  1 no 多 2 yesno一样多
    // 0 -> 1
    // 1 -> 0
    // 
    i64 cntyes = pdpy[n][2], cntno = pdpn[n][1];
    cout << cntyes << " " << cntno << endl;
    if (cntyes == cntno) {
        cout << yesno << endl;
        return;
    }
    if (cntyes > cntno) {
        i64 cyes = 0, cno = 0;
        int oko = 0;
        for (int i = 1;i <= n;i++) {
            if (s[i] == 'Y') {
                cyes = sdpy[i + 1][1];
                cno = max(sdpn[i + 1][1], pdpn[i - 1][0]);
            } else if (s[i] == 'E') {
                cyes = sdpy[i + 1][2] * pdpy[i - 1][0];
                cno = max(sdpn[i + 1][1], pdpn[i - 1][0]);    
            } else if (s[i] == 'S') {
                cyes = pdpy[i-1][1];
                cno = max(sdpn[i + 1][1], pdpn[i - 1][0]);    
            }
            if (cntyes - cyes < cntno + cno) { oko = 1; }
        }
        if (oko) {
            cout << ono << endl;
        } else {
            cout << yes << endl;
        }
    } else {
            i64 cyes = 0, cno = 0;
        int oko = 0;
        for (int i = 1;i <= n;i++) {
            if (s[i] == 'N') {
                cno = sdpn[i + 1][1];
                cyes = max(sdpy[i + 1][1], max(pdpy[i - 1][1], pdpy[i - 1][0] * sdpy[i + 1][2]));
            } else if (s[i] == 'O') {
                cno = pdpn[i - 1][0];
                cyes = max(sdpy[i + 1][1], max(pdpy[i - 1][1], pdpy[i - 1][0] * sdpy[i + 1][2]));
            }
            if (cntyes + cyes > cntno - cno) { oko = 1; }
        }
        if (oko) {
            cout << oyes << endl;
        }else{
            cout << no << endl;
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}