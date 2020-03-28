#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cmath>
/*using namespace std;
*/
extern int curPer;
extern std::string account[10];
class student
{
    public:
        student();
        void S_setper();
        void S_class();
        void S_get();
        void S_add();
        int date[3];
        int getname();
    private:
        int dob[3];
        std::string name;
        std::string m_name;
        std::string l_name;
        char gender;
        int age;
        std::string classes[6];
        double classGrade[6];
        std::string ex_classes[6];
        double ex_classGrade[6];
        std::string grade;
        double gpa;
        int missed;
        int excused;

};

#endif // STUDENT_H
