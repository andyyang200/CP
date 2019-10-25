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

int a[100005];
int main(){
    int pos = 0;
    int neg = 0;
    int n;
    cin >> n;
    FOR(i, 0, n){
        cin >> a[i];
        if (a[i] < 0) neg++;
        if (a[i] > 0) pos++;
    }
    if (pos >= (n + 1) / 2){
        cout << 1 << endl;
    }
    else if (neg >= (n + 1) / 2){
        cout << -1 << endl;
    }
    else{
        cout << 0 << endl;
    }

}

