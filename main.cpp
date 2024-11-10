#include "students.h"

int main() {
    student stud1 = student("Ваня", 2 , 5);
    student stud2 = student("Олег", 2 , 5);
    student stud3 = student (stud1);
    std::cout << stud1 << '\n' << stud2 << '\n' << stud3;
}