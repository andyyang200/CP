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
int s[100];
int cnt[100];
int n;
bool done() {
	FOR(i, 0, n) {
		if (!cnt[s[i]]) {
			return false;
		}
	}
	return true;
}
int main(void)
{
	string x;
	cin >> x;
	cin >> n;
	FOR(i, 0, n) {
		cin >> s[i];
	}
	ll ans = (ll)x.length() * (x.length() - 1) / 2 + x.length();
	int j = -1;
	FOR(i, 0, x.size()) {
		while (j + 1 < x.length()) {
			j++;
			cnt[x[j] - '0']++;
			if (done()) {
				cnt[x[j] - '0']--;
				j--;
				break;
			}
		}
		if (!done()) {
				ans -= j - i + 1;
		}
		cnt[x[i] - '0']--;
	}
	cout << ans << endl;
}