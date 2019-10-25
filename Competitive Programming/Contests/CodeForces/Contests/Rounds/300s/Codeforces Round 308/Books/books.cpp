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
ll p(int a, int b)
{
	ll ans = 1;
	FOR(i, 0, b)
	{
		ans *= a;
	}
	return ans;
}
int main()
{
	int n;
	cin >> n;
	ll ans = 0;
	FOR(i, 1, 10)
	{
		if (n < p(10, i))
		{
			ans += (n - p(10, i - 1) + 1) * i;
			break;
		}
		else
		{
			ll a = p(10, i) - 1;
			ll b = p(10, i - 1);
			ans += (a - b + 1) * i;
		}
	}
	cout << ans << endl;
}