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


bool dpSuffix[200005][105];
bool dpPrefix[200005][105];
int pb[200001];
int pw[200001];
bool white[200001];
bool black[200001];
int n, k;
bool b(int l, int r) {
	if (l > r) {
		return false;
	}
	int sum = pb[r];
	if (l > 0) {
		sum -= pb[l - 1];
	}
	return sum > 0;
}
bool w(int l, int r) {
	if (l > r) {
		return false;
	}
	int sum = pw[r];
	if (l > 0) {
		sum -= pw[l - 1];
	}
	return sum > 0;
}
std::string solve_puzzle(std::string s, std::vector<int> c) {

	k = c.size();
	n = s.length();
	s = '_' + s;
	s += '_';
	c.insert(c.begin(), 0);
	FOR(i, 1, n + 1) {
		pb[i] = (s[i] == 'X') + (i > 0 ? pb[i - 1] : 0);
		pw[i] = (s[i] == '_') + (i > 0 ? pw[i - 1] : 0);
	}
	FOR(l, 1, n + 1) { // base case first block
		int r = l + c[1] - 1;
		if (r <= n && !w(l, r) && !b(1, l - 1)) {
			dpPrefix[r][1] = true;
		}
		if (r <= n && s[r] != 'X' && dpPrefix[r - 1][1]) {
			dpPrefix[r][1] = true;
		}
	}
	FOR(r, 1, n + 1) {
		FOR(i, 2, k + 1) {
			int l = r - c[i] + 1;
			if (l < 1) {
				continue;
			}
			if (dpPrefix[r - 1][i] && s[r] != 'X') { // do not place at pos
				dpPrefix[r][i] = true;
			}
			if (l - 2 > 0 && !w(l, r) && s[l - 1] != 'X' && dpPrefix[l - 2][i - 1]) { // place at pos
				dpPrefix[r][i] = true;
			}
		}
	}
	RFOR(l, n, 0) { // base case last block
		int r = l + c[k] - 1;
		if (r <= n && !w(l, r) && !b(r + 1, n)) {
			dpSuffix[l][k] = true;
		}
		if (r <= n && s[l] != 'X' && dpSuffix[l + 1][k])
		{
			dpSuffix[l][k] = true;
		}
	}
	RFOR(l, n, 0) {
		RFOR(i, k - 1, 0) {
			int r = l + c[i] - 1;
			if (r > n) {
				continue;
			}
			if (dpSuffix[l + 1][i] && s[l] != 'X') { // do not place at pos
				dpSuffix[l][i] = true;
			}
			if (!w(l, r) && s[r + 1] != 'X' && dpSuffix[r + 2][i + 1]) { // place at pos
				dpSuffix[l][i] = true;
			}
		}
	}
	FOR(l, 1, n + 1) {
		if (s[l] == 'X') {
			continue;
		}
		if (dpPrefix[l - 1][k] && !b(l + 1, n)) {
			white[l] = true;
		}
		if (dpSuffix[l + 1][1] && !b(1, l - 1)) {
			white[l] = true;
		}
		FOR(i, 1, k) {
			if (dpPrefix[l - 1][i] && dpSuffix[l + 1][i + 1]) {
				white[l] = true;
			}
		}
	}
	FOR(i, 1, k + 1) {
		vector<int> can;
		FOR(l, 1, n + 1) {
			int r = l + c[i] - 1;
			if (r <= n && s[l - 1] != 'X' && s[r + 1] != 'X' && !w(l, r) && (i == 1 && !b(1, l - 1) || l - 2 > 0 && dpPrefix[l - 2][i - 1]) && (i == k && !b(r + 1, n) || r + 2 <= n && dpSuffix[r + 2][i + 1])) {
				can.push_back(l);
			}
		}
		FOR(j, 0, can.size()) {
			int limit = can[j] + c[i];
			if (j < can.size() - 1) {
				limit = min(limit, can[j + 1]);
			}
			FOR(x, can[j], limit) {
				black[x] = true;
			}
		}
	}
	string ans = "";
	FOR(i, 1, n + 1) {
		if (black[i] && white[i]) {
			ans += '?';
		}
		else if (black[i]) {
			ans += 'X';
		}
		else {
			ans += '_';
		}
	}
	return ans;
}


//int main(void)
//{
//	cout << solve_puzzle("..........", {3, 4}) << endl;
//}
