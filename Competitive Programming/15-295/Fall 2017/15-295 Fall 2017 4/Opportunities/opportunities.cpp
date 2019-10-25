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
set<int> edges[10001];
int v, e;
string s;





int main(void)
{
	while (true) {
		scanf("%d%d", &v, &e);
		if (v == 0 && e == 0) {
			break;
		}
		FOR(i, 0, v) {
			edges[i].clear();
		}
		FOR(i, 0, e) {
			int u, v;
			scanf("%d%d", &u, &v);
			u--;
			v--;
			edges[u].insert(v);
			edges[v].insert(u);
		}
	}
}
/*
5 6
1 2
2 3
3 4
4 5
1 3
1 4
oeooo
3 1
1 2
oeo
5 0
eeeee
5 0
eeoee
5 0
eeoeo
4 2
1 2
4 3
eeee
0 0

*/