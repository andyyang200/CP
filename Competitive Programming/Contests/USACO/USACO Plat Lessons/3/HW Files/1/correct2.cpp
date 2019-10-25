#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
int n, B;
int S[101000][210], D[101000], Mod = 1000000007, w[101000];
map<int, int>Map[101000];
void Put(int x, int d, int c) {
	Map[d][x%d] = (Map[d][x%d] + c) % Mod;
	if (d <= 200) {
		S[x + d][d] = (S[x + d][d] + c) % Mod;
	}
	else {
		for (int i = x + d; i <= n; i += d)D[i] = (D[i] + c) % Mod;
	}
}
int main() {
	int i, j;
	scanf("%d%d", &n, &B);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	D[1] = 1;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= 200; j++) {
			if (i >= j)S[i][j] = (S[i][j] + S[i - j][j]) % Mod;
			D[i] = (D[i] + S[i][j]) % Mod;
		}
		int c = D[i] - Map[w[i]][i%w[i]];
		Put(i, w[i], c);
		if (i == 1 && B != w[i]) Put(1, B, 1);
	}
	printf("%d\n", D[n]);
}
