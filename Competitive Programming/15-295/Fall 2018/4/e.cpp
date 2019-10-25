#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------

int cnt[100005];
int k, n;
int check1() {
	if ((n + 1) % k != 0) {
		return -1;
	}
	int b = (n + 1) / k;
	int a = b - 1;
	int cnta = 0;
	int cntb = 0;
	FOR(i, 1, k + 1) {
		if (cnt[i] == a) cnta++;
		if (cnt[i] == b) cntb++;
	}
	if (cnta == 1 && cntb * b + a == n) {
		FOR(i, 1, k + 1) {
			if (cnt[i] == a) {
				return i;
			}
		}
	}
	return -1;
}
int check2() {
	if ((n - 1) % k != 0) {
		return -1;
	}
	int b = (n - 1) / k;
	int a = b + 1;
	int cnta = 0;
	int cntb = 0;
	FOR(i, 1, k + 1) {
		if (cnt[i] == a) cnta++;
		if (cnt[i] == b) cntb++;
	}
	if (cnta == 1 && cntb * b + a == n) {
		FOR(i, 1, k + 1) {
			if (cnt[i] == a) {
				return i;
			}
		}
	}
	return -1;
}
pii check3() {
	if (n % k != 0) {
		return { -1, -1 };
	}
	int a = n / k - 1;
	int b = n / k;
	int c = n / k + 1;
	int cnta = 0;
	int cntb = 0;
	int cntc = 0;
	FOR(i, 1, k + 1) {
		if (cnt[i] == a) cnta++;
		if (cnt[i] == b) cntb++;
		if (cnt[i] == c) cntc++;
	}
	if (cnta == 1 && cntb * b + a + c == n && cntc == 1) {
		int x1 = -1;
		int x2 = -1;
		FOR(i, 1, k + 1) {
			if (cnt[i] == a) {
				x1 = i;
			}if (cnt[i] == c) {
				x2 = i;
			}
		}
		return { x1, x2 };
	}
	return { -1, -1 };
}
int main() {
	cin >> k >> n;
	FOR(i, 0, n) {
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
	int a = check1();
	int b = check2();
	pii c = check3();
	if (a > 0) {
		cout << "+" << a << endl;
		return 0;
	}
	if (b > 0) {
		cout << "-" << b << endl;
		return 0;
	}
	if (c.first > 0) {
		cout << "-" << c.second << " +" << c.first << endl;
		return 0;
	}
	cout << "*" << endl;
	return 0;
}
/*
3 5
1 3 2 3 1

3 7
1 2 3 3 3 2 1

3 6
3 1 2 1 3 1

3 6
2 3 2 2 2 1
*/
/*
2
6
AABABB
10
Ab9AAb2bC2
*/


