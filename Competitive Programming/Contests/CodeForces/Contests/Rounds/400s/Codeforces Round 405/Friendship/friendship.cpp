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
int n, m;
bool visited[150001];
vector<int> edges[150001];
int no, ed;
void dfs(int node)
{
	if (visited[node])
	{
		return;
	}
	visited[node] = true;
	no++;
	ed += edges[node].size();
	for (int j : edges[node])
	{
		dfs(j);
	}
}
int main(void)
{
	freopen("friendship.in", "r", stdin);
	scanf("%d%d", &n, &m);
	FOR(i, 0, m)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		u--;
		v--;
		edges[u].push_back(v);
		edges[v].push_back(u);

	}
	FOR(i, 0, n)
	{
		if (!visited[i]) {
			no = 0;
			ed = 0;
			dfs(i);
			ed /= 2;
			if ((ll)ed < ((ll)no * ((ll)no - 1) / 2))
			{
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
}