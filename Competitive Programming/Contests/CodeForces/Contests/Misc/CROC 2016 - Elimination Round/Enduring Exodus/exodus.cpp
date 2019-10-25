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
int d[100001];
int query(int l, int r)
{
	return d[r] - d[l];
}
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	char c[100001];
	scanf("%s", c);
	int pos = 0;
	int dis = 0;
	FOR(i, 0, n)
	{
		if (c[i] == '0')
		{
			d[pos] = dis;
			pos++;
			dis++;
		}
		else
		{
			dis++;
		}
	}
	n = pos;
	int ans = 100001;
	FOR(i, 0, n)
	{
		int l = i;
		int r = n - 1;
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			int right = mid;
			int left = i - (k - (right - i));
			if (left < 0)
			{
				l = mid + 1;
				continue;
			}
			int rightD = query(i, right);
			int leftD = query(left, i);
			ans = min(ans, max(rightD, leftD));
			if (leftD < rightD)
			{
				r = mid - 1;
			}
			else if (leftD > rightD)
			{
				l = mid + 1;
			}
			else
			{
				break;
			}
		}
	}
	cout << ans << endl;
}