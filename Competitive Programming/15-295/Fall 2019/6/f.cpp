#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b)  qfor(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define ri(x) scanf("%d", &x)
#define ri2(x, y) scanf("%d%d", &x, &y)
#define ri3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define rll(x) scanf("%lld", &x)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------
vector<int> edges[300];
int dp[301];
int diam[301];
int label[301];
void dfs(int u, int p, int l) {
    dp[u] = 0;
    label[u] = l;
    for(int v : edges[u]){
        if (v == p) continue;
        dfs(v, u, l);
        dp[u] = max(dp[u], dp[v] + 1);
    }
    int a = 0;
    int b = 0;
    for(int v : edges[u]){
        if (v == p) continue;
        if (dp[v] + 1 > a){
            b = a;
            a = dp[v] + 1;
        }
        else if (dp[v] + 1 > b){
            b = dp[v] + 1;
        }
    }
    diam[u] = a + b;
}
int n;
int main(){
    ri(n);
    FOR(i, 0, n - 1){
        int u, v;
        ri2(u, v);
        u--;
        v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    int ans = 0;
    FOR(i, 0, n){
        for(int v : edges[i]){
            dfs(i, v, 0);
                dfs(v, i, 1);
            int maxa = 0;
            int maxb = 0;
            FOR(j, 0, n){
                if (label[j] == 0){
                    maxa = max(maxa, diam[j]);
                }
                else{
                    maxb = max(maxb, diam[j]);
                }
            }
            ans = max(ans, maxa * maxb);
        }
    }
    cout << ans << endl;
}
