#include <iostream>
#include "Struct.h"
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



	double TriArea(){
Tri InTri;
for(int i=0;i<3;i++){
//Ask For User Input for the cords of the 3 points of the triangle
cout<<"X"<<i+1<<": ";
    cin>>InTri.x[i];
    cout<<"\n";
    cout<<"Y"<<i+1<<": ";
    cin>>InTri.y[i];
    cout<<"\n";
}
for(int i=0;i<3;i++){
//Generate Slopes For Triangle Lines
int n = i+1;
if (n>2){n=0;}
InTri.mNum[0][i]=InTri.y[n]-InTri.y[i];
InTri.mDem[0][i]=InTri.x[n]-InTri.x[i];
InTri.mNum[1][i]=(InTri.x[n]-InTri.x[i])*-1;
InTri.mDem[1][i]=InTri.y[n]-InTri.y[i];

}
//double b = InTri.y[0]+(InTri.x[0]*(InTri.mNum[1][1]/InTri.mDem[1][1]))
return InTri.x[0];
}




	void test(int ch=0){
	switch (ch) {
  case 0:
    double in[4];
		for (int i=0;i<4;i++){cin >>in[i];}
		cout<<dist(in[0],in[1],in[2],in[3])<<endl;
    break;
  case 1:
      cout<<TriArea()<<endl;
    cout<<1<<endl;
    break;
  case 2:
    cout<<2<<endl;
    break;
		default:
		test(0);
}
	}



