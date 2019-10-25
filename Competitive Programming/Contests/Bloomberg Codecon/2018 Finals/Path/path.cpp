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
#include <cassert>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;

int n, m, P;
char grid[50][50];
pii x;
pii s;
pii p[5];
int d[50][50];
pii pre[50][50];

bool police(int x, int y) {
	FOR(i, 0, P) {
		if (p[i].first == x && p[i].second == y) return true;
	}
	return false;
}
void move(int i) {
	FOR(i, 0, n) {
		FOR(j, 0, m) {
			d[i][j] = INF;
		}
	}
	queue<int> q;
	q.push(p[i].first);
	q.push(p[i].second);
	d[p[i].first][p[i].second] = 0;
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		int b = q.front();
		q.pop();
		if (a > 0 && (grid[a - 1][b] == '|' || grid[a - 1][b] == '+') && !police(a - 1, b)) {
			if (d[a - 1][b] == INF) {
				d[a - 1][b] = d[a][b] + 1;
				q.push(a - 1);
				q.push(b);
				pre[a - 1][b] = { a, b };
			}
		}
		if (b > 0 && (grid[a][b - 1] == '-' || grid[a][b - 1] == '+') && !police(a, b - 1)) {
			if (d[a][b - 1] == INF) {
				d[a][b - 1] = d[a][b] + 1;
				q.push(a);
				q.push(b - 1);
				pre[a][b - 1] = { a, b };
			}
		}
		if (a < n - 1 && (grid[a + 1][b] == '|' || grid[a + 1][b] == '+') && !police(a + 1, b)) {
			if (d[a + 1][b] == INF) {
				d[a + 1][b] = d[a][b] + 1;
				q.push(a + 1);
				q.push(b);
				pre[a + 1][b] = { a, b };
			}
		}
		if (b < m - 1 && (grid[a][b + 1] == '-' || grid[a][b - 1] == '+') && !police(a, b + 1)) {
			if (d[a][b + 1] == INF) {
				d[a][b + 1] = d[a][b] + 1;
				q.push(a);
				q.push(b + 1);
				pre[a][b + 1] = { a, b };
			}
		}
	}
	pii pp = x;
	while (pre[pp.first][pp.second] != p[i]) {
		pp = pre[pp.first][pp.second];
	}
	p[i] = pp;
}
int ans;
bool visited[50][50];
struct state{
	int a, b;
	vector<pii> pp;
	bool operator< (const state s) const{
		if (a != s.a) {
			return a < s.a;
		}
		if (b != s.b) {
			return b < s.b;
		}
		FOR(i, 0, P) {
			if (pp[i] != s.pp[i]) {
				return pp[i] < s.pp[i];
			}
		}
		return false;
	}
};
map<state, bool> mm;
void f(int a, int b, int d) {
	state ss;
	ss.a = a;
	ss.b = b;
	FOR(i, 0, P) {
		ss.pp.push_back(p[i]);
	}
	if (mm[ss]) {
		return;
	}
	mm[ss] = true;
	pii pp[5];
	FOR(i, 0, P) {
		pp[i] = p[i];
	}
	FOR(i, 0, P) {
		move(i);
	}
	if (police(a, b)) {
		return;
	}
	if (s.first == a && s.second == b) {
		ans = min(ans, d);
	}
	if (a > 0 && (grid[a - 1][b] == '|' || grid[a - 1][b] == '+') && !police(a - 1, b)) {
		f(a - 1, b, d + 1);
	}
	if (b > 0 && (grid[a][b - 1] == '-' || grid[a][b - 1] == '+') && !police(a, b - 1)) {
		f(a, b - 1, d + 1);
	}
	if (a < n - 1 && (grid[a + 1][b] == '|' || grid[a + 1][b] == '+') && !police(a + 1, b)) {
		f(a + 1, b, d + 1);
	}
	if (b < m - 1 && (grid[a][b + 1] == '-' || grid[a][b + 1] == '+') && !police(a, b + 1)) {
		f(a, b + 1, d + 1);
	}
	FOR(i, 0, P) {
		p[i] = pp[i];
	}
}
int main(void)
{
	cin >> n >> m;
	string tt;
	getline(cin, tt);
	FOR(i, 0, n) {
		string s;
		getline(cin, s);
		FOR(j, 0, m) {
			grid[i][j] = s[j];
		}
	}
	cin >> x.first >> x.second >> s.first >> s.second;
	cin >> P;
	FOR(i, 0, P) {
		cin >> p[i].first >> p[i].second;
	}
	ans = INF;
	f(x.first, x.second, 0);
	if (ans == INF) {
		cout << "IMPOSSIBLE" << endl;
	}
	else {
		cout << ans << endl;
	}
}