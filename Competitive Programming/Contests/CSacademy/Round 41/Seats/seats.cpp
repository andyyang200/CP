//Andrew Yang
//Accepted
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
	string s;
	cin >> s;
	int ones = 0;
	FOR(i, 0, s.length()) {
		if (s[i] == '1') {
			ones++;
		}
	}
	int zeroes = s.length() - ones;
	int ans = 0;
	FOR(i, 0, s.length()) {
		if (s[i] == '1'){
			int x = i;
			while (x > 0 && s[x - 1] == '0') {
				x--;
			}
			int y = i;
			while (y < s.length() - 1 && s[y + 1] == '0') {
				y++;
			}
			int l = y - i + i - x;
			if (l < zeroes) {
				ans = max(ans, l + 1);
			}
			else {
				ans = max(ans, l);
			}
		}
	}
	cout << ans << endl;
}