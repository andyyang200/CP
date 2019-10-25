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
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
int cows[100001];
double laps[100001];
int main()
{
	freopen("running.in", "r", stdin);
	freopen("running.out", "w", stdout);
	int n, l, c;
	scanf("%d%d%d", &n, &l, &c);
	int maxSpeed = 0;
	FOR(i, 0, n)
	{
		scanf("%d", &cows[i]);
		maxSpeed = max(maxSpeed, cows[i]);
	}
	FOR(i, 0, n)
	{
		laps[i] = (double)cows[i] / maxSpeed * l;
		laps[i] = round(laps[i] * INF) / INF;
	}
	ll total = 0;
	FOR(i, 0, n)
	{
		FOR(j, i + 1, n)
		{
			double overtakes = fabs(laps[j] - laps[i]);
			if ((int)overtakes != (int)(overtakes + 1e-7))
			{
				overtakes += 1e-9;
			}
			total += (ll)overtakes;
		}
	}
	cout << total << endl;
}