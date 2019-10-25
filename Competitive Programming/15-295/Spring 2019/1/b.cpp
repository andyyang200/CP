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
int a[10005];
int b[10005];
int main(){
    int n;
    cin >> n;
    FOR(i, 0, 2 * n){
        scanf("%d", &a[i]);
    }
    int x;
    cin >> x;
    int cury = 0;
    double ans = 0;
    FOR(i, 1, 2 * n){
        if (i % 2 == 1){
            cury += a[i] - a[i-1];
        }
        else{
            cury -= a[i] - a[i-1];
        }
        b[i] = cury;
    }
    double y = -1;
    FOR(i, 0, 2 * n){
        if (a[i] <= x && x <= a[i + 1]){
            y = b[i] + (double)(b[i+1]-b[i]) / (a[i+1]-a[i]) * (x-a[i]);
            break;
        }
    }
    FOR(i, 0, 2 * n){
        if (a[i] > x) break;
        double m = (double)(y - b[i]) / (x - a[i]);
        double yint = b[i] - m * a[i];
        ans = max(ans, yint);
    }
    int ret = ceil(ans);
    cout << ret << endl;
}

