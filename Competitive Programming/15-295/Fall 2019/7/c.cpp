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
// begin dinics
const int MAXN = 5000;
int nodes = MAXN, src, sink;
int dist[MAXN], Q[MAXN], work[MAXN];
struct Edge {
	int to, rev;
	int f, cap;
};
vector<Edge> G[MAXN];
// Adds directional edge.
void addEdge(int s, int t, int cap) {
	Edge a = {t, (int)G[t].size(), 0, cap};
	Edge b = {s, (int)G[s].size(), 0, 0};
	G[s].push_back(a);
	G[t].push_back(b);
}
// Adds bidirectional edge.
void addEdge2(int s, int t, int cap) {
	Edge a = {t, (int)G[t].size(), 0, cap};
	Edge b = {s, (int)G[s].size(), 0, cap};
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
// end dinics

int n, m, l;
int dis[105][105];
int P[105];
int K[105];
int main(){
    while(cin >> n){
        ri2(m, l);
        FOR(i, 0, MAXN){
            G[i].clear();
        }
        src = 3 * n + 1;
        sink = src + 2;
        FOR(i, 0, n){
            FOR(j, 0, n){
                if (i != j) dis[i][j] = INF;
                else dis[i][j] = 0;
            }
        }
        FOR(i, 0, m){
            int a, b, d;
            ri3(a, b, d);
            a--;
            b--;
            dis[a][b] = d;
            dis[b][a] = d;
        }
        FOR(i, 0, n){
            ri(P[i]);
        }
        FOR(i, 0, n){
            ri(K[i]);
        }
        FOR(k, 0, n){
            FOR(i, 0, n){
                FOR(j, 0, n){
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        FOR(i, 0, n){
            FOR(j, 0, n){
                if (dis[i][j] < l){
                    addEdge(i, j + n, INF);
                }
            }
        }
        FOR(i, 0, n){
            addEdge(src, i, P[i]);
            addEdge(i + n, sink, K[i]);
        }
        cout << maxFlow() << endl;
    }
}
/*
1 0 1
51
50
2 1 1
1 2 1
1000 0
0 1000
4 3 5
1 2 4
1 3 1
3 4 2
0 1000 1000 1000
3000 0 0 0
*/

