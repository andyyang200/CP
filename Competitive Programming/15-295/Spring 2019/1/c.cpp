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

int nim[5005];
int seen[5005];
bool update(int x){
    if (x < 5005) seen[x] = 1;
}
int main(){
    nim[0] = 0;
    nim[1] = 0;
    FOR(i, 2, 5005){
        fill(seen, seen + 5005, 0);
        update(nim[i - 2]);
        FOR(a, 1, i){
            int b = i - a - 2;
            if (b < 1) break;
            int x = nim[a] ^ nim[b];
            update(x);
        }
        FOR(x, 0, 5005){
            if (!seen[x]){
                    nim[i] = x;
                break;
            }
        }

    }
    int t;
    cin >> t;
    FOR(q, 0, t){
        int n;
        cin >> n;
        if (nim[n]){
            cout << "First" << endl;
        }
        else{
            cout << "Second" << endl;
        }
    }

}

