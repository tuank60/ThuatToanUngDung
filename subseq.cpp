#include<stdio.h>
#define MAX 1000000

int N,M;
int a[MAX];
int count=0;

void input(){
	scanf("%d",&N);
	scanf("%d",&M);
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
}

void solve(){
	for(int v=0;v<N;v++){		
		int sum=a[v];
		if(sum<=M){
			count++;
			for(int j=v+1;j<N;j++){
				sum+=a[j];
				if(sum<=M){
					count++;
				}else break;
			}
		}
				
		//printf("\nsum=%d\n",sum);
	
					
		
	}
}
int main(){
	input();
	solve();
	printf("%d",count);
}

