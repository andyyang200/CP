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
    int n;
    cin >> n;
    multiset<int> s;
    vector<string> v1;
    vector<string> v2;
    FOR(i, 0, n){
        string str;
        cin >> str;
        int x;
        if (str != "removeMin"){
            scanf("%d", &x);
        }
        if (str == "insert"){
            s.insert(x);
        }
        else if (str == "removeMin"){
            if (s.empty()){
                v1.push_back("insert");
                v2.push_back("-1000000000");
            }
            else{
                s.erase(s.begin());
            }
        }
        else{ // findmin
            while(!s.empty() && *s.begin() < x){
                v1.push_back("removeMin");
                v2.push_back("");
                s.erase(s.begin());
            }
            if (s.empty() || *s.begin() != x){
                v1.push_back("insert");
                v2.push_back(to_string(x));
                s.insert(x);
            }
        }
        v1.push_back(str);
        if (str != "removeMin")
            v2.push_back(to_string(x));
        else{
            v2.push_back("");
        }
    }
    cout << v1.size() << endl;
    FOR(i, 0, v1.size()){
        cout << v1[i];
        printf(" ");
        cout << v2[i];
        printf("\n");
    }
}
