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
int p, r, c;
int d[10005];
int e[10005];
int I[100005];
int J[100005];
int T[100005];

const int MAXN = 5000;
int nodes = MAXN, src, sink;
int dist[MAXN], Q[MAXN], work[MAXN];
struct Edge {
	int to, rev;
	int f, cap;
};
vector<Edge> G[MAXN];
// Adds bidirectional edge
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

bool check(int m){
    FOR(i, 0, 3003){
        G[i].clear();
    }
    src = 3000;
    sink = 3001;
    int sum = 0;
    FOR(i, 0, r){
        addEdge(src, i, e[i]);
    }
    FOR(i, 0, p){
        addEdge(i + r, sink, d[i]);
        sum += d[i];
    }
    FOR(i, 0, c){
        if (T[i] <= m){
            addEdge(J[i], I[i] + r, 1000000);
        }
    }
    int x = maxFlow();
    return x >= sum;
}
int main(){
    ri3(p, r, c);
    FOR(i, 0, p){
        ri(d[i]);
    }
    FOR(i, 0, r){
        ri(e[i]);
    }
    FOR(i, 0, c){
        ri3(I[i], J[i], T[i]);
        I[i]--;
        J[i]--;
    }
    int low = 0;
    int hi = 1000001;
    int ans = -1;
    while(low <= hi){
        int m = (low + hi) / 2;
        if (check(m)){
            ans = m;
            hi = m - 1;
        }
        else{
            low = m + 1;
        }
    }
    cout << ans << endl;
}
