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
ld d[105][105];
int main(){
    while(true){


        int n, m;
        cin >> n;
        if (n == 0) break;
        cin >> m;
        FOR(i, 0, n)FOR(j, 0, n)d[i][j] = INF;
		FOR(i, 0, n) d[i][i] = 0;
        FOR(i, 0, m){
            int a, b;
            double p;
            cin >> a >> b >> p;
            p = -log2(p / 100);
            a--;
            b--;
            d[a][b] = p;
            d[b][a] = p;
        }
        FOR(k, 0, n){
            FOR(i, 0, n){
                FOR(j, 0, n){
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
        ld x = pow(2.0, -d[0][n-1]);
        x *= 100;
        printf("%.6Lf\n", x);
    }


}


