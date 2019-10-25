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
  int tests;
  cin>>tests;
  for (int test=1; test <= tests; test++){


      string a;
      cin >> a;

      int n = a.length();
      string s="";
      string t="";
      for (int i=n-1; i >= 0; i--){
        if (a[i]=='0'){
          s+='0';
          t+='0';
        }
        else if (a[i]=='5'){
          s+='2';
          t+='3';
        }
        else{
          t+='1';
          s+=a[i]-1;
        }
      }
      while(s[0]=='0'&&s.length()>0){
        s=s.substr(1, s.length());
      }

       printf("Case #%d: ", test);
       cout << s << " " << t << endl;

  }
}



