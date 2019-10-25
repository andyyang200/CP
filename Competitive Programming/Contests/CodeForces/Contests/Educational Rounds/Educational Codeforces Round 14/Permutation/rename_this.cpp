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
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;

int permutation[1000001];
int group[1000001];
vector<vector<int> > groups;
vector<int> edges[1000001];
int n, m;

void findgroup(int g, int i)
{
	group[i] = g;
	groups[g].push_back(permutation[i]);
	for (int j : edges[i])
	{
		if (group[j] == -1)
		{
			findgroup(g, j);
		}
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	FOR(i, 0, n)
	{
		scanf("%d", &permutation[i]);
		group[i] = -1;
	}
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
		if (group[i] == -1)
		{
			groups.push_back(vector<int>());
			findgroup(groups.size() - 1, i);
		}
	}
	FOR(i, 0, groups.size())
	{
		sort(groups[i].begin(), groups[i].end());
	}
	FOR(i, 0, n)
	{
		cout << groups[group[i]][groups[group[i]].size() - 1] << " ";
		groups[group[i]].pop_back();
	}
	cout << endl;
}