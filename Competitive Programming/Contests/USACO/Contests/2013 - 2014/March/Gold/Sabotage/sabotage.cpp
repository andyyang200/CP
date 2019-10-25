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

double cows[100000];
double temp[100000];
int n;

bool check(double k)
{
	memcpy(temp, cows, n * sizeof(cows[0]));
	double total = 0;
	FOR(i, 0, n)
	{
		temp[i] -= k;
		total += temp[i];
	}
	double maxSoFar = max(0.0, temp[1]);
	double maxSum = temp[1];
	FOR(i, 2, n - 1)
	{
		maxSoFar = max(0.0, maxSoFar + temp[i]);
		maxSum = max(maxSum, maxSoFar);
	}
	return maxSum >= total;
}

int main()
{
	freopen("sabotage.in", "r", stdin);
	freopen("sabotage.out", "w", stdout);
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		cin >> cows[i];
	}
	double l = 0;
	double r = 10000;
	double ans = 0;
	while (round(l * 1000) < round(r * 1000))
	{
		double mid = (l + r) / 2;
		if (check(mid))
		{
			ans = mid;
			r = mid;
		}
		else
		{
			l = mid;
		}
	}
	printf("%.3f\n", ans);
}