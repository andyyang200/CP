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
int grid[100][100];
int main(void)
{
	int n, m;
	scanf("%d%d", &n, &m);
	FOR(i, 0, n) {
		FOR(j, 0, m) {
			scanf("%d", &grid[i][j]);
		}
	}
	ll ans = 0;
	FOR(i, 0, n) {
		int a = 0;
		int b = 0;
		FOR(j, 0, m) {
			if (grid[i][j] == 0) {
				a++;
			}
			else {
				b++;
			}
		}
		ans += ((ll)1 << a) - 1;
		ans += ((ll)1 << b) - 1;
		ans -= a;
		ans -= b;
	}
	FOR(j, 0, m) {
		int a = 0;
		int b = 0;
		FOR(i, 0, n) {
			if (grid[i][j] == 0) {
				a++;
			}
			else {
				b++;
			}
		}
		ans += ((ll)1 << a) - 1;
		ans += ((ll)1 << b) - 1;
		ans -= a;
		ans -= b;
	}
	ans += n * m;
	cout << ans << endl;


}