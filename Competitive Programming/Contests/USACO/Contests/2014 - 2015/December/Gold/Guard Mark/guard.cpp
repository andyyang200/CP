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

struct Cow
{
	int h, w, s;
	bool operator<(Cow c) const
	{
		return w + s > c.w + c.s;
	}
};

Cow cows[21];
bool used[21];
int n, h;
int maxSafety = -1;
void dfs(int p)
{
	if (p == n)
	{
		vector<Cow> sequence;
		int height = 0;
		FOR(i, 0, n)
		{
			if (used[i])
			{
				height += cows[i].h;
				sequence.push_back(cows[i]);
			}
		}
		if (height < h)
		{
			return;
		}
		int weights[21] = { 0 };
		RFOR(i, sequence.size() - 2, -1)
		{
			weights[i] = weights[i + 1] + sequence[i + 1].w;
		}
		int safety = 1000000000;
		FOR(i, 0, sequence.size())
		{
			safety = min(safety, sequence[i].s - weights[i]);
		}
		maxSafety = max(maxSafety, safety);
		return;
	}
	used[p] = true;
	dfs(p + 1);
	used[p] = false;
	dfs(p + 1);
}

int main()
{
	freopen("guard.in", "r", stdin);
	freopen("guard.out", "w", stdout);
	cin >> n >> h;
	FOR(i, 0, n)
	{
		cin >> cows[i].h >> cows[i].w >> cows[i].s;
	}
	sort(cows, cows + n);
	dfs(0);
	if (maxSafety == -1)
	{
		cout << "Mark is too tall" << endl;
	}
	else
	{
		cout << maxSafety << endl;
	}
}