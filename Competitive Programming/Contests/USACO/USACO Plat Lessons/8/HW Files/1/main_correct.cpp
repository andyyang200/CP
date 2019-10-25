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

vector<int> edges[200005];
int num[200005];
int low[200005];
int p[200005];
int cnt;
int ans;

void dfs(int u) {
	low[u] = num[u] = cnt++;
	for(int v : edges[u]) {
		if (num[v] == 0) {
                p[v] = u;
			dfs(v);
			if (low[v] > num[u])
				ans++;
			low[u] = min(low[u], low[v]);
		}
		else if (v != p[u])
			low[u] = min(low[u], num[v]);
	}
}

int main() {
    int n, m;
    cin >> n >> m;
    FOR(i, 0, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    cnt = 1;
    ans = 0;
    FOR(i, 1, n + 1) {
        if (num[i] == 0) {
            dfs(i);
        }
    }
    cout << ans << endl;
}
