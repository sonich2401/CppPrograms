#include "student.h"
#include <iostream>
#include <cmath>
#include <windows.h>
int curPer=-1;
std::string account[10];
student::student()
{
        void S_setper(bool auth);
        void S_get();
        void S_add();
        void S_class();
        date[0] = 3;
        date[1] = 29;
        date[2] = 2020;
        int dob[3];
        dob[0] = 0;
        dob[1] = 0;
        dob[2] = 0;
        std::string name;
        std::string m_name;
        std::string l_name;
        char gender;
        int age=0;
        std::string classes[7];
        double classGrade[6];
        std::string ex_classes[6];
        double ex_classGrade[6];
        std::string grade;
        double gpa=0;
        int missed=0;
        int excused=0;
        bool f = true;
}
void student::S_setper(bool auth){
    if (auth || f){
for(int fart=0;fart<6;fart++){classes[fart]="UnSet";}
system("cls");
std::cout<<"Thanks for choosing the Rendevios School of Computer Science"<<"\n"<<"as your school of choice."<<"\n\n\n"<<"To get started, what is your or your child's first name?"<<"\n";
std::cin >> this->name;
if (!std::cin){std::cout<<"\r"<<"Oops! Seems like that wasn't a name that you entered. Could you try again?"<<"\n"<<"What is your child's fist name?"<<"\n";std::cin >> this->name;}
std::cout<<"\r"<<"Ok wonderful! Thanks, "<<this->name<<"! Now what is your middle name?"<<"\n";
std::cin >> this->m_name;
std::cout<<"\r"<<"Thanks. Now could you do one last thing for me? What is your last name?\n";
std::cin >> this->l_name;
std::cout<<"\n\n"<<"Well "<<this->name<<" "<<this->m_name<<" "<<l_name<<", Nice to meet you!\n\n\n"<<"What is your gender "<<this->name<<" "<<this->m_name<<" "<<l_name<<"? \n ('M'=Male, 'F'=Female)\n";
std::cin >> this->gender;
std::cout<<"\n Now on to the next question.\n What was your day of birth?\n dd/mm/yyyy\ndd\r";
std::cin >> this->dob[0];
std::cout<<"mm\r";
std::cin >> this->dob[1];
std::cout<<"yyyy\r";
std::cin >> this->dob[2];
system("cls");
int tmp=(date[0]*31)+date[1]+(date[2]*365);
int tmp2=(dob[1]*31)+dob[0]+(dob[2]*365);
tmp -= tmp2;
this->age = floor(tmp/365);
std::cout<<"\n Thank you! Wow! Your "<<this->age<<"! Your nearly as old as me!\n Three more questions to go and then ill let you be on your way.\n Lets continue. What is your grade point average?\n";
std::cin >> this->gpa;
std::cout<<"\n Ok! Perfect. Now to make sure that your data is secure, you need to make a password.\nMake sure that only people that you trust know your password.\n";
bool tmp4=1;
while (tmp4){
    std::string tmpPass;
    std::cout<<"Enter Password:\n";
    std::cin >> tmpPass;
    std::cout<<"\nConfirm Password:\n";
    std::string tmpPass2;
    std::cin >> tmpPass2;
    if (tmpPass.compare(tmpPass2)){
        this->pass=tmpPass;
        tmp4=0;
    }else{system("cls");std::cout<<"\nNot Same Password Try again!\n\n";}
}
std::cout<<"\n Thanks. Ok Last question.\n What grade are you in?\n";
std::cin >> this->grade;
std::cout<<"\n\n****************\n Thanks for filling out that strenuos form!\n if you would like to manage your data please use the add() or S_get() funtion.\n We Look Forward To Meeting You!\n**********\n\n";
account[curPer]=this->name;
    }else{std::cout<<"INCORRECT PASSWORD";}
}
void student::S_get(){
system("cls");
std::cout<<"*******************\n Data for "<<this->name<<" "<<this->m_name<<" "<<l_name<<".\n*******************\n Gender: "<<this->gender<<"\n DOB: "<<this->dob[0]<<"/"<<this->dob[1]<<"/"<<this->dob[2]<<"\n Age: "<<this->age<<"\n GPA: "<<this->gpa<<"\n Grade: "<<this->grade<<"\n***************\n End Of Record\n*************\n\n";
}
void student::S_add(){
    std::cout<<"\n\n_____________\n\n____________\n\nWelcome to the Data Management Utility for "<<this->name<<" "<<this->m_name<<" "<<l_name<<"\n\n\n";
    bool dirt = 1;
    while (dirt){
    int ch=0;
    std::cout<<"There are a few options to choose from the menu\n\t1. Manage Classes\n\t2. Get Student Info\n\t3. Re-Enter Personal Info\n\t4. Exit Student Options\n\nEnter A Valid Number to Choose an Option: ";
    std::cin >> ch;
    switch (ch){
        system("cls");
        case 1:
            this->S_add_class();
        break;
        case 2:
            this->S_get();
        break;
        case 3:
            this->S_setper(true);
        break;
        case 4:
            dirt = 0;
        break;
        default:
            ch=2;}
    }
}
void student::S_add_class(){
system("cls");
std::cout<<"There are 6 periods that you can choose to set/replace";
for(int i=8;i<11;i++){
    std::cout<<"\n\t"<<i<<":30-"<<i+1<<":30 - "<<this->classes[i-8];
    //std::cout<<"\n"<<i-8;
}
std::cout<<"\n\t11:30-12:00 - Lunch";
for (int i=12;i<15;i++){
    int k=i;
    if (k > 12){k-=12;}
    std::cout<<"\n\t"<<k<<":00 - "<<k+1<<":00 - "<<this->classes[i-9];
}
    std::cout<<"\n        *************\n";
}
int student::S_pass(){
    std::string lname;
    std::string passW;
    std::cout<<"****  IMPORTANT  ****\n***********************\n\tAltering/Veiwing students information without\n\tpermission is a punishable offence.\n***********************\n\n\nEnter Your Last Name For extra Security.\n";
    std::cin >> lname;
    std::cout<<"Enter your password below with caution!! People may be watching you type your Password on your screen!!\nEnter Password Here:\n";
    std::cin >> passW;
    if (passW.compare(this->pass)==0){
        system("cls");
        std::cout<<"Password Accepted!";
        Sleep(3000);
        system("cls");
        return true;
    }

}
