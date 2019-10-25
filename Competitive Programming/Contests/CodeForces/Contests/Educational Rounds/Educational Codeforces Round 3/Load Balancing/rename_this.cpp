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
int a[100001];
int goal[100001];
int main()
{
	int n;
	scanf("%d", &n);
	int sum = 0;
	FOR(i, 0, n)
	{
		scanf("%d", &a[i]);
		sum += a[i];
	}
	sort(a, a + n);
	FOR(i, 0, n)
	{
		goal[i] = sum / n;
		if (i >= n - sum % n)
		{
			goal[i]++;
		}
	}
	int ans = 0;
	int done = 0;
	RFOR(i, n - 1, -1)
	{
		while (a[i] > goal[i])
		{
			int move = min(a[i] - goal[i], goal[done] - a[done]);
			a[i] -= move;
			a[done] += move;
			ans += move;
			if (a[done] == goal[done])
			{
				done++;
			}
		}
	}
	cout << ans << endl;
}