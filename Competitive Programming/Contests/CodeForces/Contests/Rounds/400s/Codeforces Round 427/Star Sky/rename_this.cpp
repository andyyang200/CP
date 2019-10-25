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
int a[12][105][105];
int cnt[105][105];
int query(int mat[][105], int x1, int y1, int x2, int y2) {
	return mat[x2][y2] - mat[x1 - 1][y2] - mat[x2][y1 - 1] + mat[x1 - 1][y1 - 1];

}
int main(void)
{
	int n, q, c;
	scanf("%d%d%d", &n, &q, &c);
	FOR(i, 0, n) {
		int x, y, s;
		scanf("%d%d%d", &x, &y, &s);
		a[0][x][y] += s;
		int t = c - s + 1;
		a[t][x][y]++;
		cnt[x][y]++;
	}
	FOR(i, 0, c + 1) {
		FOR(x, 1, 105) {
			FOR(y, 1, 105) {
				a[i][x][y] = a[i][x][y] + a[i][x - 1][y] + a[i][x][y - 1] - a[i][x - 1][y - 1];
			}
		}
	}
	FOR(x, 1, 105) {
		FOR(y, 1, 105) {
			cnt[x][y] = cnt[x][y] + cnt[x - 1][y] + cnt[x][y - 1] - cnt[x - 1][y - 1];
		}
	}
	FOR(i, 0, q) {
		int t, x1, y1, x2, y2;
		scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
		t %= (c + 1);
		int ans = query(a[0], x1, y1, x2, y2);
		int x = query(cnt, x1, y1, x2, y2);
		FOR(i, 1, t + 1) {
			ans += x;
			ans -= (c + 1) * query(a[i], x1, y1, x2, y2);
		}
		cout << ans << endl;
	}
}