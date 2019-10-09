#include <iostream>

#define MAX 100

using namespace std;

int N,M;
int x[MAX];
int c[MAX][MAX];
int appear[MAX];
int f, count;
int cmin;


int check(int v, int k){
	return !appear[v];
}

void solution(){
	if(f + c[x[N-1]][1] <= M) count ++;
}

void TRY(int k){
	for(int v=2; v<=N; v++){
		if(check(v,k)){
			x[k] = v;
			f = f + c[x[k-1]][v];
			appear[v] = 1;
			if(k==N-1) solution();
			else if(f+(N-k-1)*cmin < M){
				TRY(k+1);
			}
			f = f - c[x[k-1]][v];
			appear[v] = 0;
		}
	}
}

int solve(){
	f = 0;
	count = 0;
	x[0] = 1;
	for(int i=1; i<=N;i++) appear[i] = 0;
	TRY(1);
	cout<<count;
	
}

void input(){
	cin>>N;
	cin>>M;
	cmin=1000000;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cin>>c[i][j];
			if(i!=j && cmin > c[i][j]) cmin = c[i][j];
		}
	}
}

int main(){ 
	input();
	solve();
}

