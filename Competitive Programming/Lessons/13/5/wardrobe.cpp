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
/*
There are N outfits for sale. Each outfit has cost Ci, style Si, and fanciness Fi.
You want to buy a set of outfits that has total style of at least X without exceeding your budget of B.
You also want to minimize the maximum difference in fanciness between two outfits in your set.
What is this minimum difference? If there is no solution, output -1.



N, X <= 5000
B <= 10^9
Ci, Si ,Fi <= 10^9
*/
















map<int, int> back;
struct outfit {
	int c, s, f;
	bool operator<(const outfit o) const {
		return f < o.f;
	}
};
int n, b, s;

outfit a[10001];

struct row {
	vector<ll> dp;
	int i;
	row() {
		i = -1;
		dp = vector<ll>(s + 5);
	}
	row(int x) {
		i = x;
		dp = vector<ll>(s + 5);
		dp[0] = 0;
		FOR(j, 1, a[i].s + 1) {
			dp[j] = a[i].c;
		}
		FOR(j, a[i].s + 1, s + 5) {
			dp[j] = INF;
		}
	}
};
stack<row> in;
stack<row> out;
void popqueue() {
	if (out.empty()) { // move everything from in to out
		if (in.empty()) {
			return;
		}
		row r2(in.top().i);
		in.pop();
		out.push(r2);
		while (!in.empty()) {
			int i = in.top().i;
			in.pop();
			r2 = row(i);
			row r = out.top();
			FOR(j, 0, s + 5) {
				r2.dp[j] = min(r2.dp[j], r.dp[j]);
				if (j - a[i].s >= 0) {
					r2.dp[j] = min(r2.dp[j], r.dp[j - a[i].s] + a[i].c);
				}
			}
			out.push(r2);
		}
	}
	out.pop();
}
void pushqueue(int i) {
	row r2(i);
	if (!in.empty()) {
		row r = in.top();
		FOR(j, 0, s + 5) {
			r2.dp[j] = min(r2.dp[j], r.dp[j]);
			if (j - a[i].s >= 0) {
				r2.dp[j] = min(r2.dp[j], r.dp[j - a[i].s] + a[i].c);
			}
		}
	}
	in.push(r2);
}
bool test() {
	if (in.empty() && out.empty()) {
		return false;
	}
	if (out.empty()) {
		if (in.top().dp[s] <= b) {
			return true;
		}
	}
	else if (in.empty()) {
		if (out.top().dp[s] <= b) {
			return true;
		}
	}
	else {
		FOR(i, 0, s + 1) {
			if (in.top().dp[i] + out.top().dp[s - i] <= b) {
				return true;
			}
		}
	}
	return false;
}
int main(void)
{
	scanf("%d%d%d", &n, &b, &s);
	FOR(i, 0, n) {
		scanf("%d%d%d", &a[i].c, &a[i].s, &a[i].f);
		if (a[i].s >= s && a[i].c <= b) {
			cout << 0 << endl;
			return 0;
		}
	}
	sort(a, a + n);
	int j = 0;
	pushqueue(0);
	int ans = 1e9;
	FOR(i, 0, n) {
		while (j < i) {
			pushqueue(++j);
		}
		while (!test() && j < n - 1) {
			pushqueue(++j);
		}
		if (test()) {
			ans = min(ans, a[j].f - a[i].f);
		}
		popqueue();
	}
	if (ans == 1e9) {
		cout << -1 << endl;
	}
	else {
		cout << ans << endl;
	}
}