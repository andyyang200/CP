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


struct Node{
    Node* n[26];
    int cnt = 0;
    void add(string& s, int i){
        if (i == s.length()){
            return;
        }
        else{
            if (n[s[i] - 'a'] == NULL){
                n[s[i] - 'a'] = new Node();
                cnt++;
            }
            n[s[i] - 'a']->add(s, i + 1);
        }
    }
    bool win(){
        if (cnt == 0){
            return false;
        }
        FOR(i, 0, 26){
            if (n[i] != NULL && !n[i]->win()){
                return true;
            }
        }
        return false;
    }
    bool lose(){
        if (cnt == 0){
            return true;
        }
        FOR(i, 0, 26){
            if (n[i] != NULL && !n[i]->lose()){
                return true;
            }
        }
        return false;
    }
};

Node root;
int main(){

    int n, k;
    scanf("%d%d", &n, &k);
    FOR(i, 0, n){
        string s;
        cin >> s;
        root.add(s, 0);
    }

    bool w = root.win();
    bool l = root.lose();
    if (!w){
        cout << "Second" << endl;
        return 0;
    }
    else{
        if (!l){
             cout << (k % 2 == 1 ? "First" : "Second") << endl;
        }
        else{
            cout << "First" << endl;
        }
    }
}
/*
5 6
abas
dsfdf
abacaba
dartsidius
kolobok

answer: Second
*/

