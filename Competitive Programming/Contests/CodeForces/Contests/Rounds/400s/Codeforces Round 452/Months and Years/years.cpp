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
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
bool isleap(int y) {
	return (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0));
}
int a[50];
int main(void)
{
	vector<int> v;
	int year = 1900;
	int month = 1;
	FOR(i, 0, 1000 * 12) {
		if (month == 1) v.push_back(31);
		if (month == 2) {
			if (isleap(year))v.push_back(29);
			else v.push_back(28);
		}
		if (month == 3) v.push_back(31);
		if (month == 4) v.push_back(30);
		if (month == 5) v.push_back(31);
		if (month == 6) v.push_back(30);
		if (month == 7) v.push_back(31);
		if (month == 8) v.push_back(31);
		if (month == 9) v.push_back(30);
		if (month == 10) v.push_back(31);
		if (month == 11) v.push_back(30);
		if (month == 12) v.push_back(31);

		if (month == 12) {
			month = 1;
			year++;
		}
		else {
			month++;
		}
	}
	int n;
	cin >> n;
	FOR(i, 0, n) {
		cin >> a[i];
	}
	FOR(i, 0, v.size() - n + 1) {
		bool good = true;
		FOR(j, i, i + n) {
			if (a[j - i] != v[j]) {
				good = false;
				break;
			}
		}
		if (good) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;

}