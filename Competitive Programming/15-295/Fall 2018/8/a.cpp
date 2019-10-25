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

vector<int> edges[100005];
int sz[100005];
int dfs(int u, int p){
    sz[u] = 1;
    for(int v : edges[u]){
        if (v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}
int main(){
    int n;
    cin >> n;
    FOR(i, 0, n - 1){
        int u, v;
        scanf("%d%d", &u, &v);
        u--;
        v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    if (n % 2 == 1){
        cout << -1 << endl;
        return 0;
    }

    dfs(0, -1);
    int ans = 0;
    FOR(i, 0, n){
        if (sz[i] % 2 == 0) ans++;
    }
    ans--;
    cout << ans << endl;
}


