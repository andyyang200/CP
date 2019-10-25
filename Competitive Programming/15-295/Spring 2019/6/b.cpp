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
vector<int> edges[100005];
int cnt[100005];
int par[100005][20];
int dp[100005];
int depth[100005];
void dfs(int u, int d = 0){
    depth[u] = d;
    dp[u] = cnt[u];
    for(int v : edges[u]){
        if (v == par[u][0]){
            continue;
        }
        par[v][0] = u;
        dfs(v, d + 1);
        dp[u] += dp[v];
    }
}
void computeSparse() { // calculate par[i][0] first
   // dfs(0, 0, 0);
    FOR(j, 1, 19)
        FOR(i, 1, n){
            if (par[i][j - 1] == -1){
                par[i][j] = -1;
            }
            else{
                par[i][j] = par[par[i][j - 1]][j - 1];
            }
        }
}

int getLCA(int a, int b) {
    if (depth[a] > depth[b]){
        swap(a, b);
    }
    int lift = depth[b] - depth[a];
    for(int j = 19; j >= 0; j--){
        if (lift & (1 << j)){
            b = par[b][j];
        }
    }
    if (a == b){
        return a;
    }

    for(int j = 19; j >= 0; j--){
        if (par[a][j] != par[b][j]) {
            a = par[a][j];
            b = par[b][j];
        }
    }
    return par[a][0];
}
pii pairs[100005];
int main(){
    scanf("%d", &n);
    FOR(i, 0, n - 1){
        int u, v;
        scanf("%d%d", &u, &v);
        u--;
        v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
        pairs[i].first = u;
        pairs[i].second = v;
    }
    par[0][0] = -1;
    dfs(0);
    computeSparse();

    int m;
    scanf("%d", &m);
    FOR(i, 0, m){
        int u, v;
        scanf("%d%d", &u, &v);
        u--;
        v--;
        int a = getLCA(u, v);
        cnt[u]++;
        cnt[v]++;
        cnt[a] -= 2;
    }
    dfs(0);
    FOR(i, 0, n - 1){
        int u = pairs[i].first;
        int v = pairs[i].second;
        if (par[u][0] == v){
            swap(u, v);
        }
        cout << dp[v] << " ";
    }
    cout << endl;

}


