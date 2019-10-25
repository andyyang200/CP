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
char grid[800][800];
bool visited[800][800];
int d[800][800];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
int main(void)
{
	int h, w, k;
	scanf("%d%d%d", &h, &w, &k);
	int si = 0;
	int sj = 0;
	FOR(i, 0, h) {
		FOR(j, 0, w) {
			cin >> grid[i][j];
			if (grid[i][j] == 'S') {
				si = i;
				sj = j;
			}
			d[i][j] = INF;
		}
	}
	queue<int> q;
	q.push(si);
	q.push(sj);
	d[si][sj] = 0;
	visited[si][sj] = true;
	while (!q.empty())
	{
		int i = q.front();
		q.pop();
		int j = q.front();
			q.pop();
		FOR(x, 0, 4) {
			int i2 = i + dx[x];
			int j2 = j + dy[x];
			if (i2 < 0 || i2 >= h || j2 < 0 || j2 >= w || visited[i2][j2] || grid[i2][j2] == '#') {
				continue;
			}
			d[i2][j2] = d[i][j] + 1;
			visited[i2][j2] = true;
			q.push(i2);
			q.push(j2);
		}
	}
	int ans = INF;
	FOR(i, 0, h) {
		FOR(j, 0, w) {
			if (d[i][j] <= k) {
				ans = min(ans, min(min(i, h - 1 - i), min(j, w - 1 - j)));
			}
		}
	}
	if (ans % k == 0) {
		ans /= k;
	}
	else {
		ans = ans / k + 1;
	}
	cout << ans + 1 << endl;
}