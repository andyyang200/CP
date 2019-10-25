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

int color[100001];
vector<int> edges[100001];
int p[100001];
bool cycle;

void dfs(int node) // undirected graph
{
	color[node] = 1;
	for (int v : edges[node])
	{
		if (v != p[node])
		{
			if (color[node] == 1)
			{
				cycle = true;
			}
			else
			{
				p[v] = node;
				dfs(v);
			}
		}
	}
}
void dfs(int node) // directed graph
{
	if (color[node] != 0)
	{
		if (color[node] == 1)
		{
			cycle = true;
		}
		return;
	}
	color[node] = 1;
	for (int v : edges[node])
	{
		dfs(v);
	}
	color[node] = 2;
}

int main(void)
{
	FOR(i, 0, n)
	{
		if (color[i] == 0)
		{
			dfs(i);
		}
	}
}