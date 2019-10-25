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
map<pii, int> m;
int main(void)
{
    int q;
	scanf("%d", &q);
	FOR(i, 0, q) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int x, y, v;
			scanf("%d%d%d", &x, &y, &v);
			m[{x, y}] = v;
		}
		else {
			int x1, x2, y1, y2;
			scanf("%d%d%d%d", &x1, &x2, &y1, &y2);
			int cnt = 0;
			int ans = -INF;
			for(auto p : m){
                int x = p.first.first;
                int y = p.first.second;
                if (x1 <= x && x <= x2 && y1 <= y && y <= y2){
                    ans = max(ans, p.second);
                    cnt++;
                }
			}
			ll a = (ll)(x2 - x1 + 1) * (y2 - y1 + 1);
			if (cnt < a){
                ans = max(ans, 0);
			}
			printf("%d\n", ans);
		}
	}
}


