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
struct bot {
	int x0, y0, z0, x1, y1, z1;
};
bool done(bot b) {
	return b.x0 == b.x1 && b.y0 == b.y1 &&b.z0 == b.z1;
}
bot move(bot b, int direction) {
	if (direction == 0) b.y0--;
	else b.x0--;
	return b;
}
bool same(bot a, bot b) {
	return (a.x0 == b.x0 && a.y0 == b.y0 && a.z0 == b.z0);

}
void print(bot a, bot b) {
	cout << "(" << a.x0 << " " << a.y0 << " " << a.z0 << ") (" << b.x0 << " " << b.y0 << " " << b.z0 << ")" << endl;
}
int main(void)
{
	bot a, b;
	cin >> a.x0 >> a.y0 >> a.z0 >> a.x1 >> a.y1 >> a.z1;
	cin >> b.x0 >> b.y0 >> b.z0 >> b.x1 >> b.y1 >> b.z1;
	print(a, b);
	while (!done(a) || !done(b)) {
		while (!done(a)) {
			if (a.x0 < a.x1) {
				a.x0++;
				if (same(a, b)) {
					b = move(b, 0);
				}
			}
			else if (a.x0 > a.x1) {
				a.x0--;
				if (same(a, b)) {
					b = move(b, 1);
				}
			}
			else if (a.y0 < a.y1) {
				a.y0++;
				if (same(a, b)) {
					b = move(b, 1);
				}
			}
			else if (a.y0 > a.y1) {
				a.y0--;
				if (same(a, b)) {
					b = move(b, 1);
				}
			}
			else if (a.z0 < a.z1) {
				a.z0++;
				if (same(a, b)) {
					b = move(b, 1);
				}
			}
			else if (a.z0 > a.z1) {
				a.z0--;
				if (same(a, b)) {
					b = move(b, 1);
				}
			}
			print(a, b);
		}
		while (!done(b)) {
			if (b.x0 < b.x1) {
				b.x0++;
				if (same(a, b)) {
					a = move(a, 0);
				}
			}
			else if (b.x0 > b.x1) {
				b.x0--;
				if (same(a, b)) {
					a = move(a, 1);
				}
			}
			else if (b.y0 < b.y1) {
				b.y0++;
				if (same(a, b)) {
					a = move(a, 1);
				}
			}
			else if (b.y0 > b.y1) {
				b.y0--;
				if (same(a, b)) {
					a = move(a, 1);
				}
			}
			else if (b.z0 < b.z1) {
				b.z0++;
				if (same(a, b)) {
					a = move(a, 1);
				}
			}
			else if (b.z0 > b.z1) {
				b.z0--;
				if (same(a, b)) {
					a = move(a, 1);
				}
			}
			print(a, b);
		}
	}

}
/*
0 0 0 2 2 2
1 1 2 0 0 0
*/