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
int main() {

	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	int ans = 0;
	FOR(i, 0, n) {
		if (a[i] == b[i]) continue;
		if (i == n - 1) {
			ans++;
			continue;
		}
		else {
			if (a[i] == '1' && a[i + 1] == '0' && b[i + 1] == '1') {
				swap(a[i], a[i + 1]);
				ans++;
			}
			else if (a[i] == '0' && a[i + 1] == '1' && b[i + 1] == '0') {
				swap(a[i], a[i + 1]);
				ans++;
			}
			else {
				ans++;
			}
		}
	}
	cout << ans << endl;

}

