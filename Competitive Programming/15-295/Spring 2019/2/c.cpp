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
int prea[100005];
int preA[100005];
int sufa[100005];
int sufA[100005];
int main(){
    string s;
    cin >> s;
    FOR(i, 1, s.length() + 1){
        prea[i] = prea[i - 1];
        preA[i] = preA[i - 1];
        char c = s[i - 1];
        if ('a' <= c && c <= 'z'){
            prea[i]++;
        }
        else{
            preA[i]++;
        }
    }
    RFOR(i, s.length(), 0){
        sufa[i] = sufa[i + 1];
        sufA[i] = sufA[i + 1];
        char c = s[i - 1];
        if ('a' <= c && c <= 'z'){
            sufa[i]++;
        }
        else{
            sufA[i]++;
        }
    }
    int ans = INF;
    FOR(i, 1, s.length() + 2){
        int x = prea[i - 1] + sufA[i];
        ans = min(ans, x);
    }
    cout << ans << endl;
}


