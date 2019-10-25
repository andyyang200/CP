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
#include <map>
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
#define FOR(index, start, end) for(int index = start; index < end; index++)
#define RFOR(index, start, end) for(int index = start; index > end; index--)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;


typedef pair<int, int> ii;      // In this chapter, we will frequently use these
typedef vector<ii> vii;      // three data type shortcuts. They may look cryptic
typedef vector<int> vi;   // but shortcuts are useful in competitive programming

#define DFS_WHITE -1 // normal DFS, do not change this with other values (other than 0), because we usually use memset with conjunction with DFS_WHITE
#define DFS_BLACK 1

//initialize all this
vector<vii> AdjList;

vi dfs_num;     // this variable has to be global, we cannot put it in recursion
vi dfs_parent;      // to differentiate real back edge versus bidirectional edge
vi dfs_low;       // additional information for articulation points/bridges/SCCs
vi articulation_vertex;
int dfsNumberCounter, dfsRoot, rootChildren;

void articulationPointAndBridge(int u) {
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;      // dfs_low[u] <= dfs_num[u]
	for (int j = 0; j < (int)AdjList[u].size(); j++) {
		ii v = AdjList[u][j];
		if (dfs_num[v.first] == DFS_WHITE) {                          // a tree edge
			dfs_parent[v.first] = u;
			if (u == dfsRoot) rootChildren++;  // special case, count children of root

			articulationPointAndBridge(v.first);

			if (dfs_low[v.first] >= dfs_num[u])              // for articulation point
				articulation_vertex[u] = true;           // store this information first
			if (dfs_low[v.first] > dfs_num[u])                           // for bridge
				printf(" Edge (%d, %d) is a bridge\n", u, v.first);
			dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);       // update dfs_low[u]
		}
		else if (v.first != dfs_parent[u])       // a back edge and not direct cycle
			dfs_low[u] = min(dfs_low[u], dfs_num[v.first]);       // update dfs_low[u]
	}
}
