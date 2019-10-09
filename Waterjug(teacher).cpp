#include <stdio.h>
#include <string.h>

using namespace std;

int qx[1100000],qy[1100000];
int first, last;
int qz[1001][1001];

int a,b,c;
int x,y,x;

bool pop(){
	if(first>last) return false;
	x = qx[first];
	y = qy[first];
	z = qz[x][y]+1;
	first++;
	return true;
}

int checkAndPush(int tx, int ty){
	if(tx ==c || ty == c){
		printf("%d\n",z);
		return z;
	} else if ((tx==0&&ty==0)||qz[tx][ty]>0){
		return 0;
	} else {
		last++;
		qx[last] = tx;
		qy[last] = ty;
		qz[tx][ty] = z;
		return 0;	
	}
}

void solveTestCase(){
	cin>> a >> b >> c;
	
	first = 0;
	last = 0;
	qx[last] = 0;
	qy[last] = 0;
	memset(qz, 0, sizeof(qx));
	
	int t;
	
	while (pop()){
		if(checkAndPush(0,y) > 0){
			return;
		}
		
		if(checkAndPush(x,0) > 0){
			return;
		}
		
		if(checkAndPush(a,y) > 0){
			return;
		}
		
		if(checkAndPush(x,b) > 0){
			return;
		}
		
		t=min(x,b-y);
		if(checkAndPush(x-t,y+t) > 0){
			return;
		}
		
		t=min(a-x,y);
		if(checkAndPush(x+t,y-t) > 0){
			return;
		}
	}
	
	printf("-1\n");
}

int main(){
	
}

