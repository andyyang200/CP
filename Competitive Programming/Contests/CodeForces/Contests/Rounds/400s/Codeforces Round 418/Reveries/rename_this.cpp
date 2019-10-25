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
int a[1000];
int b[1000];
int p[1000];
bool seen[1000];
int main(void)
{
	int n;
	cin >> n;
	FOR(i, 0, n) {
		cin >> a[i];
	}
	FOR(i, 0, n) {
		cin >> b[i];
	}
	FOR(i, 0, n) {
		if (a[i] != b[i]) {
			FOR(j, 0, n) {
				if (j != i) {
					p[j] = a[j];
				}
				else {
					p[j] = b[j];
				}
			}
			int cnt = 0;
			FOR(j, 0, n) {
				if (p[j] != b[j]) {
					cnt++;
				}
			}
			set<int> s;
			FOR(j, 0, n) {
				s.insert(p[j]);
			}
			if (cnt == 1 && s.size() == n) {
				FOR(j, 0, n) {
					cout << p[j] << " ";
				}
				cout << endl;
				return 0;
			}
		}
	}
	FOR(i, 0, n) {
		if (a[i] == b[i]) {
			seen[a[i]] = true;
		}
	}
	int ans = -1;
	FOR(i, 1, n + 1) {
		if (!seen[i]) {
			ans = i;
			break;
		}
	}
	FOR(i, 0, n) {
		if (a[i] == b[i]) {
			cout << a[i] << " ";
		}
		else {
			cout << ans << " ";
		}
	}
	cout << endl;
}