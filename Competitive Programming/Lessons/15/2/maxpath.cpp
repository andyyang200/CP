//Andrew Yang
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>	
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <climits>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;

/*
You have N nodes connected by M directed pathways. You are at node 1 and must end at node 1. What is the maximum number
of nodes you can reach, if you are allowed to traverse an edge in the opposite direction at most once?
N, M <= 100000
*/

























#define MAXN 100010

using namespace std;

/* Given a graph (represented by the adjacency list E) and a labelling of nodes
* into components, returns a new graph (as an adjacency list) where there is an
* edge between components if there was an edge that crossed the components in
* the original graph.  Useful after computing SCCs to obtain the SCC DAG.
* ~O(V + E) */
vector<vector<int> > collapse(const vector<vector<int> >& E,
	const vector<int>& L) {
	int N = E.size();
	vector<vector<int> > R(*max_element(L.begin(), L.end()) + 1, vector<int>());
	for (int i = 0; i < N; i++) {
		int x = L[i];
		for (int j = 0; j < E[i].size(); j++) {
			int y = L[E[i][j]];
			if (x != y) R[x].push_back(y);
		}
	}
	for (int i = 0; i < R.size(); i++) {
		sort(R[i].begin(), R[i].end());
		R[i].resize(unique(R[i].begin(), R[i].end()) - R[i].begin());
	}
	return R;
}

int scc_nidx;
int scc_idx[MAXN];
int scc_lnk[MAXN];

int scc_lbl;
int scc_sp;
int scc_stk[MAXN];

/* Helper function used by scc implementing Tarjan's SCC algorithm */
void scc_dfs(int u, const vector<vector<int> >& E, vector<int>& L) {
	int idx = scc_idx[u] = scc_nidx++;
	int& lnk = scc_lnk[u];
	lnk = idx;

	scc_stk[scc_sp++] = u;
	for (int i = 0; i < E[u].size(); i++) {
		int v = E[u][i];
		if (scc_idx[v] == -1) {
			scc_dfs(v, E, L);
			lnk = min(lnk, scc_lnk[v]);
		}
		else {
			lnk = min(lnk, scc_idx[v]);
		}
	}

	if (idx == lnk) {
		for (int y = -1; y != u; ) {
			y = scc_stk[--scc_sp];
			scc_idx[y] = E.size();
			L[y] = scc_lbl;
		}
		scc_lbl++;
	}
}

/* Return a labelling of the M SCCs.
* The ith vertex is part of the L[i]-th SCC.  O(V + E) */
vector<int> scc(const vector<vector<int> >& E) {
	int N = E.size();
	vector<int> L(N, -1);

	memset(scc_idx, -1, sizeof(int) * N);
	scc_nidx = scc_lbl = scc_sp = 0;
	for (int i = 0; i < N; i++) {
		if (L[i] == -1) {
			scc_dfs(i, E, L);
		}
	}
	return L;
}

int memo[2][100010];

/* Computes the maximum weight path from s to t.
* Doesn't include the weight of node t. Returns -2 if s cannot reach t. */
int solve(int cid, const vector<int>& W,
	const vector<vector<int> >& E, int s, int t) {
	if (s == t) {
		return 0;
	}

	int& ref = memo[cid][s];
	if (ref != -1) {
		return ref;
	}

	ref = -2;
	for (int i = 0; i < E[s].size(); i++) {
		int res = solve(cid, W, E, E[s][i], t);
		if (res >= 0) {
			ref = max(ref, W[s] + res);
		}
	}
	return ref;
}

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<int> > E(N);
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		E[u].push_back(v);
	}

	/* Compute the SCC graph and its reverse */
	vector<int> L = scc(E);
	E = collapse(E, L);
	int st = L[0];

	vector<vector<int> > RE(E.size());
	for (int i = 0; i < E.size(); i++) {
		for (int j = 0; j < E[i].size(); j++) {
			RE[E[i][j]].push_back(i);
		}
	}

	/* Compute the weight of each node in the SCC graph. */
	vector<int> W(E.size(), 0);
	for (int i = 0; i < N; i++) {
		W[L[i]]++;
	}

	/* Try each edge in the SCC graph. */
	int result = W[st];
	memset(memo, -1, sizeof(memo));
	for (int i = 0; i < E.size(); i++) {
		/* Compute the max path weight from node i to st. */
		int r1 = solve(0, W, E, i, st);
		if (r1 < 0) {
			continue;
		}
		for (int j = 0; j < E[i].size(); j++) {
			/* Compute the max path weight from node st to E[i][j]. */
			int r2 = solve(1, W, RE, E[i][j], st);
			if (r2 >= 0) {
				result = max(result, W[st] + r1 + r2);
			}
		}
	}

	cout << result << endl;

	return 0;
}