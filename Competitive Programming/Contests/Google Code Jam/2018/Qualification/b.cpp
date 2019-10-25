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


int a[100005];
int b[100005];
int c[100005];
int main(void)
{
	int tests;
	scanf("%d", &tests);
	FOR(test, 1, tests + 1) {
		int n;
		scanf("%d", &n);
		int i = 0;
		int j = 0;
		FOR(k, 0, n) {
			if (k % 2 == 0) {
				scanf("%d", &a[i++]);
			}
			else {
				scanf("%d", &b[j++]);
			}
		}
		sort(a, a + i);
		sort(b, b + j);
		FOR(k, 0, i) {
			c[2 * k] = a[k];
		}
		FOR(k, 0, j) {
			c[2 * k + 1] = b[k];
		}
		int ans = -1;
		FOR(k, 0, n - 1) {
			if (c[k] > c[k + 1]) {
				ans = k;
				break;
			}
		}
		if (ans == -1) {
			printf("Case #%d: OK\n", test);
		}
		else {
			printf("Case #%d: %d\n", test, ans);
		}
	}
}


