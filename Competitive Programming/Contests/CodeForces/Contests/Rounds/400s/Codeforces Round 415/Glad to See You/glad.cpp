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
int n, k;
int find(int l, int r) {
	if (l > r) {
		return -1;
	}
	if (l == r) {
		return l;
	}
	int ans = 0;
	r--;
	while (l <= r) {
		int mid = (l + r) / 2;
		cout << 1 << " " << mid << " " << mid + 1 << "\n";
		fflush(stdout);
		string a;
		cin >> a;
		if (a == "TAK") {
			r = mid - 1;
			ans = mid;
		}
		else {
			l = mid + 1;
			ans = mid + 1;
		}
	}
	return ans;
}
bool test(int i) {
	if (i < 1 || i > n) {
		return false;
	}
	if (i == 1) {
		cout << 1 << " " << i << " " << i + 1 << "\n";
		fflush(stdout);
		string a;
		cin >> a;
		return a == "TAK";
	}
	else if (i == n) {
		cout << 1 << " " << i << " " << i - 1 << "\n";
		fflush(stdout);
		string a;
		cin >> a;
		return a == "TAK";
	}
	cout << 1 << " " << i  << " " << i - 1 << "\n";
	fflush(stdout);
	string a;
	cin >> a;
	if (a == "NIE") {
		return false;
	}
	cout << 1 << " " << i << " " << i + 1 << "\n";
	fflush(stdout);
	string a2;
	cin >> a2;
	if (a2 == "NIE") {
		return false;
	}
	return true;
}
int main(void)
{
	scanf("%d%d", &n, &k);
	int l = 1;
	int r = n - 1;
	int first = find(1, n);
	int second = find(1, first - 1);
	if (test(second))
	{
		cout << 2 << " " << first << " " << second << "\n";
		fflush(stdout);
		return 0;
	}
	second = find(first + 1, n);
	if (test(second))
	{
		cout << 2 << " " << first << " " << second << "\n";
		fflush(stdout);
		return 0;
	}
	cout << 2 << " " << first << " " << n << "\n";
	fflush(stdout);
}