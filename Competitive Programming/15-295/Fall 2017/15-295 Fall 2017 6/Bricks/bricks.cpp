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
bool e(long double a, long double b) {
	return abs(a - b) <= 1e-9;
}
int x[100005];
char c[100005];
int main(void)
{
	//freopen("rename_this.in", "r", stdin);
	//freopen("rename_this.out", "w", stdout);
	int t;
	scanf("%d", &t);
	FOR(asd, 0, t) {
		int n;
		scanf("%d", &n);
		ll W = 0;
		ll B = 0;
		FOR(i, 0, n) {
			scanf("%d %c", &x[i], &c[i]);
			if (c[i] == 'B') {
				B += x[i];
			}
			else {
				W += x[i];
			}
		}
		if (W == 0 || B == 0) {
			cout << W + B << endl;
			continue;
		}
		ll w = 0;
		ll b = 0;
		int ans = 0;
		FOR(i, 0, n) {
			if (c[i] == 'B') {
				if (w != 0 && w * B % W == 0) {
					ll bn = w * B / W - b;
					if (bn > 0 && bn <= x[i]) {
						b = -bn;
						w = 0;
						ans++;
					}
				}
				b += x[i];
			}
			else {
				if (b != 0 && W * b % B == 0) {
					ll wn = W * b / B - w;
					if (wn > 0 && wn <= x[i]) {
						w = -wn;
						b = 0;
						ans++;
					}
				}
				w += x[i];
			}
		}
		printf("%d\n", ans);
	}
	
}
/*
3
3
1 B
3 W
2 B
4
3 W
3 B
9 W
1 B
2
2 W
3 W
*/


/*
1
4
1 B
1 W
1 B
1 W
*/