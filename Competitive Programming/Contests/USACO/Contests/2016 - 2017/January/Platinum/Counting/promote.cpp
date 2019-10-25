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

vector<int> children[100001];
int proficiency[100001];
int proficiencyPath[200001];
int first[100001];
int last[100001];
int sz[100001];
int p[100001];
int indx;

int getPath(int cur)
{
	proficiencyPath[indx] = proficiency[cur];
	first[cur] = indx;
	indx++;
	sz[cur] = 1;
	FOR(i, 0, children[cur].size())
	{
		int next = children[cur][i];
		getPath(next);
		sz[cur] += sz[next];
	}
	proficiencyPath[indx] = proficiency[cur];
	last[cur] = indx;
	indx++;
	return sz[cur];
}

class OrderStatisticsTree
{
public:
	int* value;
	int* size;
	OrderStatisticsTree()
	{
		value = NULL;
		size = NULL;
	}
	OrderStatisticsTree(int n)
	{
		value = new int[n];
		size = new int[n];
		memset(value, -1, n * sizeof(int));
		memset(size, 0, n * sizeof(int));
	}
	void add(int node, int v)
	{
		size[node]++;
		if (value[node] == -1)
		{
			value[node] = v;
			return;
		}
		else if (v <= value[node])
		{
			add(node * 2 + 1, v);
		}
		else
		{
			add(node * 2 + 2, v);
		}
	}
	void add(int v)
	{
		add(0, v);
	}
	int query(int node, int v)
	{
		if (value[node] = -1)
		{
			return 0;
		}
		else if (v < value[node])
		{
			return 1 + size[2 * node + 2] + query(2 * node + 1);
		}
		else
		{
			return query(2 * node + 2);
		}
	}
	int query(int v)
	{
		return query(0, v);
	}
};
OrderStatisticsTree SegmentTree[600000];
void buildTree(int node, int sl, int sr)
{
	FOR(i, sl, sr + 1)
	{
		SegmentTree[node].add(proficiencyPath[i]);
	}
	if (sl == sr)
	{
		return;
	}
	buildTree(node * 2 + 1, sl, (sl + sr) >> 1);
	buildTree(node * 2 + 2, ((sl + sr) >> 1) + 1, sr);
}
int queryTree(int node, int sl, int sr, int ql, int qr, int x)
{
	if (ql > qr)
		return 0;
	if (sl > qr || sr < ql)
		return 0;
	if (sl >= ql && sr <= qr)
		return SegmentTree[node].query(x);
	return queryTree((node << 1) + 1, sl, (sl + sr) >> 1, ql, qr, x) + queryTree((node << 1) + 2, ((sl + sr) >> 1) + 1, sr, ql, qr, x);
}
int main(void)
{
	//freopen("promote.in", "r", stdin);
	//freopen("promote.out", "w", stdout);
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		scanf("%d", &proficiency[i]);
	}
	FOR(i, 0, n - 1)
	{
		int manager;
		scanf("%d", &manager);
		manager--;
		p[i + 1] = manager;
		children[manager].push_back(i + 1);
	}
	indx = 0;
	getPath(0);
	buildTree(0, 0, 2 * n - 1);
	FOR(i, 0, n)
	{
		if (children[i].size() == 0)
		{
			cout << 0 << endl;
		}
		else
		{
			cout << queryTree(0, 0, 2 * n - 1, first[i] + 1, first[i] + 2 * sz[i] - 1 - 1, proficiency[i]) / 2 << endl;
		}
	}
}