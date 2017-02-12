#include <bits/stdc++.h>
using namespace std;

long long int mod=1000000007;
long long int bin[121][121];

int main(){
	long long int N,i,j,p,q;
	cin>>N;
	for(i=0;i<N;i++)cin>>p;

	for(i=0;i<=N;i++)bin[i][i]=1,bin[i][0]=1;
	for(i=1;i<=N;i++){
		for(j=1;j<i;j++){
			bin[i][j]=(bin[i-1][j]+bin[i-1][j-1])%mod;
		}
	}
	long long int ans=0;
	for(i=1;i<=N;i++){
		if(N-i*2>=0){
			ans=(ans+(bin[N][i]*bin[N-i][i])%mod)%mod;
		}
	}
	cout<<ans<<"\n";
}
