//#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#define NMAX 100
int n, m;
int x[NMAX];
int appear[NMAX];
int c[100][100];
int s;
int dem;
int cmin;
void input()
{
	cmin = 100000000;
	cin >> n;
	cin >> m;
	
	for (int i = 1; i <= n; i++)
	{
		appear[i] = 0;//chua xuat hien
	}
	for (int i = 1; i <=n; i++)
	{
		for (int j = 1; j <=n; j++)
		{
			cin >> c[i][j];
			if (i!=j && cmin > c[i][j]) cmin = c[i][j];
		}
	}
}
int check(int v, int k)
{
	if (!appear[v]) return 1;
	return 0;
}
void solution()
{
	if (s + c[x[n-1]][1] <= m) dem++;
}
void TRY(int k)
{
	for (int v = 2; v <= n; v++)
	{
		if (check(v, k))
		{
			x[k] = v;
			s = s + c[x[k-1]][v];
			appear[v] = 1;
			if (k == n-1)
				solution();
			else
			{
				if (s + cmin*(n-1-k)<m)
					TRY(k + 1);
			}
			appear[v] = 0;
			s -= c[x[k - 1]][v];
		}
	}
 
}
void solve()
{
	
	dem = 0;
	x[0] = 1;
	s = 0;
	
	TRY(1);
}
int main()
{
//	freopen("input.txt", "r", stdin);
	input();
	solve();
	cout << dem << endl;
	return 0;
}
