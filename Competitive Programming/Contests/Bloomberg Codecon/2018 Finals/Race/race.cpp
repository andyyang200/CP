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


int E[5];
int energy[5];
int R[5];
int a[5][5];
int T;
int ans;
int n;
void f(int t, int x, int y, int c) {
	if (t == T) {
		ans = max(ans, c);
		return;
	}
	int ee[5];
	FOR(i, 0, n) {
		ee[i] = energy[i];
	}
	bool can = false;
	if (energy[x] >= R[x] && energy[y] >= R[y]) {
		can = true;
		energy[x] -= R[x];
		energy[y] -= R[y];
		FOR(i, 0, 5) {
			if (i != x && i != y) {
				energy[i] = min(E[i], energy[i] + R[i]);
			}
		}
		f(t + 1, x, y, c + a[x][y] * 100);
		FOR(i, 0, 5) {
			energy[i] = ee[i];
		}
	}
	FOR(i, 0, n) {
		FOR(j, i + 1, n) {
			if (energy[i] >= R[i] && energy[j] >= R[j] && (i != x || j != y)) {
				energy[i] -= R[i];
				energy[j] -= R[j];
				FOR(k, 0, 5) {
					if (k != i && k != j) {
						energy[k] = min(E[k], energy[k] + R[k]);
					}
				}
				f(t + 1, i, j, c + a[i][j] * 100 - 200);
				FOR(i, 0, 5) {
					energy[i] = ee[i];
				}
				can = true;
			}
		}
	}
	if (!can) {
		FOR(i, 0, 5) {
			energy[i] = min(E[i], energy[i] + R[i]);
		}
		f(t + 1, x, y, c - 200);
		FOR(i, 0, 5) {
			energy[i] = ee[i];
		}
	}
	
}
int main(void)
{
	cin >> n;
	FOR(i, 0, n) {
		string s;
		cin >> s;
		cin >> E[i] >> R[i];
		energy[i] = E[i];
	}
	FOR(i, 0, n) {
		FOR(j, 0, n) {
			cin >> a[i][j];
		}
	}
	ans = 0;
	cin >> T;
	FOR(i, 0, n) {
		FOR(j, i + 1, n) {
			f(0, i, j, 0);
		}
	}
	cout << ans << endl;
}