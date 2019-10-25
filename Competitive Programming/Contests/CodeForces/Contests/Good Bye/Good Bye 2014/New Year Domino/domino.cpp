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

int x[200001];
int l[200001];
bool fall[200001];
int n, q;

void push(int p)
{
	fall[p] = true;
	FOR(i, p + 1, 200001)
	{
		if (x[i] - x[p] > l[p])
		{
			return;
		}
		if (i >= n)
		{
			return;
		}
		if (!fall[i])
		{
			push(i);
		}
	}
}

int main()
{
	cin >> n;
	FOR(i, 0, n)
	{
		cin >> x[i] >> l[i];
	}
	cin >> q;
	FOR(i, 0, q)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		FOR(i, a, b + 1)
		{
			fall[i] = false;
		}
		push(a);
		int sum = 0;
		while (!fall[b])
		{
			int target = -1;
			FOR(i, a, b + 1)
			{
				if (!fall[i])
				{
					target = i;
					break;
				}
			}
			int minCost = 1000000000;
			FOR(i, a, target)
			{
				int cost = x[target] - x[i] - l[i];
				if (cost < minCost)
				{
					minCost = cost;
				}
			}
			sum += minCost;
			push(target);
		}
		cout << sum << endl;
	}
}