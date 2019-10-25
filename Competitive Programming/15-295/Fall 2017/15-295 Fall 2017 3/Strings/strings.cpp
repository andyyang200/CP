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
string a[105];
bool cmp(string a, string b) {
	if ((a.length() < b.length() && b.substr(0, a.length()) == a) || (b.length() < a.length() && a.substr(0, b.length()) == b)) {
		if (a + b < b + a) {
			return true;
		}
		else {
			return false;
		}
	}
	return a < b;
}
int main(void)
{
	int n;
	cin >> n;
	FOR(i, 0, n) {
		cin >> a[i];
	}
	sort(a, a + n, cmp);
	string ans = "";
	FOR(i, 0, n) {
		ans += a[i];
	}
	cout << ans << endl;
}
/*
6
it
looks
like
an
easy
problem
*/

/*
2
ac
acaa

*/