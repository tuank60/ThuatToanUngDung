//de quy quay lui (liet ke hoan vi 1,2,...,n)
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define MAX 100
int n;
int x[MAX];
int appear[MAX]; //appear = 1 co nghia v da suat hien
int c[MAX][MAX];
int f; // do dai trong qua trinh duyet
int f_best; // do dai it nhat
int x_best[MAX];
int cmin;

int check(int v,int k){
	return !appear[v];
}

void solution(){
	if (f+c[x[n]][0]<f_best){
		f_best=f+c[x[n]][0];
		for(int i=0;i<=n;i++){
			x_best[i]=x[i];
		}
	}
}

void TRY(int k){
	for(int v=1;v<=n;v++){
		if (check(v,k)){
			x[k]=v;
			f+=c[x[k-1]][x[k]];
			appear[v]=1; // danh dau v da suat hien
			if(k==n) solution();
			else{
				if(f+cmin*(n-k+1)<f_best){
					TRY(k+1);	
				}
			}
			appear[v]=0; // khoi phuc trang thai
			f-=c[x[k-1]][x[k]];
		}
	}
}

void input(){
	cmin=100000;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			cin>>c[i][j];
			if(i!=j && cmin>c[i][j]){
				cmin=c[i][j];
			}
		}
	}
}

void solve(){
	f=0;
	f_best=100000;
	for(int v=1;v<=n;v++) appear[v]=0;
	x[0]=1;
	TRY(1);
	cout<<f_best;
}

int main(){
	input();
	solve();
}



