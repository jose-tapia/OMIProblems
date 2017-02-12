#include <bits/stdc++.h>
using namespace std;
const int MaxS=2501,MaxN=101;
long long int dp[MaxS][MaxS][2],mod=1000000007;
long long int arr[MaxN];
int main(){
	long long int S=0,a=1,b=0,i,j,p,q,N,D;
	cin>>N;
	for(i=0;i<N;i++)cin>>arr[i];
	dp[0][0][1]=1;	
	for(i=0;i<N;i++){
		D=arr[i];
		S+=D;
		for(j=0;j<=S;j++){
			for(p=0;p<=S-j;p++){
				if(j<D&&p<D)dp[j][p][b]=dp[j][p][a];
				else {
					if(j<D){
						dp[j][p][b]=(dp[j][p-D][a]+dp[j][p][a])%mod;
					}
					else {
						if(p<D){
							dp[j][p][b]=(dp[j-D][p][a]+dp[j][p][a])%mod;
						}
						else {
							dp[j][p][b]=(dp[j-D][p][a]+(dp[j][p-D][a]+dp[j][p][a])%mod)%mod;

						}
					}
				}
			}
		}
		swap(a,b);
	}
	long long int ans=0;
	for(i=0;i<=S;i++){
		ans=(ans+dp[i][i][a])%mod;
	}
	cout<<ans-1<<"\n";
}
