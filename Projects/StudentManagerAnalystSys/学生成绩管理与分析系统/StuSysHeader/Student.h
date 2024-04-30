

#include "Package.h"



#ifndef _STUDENT_H
#define _STUDENT_H
class Student
{
    
    public:
        int id;//学号 
        char name[50];//姓名 
        char sex[10];//性别 
        int ma,en,et,pc;//数英体机 
        int sum;//总分 
        int avr;

        Student *next;//指针域 

        Student(/* args */);
        ~Student();
};


Student::Student()
{
    next = NULL;
}

Student::~Student()
{
}

#endif