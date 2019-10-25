#include <bits/stdc++.h>
using namespace std;
const int MAXN = 30000;
int nodes = MAXN, src, sink;
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
	for (int qh = 0; qh < qt; ++qh) {
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
string s;
char grid[10001];
int n, m;
int pos[500];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
inline int key(int r, int c){
    return r * m + c;
}
inline int node(int r, int c){
    return 2 * (m * r + c);
}
inline bool valid(int r, int c){
    return r >= 0 && r < n && c >= 0 && c < m && grid[key(r, c)] != '.';
}
int main(){
    cin >> s;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < s.length(); ++i){
        pos[s[i]] = i;
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            scanf(" %c", &grid[key(i, j)]);
        }
    }
    src = 2 * n * m + 1;
    sink = 2 * n * m + 2;
    nodes = n * m * 2 + 3;
    for(int r = 0; r < n; ++r){
        for(int c = 0; c < m; ++c){
            if (grid[key(r, c)] == '.') continue;
            for(int k = 0; k < 4; ++k){
                int r2 = r + dr[k];
                int c2 = c + dc[k];
                if (valid(r2, c2) && (pos[grid[key(r, c)]] == pos[grid[key(r2, c2)]] - 1 || grid[key(r, c)] == grid[key(r2, c2)])){
                    addEdge(node(r, c) + 1, node(r2, c2), 1);
                }
            }
            if (grid[key(r, c)] == s[0]){
                addEdge(src, node(r, c), 1);
            }
            if (grid[key(r, c)] == s[s.length() - 1]){
                addEdge(node(r, c) + 1, sink, 1);
            }
            addEdge(node(r, c), node(r, c) + 1, 1);
        }
    }
    cout << maxFlow() << endl;
}
