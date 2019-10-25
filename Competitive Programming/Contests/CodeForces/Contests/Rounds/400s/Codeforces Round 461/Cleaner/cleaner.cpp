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
bool seen[1000005];
ll calc(string x) {
	ll a = 0;
	ll ans = 0;
	FOR(i, 0, x.length()) {
		if (x[i] == 'h') {
			ans += a;
		}
		else {
			a++;
		}
	}
	return ans;
}
bool f(string a, string b) {
	string x = a + b;
	string y = b + a;
	return calc(x) > calc(y);
}
int main(void)
{
	int n;
	cin >> n;
	vector<string> v;
	int a = 0;
	int b = 0;
	FOR(i, 0, n) {
		string s;
		cin >> s;
		if (s.find('s') == -1) {
			b += s.length();
		}
		else if (s.find('h') == -1) {
			a += s.length();
		}
		else {
			v.push_back(s);
		}
	}
	sort(v.begin(), v.end(), f);
	string s = "";
	FOR(i, 0, a) s += 's';
	for (string x : v)s += x;
	FOR(i, 0, b) s += 'h';
	cout << calc(s) << endl;


}