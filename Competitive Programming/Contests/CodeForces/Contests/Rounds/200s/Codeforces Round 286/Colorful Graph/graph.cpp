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

int n, m;
set<int> colors;
vector<pii> edges[100];
int visited[100];
bool possible;
void fill(int node, int a, int b, int color)
{
	if (node == b)
	{
		possible = true;;
	}
	if (visited[node])
	{
		return;
	}
	visited[node] = true;
	for (pii p : edges[node])
	{
		if (p.second == color)
		{
			fill(p.first, a, b, color);
		}
	}
}

int count(int a, int b)
{
	int count = 0;
	for (auto itr = colors.begin(); itr != colors.end(); itr++)
	{
		possible = false;
		FOR(j, 0, n)
		{
			visited[j] = false;
		}
		fill(a, a, b, *itr);
		if (possible)
		{
			count++;
		}
	}
	return count;
}

int main()
{
	cin >> n >> m;
	FOR(i, 0, m)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		edges[a].push_back(pii(b, c));
		edges[b].push_back(pii(a, c));
		colors.insert(c);
	}
	int q;
	cin >> q;
	FOR(i, 0, q)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		cout << count(a, b) << endl;
	}
}