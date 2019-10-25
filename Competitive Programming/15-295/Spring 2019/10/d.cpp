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
string s;
int n;
int m[26][26][5005];
int strat[250];
int main(){
    cin >> s;
    n = s.length();
    FOR(i, 0, n){
        FOR(d, 1, n){
            char c1 = s[i];
            char c2 = s[(i + d) % n];
            m[c1 - 'a'][c2 - 'a'][d]++;
        }
    }
    for(char c = 'a'; c <= 'z'; c++){
        int maxx = 0;
        FOR(d, 1, n){
            int x = 0;
            FOR(i, 0, n){
                char c2 = s[(i + d) % n];
                if (s[i] == c && m[c - 'a'][c2 - 'a'][d] == 1){
                    x++;
                }
            }
            if (x > maxx){
                maxx = x;
                strat[c] = d;
            }
        }
    }
    ld ans = 0;
    FOR(i, 0, n){
        char c1 = s[i];
        int d = strat[c1];
        char c2 = s[(i + d) % n];
        if (m[c1 - 'a'][c2 - 'a'][d] == 1){
            ans++;
        }
    }
    ans /= n;
    printf("%.15Lf\n", ans);

}


