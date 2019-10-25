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

ll c, hr, hb, wr, wb;

int main(){

	cin >> c >> hr >> hb >> wr >> wb;
	ll ans = 0;
	FOR(x, 0, 1000001)
	{
		if (x * wr > c)
		{
			break;
		}
		ll y = (c - x * wr) / wb;
		ans = max(ans, x * hr + y * hb);
	}
	FOR(y, 0, 10000001)
	{
		if (y * wb > c)
		{
			break;
		}
		ll x = (c - y* wb) / wr;
		ans = max(ans, x * hr + y * hb);
	}
	cout << ans << endl;
}