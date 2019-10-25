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
int main(void)
{
	int n, k;
	scanf("%d%d", &n, &k);
	FOR(i, 0, n)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int ans = 0;
	FOR(i, 0, n)
	{
		int x = a[i] / k;
		if (a[i] % k != 0)
		{
			x++;
		}
		if (x % 2 == 0)
		{
			ans += x / 2;
		}
		else
		{
			ans += x / 2 + 1;
			if (i < n - 1)
			{
				a[i + 1] = max(0, a[i + 1] - k);
			}
			
		}
	}
	cout << ans << endl;

}