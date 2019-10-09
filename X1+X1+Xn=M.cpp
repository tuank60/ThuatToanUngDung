//de quy quay lui(tim cac cap so thoa man x1+x2+...+xn=M)
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define MAX 100
int n,M;
int x[MAX];
int T;
void solution(){
	for (int i=1;i<n;i++)
		cout<<x[i]<<"";
	cout<<endl;
}

int check(int v,int k){
	int T = 0;
	for (int i=1;i<=k-1;i++) T+=x[i];
	if(k<n) return T+v<M;
	return T+v==M;
}

void TRY(int k){
	for(int v=1;v<=n;v++){
		if (check(v,k)){
			x[k]=v;
			if(k==n){
				solution();	
			}
			else{
				TRY(k+1);
			}
		}
	}
}

void input(){
	cin>>n>>M;
}

void solve(){
	TRY(1);
}

int main(){
	T=0;
	input();
	solve();
}



