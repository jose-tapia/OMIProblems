#include <bits/stdc++.h>
using namespace std;
int N,ans,mod=1000000007,A[101];
void brute(int S,int ind){
	if(ind==N){
		if(S==0)ans=(ans+1)%mod;
		return;
	}
	brute(S,ind+1);
	brute(S+A[ind],ind+1);
	brute(S-A[ind],ind+1);
}
int main(){
	int i,j,p,q;
	cin>>N;
	for(i=0;i<N;i++)cin>>A[i];
	brute(0,0);
	cout<<ans-1<<"\n";
}
