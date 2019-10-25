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
int t[200005];
int room[200005];
int last[200005];
int main(void)
{
	int n;
	cin >> n;
	FOR(i, 1, n + 1) scanf("%d", &t[i]);
	last[1] = 0;
	room[0] = 1;
	int ans = 1;
	FOR(i, 1, n + 1) {
		int x = t[i];
		int r = room[x];
		if (x == last[room[x]]) {
			room[i] = r;
			last[r] = i;
		}
		else {
			ans++;
			room[i] = ans;
			last[ans] = i;
		}
	}
	cout << ans << endl;
}