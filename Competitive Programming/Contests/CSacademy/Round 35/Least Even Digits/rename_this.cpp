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
int cnt(string s) {
	int ret = 0;
	FOR(i, 0, s.length()) {
		if ((s[i] - '0') % 2 == 0) {
			ret++;
		}
	}
	return ret;
}
int main(void)
{
	int x;
	cin >> x;
	string s = to_string(x);
	bool even = false;
	FOR(i, 0, s.length()) {
		if ((s[i] - '0') % 2 == 0) {
			even = true;
			break;
		}
	}
	if (!even) {
		cout << -1 << endl;
		return 0;
	}
	string s1 = s;
	RFOR(i, s1.length() - 1, -1) {
		if ((s1[i] - '0') % 2 == 0) {
			s1[i]++;
			FOR(j, i + 1, s1.length()) {
				s1[j] = '1';
			}
			break;
		}
	}
	int ans = cnt(s);
	string s2 = s; 
	while (cnt(s2) >= cnt(s)) {
		RFOR(i, s2.length() - 1, -1) {
			if ((s2[i] - '0') % 2 == 0) {
				RFOR(j, i, -1) {
					if (s2[j] > '0') {
						s2[j]--;
						break;
					}
					else {
						s2[j] = '9';
					}
				}
				FOR(j, i + 1, s2.length()) {
					s2[j] = '9';
				}
				break;
			}
		}
		while (s2[0] == '0') {
			s2.erase(s2.begin());
		}
	}
	ll b = stoi(s2) - x;
	ll a = x - stoi(s1);
	cout << a * b << endl;

}