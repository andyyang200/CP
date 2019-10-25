#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b)  qfor(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------

int overlap(int a, int b, int c, int d) {
	if (b < c || a > d) {
		return -1;
	}
	int l = max(a, c);
	int r = min(b, d);
	return r - l + 1;
}

struct node {
	pii val;
	int lazy;
	struct node* C[2];

	node(int sl, int sr) {
		val = { 0, sr - sl + 1 };
		lazy = 0;
		C[0] = C[1] = NULL;
	}

	node* getc(int c, int sl, int sr) {
		if (!C[c]) {
			C[c] = new node(sl, sr);
		}
		return C[c];
	}
	pii f(pii a, pii b) {
		if (a.first == b.first) {
			return { a.first, a.second + b.second };
		}
		return min(a, b);
	}
	void update(int ql, int qr, int v, int sl, int sr) {
		int md = ((sl + sr < 0) ? (sl + sr - 1) / 2 : (sl + sr) / 2);
		if (lazy) {
			val.first += lazy;
			if (sl != sr) {
				getc(0, sl, md)->lazy += lazy;
				getc(1, md + 1, sr)->lazy += lazy;
			}
			lazy = 0;
		}
		if (sl >= ql && sr <= qr) {
			val.first += v;
			if (sl != sr) {
				getc(0, sl, md)->lazy += v;
				getc(1, md + 1, sr)->lazy += v;
			}
			return;
		}
		if (sl > qr || sr < ql) {
			return;
		}

		getc(0, sl, md)->update(ql, qr, v, sl, md);
		getc(1, md + 1, sr)->update(ql, qr, v, md + 1, sr);
		val = f(C[0]->val, C[1]->val);
	}

	pii query(int ql, int qr, int sl, int sr) {
		int md = ((sl + sr < 0) ? (sl + sr - 1) / 2 : (sl + sr) / 2);
		if (lazy) {
			val.first += lazy;
			if (sl != sr) {
				getc(0, sl, md)->lazy += lazy;
				getc(1, md + 1, sr)->lazy += lazy;
			}
			lazy = 0;
		}
		if (sl >= ql && sr <= qr) {
			return val;
		}
		else if (sr < ql || sl > qr) {
			return { INF, INF };
		}
		int loverlap = overlap(ql, qr, sl, md);
		int roverlap = overlap(ql, qr, md + 1, sr);
		pii l = C[0] ? C[0]->query(ql, qr, sl, md) : (loverlap == -1 ? make_pair(INF, 0) : make_pair(0, loverlap));
		pii r = C[1] ? C[1]->query(ql, qr, md + 1, sr) : (roverlap == -1 ? make_pair(INF, 0) : make_pair(0, roverlap));
		return f(l, r);
	}
};
node* root;

struct event {
	int x, y1, y2, type;
	event(int a, int b, int c, int d) {
		x = a;
		y1 = b;
		y2 = c;
		type = d;
	}

	bool operator<(const event o) const {
		return x < o.x;
	}
};

int main() {
	int n;
	cin >> n;
	vector<event> v;
	FOR(i, 0, n) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		int x1 = min(a, c);
		int y1 = min(b, d);
		int x2 = max(a, c);
		int y2 = max(b, d);
		v.push_back(event(x1, y1, y2, 1));
		v.push_back(event(x2, y1, y2, 2));
	}
	sort(v.begin(), v.end());
	node* root = new node(-INF, INF);
	ll ans = 0;
	FOR(i, 0, v.size()) {
		if (i > 0) {
			pii p = root->query(-INF, INF, -INF, INF);
			if (p.first != 0) {
				p.second = 2 * INF + 1;
			}
			int u = 2 * INF + 1 - p.second;
			ans += (ll)(v[i].x - v[i - 1].x) * u;
		}
		if (v[i].type == 1) {
			root->update(v[i].y1, v[i].y2 - 1, 1, -INF, INF);
		}
		else {
			root->update(v[i].y1, v[i].y2 - 1, -1, -INF, INF);
		}
	}
	cout << ans << endl;
}
