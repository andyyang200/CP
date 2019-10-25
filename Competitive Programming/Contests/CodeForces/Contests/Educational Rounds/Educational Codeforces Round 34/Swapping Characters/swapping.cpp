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
string a[5001];
int dis[5001];
int cnt[5000][26];
int cnt2[50];
int main(void)
{
	int k, n;
	cin >> k >> n;
	FOR(i, 0, k) {
		cin >> a[i];
		FOR(j, 0, n) {
			cnt[i][a[i][j] - 'a']++;
		}
	}
	FOR(i, 0, k - 1) {
		FOR(j, 0, 26) {
			if (cnt[i][j] != cnt[i + 1][j]) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	FOR(i, 1, k) {
		FOR(j, 0, n) {
			if (a[i][j] != a[0][j]) {
				dis[i]++;
			}
		}
	}
	FOR(i, 0, n) {
		FOR(j, i + 1, n) {
			bool good = true;
			FOR(x, 1, k) {
				int d = dis[x];
				if (a[x][i] != a[0][i] && a[x][i] == a[0][j]) {
					d--;
				}
				if (a[x][i] == a[0][i] && a[x][i] != a[0][j]) {
					d++;
				}
				if (a[x][j] != a[0][j] && a[x][j] == a[0][i]) {
					d--;
				}
				if (a[x][j] == a[0][j] && a[x][j] != a[0][i]) {
					d++;
				}
				assert(d != 1);
				if (d > 2) {
					good = false;
					break;
				}
				if (d == 0) {
					bool good2 = false;
					FOR(asd, 0, 26) {
						if (cnt[x][asd] > 1) {
							good2 = true;
							break;
						}
					}
					if (!good2) {
						good = false;
						break;
					}
				}

			}
			if (good) {
				string s = a[0];
				char t = s[i];
				s[i] = s[j];
				s[j] = t;
				cout << s << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
}