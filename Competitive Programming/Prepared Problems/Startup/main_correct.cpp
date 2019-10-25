#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 1005;
int nodes, src, sink;
int dist[MAXN], Q[MAXN], work[MAXN];
struct Edge {
	int to, rev;
	int f, cap;
};
vector<Edge> G[MAXN];
void addEdge(int s, int t, int cap) {
	Edge a = {t, (int)G[t].size(), 0, cap};
	Edge b = {s, (int)G[s].size(), 0, 0};
	G[s].push_back(a);
	G[t].push_back(b);
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
bool can[1005];
bool used[1005];
vector<int> neighbors[1005];
pair<int, int> edges[10005];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		edges[i] = {u, v};
		neighbors[v].push_back(u);
		neighbors[u].push_back(v);
	}
	src = 0;
	sink = n + 1;
	nodes = sink + 1;
	for (int i = 1; i <= n; ++i) {
		int rem = n - neighbors[i].size() - 1;
		if (neighbors[i].size() < rem) continue;
		memset(can, 0, sizeof(can));
		for (int u : neighbors[i]) can[u] = true;
		for (int j = 0; j <= sink; ++j) G[j].clear();
		for (int j = 0; j < m; ++j) {
			int u = edges[j].first, v = edges[j].second;
			if (u == i || v == i) continue;
			if (can[u] && !can[v]) addEdge(v, u, 1);
			if (can[v] && !can[u]) addEdge(u, v, 1);
		}
		for (int j = 1; j <= n; ++j) {
			if (j == i) continue;
			if (!can[j]) addEdge(src, j, 1);
			else addEdge(j, sink, 1);
		}
		int val = maxFlow();
		if (val == rem) {
			printf("Yes\n%d %d\n", i, neighbors[i].size());
			for (int j = 1; j <= n; ++j) {
				if (j == i) continue;
				if (can[j]) continue;
				for (int k = 0; k < G[j].size(); ++k) {
					Edge &e = G[j][k];
					int v = e.to;
					if (e.f == e.cap && e.cap == 1) {
						// j is connected to v
						printf("%d %d\n", j, v);
						used[v] = true;
					}
				}
			}
			for (int j = 1; j <= n; ++j)
				if (can[j] && !used[j]) printf("%d -1\n", j);
			return 0;
		}
	}
	printf("No\n");
}
