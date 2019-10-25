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
ll power[65];
int main()
{
	ll a, b;
	cin >> a >> b;
	power[0] = 1;
	FOR(i, 1, 65)
	{
		power[i] = 2 * power[i - 1];
	}
	int ans = 0;
	FOR(digits, 1, 65)
	{
		ll value = 0;
		FOR(i, 0, digits)
		{
			value += power[i];
		}
		RFOR(loc, digits - 2, -1)
		{
			if (value - power[loc] >= a && value - power[loc] <= b)
			{
				ans++;
			}
			if (value - power[loc] >= b)
			{
				break;
			}
		}
	}
	cout << ans << endl;
}