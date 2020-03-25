#include <iostream>
#include <math.h>
using namespace std;
int dist(double x1,double y1, double x2, double y2) {
	double tem[2];
	tem[0]=(x2-x1);
	tem[0]=tem[0]*tem[0];
	tem[1]=(y2-y1);
	tem[1]=tem[1]*tem[1];
	tem[0]=tem[0]+tem[1];
	tem[0]=sqrt(tem[0]);
	return tem[0];
	}
void test(int ch=0){
	switch (ch) {
  case 0:
    double in[4];
		for (int i=0;i<4;i++){cin >>in[i];}
		cout<<dist(in[0],in[1],in[2],in[3])<<endl;
    break;
  case 1:
    cout<<1<<endl;
    break;
  case 2:
    cout<<2<<endl;
    break;
		default:
		test(0);
}
	}
bool t = 1;
int main() {
    while (t){
	int ch=0;
	cout<<"0: Distace  1: Area of Triangle  2: undefined  3:  undefined"<<endl;
	cin >> ch;
	if (!cin){t=0;}
	if (t){
	cout<<"____________"<<endl;
	test(ch);
	cout << "**********"<<endl;
	}
	}
	return 0;
}
