#pragma ocne
#include "studentAfterSession1.h"
class studentAfterSession2 : public studentAfterSession1 {
    protected:
    int markSession2[5] = {0, 0, 0, 0, 0};
    public:
    studentAfterSession2() = delete;
    studentAfterSession2(char* _name, int _course, int _group, int* marks1, int* marks2);
    studentAfterSession2(const studentAfterSession2 &other);
    int* getMarks2();
    int getMarks2(int position);
    void printMarks2 ();
    void setMarks2(int* marks);
    void setMarks2(int mark, int position);
    double avarageScore() override;
};
std::ostream& operator << (std::ostream &os, studentAfterSession2 &person);