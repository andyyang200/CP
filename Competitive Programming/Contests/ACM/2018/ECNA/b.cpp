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
int seq[10005];
int main(){
    int r, m;
    cin >> r >> m;
    set<int> s;
    FOR(i, 1, 10001){
        s.insert(i);
    }
    s.erase(s.find(r));
    int prev = r;
    if ( m == r){
        cout << 1 << endl;
        return 0;
    }
    seq[1] = r;
    FOR(i, 2, 10001){
        int d = *s.begin();
        s.erase(s.begin());
        int x = prev + d;
        if (d == m || x == m){
            cout << i << endl;
            return 0;

        }
        seq[i] = x;
        auto itr = s.find(x);
        if (itr != s.end()){
            s.erase(itr);
        }
        FOR(j, 1, i){
            int d = abs(x - seq[j]);
            if (d == m){

                cout << i << endl;
                return 0;
            }
            auto itr = s.find(d);
            if (itr != s.end()){
                s.erase(itr);
            }
        }
        prev = x;
    }
}

