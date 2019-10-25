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

int main(void)
{
	ll  n, m;
	cin >> n >> m;
	if (m >= n)
	{
		cout << n << endl;
		return 0;
	}
	ll  k = -1;
	ll  l = 0;
	ll  r = 2e9;
	n -= m;
	while (l <= r)
	{
		ll  mid = (l + r) / 2;
		if (n - mid * (mid + 1) / 2 <= 0)
		{
			r = mid - 1;
			k = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	cout << m + k << endl;
}