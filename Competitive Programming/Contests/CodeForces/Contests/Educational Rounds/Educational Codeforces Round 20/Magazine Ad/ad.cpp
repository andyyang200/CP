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

int main(void)
{
	int k;
	scanf("%d", &k);
	string s;
	getline(cin, s);
	getline(cin, s);
	FOR(i, 0, s.length()) {
		if (s[i] == '-')
		{
			s[i] = ' ';
		}
	}
	int l = 1;
	int r = s.length() + 1;
	int ans = -1;
	while (l <= r) {
		int m = (l + r) >> 1;
		int j = -1;
		int len = 0;
		bool good = true;
		int lines = 1;
		FOR(i, 0, s.length()) {
			len++;
			if (len > m) {
				if (j == -1) {
					good = false;
					break;
				}
				else {
					if (i - j > m) {
						good = false;
						break;
					}
					len = i - j;
					lines++;
				}
			}
			if (s[i] == ' ') {
				j = i;
			}
		}
		if (len - 1 - j > m) {
			good = false;
		}
		if (good && lines <= k ) {
			r = m - 1;
			ans = m;
		}
		else
		{
			l = m + 1;
		}
	}
	cout << ans << endl;
}