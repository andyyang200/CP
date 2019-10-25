//Andrew Yang
//accepted
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
int a[1005][1005];
int r[1005];
int c[1005];
int main(void)
{
	int n;
	cin >> n;
	FOR(i, 0, n) {
		FOR(j, 0, n) {
			scanf("%d", &a[i][j]);
			r[i] += a[i][j];
			c[j] += a[i][j];
		}
	}
	int ans = 0;
	FOR(i, 0, n) {
		ans = max(ans, r[i]);
		ans = max(ans, c[i]);
	}
	FOR(i, 0, n) {
		FOR(j, 0, n) {
			int d = min(ans - r[i], ans - c[j]);
			a[i][j] += d;
			r[i] += d;
			c[j] += d;
		}
	}
	FOR(i, 0, n) {
		FOR(j, 0, n) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

}