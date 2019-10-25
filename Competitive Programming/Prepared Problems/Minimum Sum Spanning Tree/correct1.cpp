// team : SPb ITMO University 1
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(),a.end()
#define pw(x) (1LL<<(x))

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl

using namespace std;

typedef long long ll;
typedef double dbl;
const ll INF = 1.01e18;



int main() {
#define TASK "F"
#ifdef HOME
    assert(freopen(TASK".in", "r", stdin));
#endif
    int n;
    scanf("%d", &n);
    vector<vector<ll>> a(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x;
            scanf("%d", &x);
            a[i][j] = a[j][i] = x;
        }
    }
    /*n = 15;
    a.assign(n, vector<ll>(n));
    db(a.size());
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x = rand();
            a[i][j] = a[j][i] = x;
        }
    }*/
    vector<vector<ll>> dp(pw(n), vector<ll>(n, INF));
    vector<vector<int>> ch(pw(n));
    for (int mask = 0; mask < pw(n); mask++) {
        for (int i = 0; i < n; i++) {
            if (mask & pw(i)) {
                ch[mask].pb(i);
            }
        }
    }

    for (int mask = 1; mask < pw(n); mask++) {
        //db(mask);
        vector<int> who;
        for (int i = 0; i < n; i++) {
            if (mask & pw(i)) {
                who.pb(i);
                //dp[mask][i] = 0;
            }
        }
        if (sz(who) == 1) {
            dp[mask][who[0]] = 0;
        }
        else  {
            if (mask & 1) {
                who.clear();
                who.pb(0);
            }
            for (auto v: who) {
                ll mn = INF;
                int nmask = mask ^ pw(v);
                for (int sub = nmask; sub > 0; sub = (sub - 1) & nmask) {
                    //db2(sub, nmask);
                    //int k = __builtin_popcount(sub);
                    //for (int j = 0; j < n; j++) {
                    int k = ch[sub].size();
                    for (auto j: ch[sub]) {
                        mn = min(mn, dp[mask ^ sub][v] + dp[sub][j] + a[v][j] * k * (n - k));
                        //if (sub & pw(j)) {
                        //}
                    }
                }
                dp[mask][v] = mn;
            }
        }
    }

    ll answer = INF;
    for (int i = 0; i < n; i++) {
        answer = min(answer, dp[pw(n) - 1][i]);
        //db(dp[pw(n) - 1][i]);
    }

    cout << answer << endl;







#ifdef HOME
    cerr << "time:  " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
    return 0;
}

