#include "student.h"
#include "studentAfterFirstSession.h"
#include "studentAfterSecondSession.h"

int main() {
    std::vector<int> marks = {4, 6, 8, 3};
    std::vector<int> marks1 = {9, 8, 7, 6, 5};
    std::vector<int> marks3 = {5, 8, 2, 7};
    std::vector<int> marks4 = {5, 8, 2, 7, 4};
    
    student stud1 = student("Ваня", 2 , 5);
    studentAfterFirstSession stud2 = studentAfterFirstSession("Олег", 2 , 5, marks);
    studentAfterSecondSession stud3 = studentAfterSecondSession ("Кирилл", 2, 5, marks, marks1);
    studentAfterFirstSession stud4 = studentAfterFirstSession("Олег1", 3 , 4, marks3);
    studentAfterSecondSession stud5 = studentAfterSecondSession ("Кирилл1", 4, 3, marks3, marks4);
    
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
    
    std::cout << avarageScoreofVector(students) << '\n' << avarageScoreofGroup(students, 3) << '\n';
    std::cout << stud1 << '\n' << stud2 << '\n' << stud3;
}