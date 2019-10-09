#include<stdio.h>
#include<stdlib.h>
#define MAX 1000000
int N,M;
int c[16][16];
int x[MAX];
bool m[MAX];//Mang danh dau
int f;//chi phi
int count=0,c_min=99999;
void updateBest(){
	if(f+c[x[N]][x[1]]<=M){
//		printf("x[N]=%d",x[N]);
//		printf("\nf=%d\n",f+c[x[N]][x[1]]);
		count++;
	}
}
void Try(int k){
	
	for (int v=1; v<=N;v++){
		if(!m[v]){
			x[k]=v;
			m[v]=true;
			f+=c[x[k-1]][x[k]];
			int g=f+(N-k+1)*c_min;
			if(k==N) updateBest();
			else if(g<M) Try(k+1);
			m[v]=false;
			f-=c[x[k-1]][x[k]];
		}
	}
}
void solve(){
	for(int v=1;v<=N;v++)m[v]=false;
	f=0;	
	x[1]=1;
	m[1]=true;
	Try(2);
	
}

void input () {
   
    scanf("%d",&N);
    scanf("%d",&M);
    for(int i = 1; i<=N; i++) {
        for(int j = 1; j<=N; j++) {
            scanf("%d",&c[i][j]);
            if(i!=j&&c_min>c[i][j]){
            	c_min=c[i][j];
            	//printf("\nc_min=%d",c_min);
			}
        }
    }

//    printf("\nc=%d",c_min);
    
    
}
int main(){

	input();
	solve();
	
	printf("%d",count);

}
