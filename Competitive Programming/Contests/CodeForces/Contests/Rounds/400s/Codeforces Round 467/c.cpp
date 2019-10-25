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
typedef long double ld;
typedef pair<int, int> pii;



int main(void)
{
	ll k, d, t;
	cin >> k >> d >> t;
	if (k % d == 0){
        cout << t << endl;
        return 0;
	}
	d = ((k + d) / d) * d;
	ld x = 1.0 / t * k + 0.5 / t * (d - k);
	ld ans = 0;
	ld b = fmod(1.0, x);
	ans += (1.0 - b) / x * d;
	if (1.0 / t * k > b) {
		ans += b * t;
	}
	else {
		ans += k;
		b -= 1.0 / t * k;
		ans += b * 2.0 * t;
	}
	printf("%.10Lf\n", ans);
	//cout << ans << endl;
}

