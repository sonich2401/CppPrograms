#include <iostream>
#include "student.h"
#include <string.h>
using namespace std;
void accountAdd(student database[]){
    curPer++;
    database[curPer].S_setper();
}
void getAccount(student database[]){
cout<<"Welcome to the Account Destination Seter!\n\nPlease enter the first name of the studet\n that you would like to manage the data for.\n";
std::string tmp3;
std::cin >> tmp3;
for(int i=0;i<10;i++){
       /* std::cout<<"ACCOUNT NAME: "<<account[i]<<"\n"<<account[i]<<"\n"<<tmp3<<"\n";*/

    int re = account[i].compare(tmp3);
    /*std::cout<<"\n"<<re<<" I: "<<i<<"\n";*/
    if(re==0){database[i].S_add();}
}
}
int main()
{
    student database[10];
    accountAdd(database);
    getAccount(database);
  /* std::cout<<"\n\n\n\n"<<account[1];*/
    return 0;
}
