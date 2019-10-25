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
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
ll dp[505][505];
ll a[505];
int main()
{
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		scanf("%d", &a[i]);
	}
	FOR(i, 2, n)
	{
		FOR(j, 0, n - i)
		{
			FOR(k, j + 1, j + i)
			{
				dp[j][j + i] = max(dp[j][j + i], dp[j][k] + dp[k][j + i] + a[j] * a[j + i]);
			}
		}
	}
	cout << dp[0][n - 1] << endl;
}