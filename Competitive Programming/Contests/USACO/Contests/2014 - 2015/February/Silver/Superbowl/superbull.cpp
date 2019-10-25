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

int edges[2000][2000];
int teams[2000];
bool inTree[2000];
int d[2000];
int main()
{
	freopen("superbull.in", "r", stdin);
	freopen("superbull.out", "w", stdout);
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		scanf("%d", &teams[i]);
	}
	FOR(i, 0, n)
	{
		FOR(j, i + 1, n)
		{
			edges[i][j] = edges[j][i] = (teams[i] ^ teams[j]);
		}
	}
	FOR(i, 0, n)
	{
		d[i] = edges[0][i];
	}
	int treeSize = 1;
	ll treeCost = 0;
	inTree[0] = true;
	while (treeSize < n)
	{
		int maxDistance = -1;
		int maxNode = -1;
		for (int i = 0; i < n; i++)
		{
			if (!inTree[i] && d[i] > maxDistance)
			{
				maxDistance = d[i];
				maxNode = i;
			}
		}
		treeSize++;
		inTree[maxNode] = true;
		treeCost += d[maxNode];
		for (int i = 0; i < n; i++)
		{
			d[i] = max(d[i], edges[maxNode][i]);
		}
	}
	cout << treeCost << endl;

}