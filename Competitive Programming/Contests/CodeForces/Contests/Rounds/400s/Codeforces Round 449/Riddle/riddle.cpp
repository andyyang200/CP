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
string z = "What are you doing at the end of the world? Are you busy? Will you save us?";
string a = "What are you doing while sending \"";
string b = "\"? Are you busy? Will you send \"";
string c = "\"?";
ll len[100005];
char f(int n, ll k) {
	if (n == 0) {
		if (k < z.length()) {
			return z[k];
		}
		return '.';
	}
	if (k < a.length()) {
		return a[k];
	}
	k -= a.length();
	if (k < len[n - 1]) {
		return f(n - 1, k);
	}
	k -= len[n - 1];
	if (k < b.length()) {
		return b[k];
	}
	k -= b.length();
	if (k < len[n - 1]) {
		return f(n - 1, k);
	}
	k -= len[n - 1];
	if (k < c.length()) {
		return c[k];
	}
	return '.';
}
int main(void)
{
	len[0] = z.length();
	FOR(i, 1, 100005) {
		len[i] = a.length() + b.length() + c.length() + 2 * len[i - 1];
		if (len[i] >= (ll)1000000000 * (ll)1000000000) {
			len[i] = (ll)1000000000 * (ll)1000000000;
		}
	}
	int q;
	scanf("%d", &q);
	string ans = "";
	FOR(i, 0, q) {
		ll n, k;
		cin >> n >> k;
		k--;
		ans += f(n, k);
	}
	cout << ans << endl;
}
/*
1
100000
1000000000000000000
*/
