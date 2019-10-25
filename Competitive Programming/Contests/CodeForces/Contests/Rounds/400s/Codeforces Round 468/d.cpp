//Andy Yang
#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;


int cnt[5005][30][30];
int ccnt[30];
int main(void)
{
	string s;
	cin >> s;
	int n = s.length();
	FOR(i, 0, n) {
		FOR(j, 1, n) {
			int r = (i + j) % n;
			cnt[j][s[i] - 'a'][s[r] - 'a']++;
		}
		ccnt[s[i] - 'a']++;
	}
	ld ans = 0;
	FOR(i, 0, 26) {
		bool done = false;
		FOR(j, 0, 26) {
			if (done) break;
			FOR(k, 1, n) {
				if (cnt[k][i][j] == 1) {
					ans += (double)ccnt[i] / n;
					done = true;
					break;
				}
			}

		}
	}
	printf("%.9Lf\n", ans);
}
