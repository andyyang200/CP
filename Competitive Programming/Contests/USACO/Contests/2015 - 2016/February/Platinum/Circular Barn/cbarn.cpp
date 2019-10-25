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
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
#define MAXN 1010
#define MAXK 10
#define INF 0x3FFFFFFFFFFFFFFFLL

int rot;
int N, K;
long long A[MAXN];
long long DP[MAXK][MAXN];
long long WSUM[MAXN][MAXN];

int madd(int x, int y) 
{
	x += y;
	if (x >= N) 
	{
		x -= N;
	}
	return x;
}

long long wsum(int a, int b) 
{
	return WSUM[madd(a, rot)][madd(b, N - a)];
}

void solve(int k, int ia, int ib, int ja, int jb) 
{
	if (ia == ib) 
	{
		return;
	}

	int i = (ia + ib) / 2;
	int arg_j = -1;

	DP[k][i] = INF;
	for (int j = max(i + 1, ja); j < jb; j++) 
	{
		long long v = wsum(i, j) + DP[k - 1][j];
		if (v < DP[k][i]) 
		{
			arg_j = j;
			DP[k][i] = v;
		}
	}

	solve(k, ia, i, ja, arg_j + 1);
	solve(k, i + 1, ib, arg_j, jb);
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) 
	{
		cin >> A[i];
	}
	reverse(A, A + N);

	for (int i = 0; i < N; i++) 
	{
		long long sm = 0;
		for (int j = 1; j <= N; j++) 
		{
			WSUM[i][j] = WSUM[i][j - 1] + sm;
			sm += A[madd(i, j - 1)];
		}
	}

	long long result = INF;
	memset(DP, 0x3F, sizeof(DP));
	DP[0][N] = 0;
	for (rot = 0; rot < N; rot++) 
	{
		for (int i = 1; i <= K; i++) 
		{
			solve(i, 0, N, 1, N + 1);
		}
		result = min(result, DP[K][0]);
	}
	cout << result << endl;
}