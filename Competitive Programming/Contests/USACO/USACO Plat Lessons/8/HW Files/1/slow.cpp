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

bool visited[200005];
set<int> edges[200005];
int n, m;
void dfs(int u) {
    if (visited[u]) return;
    visited[u] = true;
    for(int v : edges[u]) dfs(v);
}
int count() {
    int ans = 0;
    fill(visited, visited + n + 1, false);
    FOR(i, 1, n + 1) {
        if (!visited[i]) {
            ans++;
            dfs(i);
        }
    }
    return ans;
}

int main() {
    cin >> n >> m;
    vector<pii> edgelist;
    FOR(i, 0, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        edges[u].insert(v);
        edges[v].insert(u);
        edgelist.push_back({u, v});
    }
    int ans = 0;
    for(pii e : edgelist) {
        int u = e.first;
        int v = e.second;
        int cnt1 = count();
        edges[u].erase(v);
        edges[v].erase(u);
        int cnt2 = count();
        edges[u].insert(v);
        edges[v].insert(u);
        if (cnt2 > cnt1) {
            ans++;
        }
    }
    cout << ans << endl;
}
