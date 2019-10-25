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



bool good1[5000][5000];
bool good2[5000][5000];
int main(void)
{
	string s;
	cin >> s;
	int n = s.length();
	int ans = 0;
	FOR(i, 0, n) {
		int a = 0;
		int b = 0;
		int c = 0;
		FOR(j, i, n) {
			if (s[j] == '(') {
				a++;
			}
			if (s[j] == ')') {
				b++;
			}
			if (s[j] == '?') {
				c++;
			}
			if (a + c - b < 0) break;
			if ((a + b + c) % 2 == 0 && c >= abs(a -b)) {
				good1[i][j] = true;
			}
		}
	}
	RFOR(i, n - 1, -1) {
		int a = 0;
		int b = 0;
		int c = 0;
		RFOR(j, i, -1) {
			if (s[j] == ')') {
				a++;
			}
			if (s[j] == '(') {
				b++;
			}
			if (s[j] == '?') {
				c++;
			}
			if (a + c - b < 0) break;
			if ((a + b + c) % 2 == 0 && c >= abs(a - b)) {
				good2[j][i] = true;
			}
		}
	}
	FOR(i, 0, n) {
		FOR(j, i, n) {
			if (good1[i][j] && good2[i][j]) {
				ans++;
			}
		}
	}
	cout << ans << endl;
}