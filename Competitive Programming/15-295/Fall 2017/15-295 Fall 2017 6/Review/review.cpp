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
#define FOR(index, start, end) for(ll index = start; index < end; ++index)
#define RFOR(index, start, end) for(ll index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<ll, ll> pii;
class SegmentTree
{
public:
	ll* st;
	ll length;
	SegmentTree(ll n)
	{
		length = n;
		ll height = (ll)(ceil(log2(n)));
		ll maxSize = 2 * (1 << height) - 1;
		st = new ll[maxSize];
		build(0, 0, length - 1);
	}
	ll f(ll a, ll b) // change for different problems
	{
		return a + b;
	}
	void build(ll node, ll l, ll r)
	{
		if (l == r)
			st[node] = 0;
		else
		{
			ll mid = (l + r) / 2;
			build(node * 2 + 1, l, mid);
			build(node * 2 + 2, mid + 1, r);
			st[node] = f(st[node * 2 + 1], st[node * 2 + 2]);
		}
	}

	void update(ll i, ll v)
	{
		update(0, 0, length - 1, i, v); //if sum query last parameter should be v - a[i], otherwise should be v
	}
	void update(ll node, ll sl, ll sr, ll i, ll v)
	{
		if (i < sl || i > sr)
			return;
		if (sl == sr)
		{
			st[node]+=v;
		}
		if (sl != sr)
		{
			ll mid = (sl + sr) / 2;
			update(node * 2 + 1, sl, mid, i, v);
			update(node * 2 + 2, mid + 1, sr, i, v);
			st[node] = f(st[node * 2 + 1], st[node * 2 + 2]);
		}
	}

	ll query(ll ql, ll qr)
	{
		if (ql > qr) return 0;
		return query(0, 0, length - 1, ql, qr);
	}
	ll query(ll node, ll sl, ll sr, ll ql, ll qr)
	{
		if (sl > qr || sr < ql)
			return -1;
		if (sl >= ql && sr <= qr)
			return st[node];
		ll mid = (sl + sr) / 2;
		ll a = query(node * 2 + 1, sl, mid, ql, qr);
		ll b = query(node * 2 + 2, mid + 1, sr, ql, qr);
		if (a == -1)
			return b;
		if (b == -1)
			return a;
		return f(a, b);
	}
};
ll p[100005];
vector<ll> children[100005];
ll t[100005];
ll r[100005];
ll ans[100005];
SegmentTree st(100005);
void dfs(ll u) {
	ll x = st.query(0, r[u] - 1);
	for (ll v : children[u]) {
		dfs(v);
	}
	ans[u] = st.query(0, r[u] - 1) - x;
	st.update(r[u], t[u]);
}
int main(void)
{
	ll n;
	cin >> n;
	ll start = -1;
	FOR(i, 0, n) {
		cin >> p[i] >> r[i] >> t[i];
		if (p[i] != -1) {
			p[i]--;
			children[p[i]].push_back(i);
		}
		else {
			start = i;
		}
	}
	dfs(start);
	FOR(i, 0, n) {
		cout << ans[i] << endl;
	}
}
/*
5
4 4 80
1 1 40
-1 10 60
3 5 50
4 8 70
*/		