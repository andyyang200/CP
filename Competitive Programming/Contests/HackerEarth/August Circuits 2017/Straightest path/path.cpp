//Andrew Yang
//Accepted
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
#include <deque>
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
char grid[1005][1005];
bool visited[1005][1005][5];
int n, m;
struct node {
	int r, c, d;
	int x;
	node(int x1, int y, int z, int pp) {
		r = x1;
		c = y;
		d = z;
		x = pp;
	}
};
bool valid(int r, int c, int d) {
	return r >= 0 && r < n && c >= 0 && c < m && grid[r][c] != '*' && !visited[r][c][d];
}
node move(node x) {
	if (x.d == 0) {
		x.r--;
	}
	if (x.d == 1) {
		x.c++;
	}
	if (x.d == 2) {
		x.r++;
	}
	if (x.d == 3) {
		x.c--;
	}
	return x;
}
int main(void)
{
	cin >> n >> m;
	FOR(i, 0, n) {
		FOR(j, 0, m) {
			cin >> grid[i][j];
		}
	}
	deque<node> q;
	FOR(i, 0, n) {
		FOR(j, 0, m) {
			if (grid[i][j] == 'V') {
				q.push_back(node(i, j, 0, 0));
				q.push_back(node(i, j, 1, 0));
				q.push_back(node(i, j, 2, 0));
				q.push_back(node(i, j, 3, 0));
				FOR(k, 0, 4) {
					visited[i][j][k] = 1;
				}
			}
		}
	}
	while (!q.empty()) {
		node x = q.front();
		if (grid[x.r][x.c] == 'H') {
			cout << x.x << endl;
			return(0);
		}
		q.pop_front();
		node nxt = move(x);
		if (valid(nxt.r, nxt.c, nxt.d)) {
			q.push_front(nxt);
			visited[nxt.r][nxt.c][nxt.d] = true;
		}

		node lft = node(x.r, x.c, (x.d - 1 + 4) % 4, x.x + 1);
		if (valid(lft.r, lft.c, lft.d)) {
			q.push_back(lft);
			visited[lft.r][lft.c][lft.d] = true;
		}
		node rht = node(x.r, x.c, (x.d + 1 + 4) % 4, x.x + 1);
		if (valid(rht.r, rht.c, rht.d)) {
			q.push_back(rht);
			visited[rht.r][rht.c][rht.d] = true;
		}
	}
	cout << -1 << endl;
}