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
// begin dinics
const int MAXN = 15000;
int nodes = MAXN, src, sink;
int dist[MAXN], Q[MAXN], work[MAXN];
struct Edge {
	int to, rev;
	int f, cap;
};
vector<Edge> G[MAXN];
// Adds directional edge. May create uneccesary edges, so modify if needed
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
// end dinics



int x[2501];
int y[2501];
map<ll, int> index;
int main(){
    int n;
    cin >> n;
    set<ll> s;
    FOR(i, 0, n){
        scanf("%d%d", &x[i], &y[i]);
        s.insert(x[i] + y[i]);
        s.insert(x[i] - y[i]);
        s.insert((ll)x[i] * y[i]);
    }

    vector<ll> v;
    for(ll x : s){
        v.push_back(x);
        index[x] = v.size() - 1;
    }
    src = 10000;
    sink = src + 1;
    FOR(i, 0, n){
        ll a = x[i] + y[i];
        addEdge(i, n + index[a], 1);
        a = x[i] - y[i];
        addEdge(i, n + index[a], 1);
        a = (ll)x[i] * y[i];
        addEdge(i, n + index[a], 1);
        addEdge(src, i, 1);
    }
    FOR(i, 0, v.size()){
        addEdge(i + n, sink, 1);
    }
    int f = maxFlow();
    if (f != n){
        cout << "impossible" << endl;
        return 0;
    }
    FOR(i, 0, n){
        for(Edge e : G[i]){
            if (e.to != src && e.f > 0){
                ll a = v[e.to - n];
                if (a == x[i] + y[i]){
                    printf("%d + %d = %lld\n", x[i], y[i], a);
                }
                else if (a == x[i] - y[i]){
                    printf("%d - %d = %lld\n", x[i], y[i], a);
                }
                else{
                    printf("%d * %d = %lld\n", x[i], y[i], a);
                }
                break;
            }
        }
    }

}

/*
4
1 5
3 3
4 5
-1 -6
*/

/*
4
-4 2
-4 2
-4 2
-4 2
*/

/*
3
1000000 1000000
1000000 1000000
1000000 1000000
*/

