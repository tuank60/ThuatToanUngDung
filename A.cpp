#include <iostream>

#define MAX 100
using namespace std;

int N,M,K;
int c[MAX][MAX];
int x[MAX];
int Min_x[MAX];
bool check[MAX];
int f,Min_f;
int count[MAX],Min_c=1000000;

void input () {
	cin>>N;
	cin>>M;
	cin>>K;
    for(int i = 1; i<=M; i++) {
        for(int j = 1; j<=N; j++) {
            cin>>c[i][j];
        }
    }
     for(int i = 1; i<=M; i++) {
        for(int j = 1; j<=N; j++) {
            if(Min_c>c[i][j]){
            	Min_c=c[i][j];
			}
        }
    }
}

void solution(){
	if(f<Min_f){
		Min_f=f;
		for (int i=1;i<=N;i++){
			Min_x[i]=x[i];
		}	
	}
}

void TRY(int k){	
	for (int v=1; v<=M;v++){
		if(count[v]<K){
			count[v]++;
			x[k]=v;
			check[v]=true;
			f+=c[v][k];
			int g=f+(N-k+1)*Min_c;
			if(k==N) solution();
			else if(g<Min_f) TRY(k+1);
			check[v]=false;
			f-=c[v][k];
			count[v]--;
		}
	}
}

void solve(){
	for(int v=1;v<=N;v++)check[v]=false;
	for(int v=1;v<=M;v++)count[v]=0;
	f=0;
	Min_f=1000000;		
	TRY(1);
}

int main(){
	input();
	solve();
	cout<<Min_f;
}


