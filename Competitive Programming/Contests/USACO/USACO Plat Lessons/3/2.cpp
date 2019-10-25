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

//In a tree, support two queries: 1. change the value of an edge, and 2. Given two nodes, find the maximum value of an edge on the path between them

//heavy light decomposition

int heavy[100005]; // heavy[i]=j means heavy edge between i and j
int sz[100005];
int chainHead[1000005];
int stIndex[100005];
int cost[100005];
pii edges[100005];
parent[100005];

dfs(int u, int p){
	sz[u] = 1;
	for(pii y : edges[u]){
		int v = y.first;
		if (v == p) continue;
		parent[v] = u;
		cost[v] = y.second;
		dfs(v);
		sz[u] += sz[v];
	}
	for(pii y : edges[u]){
		int v = y.first;
		if (v == p) continue;
		if (sz[v] > sz[u] / 2){
			heavy[u] = v;
			break;
		}
	}
}
int a[100005];
int x = 0;
SegmentTree st;
buildHlD(){
	fill(heavy, heavy + n, -1);
	dfs(0, -1);
	for(int i = 0; i < n){
		if (parent[i] == -1 || heavy[parent[i]] != i){
			for(int k = i; k != -1; k = heavy[i]){
				a[c] = cost[k];
				stIndex[k] = c++;
				chainHead[k] = i;
			}
		}
	}
	st = SegmentTree(a, n);
}

int queryUp(int a, int lca){
	int ans = 0;
	while(a != lca){
		if (heavy[parent[a]] != a){
			ans = max(ans, cost[a]);
			a = parent[a];
		}
		else{
			int b = -1;
			if (chainHead[lca] = chainHead[a]){
				b = lca;
			}
			else{
				b = chainHead[a];
			}
			int pos1 = min(stIndex[a], stIndex[b]);
			int pos2 = max(stIndex[a], stIndex[b]);
			pos1++;
			ans = max(ans, st.query(pos1, pos2));
			a = b;
		}
	}
	return ans;
}

int query(int a, int b){
	int lca = getLCA(a, b);
	return max(queryUp(a, lca), queryUp(b, lca));
}

void update(int a, int v){
	int p = parent[a];
	if(heavy[p] != a){
		cost[a] = v;
	}
	else{
		st.update(stIndex[a], v);
	}
}

int main(void)
{
	
}


