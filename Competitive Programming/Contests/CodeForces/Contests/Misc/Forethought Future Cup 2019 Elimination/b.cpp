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


int main(){
    string s;
    cin >> s;
    string t = "";
    int cnta = 0;
    for(int i = 0; i < s.length(); i++){
        if (s[i] != 'a'){
            t += s[i];
        }
        else{
            cnta++;
        }
    }
    if (t.length() % 2 == 1){
        cout << ":(" << endl;
    }
    else{
        string a = t.substr(0, t.length() / 2);
        string b = t.substr(t.length() / 2, t.length() / 2);
        if (a == b){

            string ans = s.substr(0, cnta + a.length());
            string ansremovea = "";
            for(int i = 0; i < ans.length(); i++){
                if (ans[i] != 'a'){
                    ansremovea += ans[i];
                }
            }
            if (ansremovea == a && s.substr(cnta + a.length()) == a){
                cout << ans << endl;
            }
            else{
                cout << ":(" << endl;
            }
        }
        else{
            cout << ":(" << endl;
        }
    }
}
