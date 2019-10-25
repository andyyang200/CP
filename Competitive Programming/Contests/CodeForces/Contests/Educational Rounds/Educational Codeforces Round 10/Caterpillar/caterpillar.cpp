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
	int h1, h2;
	int a, b;
	scanf("%d%d%d%d", &h1, &h2, &a, &b);
	if (b >= a && h1 + 8 * a < h2)
	{
		cout << -1 << endl;
		return 0;
	}
	h1 += 8 * a;
	if (h1 >= h2)
	{
		cout << 0 << endl;
		return 0;
	}
	h1 -= 12 * b;
	int l = 0;
	int r = 200000;
	int days = -1;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (h1 + (ll)(mid + 1) * 12 * a - (ll)mid * 12 * b >= h2)
		{
			days = mid;
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	cout << days + 1 << endl;
}