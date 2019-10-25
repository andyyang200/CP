#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b)  qfor(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define ri(x) scanf("%d", &x)
#define ri2(x, y) scanf("%d%d", &x, &y)
#define ri3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define rll(x) scanf("%lld", &x)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------
int n;
int t[300005];
int dp[300005]; // # trailers if unique, -1 ambiguous, -2 impossible
int main(){
    ri(n);
    FOR(i, 0, n){
        ri(t[i]);
    }
    if (n == 1){
        cout << "Impossible" << endl;
        return 0;
    }
    dp[n] = 0;
    dp[n - 1] = -2;
    if (t[n - 1] - t[n - 2] < 2000){
        dp[n - 2] = 0;
    }
    else{
        dp[n - 2] = -2;
    }

    if (n >= 3){
        if (t[n - 1] - t[n - 2] < 2000 && t[n - 2] - t[n - 3] < 2000){
            dp[n - 3] = 1;
        }
        else{
            dp[n - 3] = -2;
        }
    }

    RFOR(i, n - 3, -1){
        if (t[i + 1] - t[i] >= 2000){ // impossible
            dp[i] = -2;
            continue;
        }
        // must be same car
        int b = dp[i + 2];
        int c = dp[i + 3];

        bool can3 = t[i + 2] - t[i + 1] < 2000 && (i + 3 >= n || t[i + 3] - t[i + 2] > 1000) &&(c != -2);
        bool can2 = b != -2 && t[i + 2] - t[i + 1] > 1000;
        if (!can2 && !can3){ // impossible
            dp[i] = -2;
            continue;
        }
        set<int> s;


        if ((can2 && b == -1) || (can3 && c == -1)){ // ambiguous
            dp[i] = -1;
            continue;
        }if (can2){
            s.insert(b);
        }
        if (can3){
            s.insert(c + 1);
        }
        if (s.size() == 2){
            dp[i] = -1;
        }
        else{
            dp[i] = *s.begin();
        }

    }
    int x = dp[0];
    if (x == -1){
        cout << "Ambiguous" << endl;
    }
    else if (x == -2){
        cout << "Impossible" << endl;
    }
    else{
        int y = (n - 3 * x) / 2;
        printf("Cars without trailers: %d\nCars with trailers: %d\n", y, x);
    }
}
/*
7
10 200 5000 6100 7200 8300 9400

6
0 1100 2200 3300 4400 5500

4
0 1000 2000 3001
*/
