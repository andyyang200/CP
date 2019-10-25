/*
ID: andyyang200
PROG: fence
LANG: C++
*/

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
#define FOREACH(itr, b) for(auto& itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto& itr = b.rbegin(); itr != b.rend; itr++)
typedef long long ll;
typedef pair<int, int> pii;

vector<int> edges[501];
vector<int> path;
void find(int node)
{
	while(edges[node].size() > 0)
	{
		int next = edges[node][0];
		edges[node].erase(edges[node].begin());
		edges[next].erase(find(edges[next].begin(), edges[next].end(), node));
		find(next);
	}
	path.push_back(node + 1);
}

int main()
{
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);
	int f;
	cin >> f;
	FOR(i, 0, f)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	FOR(i, 0, 500)
	{
		sort(edges[i].begin(), edges[i].end());
	}
	FOR(i, 0, 500)
	{
		if (edges[i].size() % 2 == 1)
		{
			find(i);
			break;
		}
	}
	if (path.size() == 0)
	{
		find(0);
	}
	RFOR(i, path.size() - 1, -1)
	{
		cout << path[i] << endl;
	}
}