//Andrew Yang
//accepted
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
ll up[1505][1505];
ll down[1505][1505];
ll path[1505][1505];
long long getMaximumPoints(int R, int C, int K,
	std::vector<std::vector<int> > T, std::vector<std::vector<int> > P) {
	FOR(i, 0, R) {
		T[i].insert(T[i].begin(), 0);
		P[i].insert(P[i].begin(), 0);
		T[i].push_back(0);
		P[i].push_back(0);
	}
	T.insert(T.begin(), vector<int>(C + 2));
	P.insert(P.begin(), vector<int>(C + 2));
	T.push_back(vector<int>(C + 2));
	P.push_back(vector<int>(C + 2));
	FOR(i, 0, R + 2) {
		FOR(j, 0, C + 2) {
			up[i][j] = (ll)-1e17;
			down[i][j] = (ll)-1e17;
			path[i][j] = (ll)-1e17;
		}
	}
	FOR(i, 1, C + 1) {
		up[1][i] = P[1][i];
	}
	FOR(i, 2, R + 1) { // compute up[][]
		FOR(j, 1, C + 1) {
			up[i][j] = up[i - 1][j - 1] + P[i][j];
			up[i][j] = max(up[i][j], up[i - 1][j]+ P[i][j]);
			up[i][j] = max(up[i][j], up[i - 1][j + 1] + P[i][j]);
		}
	}
	FOR(i, 1, C + 1) {
		down[R][i] = P[R][i];
	}
	RFOR(i, R - 1, 0) { // compute down[][]
		FOR(j, 1, C + 1) {
			down[i][j] = down[i + 1][j - 1] + P[i][j];
			down[i][j] = max(down[i][j], down[i + 1][j] + P[i][j]);
			down[i][j] = max(down[i][j], down[i + 1][j + 1] + P[i][j]);
		}
	}
	RFOR(i, R, 0) { // compute path[][]
		FOR(j, 1, C + 1) {
			path[i][j] = max(path[i][j], path[i + 1][j - 1]);
			path[i][j] = max(path[i][j], path[i + 1][j]);
			path[i][j] = max(path[i][j], path[i + 1][j + 1]);
			if (path[i][j] != -1e17) {
				path[i][j] += P[i][j];
			}
			if (T[i][j] == 1) {
				path[i][j] = max(path[i][j], (ll)P[i][j]);
			}
		}
	}
	ll maxUp = (ll)-1e18;
	ll maxDown = (ll)-1e18;
	ll maxPath = (ll)-1e18;
	FOR(i, 1, R + 1) {
		FOR(j, 1, C + 1) {
			if (T[i][j] == 1) {
				maxUp = max(maxUp, up[i][j]);
				maxDown = max(maxDown, down[i][j]);
				maxPath = max(maxPath, path[i][j]);
			}
		}
	}
	maxPath = max(maxPath, (ll)0);
	ll ans = (ll)-1e18;
	FOR(i, 1, C + 1) { // no portals
		ans = max(ans, up[R][i]);
	}
	if (K > 0) {
		ans = max(ans, maxUp + maxDown + (K - 1) * maxPath);
	}
	return ans;
}
//int main() {
//	cout << getMaximumPoints(3, 3, 20, { { 0, 1, 0 }, { 0, 0, 0 }, { 0, 0, 0 } }, { { 1, -10000, 3 },{ 4, 5, 6 },{ 7, -10000, 9 } }) << endl;
//}
