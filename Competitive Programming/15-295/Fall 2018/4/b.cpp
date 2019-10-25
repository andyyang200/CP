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
#define MOD 1000000009
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------

#define MAXL 257
int grid[10][10];
int L;
int n, m;

ll trs[MAXL][MAXL];

ll res[MAXL];

ll tmp[MAXL][MAXL];

void mult1(ll a[MAXL], ll b[MAXL][MAXL]){
    FOR(i, 0, L){
        tmp[0][i] = 0;
        FOR(j, 0, L){
            tmp[0][i] += a[j] * b[i][j];
            tmp[0][i] %= MOD;
        }
    }
    FOR(i, 0, L){
        a[i] = tmp[0][i];
    }
}

void mult2(ll a[MAXL][MAXL], ll b[MAXL][MAXL]) {
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++) {
			tmp[i][j] = 0;
			for (int k = 0; k < L; k++) {
				tmp[i][j] += a[i][k] * b[k][j];
				tmp[i][j] %= MOD;
			}
		}
	}
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++) {
			a[i][j] = tmp[i][j];
		}
	}
}

bool can(int mask1, int mask2) {
	mask2 <<= (2 * n);
	mask1 += mask2;
	FOR(i, 0, 6){
        FOR(j, 0, 6){
            grid[i][j] = 0;
        }
	}
	FOR(i, 0, n) {
		FOR(j, 0, 3) {
			grid[i][j] = mask1 & (1 << (j * n + i));
		}
	}
	bool bad = false;
	FOR(i, 0, n) {
		FOR(j, 0, 3) {
			if (grid[i][j] && grid[i + 1][j + 2]) bad = true;
			if (grid[i][j] && grid[i + 2][j + 1]) bad = true;
		}
	}
	FOR(i, 2, n) {
		FOR(j, 0, 3) {
			if (grid[i][j] && grid[i - 2][j + 1]) bad = true;

		}
	}
	FOR(i, 1, n) {
		FOR(j, 0, 3) {
			if (grid[i][j] && grid[i - 1][j + 2]) bad = true;
		}
	}
	return !bad;
}
ll calc(){
    FOR(mask1, 0, L) {
		res[mask1] = can(mask1, 0);
	}
    FOR(i, 0, L){
        FOR(j, 0, L){
            trs[i][j] = 0;
        }
    }
	FOR(mask1, 0, L) {
		FOR(mask2, 0, 1 << n) {
			if (can(mask1, mask2)) {
				int endmask = (mask1 >> n) + (mask2 << n);
				trs[endmask][mask1]++;
			}
		}
	}

	m -= 2;
	while (m) {
		if (m % 2) mult1(res, trs);
		m /= 2;
		mult2(trs, trs);
	}

	ll ans = 0;
	FOR(i, 0, L) {
		ans += res[i];
		ans %= MOD;
	}
	return ans;
}

ll powmod(ll a, ll p, ll m) {
    ll ans = 1;
    while(p) {
        if(p % 2 == 1){
            ans *= a;
            ans %= m;
            p--;
        }
        a *= a;
        a %= m;
        p /= 2;
    }
    return ans % m;
}
int main() {
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        if (m == 1){
            cout << (1 << n) << endl;
            continue;
        }
        if (n == 1){
            cout << powmod(2, m, MOD) << endl;
            continue;
        }
        L = 1 << (2 * n);
        cout << calc() << endl;
    }


}
