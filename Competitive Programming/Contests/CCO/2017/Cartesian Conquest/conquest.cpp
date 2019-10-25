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
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
int mindp[1005][1005];
int maxdp[1005][1005];
int getMin(int n, int m) {
	if (n == 0 || m == 0) {
		return 0;
	}
	if (mindp[n][m] != 0) {
		return mindp[n][m];
	}
	int ans = INF;
	if (2 * n <= m)
	{
		ans = min(ans, 1 + getMin(n, m - 2 * n));
	}
	if (n % 2 == 0 && n / 2 <= m) {
		ans = min(ans, 1 + getMin(n, m - n / 2));
	}
	swap(n, m);
	if (2 * n <= m)
	{
		ans = min(ans, 1 + getMin(n, m - 2 * n));
	}
	if (n % 2 == 0 && n / 2 <= m) {
		ans = min(ans, 1 + getMin(n, m - n / 2));
	}
	return mindp[n][m] = mindp[m][n] = ans;
}
int getMax(int n, int m) {
	if (n == 0 || m == 0) {
		return 0;
	}
	if (maxdp[n][m] != 0) {
		return maxdp[n][m];
	}
	if (n == 0 || m == 0) {
		return 0;
	}
	int ans = 0;
	if (2 * n <= m)
	{
		ans = max(ans, 1 + getMax(n, m - 2 * n));
	}
	if (n % 2 == 0 && n / 2 <= m) {
		ans = max(ans, 1 + getMax(n, m - n / 2));
	}
	swap(n, m);
	if (2 * n <= m)
	{
		ans = max(ans, 1 + getMax(n, m - 2 * n));
	}
	if (n % 2 == 0 && n / 2 <= m) {
		ans = max(ans, 1 + getMax(n, m - n / 2));
	}
	return maxdp[n][m] = maxdp[m][n] = ans;
}
int main(void)
{
	int n, m;
	cin >> n >> m;
	cout << getMin(n, m) << " " << getMax(n, m) << endl;
}