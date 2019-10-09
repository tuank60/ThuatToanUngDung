#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int x,n;
int P=1000000007;
//TU TINH
//int sqr(int x) {
//    return x*x;
//}
//
//int pow(int a, int b, int MOD) {
//    if (b == 0) return 1 % MOD;
//    else
//        if (b % 2 == 0)
//            return sqr(pow(a, b/2)) % MOD;
//        else
//            return a * (sqr(pow(a, b/2)) % MOD) % MOD;

int addmod(int a, int b, int P){
	a=a%P;
	b=b%P;
	int tmp = P-a;
	if(tmp>b){
		return a+b;
	}else {
		return b-tmp;
	}
}

int mulmod(int a, int b,int P){
	if(a==1)return b%P;
	if(b==1)return a%P;
	if(a>b){
		int tmp=a;a=b;b=tmp;
	}
	int c = mulmod(a/2,b,P);
	c=addmod(c,c,P);
	if(a%2==0){
		return c;
	}else{
		return addmod(c,b,P);
	}
}

int XmuN(int X, int N){
	if(N==1)return X%P;
	int a=XmuN(X,N/2);
	a = mulmod(a,a,P);
	if(N%2==0)return a;
	else return mulmod(a,X,P);
	
}
int main(){
	cin>>x>>n;
	cout<<XmuN(x,n);
}


