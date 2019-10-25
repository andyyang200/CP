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
int a[100010];
int b[100010];
int main(void)
{
	int n;
	cin >> n;
	FOR(i, 1, n) {
		scanf("%d", &a[i]);
	}
	FOR(i, 1, n) {
		b[i + a[i] - 1] = max(b[i + a[i] - 1], a[i]);
	}
	RFOR(i, n - 1, 0) {
		b[i] = max(b[i], b[i + 1] - 1);
	}
	FOR(i, 1, n) {
		cout << b[i] << " ";
	}
	cout << endl;
}