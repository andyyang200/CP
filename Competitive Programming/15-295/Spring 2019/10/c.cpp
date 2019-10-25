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
int depth[100005];
vector<int> edges[100005];
void dfs(int u, int p, int d){
    depth[u] = d;
    for (int v : edges[u]){
        if (v == p){
            continue;
        }
        dfs(v, u, d + 1);
    }
}
int main(){
    cin >> n;
    FOR(i, 0, n - 1){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    dfs(0, -1, 1);
    ld ans = 0;
    FOR(i, 0, n){
        ans += (ld) 1 / depth[i];
    }
    printf("%.9Lf\n", ans);
}


