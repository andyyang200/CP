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
int ans[100][100];
int main(void)
{
	int n, k;
	scanf("%d%d", &n, &k);
	if (k > n*n) {
		cout << -1 << endl;
		return 0;
	}
	FOR(i, 0, n) {
		FOR(j, 0, n) {
			if (ans[i][j] != 1 && k > 0) {
				if (i == j) {
					ans[i][j] = 1;
					k--;
				}
				else if (k > 1) {
					ans[i][j] = 1;
					ans[j][i] = 1;
					k -= 2;
				}
			}
		}
	}

	FOR(i, 0, n) {
		if (k > 0 && ans[i][i] != 1) {
			ans[i][i] = 1;
			k--;
		}
	}

	FOR(i, 0, n) {
		FOR(j, 0, n) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}