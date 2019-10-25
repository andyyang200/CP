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
vi dfs_low;       // additional information for articulation points/bridges/SCCs
int dfsNumberCounter;
vi S, visited;                                    // additional global variables
int numSCC;

void tarjanSCC(int u) {
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;      // dfs_low[u] <= dfs_num[u]
	S.push_back(u);           // stores u in a vector based on order of visitation
	visited[u] = 1;
	for (int j = 0; j < (int)AdjList[u].size(); j++) {
		ii v = AdjList[u][j];
		if (dfs_num[v.first] == DFS_WHITE)
			tarjanSCC(v.first);
		if (visited[v.first])                                // condition for update
			dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
	}

	if (dfs_low[u] == dfs_num[u]) {         // if this is a root (start) of an SCC
		printf("SCC %d:", ++numSCC);            // this part is done after recursion
		while (1) {
			int v = S.back(); S.pop_back(); visited[v] = 0;
			printf(" %d", v);
			if (u == v) break;
		}
		printf("\n");
	}
}
