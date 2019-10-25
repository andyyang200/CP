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

vector<int> edges[100005];
int sz[100005];

//get the size of each subtree
void getSizes(int u, int p) {
	sz[u] = 1;
	for (int v : edges[u]) {
		if (v == p) continue;
		getSizes(v, u);
		sz[u] += sz[v];
	}
}

//get the centroid
int getCentroid(int u, int p, int n) {
	for (int v : edges[u]) {
		if (v == p) continue;
		if (sz[v] > n / 2) {
			return getCentroid(v, u, n);
		}
	}
	return u;
}

vector<int> depths;
ll one[100005];
ll two[100005];
void case1dfs(int u, int p, int d) {
	depths.push_back(d);
	for (int v : edges[u]) {
		if (v == p) continue;
		case1dfs(v, u, d + 1);
	}
}
//calculate the number of triples with center c
ll case1(int c) {
	ll ans = 0;
	int maxd = 0;
	for (int v : edges[c]) {
		depths = vector<int>();
		case1dfs(v, c, 0);
		for (int d : depths) ans += two[d];
		for (int d : depths) two[d] += one[d];
		for (int d : depths) {
			one[d]++;
			maxd = max(d, maxd);
		}
	}
	FOR(i, 0, maxd + 1) {
		one[i] = 0;
		two[i] = 0;
	}
	return ans;
}

int cdcount[100005]; //cdcount[d] is the number of nodes of depth i from the centroid
void addcdcount(int u, int p, int d, int x) {
	cdcount[d] += x;
	for (int v : edges[u]) {
		if (v == p) continue;
		addcdcount(v, u, d + 1, x);
	}
}

/*
dcount[i][d] is the number of nodes of depth d (relative to u) in the subtree rooted at i.
we calculate dcount[i] for each node during the dfs by merging smallest to largest.
Simultaneously we use dcount to calculate, for every node,
the number of triples that touch the centroid and are centered there.
*/
deque<int> dcount[100005];

ll work(int u, int p, int d) {
	dcount[u].clear();
	ll ans = 0;
	for (int v : edges[u]) {
		if (v == p) continue;
		ans += work(v, u, d + 1);
		if (dcount[v].size() > dcount[u].size()) {
			swap(dcount[u], dcount[v]);
		}
		FOR(i, d - 1, dcount[v].size()) {
			int x = dcount[v][i];
			int y = dcount[u][i];
			int remaining = i + 1 - d;
			ans += (ll)x * y * cdcount[remaining];
		}
		FOR(i, 0, dcount[v].size()) {
			dcount[u][i] += dcount[v][i];
		}
		dcount[v] = deque<int>();
	}
	dcount[u].push_front(1);
	return ans;
}


ll decompose(int u) {
	getSizes(u, -1);
	fill(cdcount, cdcount + sz[u], 0);
	int c = getCentroid(u, -1, sz[u]);

	//count the number of triples with each node in a different branch (center is c)
	ll ans = case1(c);

	//count the number of triples with two nodes in the same branch
	addcdcount(c, -1, 0, 1);
	for (int v : edges[c]) {
		addcdcount(v, c, 1, -1);
		ans += work(v, c, 1);
		addcdcount(v, c, 1, 1);
		dcount[v] = deque<int>();
	}

	//recurse, counting the number of triples with all three nodes in the same branch
	for (int v : edges[c]) {
		FOREACH(itr, edges[v]) {
			if (*itr == c) {
				edges[v].erase(itr);
				break;
			}
		}
		ans += decompose(v);
	}
	return ans;
}

int main() {
    int n;
	scanf("%d", &n);
	FOR(i, 0, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	cout << decompose(0) << endl;
}
