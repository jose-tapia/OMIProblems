#include <bits/stdc++.h>
using namespace std;
const int MaxN=101,MaxS=51102;
int mod=1000000007;
int dp[MaxS][2];
int main(){
	int i,j,p,q,S,N,D,a,b,C=MaxS/2;
	S=0;
	cin>>N;
	a=1,b=0;
	dp[C][a]=1;
	for(i=0;i<N;i++){
		cin>>D;
		S+=D;
		for(j=C-S;j<=C+S;j++)
			dp[j][b]=(dp[j-D][a]+(dp[j][a]+dp[j+D][a])%mod)%mod;
		swap(a,b);
	}
	cout<<dp[C][a]-1<<"\n";
}
