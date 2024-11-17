#include "student.h"
int student::studCounter = 1;
student::student(char* _name, int _course, int _group) : course(_course), group(_group) {
    id = 0xabcadef + studCounter;
    recordBook = studCounter;
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
char* student::getName() {
    return name;
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
std::ostream& operator << (std::ostream &os, student &person) {
    os << "ID: " << std::hex << person.getId() << '\n';
    os << "Имя студента: " << person.getName() << '\n';
    os << "Учиться на курсе: " << person.getCourse() << '\n';
    os << "В группе: " << person.getGroup() << '\n';
    os << "Номер зачетки: " << person.getRecordBook();
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
double avarageScoreofGroup(std::vector<student*> &students, int group) {
    int counter = 0;
    double avarageScoreofGroup = 0;
    for (student* s : students) {
        if (s->getGroup() == group) {
            if (typeid(s) == typeid(student)) {
                continue;
            } else {
                avarageScoreofGroup += s->avarageScore();
                counter++;
            }
        } 
        continue;
    }
    avarageScoreofGroup /= counter;
    return avarageScoreofGroup;
}