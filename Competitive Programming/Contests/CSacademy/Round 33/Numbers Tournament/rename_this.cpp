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
pii child[100];
vector<int> v[100];
bool piicompare(pii a, pii b) {
	if (a.first != b.first) {
		return a.first > b.first;
	}
	return a.second < b.second;
}
int main(void)
{
	int n;
	cin >> n;
	FOR(i, 0, n) {
		FOR(j, 0, n) {
			int a;
			cin >> a;
			v[i].push_back(a);
		}
		child[i].second = i;
	}
	FOR(i, 0, n) {
		FOR(j, i + 1, n) {
			int a = INF;
			int b = 0;
			FOR(k, 0, n) {
				FOR(h, 0, n) {
					if (v[i][k] == v[j][h]) {
						a = min(a, v[i][k]);
						b = max(b, v[i][k]);
						break;
					}
				}
			}
			int s1, s2;
			if (a == INF) {
				s1 = 1;
				s2 = 1;
			}
			else {
				s1 = 0;
				s2 = 0;
				FOR(k, 0, n) {
					if (v[i][k] < a || v[i][k] > b) {
						s1++;
					}
				}
				FOR(k, 0, n) {
					if (v[j][k] < a || v[j][k] > b) {
						s2++;
					}
				}
				if (s1 > s2) {
					s1 = 2;
					s2 = 0;
				}
				else if (s2 > s1) {
					s2 = 2;
					s1 = 0;
				}
				else {
					s2 = 1;
					s1 = 1;
				}
			}
			child[i].first += s1;
			child[j].first += s2;
		}
	}
	sort(child, child + n, piicompare);
	FOR(i, 0, n) {
		cout << child[i].second + 1 << endl;
	}
}