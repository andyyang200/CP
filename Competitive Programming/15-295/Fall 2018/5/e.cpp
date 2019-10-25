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

//-------------------------------------------------------------------------------------------------------------------------------------
int bad[2000005];
int main() {
	int r, c;
	cin >> r >> c;
	int d = 1;
	bad[1] = 1;
	FOR(i, 2, r + 1) {
		if (bad[i] != 0) continue;
		bad[i] = i + d;
		bad[i + d] = i;
		d++;
	}
	if (bad[r] == c) {
		cout << "Britney" << endl;
	}
	else {
		cout << "Alice" << endl;
	}
}

