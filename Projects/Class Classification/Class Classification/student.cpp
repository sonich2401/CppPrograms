#include "student.h"
#include <iostream>
#include <cmath>
int curPer=-1;
std::string account[10];
student::student()
{
        void S_setper();
        void S_get();
        void S_add();
        void S_class();
        date[0] = 3;
        date[1] = 27;
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
        std::string classes[6];
        double classGrade[6];
        std::string ex_classes[6];
        double ex_classGrade[6];
        std::string grade;
        double gpa=0;
        int missed=0;
        int excused=0;
}
void student::S_setper(){
std::cout<<"Thanks for choosing the Rendevios School of Computer Science"<<"\n"<<"as your school of choice."<<"\n\n\n"<<"To get started, what is your or your child's first name?"<<"\n";
std::cin >> this->name;
if (!std::cin){std::cout<<"\r"<<"Oops! Seems like that wasn't a name that you entered. Could you try again?"<<"\n"<<"What is your child's fist name?"<<"\n";std::cin >> this->name;}
std::cout<<"\r"<<"Ok wonderful! Thanks, "<<this->name<<"! Now what is your middle name?"<<"\n";
std::cin >> this->m_name;
std::cout<<"\r"<<"Thanks. Now could you do one last thing for me?"<<"\n"<<"What is your last name?  ";
std::cin >> this->l_name;
std::cout<<"\n\n"<<"Well "<<this->name<<" "<<this->m_name<<" "<<l_name<<", Nice to meet you!\n\n\n"<<"What is your gender "<<this->name<<" "<<this->m_name<<" "<<l_name<<"? \n ('M'=Male, 'F'=Female)\n";
std::cin >> this->gender;
std::cout<<"\n Now on to the next question.\n What was your day of birth?\n dd/mm/yyyy\n dd";
std::cin >> this->dob[0];
std::cout<<"mm\r";
std::cin >> this->dob[1];
std::cout<<"yyyy\r";
std::cin >> this->dob[2];
int tmp=(date[0]*31)+date[1]+(date[2]*365);
int tmp2=(dob[1]*31)+dob[0]+(dob[2]*365);
tmp -= tmp2;
this->age = floor(tmp/365);
std::cout<<"\n Thank you! Wow! Your "<<this->age<<"! Your nearly as old as me!\n Two more questions to go and then ill let you be on your way.\n Lets contine. What is your grade point average?\n";
std::cin >> this->gpa;
if (this->gpa<=4){std::cout<<"\n Thanks. Ok Last question.\n What grade are you in?\n";}else{std::cin >> this->gpa;}
std::cout<<"\n\n****************\n Thanks for filling out that strenuos form!\n if you would like to manage your data please use the add() or S_get() funtion.\n We Look Forward To Meeting You!\n**********\n\n";
account[curPer]=this->name;
}
void student::S_get(){
std::cout<<"*******************\n Data for "<<this->name<<" "<<this->m_name<<" "<<l_name<<".\n*******************\n Gender: "<<this->gender<<"\n DOB: "<<this-dob[0]<<"/"<<this->dob[1]<<"/"<<this->dob[2]<<"\n Age: "<<this->age<<"\n GPA: "<<this->gpa<<"\n***************\n End Of Record\n*************\n\n";
}
void student::S_add(){
    std::cout<<"\n\n_____________\n\n____________\n\nWelcome to the Data Management Utility for "<<this->name<<" "<<this->m_name<<" "<<l_name<<"\n\n\n";
    bool dirt = 1;
    while (dirt){
    int ch=0;
    std::cout<<"There are a few options to choose from the menu\n\t1. Manage Classes\n\t2. Get Student Info\n\t3. Re-Enter Personal Info\n\t4. Exit Student Options\n\nEnter A Valid Number to Choose an Option: ";
    std::cin >> ch;
    switch (ch){
        case 1:
            std::cout<<"\n\nTHIS IS THE CLASS MANAGEMENT PROGRAM\n\n--> THIS IS THE END OF THE CLASS MANAGEMENT PROGRAM\n\n";
        break;
        case 2:
            std::cout<<"\n\nTHIS IS THE STUDENT INFO VEIWING PROGRAM\n\n--> THIS IS THE END OF THE STIUDENT INFO VIEWING PROGRAM\n\n";
        break;
        case 3:
            std::cout<<"\n\nTHIS IS THE PROGRAM FOR RE-ENTERING PERSONAL INFORMATION\n\n---> THIS IS THE END OF THE PROGRAM FOR RE-ENTERING PERSONAL INFORMATION\n\n";
        break;
        case 4:
            dirt = 0;
        break;
        default:
            ch=2;}
    }
}
