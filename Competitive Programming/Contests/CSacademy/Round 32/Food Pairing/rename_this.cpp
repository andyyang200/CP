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
ll a[50];
ll b[1000][50];
int main(void)
{
	int n;
	cin >> n;
	FOR(i, 0, n) {
		cin >> a[i];
	}
	int m;
	cin >> m;
	FOR(i, 0, m) {
		FOR(j, 0, n) {
			cin >> b[i][j];
		}
	}
	ll ans = 0;
	FOR(i, 0, m) {
		FOR(j, i + 1, m) {
			ll dishes = 1e18;
			FOR(k, 0, n) {
				if (b[i][k] + b[j][k] != 0)
					dishes = min(dishes, a[k] / (b[i][k] + b[j][k]));
			}
			ans = max(ans, dishes);
		}
	}
	cout << ans << endl;
}