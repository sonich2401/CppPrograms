#include <iostream>
#include "student.h"
#include <string.h>
#include <stdlib.h>
using namespace std;
void accountAdd(student database[]){
    curPer++;
    database[curPer].S_setper(true);
}
void S_save(student database[]){
//for ()
}
void getAccount(student database[]){
    cout<<"Welcome to the Account Destination Seter!\n\nPlease enter the first name of the studet\n that you would like to manage the data for.\n";
    std::string tmp3;
    std::cin >> tmp3;
    for(int i=0;i<10;i++){
        int re = account[i].compare(tmp3);
        if(re==0){
                if(database[i].S_pass()){
                    system("cls");
                    database[i].S_add();}}
    }
}
int main()
{
    int ch;
    student database[10];
    bool dirt = 1;
    while (dirt){
        system("cls");
        std::cout<<"\n\n*****Menu Root Options******\n\nWould you like to...\n\t1. Add New Student\n\t2. Manage Student Data\n\t3. Save And Exit\n Enter Valid Number responce: \n";
        std::cin >> ch;
        system("cls");
        switch (ch){
            case 1:
                accountAdd(database);
            break;
        case 2:
                getAccount(database);
        break;
        case 3:
            dirt = 0;
        break;
        case 4:
            dirt = 0;
        break;
        default:
            ch = 2;
        }
    }
    return 0;
}
