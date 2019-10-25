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

string a[1000005];
string b[1000005];
map<string, int> dif;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        scanf("%d", &n);
        FOR(i, 0, n){
            cin >> a[i];
        }
        FOR(i, 0, n){
            cin >> b[i];
        }
        int prev = -1;
        FOR(i, 0, n){
            dif[a[i]]++;
            dif[b[i]]--;
            auto it = dif.find(a[i]);
            if (dif[a[i]] == 0){
                it = dif.find(a[i]);
                if (it != dif.end()){
                    dif.erase(it);
                }
            }
            if (dif[b[i]] == 0){
                it = dif.find(b[i]);
                if (it != dif.end()){
                    dif.erase(it);
                }
            }

            if (dif.size() == 0){
                cout << i - prev << " ";
                prev = i;
            }
        }
        cout << endl;
    }
}
/*
3
5
A
B
C
D
E
A
C
D
B
E
3
RED
BLUE
ORANGE
RED
BLUE
ORANGE
3
MOE
LARRY
CURLY
CURLY
MOE
LARRY
*/


