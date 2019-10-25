//Andrew Yang
#define _CRT_SECURE_NO_WARNINGS
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
#define M 1000000007
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

typedef long long ll;
typedef pair<int, int> pii;
map<string, vector<string>> m;

int a[1000005];
int main(void)
{
	int n, m, k;
	cin >> n >> m >> k;
	FOR(i, 0, n) {
		int x;
		scanf("%d", &x);
		a[x] = true;
	}
	int i = 1;
	int j = m;
	int cnt = 0;
	int ans = 0;
	FOR(x, i, j + 1) {
		if (a[x]) {
			if (cnt == k - 1) {
				ans++;
				a[x] = false;
			}
			else {
				cnt++;
			}
		}
	}
	while (j <= 1000000) {
		if (a[i]) {
			cnt--;
		}
		i++;
		j++;
		if (a[j]) {
			if (cnt == k - 1) {	
				ans++;
				a[j] = false;
			}
			else {
				cnt++;
			}
		}
	}
	cout << ans << endl;
}