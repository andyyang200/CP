#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", z = " << z << endl
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
int n;
int a[5005];
bool ok[5005];
bool test(int x, int y){
    ll z = x * y;
    if (z < 0) return false;
    ld s = sqrt(z);
    return s - floor(s) == 0;
}
int main(void)
{
    cin >> n;
    FOR(i, 0, n){
        scanf("%d", &a[i]);
    }
    FOR(i, 0, n){
        FOR(j, 0, n){
            ok[i][j] = test(a[i], a[j]);
        }
    }

}

