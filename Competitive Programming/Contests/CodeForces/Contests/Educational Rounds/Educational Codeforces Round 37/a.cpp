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
#include <cassert>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
typedef long long ll;
typedef pair<int, int> pii;
int x[1000];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int k;
		cin >> k;
		FOR(i, 0, n) {
			x[i] = false;
		}
		FOR(i, 0, k) {
			int a;
			cin >> a;
			a--;
			x[a] = true;
		}


		int ans = 0;
		FOR(i, 0, n) {
			int m = 10120;
			FOR(j, 0, n) {
				if (x[j]) {
					m = min(m, abs(j - i) + 1);
				}
			}
			ans = max(ans, m);
		}
		cout << ans << endl;

	}

}
