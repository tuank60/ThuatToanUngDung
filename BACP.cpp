
#include <iostream>
#include <stdlib.h>
#include <time.h>

#define MAX_N 30
#define MAX_M 10 

using namespace std;

int N;
int M;
int c[MAX_N];
int A[MAX_N][MAX_N];

int X[MAX_N]; 
int f[MAX_M]; //f[j] the load 
int f_best; //best objective value

void input(){
	cin>>N;
	cin>>M;
	
	for(int i=1;i<=N;i++){
		cin>>h[i];
	}
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cin>>A[i][j];
		}
	}
}
// sua lai ham check
int check(int v, int k){
	for(int i=1;i<k-1;i++){
		if(A[i][k] == 1) return 0;
		if(v=X[k]) return 0;
	}
	return 1;
}

void solution(){
	int max = 0;
	for(int i=1;i<=M;i++){
		if(max <f[i]) max = f[i];
	}
	if(max<f_best){
		f_best = max;
	}
}

void TRY(int k){
	for(int v=1; v<=M;v++){
		if(check(v,k)){
			X[k]=v;
			f[v]+=h[k]; //accmulate load for teacher v
			if(k=N){
				solution();
			}else{
				TRY(k+1);
			}
			f[v]-=h[k]; //recover load when breaktracking 
		}
	}
}

void solve(){
	f_best=1000000;
	for (int i=1;i<=M;i++){
		f[i]=0;
	}
	TRY(1);
	cout<<f_best;
}

int main(){
	input();
	solve();
}

