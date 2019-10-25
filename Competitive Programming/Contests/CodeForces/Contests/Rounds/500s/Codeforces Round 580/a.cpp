#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b)  qfor(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define readint(x) scanf("%d", &x)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------
int a[500];
int b[500];
int main(){
    int n;
    readint(n);
    FOR(i, 0, n){
        readint(a[i]);
    }
    int m;
    readint(m);
    FOR(i, 0, m){
        readint(b[i]);
    }
    sort(a, a + n);
    sort(b, b + m);
    cout << a[n - 1] << " " << b[m - 1] << endl;
}
