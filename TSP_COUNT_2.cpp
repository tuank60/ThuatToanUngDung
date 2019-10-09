#include <stdlib.h>
#include <stdio.h>
#define MAX 100

int m,n;
int c[MAX][MAX];
int f, count;
int cmin;
int appear[MAX];
int x[MAX];

void input(){
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			scanf("%d",&c[i][j]);
			if(cmin > c[i][j]) cmin = c[i][j];
		}
	}
}

int check(int v, int k){
	return !appear[v];
}

void solution(){
	if(f + c[x[n]][1] <= m) count ++;
}

void TRY(int k){
	for(int v=2; v<=n; v++){
		if(check(v,k)){
			x[k] = v;
			f = f + c[x[k-1]][x[k]];
			appear[v] = 1;
			if(k==n) solution();
			else if(f+(n-k+1)*cmin < m){
				TRY(k+1);
			}
			f = f - c[x[k-1]][x[k]];
			appear[v] = 0;
		}
	}
}


int solve(){
	f = 0;
	count = 0;
	x[1] = 1;
	for(int i=2; i<=n;i++) appear[i] = 0;
	TRY(2);
	printf("%d", count);
	
}
int main(){ 
	input();
	solve();
}
