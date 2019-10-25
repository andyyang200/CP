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
int dp[1005][10005];
int v[10005];
int w[10005];
int main(){
    int n, W;
    cin >> n >> W;
    FOR(i, 0, n){
        scanf("%d", &v[i]);
    }
    FOR(i, 0, n){
        scanf("%d", &w[i]);
    }
    dp[0][w[0]] = v[0];
    FOR(i, 1, n){
        FOR(x, 0, W + 1){
            dp[i][x] = dp[i-1][x];
            if (x - w[i] >= 0){
                dp[i][x] = max(dp[i][x], dp[i - 1][x - w[i]] + v[i]);
            }
        }
    }
    int ans = 0;
    FOR(i, 0, W + 1){
        ans = max(ans, dp[n - 1][i]);
    }
    cout << ans << endl;


}


