#include <stdio.h> 

int n;
int i,j;
long long a[1000000] ;
long long res;
long long sum;

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	int res=a[0];
	int sum = a[0];
	for(int i=1; i < n; i++){
		if(sum>0){
			sum+=a[i];
		}else{
			sum=a[i];
		}
		if(sum>res){
			res=sum;
		}
	}
	printf("%d",res);
}

