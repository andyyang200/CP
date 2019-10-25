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
char grid[100][100];
int main(void)
{
	int n, m;
	cin >> n >> m;
	int sr = -1;
	int sc = -1;
	FOR(i, 0, n) {
		FOR(j, 0, m) {
			cin >> grid[i][j];
			if (grid[i][j] == 'S') {
				sr = i;
				sc = j;
			}
		}
	}
	string s;
	cin >> s;
	int a[] = { 1, 2, 3, 4 };
	int ans = 0;
	do
	{
		int r = sr;
		int c = sc;
		bool good = true;
		FOR(k, 0, s.length()) {
			if (a[s[k] - '0'] == 1) {
				r--;
			}
			if (a[s[k] - '0'] == 2) {
				c++;
			}
			if (a[s[k] - '0'] == 3) {
				r++;
			}
			if (a[s[k] - '0'] == 4) {
				c--;
			}
			if (r < 0 || r >= n || c < 0 || c >= m) {
				good = false;
				break;
			}
			if (grid[r][c] == '#') {
				good = false;
				break;
			}
			if (grid[r][c] == 'E') {
				break;
			}
		}
		if (good && grid[r][c] == 'E') {
			ans++;
		}
	} while (next_permutation(a, a + 4));
	cout << ans << endl;
}