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
vector<pair<int, int>> g[200001];
vector<int>  ans[200001];
int used[200001];
int m;

void dfs(int node, int f) 
{
	used[node] = true;
	int c = 0;
	for (int i = 0; i < g[node].size(); ++i)
	{
		if (!used[g[node][i].first])
		{
			if (c == f)
				c++;
			ans[c].push_back(g[node][i].second);
			dfs(g[node][i].first, c);
			c++;
		}
	}
}

int main()
{
	m = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i) 
	{
		int a, b;
		cin >> a >> b;
		g[a - 1].push_back(make_pair(b - 1, i));
		g[b - 1].push_back(make_pair(a - 1, i));
		m = max(m, (int)g[a - 1].size());
		m = max(m, (int)g[b - 1].size());

	}
	dfs(0, -1);
	cout << m << "\n";
	for (int i = 0; i < m; ++i) 
	{
		cout << ans[i].size() << " ";
		for (int j = 0; j < ans[i].size(); ++j)
		{
			cout << ans[i][j] + 1 << " ";
		}
		cout << endl;
	}
}