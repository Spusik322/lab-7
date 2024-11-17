#include "studentAfterSession2.h"
studentAfterSession2::studentAfterSession2(char* _name, int _course, int _group, int* marks1, int* marks2) : studentAfterSession1(_name, _course, _group, marks1) {
    for (int i = 0; i < 5; i++) {
        markSession2[i] = marks2[i];
    }
}
studentAfterSession2::studentAfterSession2(const studentAfterSession2 &other) : studentAfterSession1(other) {
    for (int i = 0; i < 5; i++) {
        markSession2[i] = other.markSession2[i];
    }
}
int* studentAfterSession2::getMarks2() {
    return markSession2;
}
int studentAfterSession2::getMarks2(int position) {
    return markSession2[position];
}
void studentAfterSession2::printMarks2 () {
    std::cout << "Массив оценок за второй сем. ";
    for (int i = 0; i < 5; i++){
        std::cout << markSession2[i] << ' ';
    }
}
void studentAfterSession2::setMarks2(int* marks) {
    for (int i = 0; i < 5; i++) {
        markSession2[i] = marks[i];
    }
}
void studentAfterSession2::setMarks2(int mark, int position) {
    markSession2[position] = mark;
}
double studentAfterSession2::avarageScore() {
    double avarageScore;
    for (int i = 0; i < 4; i++) {
        avarageScore += markSession1[i];
    }
    for (int i = 0; i < 5; i++) {
        avarageScore += markSession2[i];
    }
    return avarageScore / 9;
}
std::ostream& operator << (std::ostream &os, studentAfterSession2 &person) {   
    os << "ID: " << std::hex << person.getId() << '\n';
    os << "Имя студента: " << person.getName() << '\n';
    os << "Учиться на курсе: " << person.getCourse() << '\n';
    os << "В группе: " << person.getGroup() << '\n';
    os << "Номер зачетки: " << person.getRecordBook() << '\n';
    os << "Массив оценок за первый сем. ";
    for (int i = 0; i < 4; i++) {
        os << person.getMarks1()[i] << ' ';
    }
    os << '\n';
    os << "Массив оценок за второй сем. ";
    for (int i = 0; i < 5; i++) {
        os << person.getMarks2()[i] << ' ';
    }
    return os;
}