#include "students.h"

int main() {
    student stud1 = student("Ваня", 2 , 5);
    student stud2 = student("Олег", 2 , 5);
    student stud3 = student (stud1);
    std::cout << stud1 << '\n' << stud2 << '\n' << stud3 << '\n';
    int marks[4] = {4, 6, 8, 3};
    int marks1[5] = {9, 8, 7, 6, 5};
    studentAfterSession2 stud4 = studentAfterSession2("Чмоня", 3 , 52, marks, marks1);
    std::cout << stud4 << "\n" << stud4.avarageScore() << '\n';
}