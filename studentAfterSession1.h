#pragma once 
#include "student.h"
class studentAfterSession1 : public student {
    protected:
    int markSession1[4] = {0, 0, 0, 0};
    public:
    studentAfterSession1() = delete;
    studentAfterSession1(char* _name, int _course, int _group, int* marks);
    studentAfterSession1(const studentAfterSession1 &other);
    int* getMarks1();
    int getMarks1(int position);
    void printMarks1 ();
    void setMarks1(int* marks);
    void setMarks1(int mark, int position);
    double avarageScore() override;
};
std::ostream& operator << (std::ostream &os, studentAfterSession1 &person);