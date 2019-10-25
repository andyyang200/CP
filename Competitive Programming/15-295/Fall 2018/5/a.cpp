#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------
long double d[1000][1000];

int r[1000];
int x[1000];
int y[1000];
int n, k;
bool check(int i, int j){
    int dx = x[i] - x[j];
    int dy = y[i] - y[j];
    int x = k + r[i] + r[j];
    return dx * dx + dy * dy <= x * x;
}
int dist(int i, int j){
    int dx = x[i] - x[j];
    int dy = y[i] - y[j];
    return dx * dx + dy * dy;
}
ld dist2(int i, int j){
    return max(0.0, sqrt(dist(i, j)) - r[i] - r[j]);
}
bool cmp(ll a, ll b, ll c){
  if(c < 0) return false;
  ll x = c * c - a - b;
  return (x >= 0 && 4 * a * b <= x * x);
}
int main() {
	cin >> n >> k;
	cin >> x[n + 1];
	cin >> y[n + 1];
	FOR(i, 1, n + 1) {
		scanf("%d%d%d", &x[i], &y[i], &r[i]);
	}
	FOR(i, 0, n + 2) {
		FOR(j, 0, n + 2) {
			int dx = x[i] - x[j];
			int dy = y[i] - y[j];
			d[i][j] = dist2(i, j);
            if(!cmp(dist(i, j), 0, k + r[i] + r[j])){
                d[i][j] = -10;
            }
		}
	}
	FOR(k, 0, n + 1){
        FOR(i, 0, n + 1){
            FOR(j, 0, n + 1){
                if (d[i][k] < -5 || d[k][j] < -5) continue;
                if (d[i][j] < -5 || d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
	}
	ld ans = -10;
	FOR(i, 0, n + 1){
	    FOR(j, 0, n + 1){
            if(d[0][i] < -5) continue;
            if(d[0][j] < -5) continue;

            int d1 = dist(i, n + 1);
            int d2 = dist(j, n + 1);
            if (!cmp(d1, d2, k+r[i]+r[j])){
                continue;
            }
            ld x = d[0][i] + d[0][j] + dist2(i, n + 1) + dist2(j, n + 1);
            if (ans < -5 || ans > x ){
                ans = x;
            }
        }
	}
    if (ans < -5){
        cout << -1 << endl;
        return 0;
    }
	printf("%.15Lf\n", ans);
}
/*
0 1 0 0

0 20 1 2

0 10 20 20

2 2 7 4
6 2 2
2 2 1

1 2 3 3
0 3 2

*/
