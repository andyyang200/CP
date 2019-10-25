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

int n;
vector<int> edges[50005];
int p[50005];
int dp[50005][505];
int k;
void dfs(int u){
    dp[u][0] = 1;
    for(int v : edges[u]){
        if (v == p[u]) continue;
        p[v] = u;
        dfs(v);
        FOR(i, 1, k + 1){
            dp[u][i] += dp[v][i - 1];
        }
    }
}


int main(){
    scanf("%d%d", &n, &k);
    FOR(i, 0, n - 1){
        int u, v;
        scanf("%d%d", &u, &v);
        u--;
        v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(0);
    ll ans = 0;
    FOR(u, 0, n){
        ans += dp[u][k];
        ll x = 0;
        for(int v : edges[u]){
            if (v == p[u]) continue;
            FOR(d, 0, k - 1){
                x += (ll)dp[v][d] * (dp[u][k - d - 1] - dp[v][k - d - 2]);
            }
        }
        ans += x / 2;
    }
    cout << ans << endl;
}


