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
#define MAXN 100010
int dfs_low[MAXN];       
int dfs_num[MAXN]; // initialized to -1
int articulation_vertex[MAXN];
int parent[MAXN];
vector<int> edges[MAXN];
int dfsNumberCounter, dfsRoot, rootChildren;

void articulationPointAndBridge(int u) {
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;      
	for (int j = 0; j < (int)edges[u].size(); j++) {
		int v = edges[u][j];
		if (dfs_num[v] == -1) {                        
			parent[v] = u;
			if (u == dfsRoot) rootChildren++; 

			articulationPointAndBridge(v);

			if (dfs_low[v] >= dfs_num[u])             
				articulation_vertex[u] = true;          
			if (dfs_low[v] > dfs_num[u])                         
				printf(" Edge (%d, %d) is a bridge\n", u, v);
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);      
		}
		else if (v != parent[u])       
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);      
	}
}

int main(void)
{
	//freopen("rename_this.in", "r", stdin);
	//freopen("rename_this.out", "w", stdout);
}


