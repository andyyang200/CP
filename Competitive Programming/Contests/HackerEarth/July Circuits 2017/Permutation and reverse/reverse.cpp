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
int p[200];
int a[200];
int dp[200];
vector<int> v[200];
int main(void)
{
	int n;
	scanf("%d", &n);
	FOR(i, 1, n + 1) {
		scanf("%d", &p[i]);
	}
	FOR(i, 0, n) {
		scanf("%d", &a[i]);
	}
	vector<pii> ans;
	int curpos = 0; // position in a
	FOR(i, 1, n + 1) {
		FOR(j, i, n + 1) {
			if (p[j] == i) {
				if (j != i) {
					int dis = j - i;
					FOR(k, 0, n + 1) { // reset dp
						dp[k] = false;
						v[k].clear();
					}
					dp[0] = true;
					while (true) { // dp until found
						RFOR(k, n, 0) {
							if (k - a[curpos] + 1 < 0) {
								break;
							}
							if (!dp[k] && dp[k - a[curpos] + 1]) {
								dp[k] = true;
								v[k] = v[k - a[curpos] + 1];
								v[k].push_back(a[curpos]);
							}
						}
						curpos++;
						curpos %= n;
						if (dp[dis]) {
							break;
						}
					}
					int targetIndex = j;
					for (int x : v[dis]) {
						ans.push_back({ targetIndex - x + 1, targetIndex });
						reverse(p + targetIndex - x + 1, p + targetIndex + 1);
						targetIndex = targetIndex - x + 1;
					}
				}
				break;
			}

		}
	}
	cout << ans.size() << endl;
	for (pii x : ans) {
		cout << x.first << " " << x.second << endl;
	}
}