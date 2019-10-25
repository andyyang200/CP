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

int main(void)
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int ans = 0;
	while (a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
		if (a == b && b == c) {
			cout << -1 << endl;
			return 0;
		}
		int a1 = (b + c) / 2;
		int b1 = (a + c) / 2;
		int c1 = (a + b) / 2;
		a = a1;
		b = b1;
		c = c1;
		ans++;
	}
	cout << ans << endl;
}