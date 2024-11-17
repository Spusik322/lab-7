#include "studentAfterSession1.h"
studentAfterSession1::studentAfterSession1(char* _name, int _course, int _group, int* marks) : student(_name, _course, _group) {
        for (int i = 0; i < 4; i++){
            markSession1[i] = marks[i];
        }
}
studentAfterSession1::studentAfterSession1(const studentAfterSession1 &other) : student(other){
    for (int i = 0; i < 4; i++) {
        markSession1[i] = other.markSession1[i];
    }
}
int* studentAfterSession1::getMarks1() {
    return markSession1;
}
int studentAfterSession1::getMarks1(int position) {
    return markSession1[position];
}
void studentAfterSession1::printMarks1 () {
    std::cout << "Массив оценок за первый сем. ";
    for (int i = 0; i < 4; i++){
        std::cout << markSession1[i] << ' ';
    }
}
void studentAfterSession1::setMarks1(int* marks) {
    for (int i = 0; i < 4; i++) {
        markSession1[i] = marks[i];
    }
}
void studentAfterSession1::setMarks1(int mark, int position) {
    markSession1[position] = mark;
}
double studentAfterSession1::avarageScore() {
    double avarageScore;
    for (int i = 0; i < 4; i++) {
        avarageScore += markSession1[i];
    }
    return avarageScore / 4;
}
std::ostream& operator << (std::ostream &os, studentAfterSession1 &person) {   
    os << "ID: " << std::hex << person.getId() << '\n';
    os << "Имя студента: " << person.getName() << '\n';
    os << "Учиться на курсе: " << person.getCourse() << '\n';
    os << "В группе: " << person.getGroup() << '\n';
    os << "Номер зачетки: " << person.getRecordBook() << '\n';
    os << "Массив оценок за первый сем. ";
    for (int i = 0; i < 4; i++) {
        os << person.getMarks1()[i] << ' ';
    }
    return os;
}