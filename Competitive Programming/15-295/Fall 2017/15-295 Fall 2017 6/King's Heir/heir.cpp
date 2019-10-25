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
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
struct son {
	int i;
	int d, m, y;
};
bool cmp(son a, son b) {
	if (a.y != b.y) return a.y <= b.y;
	if (a.m != b.m) {
		return a.m <= b.m;
	}
	return a.d <= b.d;
}
son a[105];
int main(void)
{
	freopen("king.in", "r", stdin);
	freopen("king.out", "w", stdout);
	son d;
	cin >> d.d >> d.m >> d.y;
	int n;
	cin >> n;
	FOR(i, 0, n) {
		son s;
		s.i = i;
		cin >> s.d >> s.m >> s.y;
		a[i] = s;
	}
	sort(a, a + n, cmp);
	int ans = -1;
	RFOR(i, n - 1, -1) {
		son t = a[i];
		t.y += 18;
		if (cmp(t, d)) {
			ans = t.i + 1;
			break;
		}

	}
	cout << ans << endl;
}
/*
22 10 2016
7
28 2 1999
22 7 1995
21 10 1998
23 10 1998
3 9 2000
1 4 2013
17 12 2004
*/
/*
22 10 2016
1
28 2 1999
*/