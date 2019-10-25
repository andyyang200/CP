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

int main()
{
	int m;
	scanf("%d", &m);
	int l = 0;
	int r = 1000000;
	int ans = INF;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		int zeroes = 0;
		int temp = mid;
		while (temp > 0)
		{
			zeroes += temp / 5;
			temp /= 5;
		}
		if (zeroes > m)
		{
			r = mid - 1;
		}
		else if (zeroes < m)
		{
			l = mid + 1;
		}
		else
		{
			ans = min(ans, mid);
			r = mid - 1;
		}
	}
	if (ans == INF)
	{
		cout << 0 << endl;
	}
	else
	{
		cout << 5 << endl;
		cout << ans << " " << ans + 1 << " " << ans + 2 << " " << ans + 3 << " " << ans + 4 << endl;
	}
	
}