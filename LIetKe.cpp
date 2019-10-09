
#include <bits/stdc++.h>
#include <iostream>

#define MAX 100
int n;
int x[MAX];
int cnt;

using namespace std;

int check(int v, int k){
	return 1;
}

void solution(){
	for(int i=1;i<=1;i++)
		cout<<x[i];
	//cout<<endl;	
}

void TRY(int k){
	for(int v=0;v<=n;v++){
		if(check(v,k)){
			x[k]=v;
			if(k==n) solution();
			else TRY(k+1);
		}
	}
}

void input(){
	cin>>n;
}

void solve(){
	TRY(1);
}

int main(){
	input();
	solve();
}
