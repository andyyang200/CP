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
int dpb[100005];
int dpa[100005];
int a[100005];
int main(void)
{
	int n;
	scanf("%d", &n);
	FOR(i, 0, n) {
		scanf("%d", &a[i]);
	}
	dpb[n - 1] = 1;
	RFOR(i, n - 2, -1) {
		if (a[i] > a[i + 1]){
			dpb[i] = 1 + dpb[i + 1];
		}
		else {
			dpb[i] = 1;
		}
	}
	dpa[0] = 1;
	FOR(i, 1, n) {
		if (a[i] < a[i - 1]) {
			dpa[i] = 1 + dpa[i - 1];
		}
		else {
			dpa[i] = 1;
		}
	}
	FOR(i, 0, n) {
		cout << dpa[i] + dpb[i] - 1 << " ";
	}
	cout << endl;
}