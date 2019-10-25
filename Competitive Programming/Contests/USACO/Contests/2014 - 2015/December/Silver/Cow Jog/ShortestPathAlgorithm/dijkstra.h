#include <vector>
#include <set>
#include <stdio.h>
using namespace std;

#define MAX_N 10000


struct edge {
	int to, len;
	edge(int a, int b) { to = a; len = b; }
};

struct state {
	int v, dist;
	state(int a, int b) { v = a; dist = b; }
};


bool operator<(const state& a, const state& b) {
	return a.dist == b.dist ? a.v < b.v : a.dist < b.dist;
}


vector<vector<edge> > g;
int dist[MAX_N];

void dijkstra(int start) {
	memset(dist, -1, sizeof(dist));
	dist[start] = 0;
	set<state> s;
	s.insert(state(start, 0));
	while (!s.empty()) {
		state cur = *s.begin();
		s.erase(s.begin());
		for (int i = 0; i < g[cur.v].size(); ++i) {
			edge next = g[cur.v][i];
			if (dist[cur.v] + next.len < dist[next.to] || dist[next.to] == -1) {
				s.erase(state(next.to, dist[next.to]));
				dist[next.to] = dist[cur.v] + next.len;
				s.insert(state(next.to, dist[next.to]));
			}
		}
	}
}

//int _tmain(int argc, _TCHAR* argv[])
//{
//	int N, M;
//	scanf("%d %d", &N, &M);
//	g.resize(N + 1);
//	for (int i = 0; i < M; ++i) {
//		int p, q, r;
//		scanf("%d %d %d", &p, &q, &r);
//		g[p].push_back(edge(q, r));
//		g[q].push_back(edge(p, r));
//	}
//	dijkstra(1);
//	for (int j = 1; j < N + 1; j++) {
//		printf("%d  ", dist[j]);
//	}
//
//	return 0;
//}