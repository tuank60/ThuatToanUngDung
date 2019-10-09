#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
int N,M,K;
int c[100][100];
int x[100];
int x_min[100];
bool m[100];//Mang danh dau
int f,f_min;//chi phi
int count[100],c_min=99999;

void input () {
	scanf("%d",&N);
    scanf("%d",&M);
    scanf("%d",&K);
    for(int i = 1; i<=M; i++) {
        for(int j = 1; j<=N; j++) {
            scanf("%d",&c[i][j]);
           
        }
    }
     for(int i = 1; i<=M; i++) {
        for(int j = 1; j<=N; j++) {
           
            if(c_min>c[i][j]){
            	c_min=c[i][j];
            	//printf("\nc_min=%d",c_min);
			}
        }
    }
 
}
void updateBest(){
	if(f<f_min){
//		printf("%d ",f);
		f_min=f;
		for (int i=1;i<=N;i++){
			x_min[i]=x[i];
		}	
	}
}
void Try(int k){	
	for (int v=1; v<=M;v++){
		if(count[v]<K){
			count[v]++;
			x[k]=v;
			m[v]=true;
			f+=c[v][k];
			int g=f+(N-k+1)*c_min;
			if(k==N) updateBest();
			else if(g<f_min) Try(k+1);
			m[v]=false;
			f-=c[v][k];
			count[v]--;
		}
	}
}
void solve(){
	for(int v=1;v<=N;v++)m[v]=false;
	for(int v=1;v<=M;v++)count[v]=0;
	f=0;
	f_min=99999;		
	Try(1);
	
}

int main(){
	input();
//	printf("%d %d %d",N,M,K);
//	for(int i = 1; i<=M; i++) {
//        for(int j = 1; j<=N; j++) {
//            printf("%d ",c[i][j]);
//           
//        }
//        printf("\n");
//    }
    
	solve();
	printf("%d",f_min);	

	
}
