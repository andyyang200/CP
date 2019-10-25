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
bool seen[100005];
int main(void)
{
	int a, b, c;
	cin >> a >> b >> c;
	string ans = "";
	a *= 10;
	while (true) {
		int x = a / b;
		ans += to_string(x);
		a -= b * x;
		if (seen[a]) break;
		seen[a] = true;
		a *= 10;
	}
	FOR(i, 0, ans.length()) {
		if (ans[i] == (c + '0')) {
			cout << i + 1 << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}