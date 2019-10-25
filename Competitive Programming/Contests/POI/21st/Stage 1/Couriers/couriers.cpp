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
#include <map>
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
struct query {
	int l, r, block, original;
	bool operator<(const query o) {
		if (block != o.block) {
			return block < o.block;
		}
		return r < o.r;
	}
};
int n, m;
int sz;
int a[500001];
query q[500001];	
int cnt[500001];
set<pii> s;
void add(int i) {
	int x = a[i];
	if (cnt[x] != 0) {
		s.erase(s.find(make_pair(cnt[x], x)));
	}
	s.insert(make_pair(cnt[x] + 1, x));
	cnt[x]++;
}
void remove(int i) {
	int x = a[i];
	s.erase(s.find(make_pair(cnt[x], x)));
	s.insert(make_pair(cnt[x] - 1, x));
	cnt[x]--;
}
int ans[500001];
int main(void)
{
	scanf("%d%d", &n, &m);
	sz = sqrt(n);
	FOR(i, 0, n) {
		scanf("%d", &a[i]);
	}
	FOR(i, 0, m) {
		scanf("%d%d", &q[i].l, &q[i].r);
		q[i].l--;
		q[i].r--;
		q[i].block = q[i].l / sz;
		q[i].original = i;
	}
	sort(q, q + m);
	int l = 0;
	int r = 0;
	cnt[a[0]]++;
	s.insert(make_pair(1, a[0]));
	FOR(i, 0, m) {
		while (l < q[i].l) {
			remove(l++);
		}
		while (l > q[i].l) {
			add(--l);
		}
		while (r < q[i].r) {
			add(++r);
		}
		while (r > q[i].r) {
			remove(r--);
		}
		set<pii>::iterator itr = --(s.end());
		if (itr->first > (q[i].r - q[i].l + 1) / 2) {
			ans[q[i].original ]= itr->second;
		}
		else {
			ans[q[i].original] = 0;
		}
	}
	FOR(i, 0, m) {
		cout << ans[i] << endl;
	}
	return 0;
}