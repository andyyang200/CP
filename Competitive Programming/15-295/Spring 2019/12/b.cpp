#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b)  qfor(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------

multiset<int> in;
set<int> notin;

void add(int x) {
	in.insert(x);
	auto itr = notin.find(x);
	if (itr != notin.end()) {
		notin.erase(itr);
	}
}
void remove(int x) {
	in.erase(in.find(x));
	auto itr = in.find(x);
	if (itr == in.end()) {
		notin.insert(x);
	}
}

int nim[200005];
int arr[2005];
int main() {
	while (true) {
		int a, b, c, k;
		scanf("%d%d%d%d", &a, &b, &c, &k);
		if (k == 0) {
			break;
		}
		nim[0] = 0;
		in.clear();
		notin.clear();
		int lim = 0;
		FOR(i, 0, k) {
			scanf("%d", &arr[i]);
			lim = max(lim ,arr[i]);
		}
		FOR(i, 0, lim + 3) {
			notin.insert(i);
		}
		add(0);
		FOR(i, 1, lim + 1) {
			if (i - a >= 0) {
				remove(nim[i - a]);
			}
			if (i - b >= 0 && b != a) {
				remove(nim[i - b]);
			}
			if (i - c >= 0 && c != b && c != a) {
				remove(nim[i - c]);
			}
			nim[i] = *notin.begin();
			if (i - a >= 0) {
				add(nim[i - a]);
			}
			if (i - b >= 0 && b != a) {
				add(nim[i - b]);
			}
			if (i - c >= 0 && c != b && c != a) {
				add(nim[i - c]);
			}
			add(nim[i]);
		}
		FOR(i, 0, k) {
			printf("%d ", nim[arr[i]]);
		}
		printf("\n");

	}

}


