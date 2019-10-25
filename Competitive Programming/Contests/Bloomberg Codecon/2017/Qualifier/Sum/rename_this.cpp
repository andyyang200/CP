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
ll a[3000001];
ll b[3000001];
ll c[3000001];
ll ac[3000001];
ll bc[3000001];
ll cc[3000001];
bool square[3000001];
int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i * i <= n; i++) {
		square[i * i] = true;
	}
	int ans = 0;
	for (int i = 1; i * i < n; i++) {
		int r = n - i * i;
		for (int j = i + 1; j * j < r; j++) {
			if (square[r - j * j] && sqrt(r - j * j) > j) {
				ans += i + j + sqrt(r - j * j);
			}
		}
	}
	for (int i = 1; 2 * i * i < n; i++) {
		if (square[n - 2 * i * i] && sqrt(n - 2 * i * i) != i) {
			ans += i + i + sqrt(n - 2 * i * i);
		}
	}
	if (n % 3 == 0 && square[n / 3]) {
		ans += sqrt(n / 3);
	}
	cout << ans << endl;
}