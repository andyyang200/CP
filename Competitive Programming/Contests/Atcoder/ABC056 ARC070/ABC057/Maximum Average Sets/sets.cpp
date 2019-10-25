//Andrew Yang
//accepted
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
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
ll v[51];
double factorial[51];
int main(void)
{
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	FOR(i, 0, n)
	{
		scanf("%lld", &v[i]);
	}
	sort(v, v + n);
	ll sum = 0;
	ll minV = v[n - a];
	int minCount = 0;
	int minNeeded = 0;
	FOR(i, n - a, n)
	{
		sum += v[i];
		if (v[i] == minV)
		{
			minNeeded++;
		}
	}
	FOR(i, 0, n)
	{
		if (v[i] == minV)
		{
			minCount++;
		}
	}
	factorial[0] = 1;
	FOR(i, 1, n + 1)
	{
		factorial[i] = factorial[i - 1] * i;
	}
	ll ways = 0;
	if (minV != v[n - 1])
	{
		ways += round((double)1 / factorial[minNeeded] / factorial[minCount - minNeeded] * factorial[minCount]);
	}
	else
	{
		for (int i = minNeeded; i <= min(minCount, minNeeded + b - a); i++)
		{
			ways += round((double)1 / factorial[i] / factorial[minCount - i] * factorial[minCount]);
		}
	}
	printf("%.9f\n", (double)sum / a);
	cout << ways << endl;
}