#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;


int n;
int a[100];
int P=1000000007;

int main(){
//	cin>>n;
//	//int k=0;
//	for(int i=0;i<n;i++){
//		cin>>a[i];
//		//a[i]=a[i]%P;
//		//k+=a[i];
//	}
//	for(int i=0;i<n-1;i++){
//		a[i]=a[i]%P;
//		a[i+1]=a[i+1]%P;
//		int tmp = P-a[i];
//		if(tmp>a[i+1]){
//			a[i+1]=a[i]+a[i+1];
//		}else{
//			a[i+1]=a[i+1]-tmp;
//		}
//		
////	}
////	if(k>P){
////		cout<<k%P;
////	}else{
////		cout<<k;
//	}
//	cout<<a[n-1];
//	
	cin>>n;
	int k=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		k=(a[i]%P+k)%P;
	}
	cout<<k;
}

