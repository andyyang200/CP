//Andrew Yang
//Accepted
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
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
int t[100005];
int d[100005];
int a[2000005];
int main(void)
{
	int n, s;
	scanf("%d%d", &n, &s);
	FOR(i, 0, n) {
		scanf("%d%d", &t[i], &d[i]);
	}
	FOR(i, 0, n - 1) {
		FOR(j, t[i], t[i + 1]) {
			a[j] = d[i];
		}
	}
	FOR(i, t[n - 1], 2000005) {
		a[i] = d[n - 1];
	}
	int j = -1;
	int sum = 0;
	double ans = INF;
	ll x = -1;
	ll y = -1;
	FOR(i, 0, 1000001) {
			while (sum + a[j + 1] < s) {
			j++;
			sum += a[j];
		}
		double time = j - i + 1 + (double)(s - sum) / a[j + 1];
		if (time + 1e-9 < ans) {
			ans = time;
			y = a[j + 1];
			x = (j - i + 1) * y + (s - sum);
		}
		sum -= a[i];
	}
	j = 2000001;
	sum = 0;
	RFOR(i, 2000000, -1) {
		while (j > 0 && sum + a[j - 1] < s) {
			j--;
			sum += a[j];
		}
		if (j == 0)
			break;
		double time = i - j + 1 + (double)(s - sum) / a[j - 1];
		if (time + 1e-9 < ans) {
			ans = time;
			y = a[j - 1];
			x = (i - j + 1) * y + (s - sum);
		}
		sum -= a[i];
	}
	FOR(i, 2, x + 1) {
		while (x % i == 0 && y % i == 0) {
			x /= i;
			y /= i;
		}
	}
	cout << x << "/" << y << endl;
}
/*
3 3
0 1
3 2
4 5
*/