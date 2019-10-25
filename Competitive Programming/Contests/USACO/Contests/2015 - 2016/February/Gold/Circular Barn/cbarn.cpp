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
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
int cows[100001];
int main()
{
	//freopen("cbarn.in", "r", stdin);
	//freopen("cbarn.out", "w", stdout);
	int n;
	scanf("%d", &n);
	int maxCows = 0;
	int maxInd = -1;
	FOR(i, 0, n)
	{
		scanf("%d", &cows[i]);
	}
	queue<int> q;
	FOR(i, 0, 2 * n)
	{
		int ind = i % n;
		if (q.size() > maxCows)
		{
			maxCows = q.size();
			maxInd = q.front() % n;
		}
		FOR(j, 0, cows[ind])
		{
			q.push(i);
		}
		if (!q.empty())
		{
			int d = i - q.front();
			q.pop();
		}
	}
	while (q.size() > 0)
	{
		q.pop();
	}
	ll ans = 0;
	FOR(i, maxInd, maxInd + n)
	{
		int ind = i % n;
		FOR(j, 0, cows[ind])
		{
			q.push(i);
		}
		if (!q.empty())
		{
			int d = i - q.front();
			q.pop();
			ans += (ll)d * d;
		}
	}
	cout << ans << endl;
}