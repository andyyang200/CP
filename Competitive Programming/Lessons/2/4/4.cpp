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
int dp[10001][100001]; // dp[i][j] = minimum coins to make j using the first i coins
int a[1001];
int main(void)
{
	int n;
	cin >> n;
	FOR(i, 0, n)
	{
		cin >> a[i];
	}
	int v;
	cin >> v;
	FOR(i, 1, n + 1)
	{
		FOR(j, 0, v + 1)
		{
			// some other if statements needed
			dp[i][j] = INF;
			dp[i][j] = dp[i - 1][j - a[i]]; // used the ith coin
			dp[i][j] = min(dp[i][j], dp[i - 1][j]);
		}
	}

	cout << dp[n][v] << endl;
}