#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", z = " << z << endl
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
int dp[5005][5005];
int a[100005];
int main(void)
{
    int n, h;
    scanf("%d%d", &n, &h);
    FOR(i, 0, n){
        scanf("%d", &a[i]);
    }
    dp[0][h] = 1;
    FOR(i, 0, n){
        FOR(j, 1, n){
            if (j != a[i] && i + j < n){
                dp[i + j][j] += dp[i][j];
                dp[i + j][j] %= M;
            }
            if (i + a[i] < n){
                dp[i + a[i]][a[i]] += dp[i][j];
                dp[i + a[i]][a[i]] %= M;
            }
        }
    }
    ll ans = 0;
    FOR(j, 1, n){
        ans += dp[n - 1][j];
        ans %= M;
    }
    cout << ans << endl;
}


