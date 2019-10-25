#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b)  qfor(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------

ll dp[105][105];
int last[1000];
ll cnt[500];

int main(){
    int n;
    ll k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = "$" + s;
    FOR(i, 0, 500){
        last[i] = -1;
    }
    dp[0][0] = 1;
    FOR(i, 1, n + 1){
        dp[i][0] = 1;
        FOR(j, 1, n + 1){
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            if (last[s[i]] != -1){
                dp[i][j] -= dp[last[s[i]] - 1][j - 1];
            }
            /*if (dp[i][j] >= k){
                cout << 0 << endl;
                return 0;
            }*/
        }

        last[s[i]] = i;
    }
    FOR(i, 1, n + 1){
        cnt[i] = dp[n][i];
        // cout << i << ": " << cnt[i] << endl;
    }
    cnt[0] = 1;

    ll ans = 0;
    RFOR(i, n, -1){
        ll take = min(k, cnt[i]);
        k -= take;
        ans += take * (n - i);
        if (k == 0) break;
    }
    if (k > 0){
        cout << -1 << endl;
    }
    else{
        cout << ans << endl;
    }

}
/*
abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz
*/
