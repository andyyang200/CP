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


int beat[1005];
int x[105][105];
int main(){
    int n;
    cin >> n;
    int t = (n - 1) / 2;
    FOR(i, 0, n){
        FOR(j, i + 1, n){
            if (beat[i] < t){
                beat[i]++;
                x[i][j] = 1;
            }
            else{
                beat[j]++;
                x[j][i] = 1;
            }
        }
    }
    FOR(i, 0, n){
        FOR(j, 0, n){
            if (x[i][j]){
                cout << i + 1 << " " << j + 1 << endl;
            }
        }
    }
}

