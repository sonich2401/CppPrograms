#include <iostream>
#include "Func.h"
using namespace std;
bool t = 1;
int main() {
    while (t){
	int ch=0;
	cout<<"0: Distace  1: Area of Triangle  2: undefined  3:  undefined"<<endl;
	cin >> ch;
	if (!cin){t=0;for(int i=0;i<100;i++){cout<<"\b";}}
	if (t){
	cout<<"____________"<<endl;
	test(ch);
	cout << "**********"<<endl;
	cout<<endl<<endl<<endl<<endl;
	}
    }
	return 0;
}
