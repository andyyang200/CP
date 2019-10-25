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

class SegmentTree
{
public:
	ll * st;
	int* a;
	int length;
	SegmentTree(int arr[], int n)
	{
		length = n;
		a = arr;
		int height = (int)(ceil(log2(n)));
		int maxSize = 2 * (1 << height) - 1;
		st = new ll[maxSize];
		build(0, 0, length - 1);
	}
	ll f(ll a, ll b) // change for different problems
	{
		return a + b;
	}
	void build(int node, int l, int r)
	{
		if (l == r)
			st[node] = a[l];
		else
		{
			int mid = (l + r) / 2;
			build(node * 2 + 1, l, mid);
			build(node * 2 + 2, mid + 1, r);
			st[node] = f(st[node * 2 + 1], st[node * 2 + 2]);
		}
	}

	void update(int i, int v)
	{
		update(0, 0, length - 1, i, v);
		a[i] = v;
	}
	void update(int node, int sl, int sr, int i, int v)
	{
		if (i < sl || i > sr)
			return;
		if (sl == sr)
		{
			st[node] = v;
		}
		if (sl != sr)
		{
			int mid = (sl + sr) / 2;
			update(node * 2 + 1, sl, mid, i, v);
			update(node * 2 + 2, mid + 1, sr, i, v);
			st[node] = f(st[node * 2 + 1], st[node * 2 + 2]);
		}
	}

	ll query(int ql, int qr)
	{
		return query(0, 0, length - 1, ql, qr);
	}
	ll query(int node, int sl, int sr, int ql, int qr)
	{
		if (sl > qr || sr < ql)
			return -1;
		if (sl >= ql && sr <= qr)
			return st[node];
		int mid = (sl + sr) / 2;
		ll a = query(node * 2 + 1, sl, mid, ql, qr);
		ll b = query(node * 2 + 2, mid + 1, sr, ql, qr);
		if (a == -1)
			return b;
		if (b == -1)
			return a;
		return f(a, b);
	}
};

int a[300005];
int d[1000001];
int getd(int x) {
	if (x <= 2) return x;
	int c = 0;
	for (int i = 1; i <= sqrt(x); i++) {
		if (x % i == 0) c += 2;
	}
	if (round(sqrt(x)) * round(sqrt(x)) == x) c--;
	return c;
}
int main(void)
{
	int n, m;
	scanf("%d%d", &n, &m);
	set<int> s;
	FOR(i, 0, n) {
		scanf("%d", &a[i]);
		if (a[i] > 2) {
			s.insert(i);
		}
	}
	FOR(i, 1, 1000001) {
		d[i] = -1;
	}
	SegmentTree st(a, n);
	FOR(i, 0, m) {
		int t, l, r;
		scanf("%d%d%d", &t, &l, &r);
		l--;
		r--;
		if (t == 1) {
			auto it = s.lower_bound(l);
			vector<int> v;
			while (it != s.end() && *it <= r) {
				int x = a[*it];
				if (d[x] == -1) d[x] = getd(x);
				a[*it] = d[x];
				if (a[*it] <= 2) {
					v.push_back(*it);
				}
				st.update(*it, a[*it]);
				it++;
			}
			for (int x : v) {
				s.erase(s.find(x));
			}
		}
		else {
			ll x = st.query(l, r);
			cout << x << endl;
		}
	}

}
