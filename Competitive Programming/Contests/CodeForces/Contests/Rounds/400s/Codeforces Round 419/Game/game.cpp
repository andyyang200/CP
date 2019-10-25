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
int g[500][500];
int main(void)
{
	int n, m;
	cin >> n >> m;
	FOR(i, 0, n) {
		FOR(j, 0, m) {
			scanf("%d", &g[i][j]);
		}
	}
	if (m > n) {
		string ans = "";
		int cnt = 0;
		FOR(i, 0, n) {
			int x = INF;
			FOR(j, 0, m) {
				x = min(g[i][j], x);
			}
			FOR(j, 0, x) {
				ans += "row ";
				ans += to_string(i + 1);
				ans += "\n";
				cnt++;
			}
			FOR(j, 0, m) {
				g[i][j] -= x;
			}
		}
		FOR(i, 0, m) {
			int x = INF;
			FOR(j, 0, n) {
				x = min(g[j][i], x);
			}
			FOR(j, 0, x) {
				ans += "col ";
				ans += to_string(i + 1);
				ans += "\n";
				cnt++;
			}
			FOR(j, 0, n) {
				g[j][i] -= x;
			}
		}
		FOR(i, 0, n) {
			FOR(j, 0, m) {
				if (g[i][j]) {
					cout << -1 << endl;
					return 0;
				}
			}
		}
		cout << cnt << endl;
		cout << ans << endl;
	}
	else {
		string ans = "";
		int cnt = 0;
		FOR(i, 0, m) {
			int x = INF;
			FOR(j, 0, n) {
				x = min(g[j][i], x);
			}
			FOR(j, 0, x) {
				ans += "col ";
				ans += to_string(i + 1);
				ans += "\n";
				cnt++;
			}
			FOR(j, 0, n) {
				g[j][i] -= x;
			}
		}
		FOR(i, 0, n) {
			int x = INF;
			FOR(j, 0, m) {
				x = min(g[i][j], x);
			}
			FOR(j, 0, x) {
				ans += "row ";
				ans += to_string(i + 1);
				ans += "\n";
				cnt++;
			}
			FOR(j, 0, m) {
				g[i][j] -= x;
			}
		}
		FOR(i, 0, n) {
			FOR(j, 0, m) {
				if (g[i][j]) {
					cout << -1 << endl;
					return 0;
				}
			}
		}
		cout << cnt << endl;
		cout << ans << endl;
	}
}