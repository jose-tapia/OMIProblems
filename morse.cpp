#include <bits/stdc++.h>
using namespace std;
int cantidad;
string letras[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
string word;
void dfs(string act,int ind){
	if(ind==word.size()){
		if(cantidad<100000){
			cantidad++;
		}
		else {
			cout<<act<<"\n";
			exit(0);
		}
		return;
	}
	for(int i=0;i<26;i++){
		int p=1;
		for(int j=0;j<letras[i].size();j++){
			if(ind+j>=word.size()||letras[i][j]!=word[ind+j])p=0;
		}
		if(p)dfs(act+(char)(i+'A'),ind+letras[i].size());
	}
}
string translate(string w){
	string K="";
	int i;
	for(i=0;i<w.size();i++){
		if('a'<=w[i]&&w[i]<='z')w[i]=w[i]-'a'+'A';
		K+=letras[w[i]-'A'];
	}
	return K;
}

int main(){
	int i,j;
/*	string A,B;
	cin>>A>>B;
	string ans[2]={"No es lo mesmo","Es lo mesmo"};
	cout<<ans[(translate(A)==translate(B))]<<"\n";
	return 0;
*/	while(cin>>word){
		cout<<word<<":\n";
		word=translate(word);
		cout<<word<<"\n";
		dfs("",0);
	}

}


