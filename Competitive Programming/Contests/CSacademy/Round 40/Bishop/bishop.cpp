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
int d[10][10];
bool visited[10][10];
bool isValid(int r, int c) {
	return r >= 1 && r <= 8 && c >= 1 && c <= 8;
}
int main(void)
{
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	queue<pii> q;
	q.push({ r1, c1 });
	visited[r1][c1] = true;
	while (!q.empty()) {
		pii x = q.front();
		q.pop();
		int r = x.first;
		int c = x.second;
		FOR(i, 1, 9) {
			if (isValid(r + i, c + i)) {
				if (!visited[r + i][c + i]) {
					visited[r + i][c + i] = true;
					q.push({ r + i, c + i });
					d[r + i][c + i] = d[r][c] + 1;
				}
			}
			if (isValid(r + i, c - i)) {
				if (!visited[r + i][c - i]) {
					visited[r + i][c - i] = true;
					q.push({ r + i, c - i });
					d[r + i][c - i] = d[r][c] + 1;
				}
			}
			if (isValid(r - i, c + i)) {
				if (!visited[r - i][c + i]) {
					visited[r - i][c + i] = true;
					q.push({ r - i, c + i });
					d[r - i][c + i] = d[r][c] + 1;
				}
			}
			if (isValid(r - i, c - i)) {
				if (!visited[r - i][c - i]) {
					visited[r - i][c - i] = true;
					q.push({ r - i, c - i });
					d[r - i][c - i] = d[r][c] + 1;
				}
			}
		}
	}
	if (!visited[r2][c2]) {
		cout << -1 << endl;
	}
	else {
		cout << d[r2][c2] << endl;
	}
}