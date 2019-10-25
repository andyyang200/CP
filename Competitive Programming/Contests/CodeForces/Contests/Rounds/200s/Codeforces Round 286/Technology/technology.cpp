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

vector<int> undirected[100001];
vector<int> directed[100001];
int visited[100001];
int colored[100001];
int n, m;
bool cycle;
void dfs(int i, set<int>& nodes)
{
	if (visited[i])
	{
		return;
	}
	visited[i] = true;
	nodes.insert(i);
	for (int next : undirected[i])
	{
		if (nodes.find(next) == nodes.end())
		{
			dfs(next, nodes);
		}
	}
}
void findCycle(int i)
{
	if (colored[i])
	{
		cycle =  true;
		return;
	}
	if (visited[i])
	{
		return;
	}
	visited[i] = true;
	colored[i] = true;
	for (int next : directed[i])
	{
		findCycle(next);
	}
	colored[i] = false;
}

int main()
{
	cin >> n >> m;
	FOR(i, 0, m)
	{
		int a, b;
		cin >> a >> b;
		directed[a].push_back(b);
		undirected[a].push_back(b);
		undirected[b].push_back(a);
	}
	int sum = 0;
	FOR(i, 1, n + 1)
	{
		if (!visited[i])
		{
			set<int> nodes;
			dfs(i, nodes);
			cycle = false;
			for (auto itr = nodes.begin(); itr != nodes.end(); itr++)
			{
				visited[*itr] = false;
			}
			for (auto itr = nodes.begin(); itr != nodes.end(); itr++)
			{
				if (!visited[*itr])
				{
					findCycle(*itr);
				}
			}
			sum += cycle ? nodes.size() : nodes.size() - 1;
		}
	}
	cout << sum << endl;
}