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
int a[1000001];
int p[1000001];
int getSum(int l, int r)
{
	return p[r] - (l > 0 ? p[l - 1] : 0);
}
int main(void)
{
	int n, k;
	scanf("%d%d", &n, &k);
	FOR(i, 0, n)
	{
		scanf("%d", &a[i]);
		p[i] = (i > 0 ? p[i - 1] : 0) + a[i];
	}
	int ans = 0;
	int j = 0;
	FOR(i, 0, n)
	{
		while (getSum(i, j) < k && j < n)
		{
			j++;
		}
		ans += n - j;
	}
	cout << ans << endl;
}

