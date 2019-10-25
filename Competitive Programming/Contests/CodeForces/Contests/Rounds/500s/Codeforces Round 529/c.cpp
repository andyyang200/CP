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
int a[500];
int main(){
    int n, k;
    cin >> n >> k;
    int x = 0;
    FOR(i, 0, 31){
        a[i] = (n & (1 << i)) > 0;
        x += a[i];
    }
    RFOR(i, 31, 0){
        while(a[i] && x < k){
            x++;
            a[i]--;
            a[i-1] += 2;
        }
    }
    if (x != k){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        FOR(i, 0 ,31){
            FOR(j, 0, a[i]){
                printf("%d ", 1 << i);
            }
        }
        printf("\n");
    }
}

