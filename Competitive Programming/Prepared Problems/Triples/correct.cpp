#ifndef LOCAL
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

using vec = vector<ll>;
using val = pair<vec, vec>;

const int MAXN = 200001;

vec e[MAXN];
ll ans;

void ad(val& l, val& r) {
	auto& vl = l.first;
	auto& vr = r.second;
	int ls = vl.size(), rs = vr.size();
	int s = min(ls, rs);
	for (int i = 1; i <= s; ++i) {
		ans += vl[ls - i] * vr[rs - i];
	}
}

vec mrgvec2(vec& l, vec& r) {
	int ls = l.size(), rs = r.size();
	for (int i = 1; i <= ls; ++i) {
		r[rs - i] += l[ls - i];
	}

	return move(r);
}

vec mrgvec(vec& l, vec& r) {
	if (l.size() < r.size()) {
		return mrgvec2(l, r);
	} else {
		return mrgvec2(r, l);
	}
}

vec npairs(vec& l, vec& r) {
	int ls = l.size(), rs = r.size();
	int s= min(ls, rs);
	vec res(s, 0);
	for (int i = 1; i <= s; ++i) {
		res[s - i] = l[ls - i] * r[rs - i];
	}

	return move(res);
}

val merg(val& l, val& r) {
	vec advec = npairs(l.first, r.first);
	ad(l, r);
	ad(r, l);
	auto ansl = mrgvec(l.first, r.first), ansr = mrgvec(l.second, r.second);
	int ads = advec.size(), rs = ansr.size();
	int d = ads - rs;
	if (d > 0) {
		ansr.resize(rs = ads, 0);
		for (int i = ads - 1; i >= d; --i) {
			ansr[i] = ansr[i - d];
		}

		fill(ansr.begin(), ansr.begin() + d, 0);
	}

	for (int i = 1; i <= ads; ++i) {
		ansr[rs - i] += advec[ads - i];
	}

	return {move(ansl), move(ansr)};
}

val f[MAXN];

void dfs(int v, int p) {
	f[v] = {{1}, {0}};

	for (int u: e[v]) {
		if (u == p) {
			continue;
		}

		dfs(u, v);
		f[u].first.push_back(0);
		f[u].second.pop_back();
		f[v] = merg(f[v], f[u]);
	}
}

void solve() {
	int n;
	cin >> n;
	ans = 0;

	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}

	dfs(1, 1);
	cout << ans << "\n";
}

int main() {
    solve();
}

