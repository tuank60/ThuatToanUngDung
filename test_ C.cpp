#include <iostream>
using namespace std;

#define MAX 1000000

int n,m;
int a[MAX];
int count=0;
int sum;
int main()
{
	cin>>n;
	cin>>m;
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		sum=a[i];
		if(sum<=m){
			count+=1;
			for(int j=i+1;j<n;j++){
				sum+=a[j];
				if(sum<=m){
					count+=1;
				}else {
					break;
				}
			}
		}
	}
	cout<<count;
    return 0;
}
