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

int main(){
    int n;
    cin >> n;
    if (n <= 2) {
        cout << "No" << endl;
        return 0;
    }
    int sum = n * (n + 1) / 2;
    int x = -1;
    for(int i = 2; i <= sqrt(sum); i++) {
        if (sum % i == 0){
            x = i;
            break;
        }
    }
    if (x == -1) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    cout << 1 << " " << x << endl;
    cout << n - 1 << " ";
    FOR(i, 1, n + 1) {
        if (i != x) cout << i << " ";
    }
    cout << endl;

}

