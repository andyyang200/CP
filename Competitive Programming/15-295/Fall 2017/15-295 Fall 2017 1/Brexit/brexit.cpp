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
vector<int> edges[200001];
int gone[200001];
int cnt[200001];
void dfs(int l) {
	gone[l] = true;
	for (int x : edges[l]) {
		if (gone[x]) continue;
		cnt[x]--;
		if (cnt[x] <= edges[x].size() / 2){
			dfs(x);
		}
	}
}
int main(void)
{
	int c, p, x, l;
	scanf("%d%d%d%d", &c, &p, &x, &l);
	x--;
	l--;
	FOR(i, 0, p) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
		cnt[a]++;
		cnt[b]++;
	}
	dfs(l);
	if (gone[x]) {
		cout << "leave" << endl;
	}
	else {
		cout << "stay" << endl;
	}
}
/*
4 3 4 1 
2 3
2 4
1 2
*/

/*
5 5 1 1
3 4
1 2
2 3
1 3
2 5
*/

/*
4 5 3 1
1 2
1 3
2 3
2 4
3 4
*/

/*
10 14 1 10 
1 2
1 3
1 4
2 5
3 5
4 5
5 6
5 7
5 8
5 9
6 10
7 10
8 10
9 10
*/