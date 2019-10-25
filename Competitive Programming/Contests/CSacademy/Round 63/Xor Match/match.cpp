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
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
int a[1005];
int b[1005];
int main(void)
{
	int n, m;
	cin >> n >> m;
	FOR(i, 0, n) {
		cin >> a[i];
	}
	FOR(i, 0, m) {
		cin >> b[i];
	}
	int ans = 0;
	FOR(j, 0, m - n + 1) {
		bool good = true;
		FOR(i, 0, n) {
			if (a[i] + b[i + j] != 1) {
				good = false;
				break;
			}
		}
		if (good) {
			ans++;
		}
	}
	cout << ans << endl;
}