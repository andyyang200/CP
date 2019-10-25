#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b)  qfor(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------


vector<int> pieces[300005];
pii loc[300005];
bool used[300005];
int match[300005];
map<int, vector<int>> has;
map<pii, int> ans;
int n;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };
int opp[4] = {2, 3, 0, 1};
void f(int i, int position, int t) {
    int x = find(pieces[i].begin(), pieces[i].end(), t) - pieces[i].begin();
    int start = (x - position + 4) % 4;
    rotate(pieces[i].begin(), pieces[i].begin() + start, pieces[i].end());
}
bool check(int r, int c) {
	int i = ans[{r, c}];
	FOR(d, 0, 4) {
	    int j = ans[{r + dr[d], c + dc[d]}];
		if (pieces[i][d] != 0 && j != 0) {
			if (pieces[i][d] != pieces[j][opp[d]]) {
				return false;
			}
		}
		if (pieces[i][d] == 0 && ans[{r + dr[d], c + dc[d]}] != 0){
            return false;
		}
	}
	return true;
}
bool possible = true;
void dfs(int r, int c) {
	if (!check(r, c)) {
		possible = false;
	}
	if (!possible) {
		return;
	}
	int i = ans[{r, c}];
	FOR(d, 0, 4) {
		if (pieces[i][d] != 0 && ans[{r + dr[d], c + dc[d]}] == 0) {
			int match = (has[pieces[i][d]][0] == i ? has[pieces[i][d]][1] : has[pieces[i][d]][0]);
			if (used[match]) {
				possible = false;
				return;
			}
			used[match] = true;
			f(match, opp[d], pieces[i][d]);
			loc[match] = {r + dr[d], c + dc[d]};
			ans[{r + dr[d], c + dc[d]}] = match;
			dfs(r + dr[d], c + dc[d]);
		}
	}
}
int zcnt[300005];
int main() {
	scanf("%d", &n);
	int maxzcnt = 0;
	FOR(i, 1, n + 1) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if (a == 0)zcnt[i]++;
		if (b == 0)zcnt[i]++;
		if (c == 0)zcnt[i]++;
		if (d == 0)zcnt[i]++;
		maxzcnt = max(maxzcnt, zcnt[i]);
		if (a != 0) {
			has[a].push_back(i);
		}
		if (b != 0) {
			has[b].push_back(i);
		}
		if (c != 0) {
			has[c].push_back(i);
		}
		if (d != 0) {
			has[d].push_back(i);
		}
		pieces[i].push_back(a);
		pieces[i].push_back(b);
		pieces[i].push_back(c);
		pieces[i].push_back(d);
		loc[i] = { -1, -1 };
	}
	int start = -1;
	if (maxzcnt < 2){
		cout << "impossible" << endl;
		return 0;
	}
	FOR(i, 1, n + 1){
        if (maxzcnt == zcnt[i]){
            start = i;
        }
	}
	ans[{0, 0}] = start;
	used[start] = true;
	loc[start] = { 0, 0 };
	int trycnt = 0;
	while (pieces[start][0] != 0 || pieces[start][1] != 0) {
		rotate(pieces[start].begin(), pieces[start].begin() + 1, pieces[start].end());
		trycnt++;
		if (trycnt > 6){
            cout << "impossible" << endl;
            return 0;
		}
	}
	dfs(0, 0);
	if (!possible) {
		cout << "impossible" << endl;
		return 0;
	}
	int maxr = 0;
	int maxc = 0;
	FOR(i, 1, n + 1){
	    if (!used[i]){
            cout << "impossible" << endl;
            return 0;
	    }
        maxr = max(maxr, loc[i].first);
        maxc = max(maxc, loc[i].second);
	}
	if ((maxr + 1) * (maxc + 1) != n){
		cout << "impossible" << endl;
		return 0;
	}
	printf("%d %d\n", maxr + 1, maxc + 1);
	FOR(i, 0, maxr + 1){
        FOR(j, 0, maxc + 1){
            printf("%d ", ans[{i, j}]);
        }
        printf("\n");
	}
}

/*
6
0 0 1 6
0 7 4 0
0 0 2 1
5 3 0 6
3 7 0 0
4 5 2 0

4
0 0 1 2
0 0 2 3
0 0 3 4
0 0 1 4
*/
