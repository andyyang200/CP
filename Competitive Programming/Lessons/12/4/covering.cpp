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
You have a convex polygon of N sides, numbered from 0 to N - 1 clockwise.
You have M cameras. The ith camera can see Li consecutive sides starting from Si.
What is the least number of cameras that need to be turned on in order to view the entire polygon?
It is guaranteed that a solution exists.
N <= 10^9
M <= 100000
0 <= Si < N;
1 <= Li <= N
*/





















const int MAXM = 100000; // limits

int n, m; // input

struct seg {
	int s, e;
	bool operator<(const seg& o) const {
		if (s != o.s) return s < o.s;
		return e > o.e;
	}
} s[MAXM];
int nxt[MAXM][18]; // nxt[i][k] = optimal location after 2^k steps
					// from i or - 1 if done

bool between(int a, int b, int c) { // cyclic a <= b <= c
	if (a <= c) return a <= b && b <= c;
	else return a <= b || b <= c;
}

bool touch_right(int a, int b) {
	if (s[a].e < n) {
		if (b <= a) return false;
		return s[b].s <= s[a].e;
	}
	else {
		if (b > a) return true;
		return s[b].s <= s[a].e % n;
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &s[i].s, &s[i].e);
	}
	for (int i = 0; i < m; i++) {
		if (s[i].e == n) { // special case L = N in case of weird stuff
			printf("%d\n", 1);
			return 0;
		}
	}

	for (int i = 0; i < m; i++) 
		s[i].e += s[i].s;
	sort(s, s + m);

	// remove covered segments
	int t = m;
	m = 0;
	for (int i = 0; i < t; i++)
		if (m == 0 || s[i].e > s[m - 1].e)
			s[m++] = s[i];

	t = 0; // remove segments covered by last segment cycling around
	while (s[t].e <= s[m - 1].e % n) {
		t++;
	}
	m -= t;
	for (int i = 0; i < m; i++)
		s[i] = s[i + t];
	
	t = 0;
	for (int i = 0; i < m; i++) { // two pointer
		while (touch_right(i, (t + 1) % m))
			t = (t + 1) % m;
		nxt[i][0] = t;
	}

	for (int k = 1; k <= 17; k++) { // calculate nxt table
		for (int i = 0; i < m; i++) {
			int a = nxt[i][k - 1];
			if (a == -1) {
				nxt[i][k] = -1;
			}
			else {
				int b = nxt[a][k - 1];
				if (b == -1 || between(i, b, a))  // done if i <= b <= a
					nxt[i][k] = -1;
				else nxt[i][k] = b;
			}
		}
	}

	int ans = m;
	for (int i = 0; i < m; i++) { // starting location
		int c = nxt[i][0], x = 1; // use starting location
		for (int k = 17; k >= 0; --k) { // find maximum steps without completing circle starting at i
			if (nxt[c][k] != -1 && !between(c, i, nxt[c][k])) {
				c = nxt[c][k];
				x += 1 << k;
			}
		}
		x++; // one more move needed to complete
		ans = min(ans, x);
	}

	printf("%d\n", ans);
	return 0;
}