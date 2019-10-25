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
int d[501][501];
ll fw[501][501];
int x[501];
ll ans[501];
int main(){
    int n;
    scanf("%d", &n);
    FOR(i, 0, n){
        FOR(j, 0, n){
            scanf("%d", &d[i][j]);
            fw[i][j] = (ll)INF * INF;
        }
    }
    FOR(i, 0, n){
        scanf("%d", &x[i]);
        x[i]--;
    }
    RFOR(asd, n - 1, -1){
        int k = x[asd];
        fw[k][k] = 0;
        FOR(asd2, 0, n){
            int i = x[asd2];
            fw[i][k] = min(fw[i][k], (ll)d[i][k]);
            fw[k][i] = min(fw[k][i], (ll)d[k][i]);
        }
        FOR(asd2, 0, n){
            FOR(asd3, 0, n){
                int i = x[asd2];
                int j = x[asd3];
                fw[i][j] = min(fw[i][j], fw[i][k] + fw[k][j]);
            }
        }
        FOR(i, asd, n){
            FOR(j, asd, n){
                ans[asd] += fw[x[i]][x[j]];
            }
        }
    }
    FOR(i, 0, n){
        cout << ans[i] << " ";
    }
    cout << endl;

}
/*
4
0 57148 51001 13357
71125 0 98369 67226
49388 90852 0 66291
39573 38165 97007 0
2 3 1 4
output:
739502 316617 52930 0
answer:
723897 306638 52930 0
*/

