#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int a,b,c;
int P=1000000007;

int main(){
	cin>>a>>b;
	a=a%P;
	b=b%P;
	int tmp = P-a;
	if(tmp>b){
		c=a+b;
	}else {
		c=b-tmp;
	}
	cout<<c;
}

