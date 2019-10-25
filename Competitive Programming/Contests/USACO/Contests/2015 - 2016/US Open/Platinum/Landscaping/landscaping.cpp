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
#define FOR(index, start, end) for(int index = start; index < end; index++)
#define RFOR(index, start, end) for(int index = start; index > end; index--)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
int a[100001];
int b[100001];
int A[100001], B[100001], nA, nB;
int C[6000][6000], X, Y, Z;

int main(void)
{
	int i, j, n;

	freopen("landscape.in", "r", stdin);
	freopen("landscape.out", "w", stdout);

	scanf("%d %d %d %d", &n, &X, &Y, &Z);
	for (int i = 0; i<n; i++)
	{
		cin >> a[i] >> b[i];
	}
	FOR(i, 0, n)
	{
		int x = min(a[i], b[i]);
		a[i] -= x;
		b[i] -= x;
	}
	FOR(i, 0, n) {
		while (a[i]>0) { A[++nA] = i; a[i]--; }
		while (b[i]>0) { B[++nB] = i; b[i]--; }
	}

	FOR(j, 0, nB + 1)
	{
		C[0][j] = j*X;
	}
	for (i = 0; i <= nA; i++) C[i][0] = i*Y;

	for (i = 1; i <= nA; i++)
		for (j = 1; j <= nB; j++) {
			C[i][j] = INF;
			C[i][j] = min(C[i][j], C[i][j - 1] + X);
			C[i][j] = min(C[i][j], C[i - 1][j] + Y);
			C[i][j] = min(C[i][j], C[i - 1][j - 1] + Z * abs(A[i] - B[j]));
		}

	printf("%d\n", C[nA][nB]);
	return 0;
}