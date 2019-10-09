#include <iostream>
#include <string.h>
 
using namespace std;
 
int a, b, c;
int qx[1000000], qy[1000000];  // Hang doi luu trang thai cua binh 1 va binh 2
int first, last;  // Vi tri bat dau va ket thuc cua hang doi
int qz[1000][1000];  // qz[i][j] so lan do nuoc toi thieu de binh 1 co i va binh 2 co j
 
int x, y, z;  //Bien tam thoi luu trang thai 2 binh va so buoc toi thieu de dat den trang thai nay
 
 
// Lay cac trang thai chua xet ra khoi queue
// Gan cac trang thai nay vao x, y, z
bool pop() {
	if (first > last) {
		return false;
	}
	x = qx[first];
	y = qy[first];
	z = qz[x][y] + 1;
	first++;
	return true;
}
 
 
// Kiem tra trang thai tx, ty co phai la nghiem khong?
// Neu tx, ty la nghiem: in ket qua va dung chuong trinh
// Tra ve z > 0: ham solveTestCase se return
// Day trang thai tx, ty vao hang doi
int checkAndPush(int tx, int ty) {
	if (tx == c || ty == c) {
		printf("%d\n", z);
		return z;
	} else if ((tx == 0 && ty == 0) || (qz[tx][ty] > 0)) {
		return 0;
	} else {
		last++;
		qx[last] = tx;
		qy[last] = ty;
		qz[tx][ty] = z;
		return 0;
	}
} 
 
void solveTestCase() {
	cin >> a >> b >> c;
 
	// Trang thai ban dau: 2 binh rong
	first = 0;
	last = 0;
	qx[last] = 0;
	qy[last] = 0;
	memset(qz, 0, sizeof(qz));
 
	int t;
	// Lay cac trang thai chua xet ra khoi queue
	// Gan cac trang thai nay vao x, y, z
	while (pop()) {
		// Do het nuoc tu binh 1 ra ngoai
		if (checkAndPush(0, y)) {
			return;
		}
		// Do het nuoc tu binh 2 ra ngoai
		if (checkAndPush(x, 0)) {
			return;
		}
		// Do nuoc day binh 1
		if (checkAndPush(a, y)) {
			return;
		}
		// Do nuoc day binh 2
		if (checkAndPush(x, b)) {
			return;
		}
		// Do nuoc tu binh 1 sang binh 2
		// cho den khi binh 1 het nuoc
		// hoac binh 2 day nuoc
		t = min(x, b-y);
		if (checkAndPush(x-t, y+t)) {
			return;
		}
		// Do nuoc tu binh 2 sang binh 1
		// cho den khi binh 2 het nuoc
		// hoac binh 1 day nuoc
		t = min(y, a-x);
		if (checkAndPush(x+t, y-t)) {
			return;
		}
	}
	// Khong the tim duoc nghiem
	printf("-1\n");
}
 
int main() {
	int T;
	
	solveTestCase();
 
	return 0;
}
