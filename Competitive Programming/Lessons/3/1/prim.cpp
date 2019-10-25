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
#define FOR(index, start, end) for(int index = start; index < end; index++)
#define RFOR(index, start, end) for(int index = start; index > end; index--)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;


vector<pii> edges[100000]; // distance to source, end node number; initialize
bool visited[100000];
int d[100000];
int n, m; // initialize
int prim()
{
	FOR(i, 0, n)
	{
		d[i] = INF;
	}
	priority_queue<pii, vector<pii>, greater<pii> > nodes; // distance to source, node number
	d[0] = 0;
	nodes.push(pii(0, 0));
	int ans = 0;
	int treeSize = 1;
	while (!nodes.empty())
	{
		int dis = nodes.top().first;
		int node = nodes.top().second;
		nodes.pop();
		if (dis != d[node])
		{
			continue;
		}
		visited[node] = true;
		treeSize++;
		ans += dis;
		for (pii edge : edges[node])
		{
			if (!visited[edge.second] && edge.first < d[edge.second])
			{
				d[edge.second] = edge.first;
				nodes.push(pii(d[edge.second], edge.second));
			}
		}
	}
	if (treeSize < n)
	{
		return -1;
	}
	return ans;
}


int main(void)
{
	//freopen("rename_this.in", "r", stdin);
	//freopen("rename_this.out", "w", stdout);
	scanf("%d%d", &n, &m);
	FOR(i, 0, m)
	{
		int u, v, x;
		scanf("%d%d%d", &u, &v, &x);
		u--;
		v--;
		edges[u].push_back({ x, v });
		edges[v].push_back({ x, u });
	}
	cout << prim() << endl;




}