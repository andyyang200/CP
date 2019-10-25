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

int totalLights[2048];
int lights[2048];
vector<int> descendants[2048];
int n;

void initiate(int node, int level, int total)
{
	if (level == n)
	{
		totalLights[node] = total;
		return;
	}
	initiate(node * 2, level + 1, total + lights[node * 2]);
	initiate(node * 2 + 1, level + 1, total + lights[node * 2 + 1]);
}
int getLevel(int node)
{
	int level = 0;
	while (node > 1)
	{
		node /= 2;
		level++;
	}
	return level;
}

int main()
{
	scanf("%d", &n);
	FOR(i, 0, (1 << (n + 1)) - 2)
	{
		scanf("%d", &lights[i + 2]);
	}
	initiate(1, 0, 0);
	int target = 0;
	FOR(i, (1 << n), (1 << (n + 1)))
	{
		target = max(target, totalLights[i]);
	}
	RFOR(i, (1 << (n + 1)) - 1, 0)
	{
		if (getLevel(i) == n)
		{
			descendants[i].push_back(i);
		}
		else
		{
			descendants[i] = descendants[i * 2];
			for (int d : descendants[i * 2 + 1])
			{
				descendants[i].push_back(d);
			}
		}
	}
	int total = 0;
	FOR(i, 2, (1 << (n + 1)))
	{
		int add = INF;
		for (int d : descendants[i])
		{
			add = min(add, target - totalLights[d]);
		}
		for (int d : descendants[i])
		{
			totalLights[d] += add;
		}
		total += add;
	}
	cout << total << endl;
}