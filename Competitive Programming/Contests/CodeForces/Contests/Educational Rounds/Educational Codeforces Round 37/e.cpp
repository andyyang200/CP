
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
#include <cassert>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000

set<int> no[200005];
set<int> visit;
int sz;
int n, m;
vector<int> ans;
void dfs(int x) {
	visit.erase(visit.find(x));
	sz++;
	while(!visit.empty()){
        int y = *visit.begin();
        if (no[x].find(y) == no[x].end()) {
            dfs(y);
            break;
        }
        else{
            int t = sz;
            sz = 0;
            dfs(y);
            ans.push_back(sz);
            sz = t;
        }
	}
}
int main() {
	cin >> n >> m;
	FOR(i, 0, n) {
		visit.insert(i);
	}
	FOR(i, 0, m) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		no[x].insert(y);
		no[y].insert(x);
	}
    sz = 0;
    dfs(0);
    ans.push_back(sz);
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int x : ans)cout << x << " ";
	cout << endl;

}

