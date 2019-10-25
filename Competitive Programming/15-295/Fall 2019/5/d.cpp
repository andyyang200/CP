#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b)  qfor(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define ri(x) scanf("%d", &x)
#define ri2(x, y) scanf("%d%d", &x, &y)
#define ri3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define rll(x) scanf("%lld", &x)
#define INF 1000000000
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------
const int MAXN = 2;
ll n = 2;
ll M[MAXN][MAXN], res[MAXN][MAXN], tmp[MAXN][MAXN];
ll start[2][2];
ll MOD = -1;
void mmult(ll A[][MAXN], ll B[][MAXN]) {
	memset(tmp, 0, sizeof(tmp));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < n; ++k)
				tmp[i][j] = ((ll)tmp[i][j] + (ll)A[i][k] % MOD * (ll)B[k][j] % MOD) % MOD;
	memcpy(A, tmp, sizeof(tmp));
}
void mexp(ll ret[][MAXN], ll p) {
	if (!p) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				ret[i][j] = i == j;
		return;
	}
	if (p & 1) {
		mexp(ret, p - 1);
		mmult(ret, M);
		return;
	}
	mexp(ret, p >> 1);
	mmult(ret, ret);
}
int main(){
    ll a1, a2;
    cin >> a1 >> a2;
    ll d;
    cin >> d;
    int l, r;
    cin >> l >> r;
    start[0][0] = a1 + a2;
    start[0][1] = a2;
    start[1][0] = a2;
    start[1][1] = a1;
    M[0][0] = 1;
    M[0][1] = 1;
    M[1][0] = 1;
    M[1][1] = 0;
    ll ans = r;
    FOR(m, l, r + 1){
        start[0][0] = a1 + a2;
        start[0][1] = a2;
        start[1][0] = a2;
        start[1][1] = a1;
        M[0][0] = 1;
        M[0][1] = 1;
        M[1][0] = 1;
        M[1][1] = 0;
        MOD = m;
        mexp(res, d - 1);
        mmult(start, res);
        ll result = start[0][0]; // d + 2 number
        result = (result - a2 % MOD + MOD) % MOD;
        result = (result + MOD) % MOD;
        ans = min(ans, result);
    }
    cout << ans << endl;
}
/*
5 17 40
1500 2000
*/
