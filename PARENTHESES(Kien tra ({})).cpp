#include <stdio.h>
#include <string.h>
using namespace std;


#define MAX_L 1000
char S[100];
int zi;

void Push(char a){
	zi++;	
	S[zi-1]=a;
	
}

char PoP(){
	char c = S[zi-1];
	zi--;
	return c;
}

int match(char c1, char c2){
	if(c1=="(" && c2==")") return 1;
	if(c1=="{" && c2=="}") return 1;
	if(c1=="[" && c2=="]") return 1;
	return 0;
}

int check(char* s){
	initStack();
	for (int i=0;i<strlen(s);i++){
		if(s[i]=="{"||s[i]=="["||s[i]=="("){
			Push(s[i]);
		}else{
			if(zi<0) return 0;
			char c = PoP();
			if(match(c,s[i])) return 0; 
		}
	}	
	return zi=0;
}

void solve(){
	int N;
	cin>>N;
	char s[MAX_L];
	for(int i=0;i<N; i++){
		cin>>s[i];
	}
	int ans = check(s[i]);
	cout<<ans<<endl;
	
}
int main(){
	solve();
}
