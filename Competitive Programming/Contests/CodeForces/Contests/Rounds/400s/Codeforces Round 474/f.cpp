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
			C[c] = new node;
		}
		return C[c];
	}

	void add(int x, int v, int lo, int hi) {
		if (hi - lo == 1) {
			val = v;
			return;
		}
		int md = (lo + hi) / 2;
		if (x < md) {
			getc(0)->add(x, v, lo, md);
		}
		else {
			getc(1)->add(x, v, md, hi);
		}
		val = max((C[0] ? C[0]->val : 0),
			(C[1] ? C[1]->val : 0));
	}

	int query(int a, int b, int lo, int hi) {
		if (a <= lo && hi <= b) {
			return val;
		}
		else if (hi <= a || b <= lo) {
			return 0;
		}
		int md = (lo + hi) / 2;
		return max((C[0] ? C[0]->query(a, b, lo, md) : 0),
			(C[1] ? C[1]->query(a, b, md, hi) : 0));
	}
};
node incoming[100005];
int main(){
	int n, m;
	cin >> n >> m;
	int ret = 0;
	FOR(i, 0, m){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		u--;
		v--;
		int ans = incoming[u].query(0, w, 0, 100000) + 1;
		incoming[v].add(w, ans, 0, 100000);
		ret = max(ans, ret);
	}
	cout << ret << endl;
}
