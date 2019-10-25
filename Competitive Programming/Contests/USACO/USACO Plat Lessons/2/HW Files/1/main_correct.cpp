#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", z = " << z << endl
#define INF 1000000010
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

//Main Solution

bool overlap(int a, int b, int c, int d){
    if (b < c || a > d){
        return false;
    }
    return true;
}

struct node1 { // inside
	int val;
	struct node1* C[2];

	node1() {
		val = 0;
		C[0] = C[1] = NULL;
	}

	node1* getc(int c) {
		if (!C[c]) {
			C[c] = new node1;
		}
		return C[c];
	}

	void update(int i, int v, int sl, int sr) {
		if (sl == sr) {
			val = v;
			return;
		}
		int md = ((sl + sr < 0) ? (sl + sr - 1) / 2 : (sl + sr) / 2);
		if (i <= md) {
			getc(0)->update(i, v, sl, md);
		}
		else {
			getc(1)->update(i, v, md + 1, sr);
		}
		val = max((C[0] ? C[0]->val : 0),
			(C[1] ? C[1]->val : 0));
	}

	int query(int ql, int qr, int sl, int sr) {
		if (sl >= ql && sr <= qr) {
			return val;
		}
		else if (sr < ql || sl > qr) {
			return -INF;
		}
		int md = ((sl + sr < 0) ? (sl + sr - 1) / 2 : (sl + sr) / 2);
		return max((C[0] ? C[0]->query(ql, qr, sl, md) : (overlap(ql, qr, sl, md) ? 0 : -INF)),
			(C[1] ? C[1]->query(ql, qr, md + 1, sr) : (overlap(ql, qr, md + 1, sr) ? 0 : -INF)));
	}
};

struct node2 { // outside
	node1* val;
	struct node2* C[2];

	node2() {
		val = new node1();
		C[0] = C[1] = NULL;
	}

	node2* getc(int c) {
		if (!C[c]) {
			C[c] = new node2;
		}
		return C[c];
	}

	void update(int x, int y, int v, int sl, int sr) {
		if (sl == sr) {
			val->update(y, v, -INF, INF);
			return;
		}
		int md = ((sl + sr < 0) ? (sl + sr - 1) / 2 : (sl + sr) / 2);
		if (x <= md) {
			getc(0)->update(x, y, v, sl, md);
		}
		else {
			getc(1)->update(x, y, v, md + 1, sr);
		}
		int ans = max((C[0] ? C[0]->val->query(y, y, -INF, INF) : 0),
			(C[1] ? C[1]->val->query(y, y, -INF, INF) : 0));
		val->update(y, ans, -INF, INF);
	}

	int query(int qxl, int qxr, int qyl, int qyr, int sl, int sr) {
		if (sl >= qxl && sr <= qxr) {
			return val->query(qyl, qyr, -INF, INF);
		}
		else if (sr < qxl || sl > qxr) {
			return -INF;
		}
		int md = ((sl + sr < 0) ? (sl + sr - 1) / 2 : (sl + sr) / 2);
		return max((C[0] ? C[0]->query(qxl, qxr, qyl, qyr, sl, md) : (overlap(qxl, qxr, sl, md) ? 0 : -INF)),
			(C[1] ? C[1]->query(qxl, qxr, qyl, qyr, md + 1, sr) : (overlap(qxl, qxr, md + 1, sr) ? 0 : -INF)));
	}
};


int main(void)
{
	int q;
	scanf("%d", &q);
	node2 root;
	FOR(i, 0, q) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int x, y, v;
			scanf("%d%d%d", &x, &y, &v);
			root.update(x, y, v, -INF, INF);
		}
		else {
			int x1, x2, y1, y2;
			scanf("%d%d%d%d", &x1, &x2, &y1, &y2);
			int ans = root.query(x1, x2, y1, y2, -INF, INF);
			printf("%d\n", ans);
		}
	}
}




