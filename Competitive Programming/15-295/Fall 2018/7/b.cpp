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
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------

const int MAXN = 10005;
int nodes = MAXN, src, sink;
int dist[MAXN], Q[MAXN], work[MAXN];
struct Edge {
	int to, rev;
	int f, cap;
};
vector<Edge> G[MAXN];
// Adds bidirectional edge
void addEdge(int s, int t, int cap) {
	Edge a = { t, (int)G[t].size(), 0, cap };
	G[s].push_back(a);
}
bool dinicBfs() {
	fill(dist, dist + nodes, -1);
	dist[src] = 0;
	int qt = 0;
	Q[qt++] = src;
	for (int qh = 0; qh < qt; qh++) {
		int u = Q[qh];
		for (int j = 0; j < G[u].size(); ++j) {
			Edge &e = G[u][j];
			int v = e.to;
			if (dist[v] < 0 && e.f < e.cap) {
				dist[v] = dist[u] + 1;
				Q[qt++] = v;
			}
		}
	}
	return dist[sink] >= 0;
}
int dinicDfs(int u, int f) {
	if (u == sink) return f;
	// Edges 0..work[u] - 1 have been saturated
	for (int &i = work[u]; i < G[u].size(); ++i) {
		Edge &e = G[u][i];
		if (e.cap <= e.f) continue;
		int v = e.to;
		if (dist[v] == dist[u] + 1) {
			int df = dinicDfs(v, min(f, e.cap - e.f));
			if (df > 0) {
				e.f += df;
				G[v][e.rev].f -= df;
				return df;
			}
		}
	}
	return 0;
}
int maxFlow() {
	int result = 0;
	while (dinicBfs()) {
		fill(work, work + nodes, 0);
		while (int delta = dinicDfs(src, INT_MAX))
			result += delta;
	}
	return result;
}


int N, M;
int familiar[5005][5005];
pii edges[5005];
bool check(int maxgifts) {
	int n = N + M + 2;
	FOR(i, 0, n) {
		G[i].clear();
	}
	FOR(i, 0, M) {
		int u = edges[i].first;
		int v = edges[i].second;
		addEdge(u, N + i, 1);
		addEdge(N + i, u, 0);
		addEdge(v, N + i, 1);
		addEdge(N + i, v, 0);
		addEdge(N + i, sink, 1);
		addEdge(sink, N + i, 0);
	}
	FOR(i, 0, N) {
		addEdge(src, i, maxgifts);
		addEdge(i, src, 0);
	}
	int mf = maxFlow();
	return mf >= M;
}

int main() {
	scanf("%d%d", &N, &M);
	FOR(i, 0, M) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--;
		v--;
		edges[i] = { u, v };
		familiar[u][v] = 1;
		familiar[v][u] = 1;
	}
	src = N + M;
	sink = N + M + 1;
	int l = 0;
	int r = M;
	int ans = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	check(ans);
	cout << ans << endl;
	FOR(i, 0, N) {
		for (Edge e : G[i]) {
			if (N <= e.to  && e.to < N + M) {
				if (e.f == 1) {
					int j = (i == edges[e.to - N].first ? edges[e.to - N].second : edges[e.to - N].first);
					printf("%d %d\n", i + 1, j + 1);
				}
			}
		}
	}
}
