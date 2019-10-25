#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int s,t;
long long n;
char S[63];
char T[100013];
int dp[63][100013];
const int MOD = 1000000007;

void mult(vector<vector<int> > a, vector<vector<int> > b, vector<vector<int> > &dest) {
	vector<vector<int> > tmp;
	for (int i=0;i<a.size();i++) tmp.push_back(vector<int>(b[0].size()));
	for (int i=0;i<a.size();i++) for (int j=0;j<b[0].size();j++) {
		for (int k=0;k<b.size();k++) tmp[i][j] = (tmp[i][j]+(long long) a[i][k]*b[k][j])%MOD;
	}
	for (int i=0;i<a.size();i++) for (int j=0;j<b[0].size();j++) dest[i][j] = tmp[i][j];
}

void solveSmall(int to) {
	for (int i=1;i<to;i++) for (int j=0;j<t;j++) T[i*t+j]=T[j];
	for (int j=0;j<=to*t;j++) dp[s][j] = 1;
	for (int i=s-1;i>=0;i--) for (int j=to*t-1;j>=0;j--) dp[i][j] = (dp[i][j+1]+((T[j]==S[i]) ? dp[i+1][j+1] : 0))%MOD;
}

int main() {
	scanf("%lld %s %s",&n,&S,&T);
	s = strlen(S);
	t = strlen(T);
	if (n<=s) {
		solveSmall(n);
		printf("%d\n",dp[0][0]);
	} else {
		solveSmall(s);
		vector<vector<int> > A;
		A.push_back(vector<int>());
		for (int i=0;i<=s;i++) A[0].push_back(dp[i][0]);
		n-=s;
		vector<vector<int> > B;
		for (int r=0;r<=s;r++) {
			B.push_back(vector<int>());
			for (int j=0;j<=s;j++) dp[j][t] = 0;
			for (int i=0;i<=s;i++) dp[i][0] = 0;
			for (int j=0;j<=t;j++) dp[r][j] = 1;
			for (int i=r-1;i>=0;i--) for (int j=t-1;j>=0;j--) dp[i][j] = (dp[i][j+1]+((T[j]==S[i]) ? dp[i+1][j+1] : 0))%MOD;
			for (int j=0;j<=s;j++) B[r].push_back(dp[j][0]);
		}
		vector<vector<int> > ans;
		for (int i=0;i<=s;i++) ans.push_back(vector<int>(s+1));
		for (int i=0;i<=s;i++) ans[i][i] = 1;
		for (int i=0;i<63;i++) {
			if (n&(1LL<<i)) mult(ans,B,ans);
			mult(B,B,B);
		}
		mult(A,ans,A);
		printf("%d\n",A[0][0]);
	}

	return 0;
}
