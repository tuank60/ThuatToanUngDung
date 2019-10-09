//de quy quay lui (liet ke hoan vi 1,2,...,n)
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define MAX 100
int n;
int x[MAX];
int appear[MAX]; //appear = 1 co nghia v da suat hien

int check(int v,int k){
	return !appear[v];
}

void solution(){
	for(int i=1; i<=n;i++)
		cout<<x[i]<<"";
	cout<<endl;
}

void TRY(int k){
	for(int v=1;v<=n;v++){
		if (check(v,k)){
			x[k]=v;
			appear[k]=v; // danh dau v da suat hien
			if(k==n) solution();
			else{
				TRY(k+1);
				appear[v]=0; // khoi phuc trang thai
			}
			
		}
	}
}

void input(){
	cin>>n;
}

void solve(){
	for(int v=1;v<n;v++) appear[v]=0;
	TRY(1);
}

int main(){
	input();
	solve();
}



