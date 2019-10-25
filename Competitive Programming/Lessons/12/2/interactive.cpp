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


/*There are N people with IDs from 1 through N. Each is holding a hidden number.
You can query two people by printing out their ID, and the grader will tell you if their numbers are "SAME" or "DIFFERENT".
More than N / 2 people have a special number. In at most N - 2 queries, print the ID of a person holding the special number.
2 <= N <= 10000
*/



















int main(void)
{
	int n;
	scanf("%d", &n);
	int cnt = 1;
	int x = 1;
	FOR(i, 2, n) {
		if (x == -1) {
			x = i;
			cnt = 1;
			continue;
		}
		cout << x << " " << i << endl;
		string result;
		cin >> result;
		if (result == "SAME") {
			cnt++;
		}
		else {
			if (cnt) {
				cnt--;
			}
			if (!cnt) {
				cnt = 0;
				x = -1;
			}
		}
	}
	if (x == -1) {
		cout << n << endl;

	}
	else {

		cout << x << endl;
	}
}