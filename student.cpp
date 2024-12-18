#include "student.h"
#include "studentAfterFirstSession.h"

int student::studCounter = 1;

student::student(char* _name, int _course, int _group) : course(_course), group(_group) {
    id = 0xabcadef + studCounter;
    recordBook = 1000000 + studCounter;
    studCounter++;
    strcpy(name, _name);
}

student::student(const student &other) {
    strcpy(name, other.name);
    id = other.id;
    recordBook = other.recordBook;
    course = other.course;
    group = other.group;
}

int student::getId() const {
    return id;
}

char* student::getName() const {
    return (char*)name;
}

int student::getGroup() const {
    return group;
}

int student::getRecordBook() const {
    return recordBook;
}

int student::getCourse() const {
    return course;
}

void student::setName(char* _name) {
    strcpy(name, _name);
}

void student::setGroup(int _group) {
    group = _group;
}

void student::setCourse(int _course) {
    course = _course;
}

double student::avarageScore() {
    throw std::logic_error("Function not yet implemented");
}

std::ostream& operator << (std::ostream &os, const student &person) {
    os << "ID: " << std::hex << person.getId() << '\n';
    os << "Имя студента: " << person.getName() << '\n';
    os << "Учиться на курсе: " << person.getCourse() << '\n';
    os << "В группе: " << person.getGroup() << '\n';
    os << "Номер зачетки: " << std::dec << person.getRecordBook();
    return os;
}

double avarageScoreofVector(std::vector<student*> &students) {
    int counter = 0;
    double avarageScoreofVector = 0;
    for (student* s : students) {
        if (typeid(*s) == typeid(student)) {
            continue;
        } else {
            avarageScoreofVector += s->avarageScore();
            counter++;
        } 
    }
    avarageScoreofVector /= counter;
    return avarageScoreofVector;
}

void avarageScoreofGroup(std::vector<student*> &students, int group) {
    int counter1 = 0;
    double avarageScoreofGroup1 = 0;
    int counter2 = 0;
    double avarageScoreofGroup2 = 0;
    for (student* s : students) {
        if (s->getGroup() == group) {
            if (typeid(*s) == typeid(student)) {
                continue;
            } else if (typeid(*s) == typeid(studentAfterFirstSession)) {
                avarageScoreofGroup1 += s->avarageScore();
                counter1++;
            } else {
                avarageScoreofGroup2 += s->avarageScore();
                counter2++;
            }
        } 
        continue;
    }
    std::cout << "Средний балл в группе " << group << '\n';
    std::cout << "После 1-ой сесии " << avarageScoreofGroup1/counter1 << '\n';
    std::cout << "После 2-ой сесии " << avarageScoreofGroup2/counter2;
}