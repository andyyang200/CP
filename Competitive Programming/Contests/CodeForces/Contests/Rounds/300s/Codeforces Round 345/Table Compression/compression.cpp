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
int getKey(int r, int c)
{
	return r * m + c;
}
vector<vector<int>> original;
vector<vector<pii>> sortedByRows; // value, key
vector<vector<pii>> sortedByCols; // value, key
vector<int> edges[1000001];
bool visited[1000001];
int ans[1000001];
vector<int> s;
void topologicalSort(int node)
{
	visited[node] = true;
	FOR(i, 0, edges[node].size())
	{
		int nxt = edges[node][i];
		if (!visited[nxt])
		{
			topologicalSort(nxt);
		}
	}
	s.push_back(node);
}
int main()
{
	scanf("%d%d", &n, &m);
	original.resize(n);
	sortedByRows.resize(n);
	FOR(i, 0, n)
	{
		original[i].resize(m);
		sortedByRows[i].resize(m);
	}
	sortedByCols.resize(m);
	FOR(i, 0, m)
	{
		sortedByCols[i].resize(n);
	}
	FOR(i, 0, n)
	{
		FOR(j, 0, m)
		{
			scanf("%d", &original[i][j]);
			sortedByRows[i][j].first = original[i][j];
			sortedByRows[i][j].second = getKey(i, j);
			sortedByCols[j][i].first = original[i][j];
			sortedByCols[j][i].second = getKey(i, j);
		}
		sort(sortedByRows[i].begin(), sortedByRows[i].end());
	}
	FOR(i, 0, m)
	{
		sort(sortedByCols[i].begin(), sortedByCols[i].end());
	}
	FOR(i, 0, n)
	{
		FOR(j, 1, m)
		{
			if (sortedByRows[i][j].first != sortedByRows[i][j - 1].first)
			{
				edges[sortedByRows[i][j - 1].second].push_back(sortedByRows[i][j].second);
			}
		}
	}
	FOR(i, 0, m)
	{
		FOR(j, 1, n)
		{
			if (sortedByCols[i][j].first != sortedByCols[i][j - 1].first)
			{
				edges[sortedByCols[i][j - 1].second].push_back(sortedByCols[i][j].second);
			}
		}
	}
	FOR(i, 0, n * m)
	{
		if (!visited[i])
		{
			topologicalSort(i);
		}
	}
	FOR(i, 0, n * m)
	{
		ans[i] = 1;
	}
	FOR(i, 0, n * m)
	{
		FOR(j, 0, edges[i].size())
		{
			int nxt = edges[i][j];
			ans[nxt] = max(ans[nxt], ans[i] + 1);
		}
	}
	FOR(i, 0, n)
	{
		FOR(j, 0, m)
		{
			printf("%d ", ans[getKey(i, j)]);
		}
		printf("\n");
	}
}