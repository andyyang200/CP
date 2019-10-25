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
	string s, a, b;
	cin >> s >> a >> b;
	string ans = "";
	FOR(i, 0, s.length()) {
		ans += s[i];
		if (ans.size() >= a.size()){
			if (ans.substr(ans.size() - a.length(), a.length()) == b) {
				ans = ans.substr(0, ans.size() - a.length());
				ans += a;
				cout << ans;
				ans = "";
			}
			else if (ans.substr(ans.size() - a.length(), a.length()) == a) {
				ans = ans.substr(0, ans.size() - a.length());
				ans += b;
				cout << ans;
				ans = "";
			}
		}
	}
	cout << ans << endl;
}