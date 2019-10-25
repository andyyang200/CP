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

map<char, int> cnt;
vector<char> v;
set<char> s;
void print(int i){
    for(int j = 0; j < cnt[v[i]]; j++){
        cout << v[i];
    }
}
int main(){
    int t;
    cin >> t;
    for(int asd = 0; asd < t; asd++){
        string str;
        cin >> str;
        cnt.clear();
        s.clear();
        for(int i = 0; i < str.length(); i++){
            s.insert(str[i]);
            cnt[str[i]]++;
        }
        v.clear();
        for(char x : s){
            v.push_back(x);
        }
        if (v.size() == 2 && v[0] + 1 == v[1]){
            printf("No answer\n");
            continue;
        }
        else if (v.size() == 3 && v[0] + 1 == v[1] && v[1] + 1 == v[2]){
            printf("No answer\n");
            continue;
        }
        else if (v.size() == 3 && v[0] + 1 == v[1]){
            print(0);
            print(2);
            print(1);
            cout << endl;
            continue;
        }
        else if (v.size() == 3 && v[1] + 1 == v[2]){
            print(2);
            print(0);
            print(1);
            cout << endl;
            continue;
        }
        else{
            for(int i = 1; i < v.size(); i += 2){
                print(i);
            }
            for(int i = 0; i < v.size(); i += 2){
                print(i);
            }
            cout << endl;
        }
    }
}

