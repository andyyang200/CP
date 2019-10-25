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


int a[500005];
int main(){
    int n;
    cin >> n;
    ll sum = 0;
    FOR(i, 0, n) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    }
    sort(a, a + n);
    if (a[n - 1] < 0) {
        sum = -sum + 2 * a[n - 1];
    }
    else if (a[0] > 0) {
        sum -= 2 * a[0];
    }
    else{
        sum = 0;
        FOR(i, 0, n) {
            sum += abs(a[i]);
        }
    }
    cout << sum << endl;
}

