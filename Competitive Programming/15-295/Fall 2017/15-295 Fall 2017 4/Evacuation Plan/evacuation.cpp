//Andrew Yang
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>	
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <climits>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
typedef long long ll;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
int X[4005], Y[4005], team[4005], SX[4005], SY[4005];
int F[4005][4005][2];
short FF[4005][4005][2];
bitset<4005> assign[4005][2];
const ll BASE = (1 << 14) - 1;
ll getval(int a, int b, int c) {
	ll f = F[a][b][c];
	return (f << 14) + FF[a][b][c];
}
void store(int a, int b, int c, ll v) {
	F[a][b][c] = v >> 14;
	FF[a][b][c] = v & BASE;
}
bool cmpX(int a, int b) {
	return X[a] < X[b];
}
bool cmpY(int a, int b) {
	return Y[a] < Y[b];
}
int main() {
	freopen("evacuation.in", "r", stdin);
	freopen("evacuation.out", "w", stdout);
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &X[i]);
		SX[i] = i;
	}
	sort(SX + 1, SX + N + 1, cmpX);
	int M;
	scanf("%d", &M);
	for (int i = 1; i <= M; ++i) {
		scanf("%d", &Y[i]);
		SY[i] = i;
	}
	sort(SY + 1, SY + M + 1, cmpY);
	for (int j = 1; j <= M; ++j) F[0][j][0] = F[0][j][1] = INF;
	F[0][1][0] = 0;
	for (int i = 1; i <= N; ++i) {
		F[i][0][0] = F[i][0][1] = INF;
		for (int j = 1; j <= M; ++j) {
			FF[i][j][0] = FF[i][j - 1][1];
			F[i][j][0] = F[i][j - 1][1];
			ll v = getval(i - 1, j, 0) + abs(X[SX[i]] - Y[SY[j]]);
			if (v < getval(i, j, 0)) {
				store(i, j, 0, v);
				assign[i][0][j] = true;
			}
			store(i, j, 1, v);
			assign[i][1][j] = true;
		}
	}
	printf("%lld\n", getval(N, M, 1));
	int i = N, j = M;
	int t = 1;
	while (i) {
		if (assign[i][t][j]) {
			t = 0;
			team[SX[i]] = SY[j];
			--i;
		}
		else {
			t = 1;
			--j;
		}
	}
	for (int i = 1; i <= N; ++i) printf("%d ", team[i]);
}