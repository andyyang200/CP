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

const int MAXN = 1000015;
int A[MAXN];
vector<int> L[MAXN];
int main() {
	int n;
	scanf("%d", &n);
	FOR(i, 0, n) {
		scanf("%d", &A[i]);
	}
	n = unique(A, A + n) - A;
	map<int, int> cnt;
	FOR(i, 0, n) {
		++cnt[A[i]];
	}
	vector<int> B;
	int ans = n - 1;
	FOR(i, 0, n) {
		B.push_back(A[i]);
		if (cnt[A[i]] == 1) {
			B.push_back(A[i]);
		}
	}
	int v = 0;
	for (auto &x : cnt) x.second = v++;
	n = B.size();
	FOR(i, 0, n) B[i] = cnt[B[i]];
	FOR(i, 0, n - 1) {
		if (B[i + 1] == B[i] + 1) {
			L[B[i]].push_back(i);
		}
	}
	int mx = 0, mx2 = 0, mxi = -2;
	FOR(i, 0, v) {
		if (L[i].empty()) continue;
		int nmx = mx, nmx2 = mx2;
		int nmxi = mxi;
		for (int x : L[i]) {
			int val;
			if (mxi != x - 1) val = mx;
			else val = mx2;
			++val;
			if (val > nmx) {
				nmx2 = nmx;
				nmx = val;
				nmxi = x;
			} else if (val > nmx2) {
				nmx2 = val;
			}
		}
		mx = nmx;
		mx2 = nmx2;
		mxi = nmxi;
	}
	ans -= mx;
	printf("%d\n", ans);
}
