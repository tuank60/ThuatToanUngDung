#include<iostream>
using namespace std;
int n;
int c[1000000];
int kq;
void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> c[i];
	}
}
int addmod(int a, int b, int p)
{
	a = a%p;
	b = b%p;
	int tmp;
	tmp = p - a;
	if (tmp > b) return a + b;
	else return b - tmp;
}
int nhanmod(int a, int  b, int p)
{
	int  c, tam;
	if (a>b)
	{
		tam = a;
		a = b;
		b = tam;
 
	}
	if (a == 1) return(b%p);
	if (a / 2 == 1)
		c = b %p;
	else
	{
		c = nhanmod(b, a / 2, p);
	}
 
	if (a % 2 == 0)
	{
 
		return addmod(c, c, p);
	}
	else
	{
		return (addmod(addmod(c, c, p), b, p));
	}
 
 
 
}
void solve()
{
 
	kq = c[0];
	for (int i = 1; i < n; i++)
	{
		kq = nhanmod(c[i], kq, 1000000007);
	}
	cout << kq << endl;
}
int main()
{
	kq = 1;
	
	input();
	
	solve();
	return 0;
}
