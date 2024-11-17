#include "studentAfterFirstSession.h"

studentAfterFirstSession::studentAfterFirstSession(char* _name, int _course, int _group, std::vector<int> marks) : 
student(_name, _course, _group), marksFirstSession(marks) {}

studentAfterFirstSession::studentAfterFirstSession(const studentAfterFirstSession &other) : 
student(other), marksFirstSession(other.marksFirstSession) {}

std::vector<int> studentAfterFirstSession::getMarksFirstSession() const {
    return marksFirstSession;
}

int studentAfterFirstSession::getOneMarkFirstSession(int position) const {
    return marksFirstSession[position];
}

void studentAfterFirstSession::printMarksFirstSession () const {
    std::cout << "Массив оценок за первый сем. ";
    for (const auto& m : marksFirstSession){
        std::cout << m << ' ';
    }
}

void studentAfterFirstSession::setMarksFirstSession(std::vector<int> marks) {
    marksFirstSession = marks;
}

void studentAfterFirstSession::setOneMarkFirstSession(int mark, int position) {
    marksFirstSession[position] = mark;
}

double studentAfterFirstSession::avarageScore() {
    double avarageScore = 0.0;
    for (const auto& m : marksFirstSession){
        avarageScore += m;
    }
    return avarageScore / 4;
}

std::ostream& operator << (std::ostream &os, const studentAfterFirstSession &person) {   
    os << "ID: " << std::hex << person.getId() << '\n';
    os << "Имя студента: " << person.getName() << '\n';
    os << "Учиться на курсе: " << person.getCourse() << '\n';
    os << "В группе: " << person.getGroup() << '\n';
    os << "Номер зачетки: " << std::dec << person.getRecordBook() << '\n';
    os << "Массив оценок за первый сем. ";
    for (const auto& m : person.getMarksFirstSession()) {
        os << m << ' ';
    }
    return os;
}