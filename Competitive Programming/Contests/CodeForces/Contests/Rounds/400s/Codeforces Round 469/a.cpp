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

int main(void)
{
    int l, r, a;
    cin >> l >> r >> a;
    if (l > r) swap(l, r);
    if (r - l >= a){
        l += a;
    }
    else{
        a -= r - l;
        l = r;
        l += a / 2;
        r += a / 2;
    }
    cout << 2 * min(l, r) << endl;
}

