#include <iostream>
#include <stdio.h>
#include <vector>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int n, m, k, lim;
int A[752][752];
int index[752][752];
int C[600002];
int first[600002];

long long int BIT[600002];
long long int mod = 1000000007;
long long int DP[752][752], sum[752][752], T[6000002];

void update(int x, long long int val){
	for (; x <= lim; x += (x & -x)){
		BIT[x] += val;
		BIT[x] %= mod;
	}
}

long long int q(int x){
	if (x == 0)
		return 0;

	long long int ret = 0;
	for (; x; x -= (x & -x)){
		ret += BIT[x];
		ret %= mod;
	}
	return ret;
}

long long int query(int val, int ind){
	long long int ret = q(ind), aux = q(first[val] - 1);
	return ((ret + mod) - aux) % mod;
}

int main(){

	freopen("hopscotch.in", "r", stdin);
	freopen("hopscotch.out", "w", stdout);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> A[i][j];

	for (int j = 1; j <= m; j++)
		for (int i = n; i > 0; i--)
			index[i][j] = ++C[A[i][j]];

	first[1] = 1; 
	lim = n * m;
	for (int i = 2; i <= k; i++)
		first[i] = first[i - 1] + C[i - 1];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			index[i][j] += first[A[i][j]] - 1;

	DP[n][m] = 1;

	for (int i = n; i > 0; i--)
	{
		for (int j = m - 1; j > 0; j--)
		{
			DP[i][j] = (sum[i + 1][j + 1]) % mod;
			DP[i][j] = ((DP[i][j] + mod) - T[A[i][j]]) % mod;
			DP[i][j] = (DP[i][j] + query(A[i][j], index[i][j])) % mod;
		}
		for (int j = m; j > 0; j--)
		{
			sum[i][j] = (sum[i + 1][j] + sum[i][j + 1] + DP[i][j]) % mod;
			sum[i][j] = ((sum[i][j] + mod) - sum[i + 1][j + 1]) % mod;

			update(index[i][j], DP[i][j]);

			T[A[i][j]] += DP[i][j];
			T[A[i][j]] %= mod;
		}
	}
	cout << DP[1][1] << "\n";

	return 0;

}