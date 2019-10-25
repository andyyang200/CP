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
void p(int *a[5], int n, int m){
    FOR(i, 0, n){
        FOR(j, 0, m){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
int* a[5];
int main(void)
{
    FOR(i, 0, 5){
        a[i] = new int[5];
        FOR(j, 0, 5){
            a[i][j] = i;
        }
    }
    p(a, 5, 5);
}


