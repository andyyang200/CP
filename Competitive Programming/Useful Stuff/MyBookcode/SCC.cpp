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
typedef long double ld;
typedef pair<int, int> pii;
//initialize all this
vector<int> edges[200005];
int dfs_num[200005];     // initialize to -1
int dfs_low[200005];
int dfsNumberCounter = 0;
vector<int> S;
int inStack[200005];
int SCCCount = 0;

int SCCNum[200005]; // SCCNum[i] is the SCC number that node i is in
vector<int> SCC[200005]; // list of nodes of each SCC

void tarjanSCC(int u) { // call on every node with dfs_num = -1
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	S.push_back(u);
	inStack[u] = 1;
	for(int v : edges[u]){
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

int main(){

}
