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
ll a, b, c, d, e, f, F[1000001], G[1000001], H[1000001];
ll getF(int n);
ll getG(int n);
ll getF(int n)
{
	if (F[n] != -1)
	{
		return F[n];
	}
	ll ret = 0;
	ret += (a * getF(n - 1)) % M;
	ret += (b * (getG(n - 2))) % M;
	return F[n] = ret;
}
ll getG(int n)
{
	if (G[n] != -1)
	{
		return G[n];
	}
	ll ret = 0;
	ret += (c * getG(n - 1)) % M;
	ret += (d * (getF(n - 2))) % M;
	return G[n] = ret;
}
int main()
{
	FOR(i, 0, 1000000)
	{
		F[i] = -1;
		G[i] = -1;
	}
	cin >> a >> b >> c >> d >> e >> f >> F[0] >> F[1] >> G[0] >> G[1];
	H[0] += e * getF(0) % M;
	H[0] += f * getG(0) % M;
	FOR(i, 1, 1000000)
	{
		H[i] += e * getF(i) % M;
		H[i] += f * getG(i) % M;
		H[i] += H[i - 1];
		H[i] %= M;
	}
	int q;
	scanf("%d", &q);
	FOR(i, 0, q)
	{
		int x;
		scanf("%d", &x);
		if (x <= 1000000)
		{
			cout << H[x] << endl;
		}
	}
}