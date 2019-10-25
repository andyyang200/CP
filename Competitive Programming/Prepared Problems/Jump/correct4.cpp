#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int A[100005], F[100005];
const int MOD = 1000000007;
int main() {
	int N, h;
	scanf("%d%d", &N, &h);
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
	F[N] = 1;
	for (int i = N - 1; i >= 1; --i) {
		for (int j = i + A[i]; j <= N; j += A[i]) {
			(F[i] += F[j]) %= MOD;
			if (A[j] == A[i]) break;
		}
		if (i == 1 && h != A[1]) {
			for (int j = 1 + h; j <= N; j += h) {
				(F[1] += F[j]) %= MOD;
				if (A[j] == h) break;
			}
		}
	}
	printf("%d\n", F[1]);
}
