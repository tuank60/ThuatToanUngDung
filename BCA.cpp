#include <iostream>
#include <stdlib.h>
#include <time.h>

#define MAX_N 50
#define MAX_M 10 

using namespace std;

//input data structure
int N; //Number of class
int M; //Number of teachers
int sz[MAX_N]; // sz[i] The Number of teacher for course i
int t[MAX_N][MAX_M]; // t[c][i] the i th teacher that can teach course c
int h[MAX_N]; //h[c] is the Number of houses of course c each week
int A[MAX_N][MAX_N]; // SO TIET TRUNG

//variables

int X[MAX_N]; //X[i] the teacher assigned to course i
int f[MAX_M]; //f[j] the load of teacher j
int f_best; //best objective value


void input(){
	cin>>N;
	cin>>M;
	for(int i=1;i<=N;i++){
		cin>>h[i];
	}
	
	for(int i=1;i<=N;i++){
		cin>>sz[i];
		for(int j=0;j<sz[i];j++){
			cin>>t[i][j];
		}
	}
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cin>>A[i][j];
		}
	}
}

int check(int v, int k){
	for(int i=1;i<k-1;i++){
		if(A[i][k] && v==X[i]) return 0;
	}
	return 1;
}

void solution(){
	int max = 0;
	for(int i=1;i<=M;i++){
		if(max < f[i]) max = f[i];
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
			if(k==N){
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
	if(f_best == 1000000){
		cout<<"-1";
	}else{
		cout<<f_best;
	}
}

int main(){
	input();
	solve();
}
