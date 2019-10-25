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
int mat[150][150];
int mat2[150][150];
vector<int> parse(string s) {
	vector<int> ans;
	int prev = 0;
	FOR(i, 0, s.length()) {
		if (s[i] == ' ') {
			ans.push_back(stoi(s.substr(prev, i - prev)));
			prev = i + 1;
		}
	}
	ans.push_back(stoi(s.substr(prev, s.length())));
	return ans;
}
int main(void)
{
	freopen("transpose.in", "r", stdin);
	freopen("transpose.out", "w", stdout);
	vector<string> lines;
	string line;
	int r = 0;
	while (getline(cin, line)) {
		r++;
		lines.push_back(line);
	}
	int c = 0;
	FOR(i, 0, lines[0].size()) {
		if (lines[0][i] == ' ')c++;
	}
	c++;
	FOR(i, 0, lines.size()) {
		vector<int> row = parse(lines[i]);
		FOR(j, 0, c) {
			mat[i][j] = row[j];
		}
	}
	FOR(i, 0, r) {
		FOR(j, 0, c) {
			mat2[j][i] = mat[i][j];
		}
	}
	FOR(i, 0, c) {
		FOR(j, 0, r) {
			cout << mat2[i][j] << " ";
		}
		cout << endl;
	}


}