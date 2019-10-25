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


map<int, int> cnt;
string a[100005];
int bits[100005];
int x[50];
int get(string s) {
	fill(x, x + 26, 0);
	FOR(j, 0, s.length()) {
		x[s[j] - 'a']++;
	}
	int b = 0;
	FOR(j, 0, 26) {
		if (x[j] % 2 == 1)
			b += 1 << j;
	}
	return b;
}
int main() {
	int n;
	cin >> n;
	ll ans = 0;
	FOR(i, 0, n) {
		string s;
		cin >> s;
		bits[i] = get(s);
		cnt[bits[i]]++;
	}
	FOR(i, 0, n) {
		int match = 0;
		ans += cnt[match ^ bits[i]];
		FOR(j, 0, 26) {
			match += 1 << j;
			ans += cnt[match ^ bits[i]];
			match -= 1 << j;
		}
	}
	cout << (ans - n) / 2 << endl;
}

