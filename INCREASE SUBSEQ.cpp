#include <iostream>

using namespace std;

int n;
int a[100];
int ct;
int st;
int maxt;

main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	maxt=0;
	
	for(int i=0;i<n;i++){
		//cin>>a[i];
		st=a[i];
		ct=1;
		for(int j=i+1;j<n;j++){
			if(a[j]>st){
				ct+=1;
				st=a[j];
			}
		}
		if(ct>maxt){
			maxt=ct;
		}
	}
	cout<<maxt;
}
