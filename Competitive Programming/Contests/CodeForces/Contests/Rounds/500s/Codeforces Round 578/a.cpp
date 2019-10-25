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
bool x[10];
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    FOR(i, 0, n){
        if (s[i] == 'L'){
            FOR(i, 0, 10){
                if (!x[i]){
                    x[i] = true;
                    break;
                }
            }
        }
        else if (s[i] == 'R'){
            RFOR(i, 9, -1){
                if (!x[i]){
                    x[i] = true;
                    break;
                }
            }
        }
        else{
            x[s[i] - '0'] = false;
        }
    }
    FOR(i, 0, 10){
        cout << x[i];
    }
    cout << endl;
}

