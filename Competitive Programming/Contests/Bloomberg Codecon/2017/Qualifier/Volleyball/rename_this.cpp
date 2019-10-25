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
string s[7];
int main(void)
{
	int n;
	cin >> n;
	string setter;
	cin >> setter;
	cin >> s[1];
	cin >> s[6];
	cin >> s[5];
	cin >> s[4];
	cin >> s[3];
	cin >> s[2];
	queue<string> sideline;
	int q;
	cin >> q;
	FOR(i, 0, q) {
		string x;
		cin >> x;
		sideline.push(x);
	}
	FOR(i, 0, n) {
		if (s[6] == setter) {
			string t = s[6];
			RFOR(j, 6, 1) {
				s[j] = s[j - 1];
			}
			s[1] = t;
		}
		else {
			sideline.push(s[6]);
			RFOR(j, 6, 1) {
				s[j] = s[j - 1];
			}
			s[1] = sideline.front();
			sideline.pop();
		}
	}
	cout << s[1] << " ";
	cout << s[6] << " ";
	cout << s[5] << " ";
	cout << s[4] << " ";
	cout << s[3] << " ";
	cout << s[2] << endl;
}