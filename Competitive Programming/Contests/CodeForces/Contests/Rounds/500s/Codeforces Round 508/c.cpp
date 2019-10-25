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

int a[100005], b[100005];

int main(){
    int n;
    cin >> n;
    FOR(i, 0, n) cin >> a[i];
    FOR(i, 0, n) cin >> b[i];
    sort(a, a + n);
    sort(b, b + n);
    reverse(a, a + n);
    reverse(b, b + n);
    ll score = 0;
    int i = 0;
    int j = 0;
    FOR(moves, 0, 2 * n){
        if (moves % 2 == 0) {
            if (a[i] >= b[j]){
                score += a[i];
                i++;
            }
            else{
                j++;
            }
        }
        else{
            if (a[i] >= b[j]){
                i++;
            }
            else{
                score -= b[j];
                j++;
            }
        }
    }
    cout << score << endl;
}

