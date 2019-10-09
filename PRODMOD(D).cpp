#include <iostream>

using namespace std;

#define MAX 1000000

int N;
int a[MAX];
int P=1000000007;
int result;
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

int mulmod(int a, int  b, int p)
{
	int  c, tam;
	if (a>b){
		tam = a;
		a = b;
		b = tam;
	}
	if (a == 1) return(b%p);
	if (a / 2 == 1)
		c = b %p;
	else{
		c = mulmod(b, a / 2, p);
	}
	if (a % 2 == 0){
		return addmod(c, c, p);
	}
	else{
		return (addmod(addmod(c, c, p), b, p));
	}
}

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
}

void solve()
{
	result = a[0];
	for(int i = 1; i < N; i++)
	{
		result = mulmod(a[i],result,P);
	}
	cout<<result<<endl;
}

int main(){
	result=1;
	input();
	solve();
	return 0;
}
