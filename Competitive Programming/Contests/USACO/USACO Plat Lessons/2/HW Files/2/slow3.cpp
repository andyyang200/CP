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
			return 0;
		}
		int md = ((sl + sr < 0) ? (sl + sr - 1) / 2 : (sl + sr) / 2);
		return max((C[0] ? C[0]->query(ql, qr, sl, md) : 0),
			(C[1] ? C[1]->query(ql, qr, md + 1, sr) : 0));
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
			return 0;
		}
		int md = ((sl + sr < 0) ? (sl + sr - 1) / 2 : (sl + sr) / 2);
		return max((C[0] ? C[0]->query(qxl, qxr, qyl, qyr, sl, md) : 0),
			(C[1] ? C[1]->query(qxl, qxr, qyl, qyr, md + 1, sr) : 0));
	}
};

int a[200005];
int b[200005];

int main(void)
{
    int n;
    scanf("%d", &n);
    vector<int> v;
    FOR(i, 0, n){
        scanf("%d", &a[i]);
        v.push_back(a[i]);
    }
    FOR(i, 0, n){
        scanf("%d", &b[i]);
        v.push_back(b[i]);
    }
    sort(v.begin(), v.end());
    FOR(i, 0, n){
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
    }
    FOR(i, 0, n){
        b[i] = lower_bound(v.begin(), v.end(), b[i]) - v.begin();
    }
    int ans = 0;
    node2 root;
    FOR(i, 0, n){
        int x = root.query(0, a[i] - 1, 0, b[i] - 1, 0, 2 * n) + 1;
        root.update(a[i], b[i], x, 0, 2 * n);
        ans = max(ans, x);
    }
    cout << ans << endl;
}


