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
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
int a[200005];
ll p[200005];
int main(void)
{
	int n, k;
	scanf("%d%d", &n, &k);
	FOR(i, 0, n) {
		scanf("%d", &a[i]);
	}
	p[0] = a[0];
	FOR(i, 1, n) {
		p[i] = a[i] + p[i - 1];
	}
	double ans = 0;
	FOR(i, 0, n) {
		if (i + k - 1 < n) {
			ll sum = p[i + k - 1];
			if (i > 0) {
				sum -= p[i - 1];
			}
			ans += (double)sum / (n - k + 1);
		}
	}
	printf("%.15f\n", ans);
}