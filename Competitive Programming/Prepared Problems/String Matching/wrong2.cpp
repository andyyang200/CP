#include <iostream>
#include <cstring>
#include <string>

using namespace std;

long long n,pow,hs,hst,ht[100005],ht2[200005],cnt,cnt2;
string s,t,t2;

int main(){
	cin>>n>>s>>t;
	t2=t+t;
	pow=1;
	for(int i=0;i<s.size();i++){
		hs+=s[i]*pow;
		pow*=1000000009;
	}
	pow=1;
	for(int i=0;i<t.size();i++){
		ht[i+1]=t[i]*pow+ht[i];
		pow*=1000000009;
	}
	pow=1;
	for(int i=0;i<t2.size();i++){
		ht2[i+1]=t2[i]*pow+ht2[i];
		pow*=1000000009;
	}
	hst=hs;
	for(int i=0;i+s.size()<=t2.size();i++){
		if(hst==ht2[i+s.size()]-ht2[i])cnt2++;
		hst*=1000000009;
	}
	hst=hs;
	for(int i=0;i+s.size()<=t.size();i++){
		if(hst==ht[i+s.size()]-ht[i])cnt++;
		hst*=1000000009;
	}

	cout<<(cnt2-2*cnt)*(n-1)+cnt*n<<"\n";
}
