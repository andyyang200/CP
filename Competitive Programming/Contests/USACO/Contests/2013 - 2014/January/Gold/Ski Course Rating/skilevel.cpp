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
typedef long long ll;
typedef pair<int, int> pii;
	
int R, C, T;
int course[500][500];

int getKey(int r, int c)
{
	return C * r + c;
}

struct Edge
{
	int a, b;
	int weight;
	Edge(int x, int y, int z)
	{
		a = x;
		b = y;
		weight = z;
	}
	bool operator<(const Edge& e) const
	{
		return weight < e.weight;
	}
};

vector<Edge> edges;

struct Node
{
	int key, parent, rank, componentSize, minDifficulty;
};

Node nodes[250000];

void assign()
{
	FOR(i, 0, R * C)
	{
		nodes[i].key = i;
		nodes[i].parent = i;
		nodes[i].rank = 1;
		nodes[i].componentSize = 1;
	}
}
int getSet(int a)
{
	if (nodes[a].parent == a)
	{
		return a;
	}
	return getSet(nodes[a].parent);
}
void join(int a, int b)
{
	int x = getSet(a);
	int y = getSet(b);
	if (x == y)
	{
		return;
	}
	if (nodes[x].rank > nodes[y].rank)
	{
		nodes[y].parent = x;
		nodes[x].componentSize += nodes[y].componentSize;
	}
	else
	{
		nodes[x].parent = y;
		nodes[y].componentSize += nodes[x].componentSize;
		if (nodes[x].rank == nodes[y].rank)
		{
			nodes[y].rank++;
		}
	}
}

bool inBounds(int r, int c)
{
	return r >= 0 && r < R && c >= 0 && c < C;
}

int difference(int r1, int c1, int r2, int c2)
{
	return abs(course[r1][c1] - course[r2][c2]);
}

int main()
{
	freopen("skilevel.in", "r", stdin);
	freopen("skilevel.out", "w", stdout);
	scanf("%d%d%d", &R, &C, &T);
	FOR(r, 0, R)
	{
		FOR(c, 0, C)
		{
			scanf("%d", &course[r][c]);
		}
	}
	FOR(r, 0, R)
	{
		FOR(c, 0, C)
		{
			if (inBounds(r + 1, c))
			{
				edges.push_back(Edge(getKey(r, c), getKey(r + 1, c), difference(r, c, r + 1, c)));
			}
			if (inBounds(r, c + 1))
			{
				edges.push_back(Edge(getKey(r, c), getKey(r, c + 1), difference(r, c, r, c + 1)));
			}
		}
	}
	sort(edges.begin(), edges.end());
	assign();
	for(Edge& e : edges)
	{
		int a = getSet(e.a);
		int b = getSet(e.b);
		if (a != b)
		{
			if (nodes[a].componentSize < T)
			{
				nodes[a].minDifficulty = e.weight;
			}
			if (nodes[b].componentSize < T)
			{
				nodes[b].minDifficulty = e.weight;
			}
			join(a, b);
		}
	}
	ll sum = 0;
	FOR(r, 0, R)
	{
		FOR(c, 0, C)
		{
			int isStart;
			scanf("%d", &isStart);
			if (isStart)
			{
				int node = getKey(r, c);
				int maxDifficulty = -1;
				while (nodes[node].componentSize < T)
				{
					maxDifficulty = max(maxDifficulty, nodes[node].minDifficulty);
					node = nodes[node].parent;
				} 
				maxDifficulty = max(maxDifficulty, nodes[node].minDifficulty);
				sum += maxDifficulty;
			}
		}
	}
	cout << sum << endl;
}