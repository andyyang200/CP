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

You must schedule N events.
Each event must occur no earlier than day Si and no later than day Ti.
Additionally, for C pairs of events, event Ai must happen at least Xi days after Bi. Note that Xi may be negative.
g
Print -1 if there is no possible scheduling.
Otherwise, for each event, print what day it takes place. If there are multiple answers, print any of them

N, C <= 5000
Si, Ti <= 10^9
*/
















int l[100005];
int r[100005];
int w[100005];
int d[100005];
int main(void)
{
	int n, m, c;
	scanf("%d%d%d", &n, &m, &c);
	int e = 0;
	FOR(i, 1, n + 1) {
		int s, t;
		scanf("%d%d", &s, &t);
		s = max(s, 1);
		t = min(t, m);
		l[e] = 0;
		r[e] = i;
		w[e] = t;
		e++;
		l[e] = i;
		r[e] = 0;
		w[e] = -s;
		e++;
	}
	FOR(i, 0, c) {
		int a, b, x;
		scanf("%d%d%d", &a, &b, &x);
		l[e] = a;
		r[e] = b;
		w[e] = -x;
		e++;
	}
	FOR(i, 1, n + 1) {
		d[i] = INF;
	}
	FOR(i, 0, n + 1) {
		FOR(j, 0, e) {
			d[r[j]] = min(d[r[j]], d[l[j]] + w[j]);
		}
	}
	FOR(j, 0, e) {
		if (d[r[j]] > d[l[j]] + w[j]) {
			cout << -1 << endl;
			return 0;
		}
	}
	FOR(i, 1, n + 1) {
		cout << d[i] << endl;
	}
}