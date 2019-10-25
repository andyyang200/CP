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
// a *= b
ll temp[MAXL][MAXL];

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
				tmp[i][j] %= M;
			}
		}
	}
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++) {
			a[i][j] = tmp[i][j];
		}
	}
}

int main(){

}

