#pragma once
#include <iostream>
#include <array>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstring>
#include <array>
#include <random>
class student {
    protected:
    char name[100];
    int course;
    int group;
    private:
    int id;
    int recordBook;
    static int studCounter;
    public:
    student() = delete;
    student(char* _name, int _course, int _group) : course(_course), group(_group) {
        id = 0xabcadef + studCounter;
        recordBook = studCounter;
        studCounter++;
        strcpy(name, _name);
    }
    student(const student &other) {
        strcpy(name, other.name);
        id = other.id;
        recordBook = other.recordBook;
        course = other.course;
        group = other.group;
    }
    int getId() const {
        return id;
    }
    char* getName() {
        return name;
    }
    int getGroup() const {
        return group;
    }
    int getRecordBook() const {
        return recordBook;
    }
    int getCourse() const {
        return course;
    }
    void setName(char* _name) {
        strcpy(name, _name);
    }
    void setGroup(int _group) {
        group = _group;
    }
    void setCourse(int _course) {
        course = _course;
    }
};
int student::studCounter = 1;
class studentAfterSession1 : public student {
    protected:
    int markSession1[4];
    public:
    studentAfterSession1() = delete;
    studentAfterSession1(char* _name, int _course, int _group, int* marks) : student(_name, _course, _group) {
        for (int i = 0; i < 4; i++){
            markSession1[i] = marks[i];
        }
    }
    studentAfterSession1(const studentAfterSession1 &other) : student(other){
        for (int i = 0; i < 4; i++) {
            markSession1[i] = other.markSession1[i];
        }
    }
    int* getMarks1() {
        return markSession1;
    }
    int getMarks1(int position) {
        return markSession1[position];
    }
    void printMarks1 (int* marks) {
        std::cout << "Массив оценок за первый сем. ";
        for (int i = 0; i < 4; i++){
            std::cout << marks[i] << ' ';
        }
    }
    void setMarks1(int* marks) {
        for (int i = 0; i < 4; i++) {
            markSession1[i] = marks[i];
        }
    }
    void setMarks1(int mark, int position) {
        markSession1[position] = mark;
    }
    virtual double avarageScore() {
        double avarageScore;
        for (int i = 0; i < 4; i++) {
            avarageScore += markSession1[i];
        }
        return avarageScore / 4;
    }
};
class studentAfterSession2 : public studentAfterSession1 {
    protected:
    int markSession2[5];
    public:
    studentAfterSession2() = delete;
    studentAfterSession2(char* _name, int _course, int _group, int* marks1, int* marks2) : studentAfterSession1(_name, _course, _group, marks1) {
        for (int i = 0; i < 5; i++) {
            markSession2[i] = marks2[i];
        }
    }
    studentAfterSession2(const studentAfterSession2 &other) : studentAfterSession1(other) {
        for (int i = 0; i < 5; i++) {
            markSession2[i] = other.markSession2[i];
        }
    }
    int* getMarks2() {
        return markSession2;
    }
    int getMarks2(int position) {
        return markSession2[position];
    }
    void printMarks2 (int* marks) {
        std::cout << "Массив оценок за первый сем. ";
        for (int i = 0; i < 5; i++){
            std::cout << marks[i] << ' ';
        }
    }
    void setMarks2(int* marks) {
        for (int i = 0; i < 5; i++) {
            markSession2[i] = marks[i];
        }
    }
    void setMarks2(int mark, int position) {
        markSession2[position] = mark;
    }
    double avarageScore() override {
        double avarageScore;
        for (int i = 0; i < 4; i++) {
            avarageScore += markSession1[i];
        }
        for (int i = 0; i < 5; i++) {
            avarageScore += markSession2[i];
        }
        return avarageScore / 9;
    }
};
std::ostream& operator << (std::ostream &os, student &person)
{   os << "ID: " << std::hex << person.getId() << '\n';
    os << "Имя студента: " << person.getName() << '\n';
    os << "Учиться на курсе: " << person.getCourse() << '\n';
    os << "В группе: " << person.getGroup() << '\n';
    os << "Номер зачетки: " << person.getRecordBook();
    return os;
}
std::ostream& operator << (std::ostream &os, studentAfterSession1 &person)
{   os << "ID: " << std::hex << person.getId() << '\n';
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
std::ostream& operator << (std::ostream &os, studentAfterSession2 &person)
{   os << "ID: " << std::hex << person.getId() << '\n';
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