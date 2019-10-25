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
bool isprime(int x){
    FOR(i, 2, sqrt(x) + 1){
        if (x % i == 0){
            return false;
        }
    }
    return true;
}
vector<int> even;
vector<int> odd;
bool visited[100005];
vector<vector<int>> ans;
int n;
int dfs(int x, bool even){
    visited[x] = true;
    ans.back().push_back(x);
    if (even){
        for (Edge e : G[x]){
            if (!visited[e.to] && e.to < 2 * n && e.f == 1){
                dfs(e.to, !even);
            }
        }
    }
    else{
        FOR(i, 0, n){
            if (visited[i]) continue;
            for (Edge e : G[i]){
                if (e.to == x && e.f == 1){
                    dfs(i, !even);
                }
            }
        }
    }
}
map<int, int> index;
int main(){
    ri(n);
    FOR(i, 0, n){
        int x;
        ri(x);
        if (x % 2 == 0){
            index[even.size()] = i;
            even.push_back(x);
        }
        else{
            index[odd.size() + n / 2] = i;
            odd.push_back(x);
        }
    }
    if (even.size() != odd.size()){
        cout << "Impossible" << endl;
        return 0;
    }
    n = even.size();
    src = 2 * n + 1;
    sink = src + 1;
    FOR(i, 0, n){
        FOR(j, 0, n){
            if (isprime(even[i] + odd[j])){
                addEdge(i, j + n, 1);
            }
        }
    }
    FOR(i, 0, n){
        addEdge(src, i, 2);
        addEdge(i + n, sink, 2);
    }
    int mf = maxFlow();
    db(mf);
    if (mf != 2 * n){
        cout << "Impossible" << endl;
        return 0;
    }
    FOR(i, 0, n){
        if (!visited[i]){
            ans.push_back(vector<int>());
            dfs(i, true);
        }
    }
    printf("%d\n", ans.size());
    FOR(i, 0, ans.size()){
        printf("%d ", ans[i].size());
        for(int x: ans[i]){
            printf("%d ", index[x] + 1);
        }
        printf("\n");
    }
}
