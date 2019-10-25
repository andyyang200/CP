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

using namespace std;
ll dp[200005][2];
vector<pair<int, int>> edges[200005];
bool a[200005];
bool b[200005];
int p[200005];
void dfs(int node){
	for(pair<int, int> x : edges[node]){
		int v = x.first;
		int w = x.second;
		if (v == p[node]) continue;
		p[v] = node;
		dfs(v);
		dp[node][0] += min(dp[v][0], dp[v][1] + w);
		dp[node][1] += min(dp[v][1], dp[v][0] + w);
	}
	if (a[node]) dp[node][0] = 1000000000LL * 1000000LL;
	if (b[node]) dp[node][1] = 1000000000LL * 1000000LL;
}
int main(){
	int n;
	cin >> n;
	FOR(i, 0, n - 1) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		u--;
		v--;
		edges[u].push_back({v, w});
		edges[v].push_back({u, w});
	}
	int q;
	cin >> q;
	FOR(i, 0, q){
		int x;
		scanf("%d", &x);
		x--;
		a[x] = true;
	}
	cin >> q;
	FOR(i, 0, q) {
		int x;
		scanf("%d", &x);
		x--;
		b[x] = true;
	}
	p[0] = -1;
	dfs(0);

	cout << min(dp[0][0], dp[0][1]) << endl;
}
