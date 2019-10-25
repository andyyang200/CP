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

map<int, bool> included;
int d[2001];
pii fields[2001];
int n, c;

int getDistance(int a, int b)
{
	return pow((fields[a].first - fields[b].first), 2) + pow((fields[a].second - fields[b].second), 2);
}

int main()
{
	freopen("irrigation.in", "r", stdin);
	freopen("irrigation.out", "w", stdout);
	cin >> n >> c;
	FOR(i, 0, n)
	{
		cin >> fields[i].first >> fields[i].second;
	}
	FOR(i, 0, n)
	{
		d[i] = getDistance(0, i) >= c ? getDistance(0, i) : -1;
	}
	included[0] = true;
	int count = 1;
	int cost = 0;
	while (count < n)
	{
		int minD = 1000000000;
		int minField = -1;
		FOR(i, 0, n)
		{
			if (!included[i] && d[i] != -1 && d[i] < minD)
			{
				minD = d[i];
				minField = i;
			}
		}
		if (minField == -1)
		{
			cout << -1 << endl;
			return 0;
		}
		included[minField] = true;
		cost += d[minField];
		count++;
		FOR(i, 0, n)
		{
			if (!included[i] && getDistance(minField, i) >= c)
			{
				if (getDistance(minField, i) < d[i] || d[i] == -1)
				{
					d[i] = getDistance(minField, i);
				}
			}
		}
	}
	cout << cost << endl;
}