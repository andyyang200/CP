#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", z = " << z << endl
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

struct node {
	int val;
	struct node* C[2];

	node() {
		val = 0;
		C[0] = C[1] = NULL;
	}

	node* getc(int c) {
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
		assert(md >= sl && md < sr);
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
		assert(md >= sl && md < sr);
		return max((C[0] ? C[0]->query(ql, qr, sl, md) : 0),
			(C[1] ? C[1]->query(ql, qr, md + 1, sr) : 0));
	}
};


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


int main(void)
{

}
