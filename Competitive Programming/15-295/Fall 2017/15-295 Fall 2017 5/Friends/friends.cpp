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
int f[100][100];
int main(void)
{
	int n, x;
	cin >> n >> x;
	x--;
	FOR(i, 0, n) {
		int j;
		cin >> j;
		FOR(asd, 0, j) {
			int t;
			cin >> t;
			t--;
			f[i][t] = 1;
			f[t][i] = 1;
		}
	}
	set<int> s;
	FOR(i, 0, n) {
		if (i == x) {
			continue;
		}
		bool good = false;
		FOR(j, 0, n) {
			if (j == x || j == i) {
				continue;
			}
			if (f[i][j] && f[j][x]) {
				good = true;
				break;
			}
		}
		if (good && !f[i][x] && !f[x][i]) {
			s.insert(i);
		}
		
	}
	cout << s.size() << endl;
	for (int x : s) {
		cout << x + 1 << endl;
	}
}
/*
4 2
1 2
2 1 3
2 4 2
1 3

*/

/*
4 1
3 4 3 2
3 1 3 4
3 1 2 4
3 1 2 3
*/