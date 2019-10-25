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
ll ans;
ll n, k;
void process(ll factor) {
	if (k == 1) {
		if (factor == n) {
			ans = max(ans, factor);
		}
		return;
	}
	double a = factor;
	double b = factor + (k - 2) * factor;
	double sum = (b + a) / 2 * (k - 1);
	if (sum < n &&n - sum > b)
	{
		ans = max(ans, factor);
	}
}
int main(void)
{
	cin >> n >> k;
	if (k > 200000) {
		cout << -1 << endl;
		return 0;
	}
	ans = 0;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			process(i);
			process(n / i);
		}
	}
	if (ans == 0) {
		cout << -1 << endl;
		return 0;
	}
	ll x = ans;
	FOR(i, 0, k - 1) {
		cout << x << " ";
		n -= x;
		x += ans;
	}
	cout << n << endl;
}