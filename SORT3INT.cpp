#include <iostream>
#include <stdio.h> 

using namespace std;
 
void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
 
 
int partition (int A[], int L, int R, int indexPivot)
{
    int pivot = A[indexPivot];
    swap(A[indexPivot], A[R]);
    int storeIndex = L;
    for (int i=L;i<=R-1;i++){
    	if(A[i]<pivot){
    		swap(A[storeIndex],A[i]);
    		storeIndex++;
    	}
    }
    swap(A[storeIndex],A[R]);
    return storeIndex;
}
 

void quickSort(int A[], int L, int R)
{
    if (L < R)
    {
        int index = (L+R)/2;
        index = partition(A,L,R,index);
        if(L<index){
        	quickSort(A,L,index-1);
        }
        if(index<R){
        	quickSort(A,index+1,R);
        }
    }
}

int main()
{	
	int n;

	cin>>n;	int A[n];
	for (int i=0; i < n; i++){
		cin>>A[i];
	}
   	quickSort(A,0,n-1);
	for (int i=0; i < n; i++){
		cout<<A[i]<<" ";
	}     
}
