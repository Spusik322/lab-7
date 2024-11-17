#include "student.h"
#include "studentAfterSession1.h"
#include "studentAfterSession2.h"
int main() {
    int marks[4] = {4, 6, 8, 3};
    int marks1[5] = {9, 8, 7, 6, 5};
    int marks3[4] = {5, 8, 2, 7};
    int marks4[5] = {5, 8, 2, 7, 4};
    student stud1 = student("Ваня", 2 , 5);
    studentAfterSession1 stud2 = studentAfterSession1("Олег", 2 , 5, marks);
    studentAfterSession2 stud3 = studentAfterSession2 ("Кирилл", 2, 5, marks, marks1);
    studentAfterSession1 stud4 = studentAfterSession1("Олег1", 3 , 4, marks3);
    studentAfterSession2 stud5 = studentAfterSession2 ("Кирилл1", 4, 3, marks3, marks4);
    std::vector<student*> students;
    student* s = &stud1;
    students.push_back(s);
    student* s1 = &stud2;
    students.push_back(s1);
    student* s2 = &stud3;
    students.push_back(s2);
    student* s3 = &stud4;
    students.push_back(s3);
    student* s4 = &stud5;
    students.push_back(s4);
    std::cout << avarageScoreofVector(students) << '\n' << avarageScoreofGroup(students, 3);
}