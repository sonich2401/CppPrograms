#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cmath>
#include <stdlib.h>
/*using namespace std;
*/
extern int curPer;
extern std::string account[10];
class student
{
    public:
        student();
        void S_setper(bool auth);
        void S_class();
        void S_get();
        void S_add();
        void S_add_class();
        int S_pass();
        int date[3];
        bool f;
    private:
        int dob[3];
        std::string name;
        std::string m_name;
        std::string l_name;
        char gender;
        int age;
        std::string classes[6];
        //double classGrade[6];
        //std::string ex_classes[6];
       // double ex_classGrade[6];
        std::string grade;
        double gpa;
        //int missed;
        //int excused;
        std::string pass;

};
/*
GETLINE CODE

#include <fstream>
#include <limits>

std::fstream& GotoLine(std::fstream& file, unsigned int num){
    file.seekg(std::ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    return file;
}*/
#endif // STUDENT_H
