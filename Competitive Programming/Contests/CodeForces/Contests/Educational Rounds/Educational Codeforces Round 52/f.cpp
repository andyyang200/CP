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
#define MAXN 1000005
vector<int> edges[MAXN];
int dfs_num[MAXN];     // initialize to -1
int dfs_low[MAXN];
int dfsNumberCounter = 0;
vector<int> S;
int inStack[MAXN];
int SCCCount = 0;

int SCCNum[MAXN]; // SCCNum[i] is the SCC number that node i is in
vector<int> SCC[MAXN]; // list of nodes of each SCC

void tarjanSCC(int u) { // call on every node with dfs_num = -1
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	S.push_back(u);
	inStack[u] = 1;
	for (int v : edges[u]) {
		if (dfs_num[v] == -1)
			tarjanSCC(v);
		if (inStack[v])
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}

	if (dfs_low[u] == dfs_num[u]) { // new scc
		while (1) {
			int v = S.back();
			S.pop_back();
			inStack[v] = 0;

			//v is a new node in the scc
			// DO IMPORTANT STUFF HERE
			SCCNum[v] = SCCCount;
			SCC[SCCCount].push_back(v);


			if (u == v) break;
		}
		SCCCount++;
	}
}
vector<int> children[MAXN];
int parent[MAXN];
vector<int> path;
int n, k;
void dfs(int u) {
	for (int v : children[u]) {
		path.push_back(v);
		dfs(v);
		path.pop_back();
	}
	if (children[u].size() == 0 && path.size() > 1) {
		int t = (path.size() >= k + 1 ? path[path.size() - k - 1] : path[0]);
		edges[u].push_back(t);
	}
}
int value[MAXN];
set<int> SCCEdges[MAXN];
bool visited[MAXN];
vector<int> tsort;
int dp[MAXN];
void toposort(int u) {
	if (visited[u]) {
		return;
	}
	visited[u] = true;
	for (int v : SCCEdges[u]) {
		toposort(v);
	}
	tsort.push_back(u);
}
int main() {
	scanf("%d%d", &n, &k);
	parent[0] = -1;
	FOR(i, 1, n) {
		scanf("%d", &parent[i]);
		parent[i]--;
		children[parent[i]].push_back(i);
		edges[parent[i]].push_back(i);
	}
	path.push_back(0);
	dfs(0);
	FOR(i, 0, n) {
		dfs_num[i] = -1;
	}
	FOR(i, 0, n) {
		if (dfs_num[i] == -1)
			tarjanSCC(i);
	}
	FOR(i, 0, n) {
		if (children[i].size() == 0) {
			value[SCCNum[i]]++;
		}
	}
	FOR(u, 0, n) {
		for (int v : edges[u]) {
			if (SCCNum[u] != SCCNum[v]) {
				SCCEdges[SCCNum[u]].insert(SCCNum[v]);
			}
		}
	}
	FOR(i, 0, SCCCount) {
		toposort(i);
	}
	FOR(i, 0, SCCCount) {
		int u = tsort[i];
		for (int v : SCCEdges[u]) {
			dp[u] = max(dp[u], dp[v]);
		}
		dp[u] += value[u];
		if (u == SCCNum[0]) {
			cout << dp[u] << endl;
			return 0;
		}
	}
}
