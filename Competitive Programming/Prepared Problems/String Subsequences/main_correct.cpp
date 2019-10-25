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
const int MAXL = 60;

ll N;
string S, T;
int L;

ll chars[10][MAXL][MAXL];
ll trs[MAXL][MAXL];

ll res[MAXL][MAXL];

ll tmp[MAXL][MAXL];

// a *= b;
void mult(ll a[MAXL][MAXL], ll b[MAXL][MAXL]) {
	for(int i = 0; i < L; i++) {
		for(int j = 0; j < L; j++) {
			tmp[i][j] = 0;
			for(int k = 0; k < L; k++) {
				tmp[i][j] += a[i][k] * b[k][j];
				tmp[i][j] %= M;
			}
		}
	}
	for(int i = 0; i < L; i++) {
		for(int j = 0; j < L; j++) {
			a[i][j] = tmp[i][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> S >> T;
	L = S.size() + 1;
	FOR(i, 0, L){
		trs[i][i] = 1;
		res[i][i] = 1;
		for(int c = 0; c < 5; c++) {
			chars[c][i][i] = 1;
		}
	}
	FOR(i, 0, S.size()){
		chars[S[i] - 'a'][i][i + 1] ++;
	}
	for(char c : T) {
		mult(trs, chars[c - 'a']);
	}
	while(N) {
		if(N % 2) mult(res, trs);
		N /= 2;
		mult(trs, trs);
	}

	cout << res[0][L - 1] << endl;

}
