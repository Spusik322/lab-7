#include "studentAfterSecondSession.h"

studentAfterSecondSession::studentAfterSecondSession(char* _name, int _course, int _group, std::vector<int> marks1, std::vector<int> marks2) : 
studentAfterFirstSession(_name, _course, _group, marks1), marksSecondSession(marks2) {}

studentAfterSecondSession::studentAfterSecondSession(const studentAfterSecondSession &other) : 
studentAfterFirstSession(other), marksSecondSession(other.marksSecondSession) {}

std::vector<int> studentAfterSecondSession::getMarksSecondSession() const {
    return  marksSecondSession;
}

int studentAfterSecondSession::getOneMarkSecondSession(int position) const {
    return  marksSecondSession[position];
}

void studentAfterSecondSession::printMarksSecondSession () const {
    std::cout << "Массив оценок за второй сем. ";
    for (const auto &m: marksSecondSession){
        std::cout << m << ' ';
    }
}

void studentAfterSecondSession::setMarksSecondSession(std::vector<int> marks) {
    marksSecondSession = marks;
}

void studentAfterSecondSession::setOneMarkSecondSession(int mark, int position) {
    marksSecondSession[position] = mark;
}

double studentAfterSecondSession::avarageScore() {
    double avarageScore = 0.0;
    for (const auto &m1: marksFirstSession) {
        avarageScore += m1;
    }
    for (const auto &m2: marksSecondSession) {
        avarageScore += m2;
    }
    return avarageScore / 9;
}

std::ostream& operator << (std::ostream &os, const studentAfterSecondSession &person) {   
    os << "ID: " << std::hex << person.getId() << '\n';
    os << "Имя студента: " << person.getName() << '\n';
    os << "Учиться на курсе: " << person.getCourse() << '\n';
    os << "В группе: " << person.getGroup() << '\n';
    os << "Номер зачетки: " << std::dec << person.getRecordBook() << '\n';
    os << "Массив оценок за первый сем. ";
    for (const auto &m1: person.getMarksFirstSession()) {
        os << m1 << ' ';
    }
    os << '\n';
    os << "Массив оценок за второй сем. ";
    for (const auto &m2: person.getMarksSecondSession()) {
        os << m2 << ' ';
    }
    return os;
}