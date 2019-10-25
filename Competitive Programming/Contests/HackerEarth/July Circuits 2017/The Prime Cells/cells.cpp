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
int a[105][105];
bool isPrime(int x) {
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}
int main(void)
{
	int n;
	scanf("%d", &n);
	FOR(i, 1, n + 1) {
		FOR(j, 1, n + 1) {
			scanf("%d", &a[i][j]);
		}
	}
	int ans = 0;
	FOR(i, 1, n + 1) {
		FOR(j, 1, n + 1) {
			int sum = 0;
			sum += a[i - 1][j];
			sum += a[i + 1][j];
			sum += a[i][j - 1];
			sum += a[i][j + 1];
			if (isPrime(sum)) {
				ans++;
			}
		}
	}
	cout << ans << endl;
}