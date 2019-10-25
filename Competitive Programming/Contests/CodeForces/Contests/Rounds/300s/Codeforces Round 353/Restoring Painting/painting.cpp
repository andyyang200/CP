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

int main(void)
{
	int n, a, b, c, d;
	scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
	ll ans = 0;
	FOR(i, 1, n + 1)
	{
		int minSum = a + b + i;
		minSum = min(minSum, a + c + i);
		minSum = min(minSum, b + d + i);
		minSum = min(minSum, c + d + i);
		int maxSum = 0;
		maxSum = max(maxSum, a + b + i);
		maxSum = max(maxSum, a + c + i);
		maxSum = max(maxSum, b + d + i);
		maxSum = max(maxSum, c + d + i);
		if (maxSum < minSum + n)
		{
			ans += minSum + n - maxSum;
		}
	}
	cout << ans << endl;
}