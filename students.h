#pragma once
#include <iostream>
#include <array>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstring>
#include <array>
#include <random>
// int generateUniqueId() {
//   std::random_device rd;
//   std::mt19937 generator(rd());
//   std::uniform_int_distribution<> distribution(100000000, 999999999);
//   int uniqueId = distribution(generator);
//   return uniqueId;
// }
// int generateRecord() {
//   std::random_device rd;
//   std::mt19937 generator(rd());
//   std::uniform_int_distribution<> distribution(0, 100);
//   int uniqueRecord = distribution(generator);
//   return uniqueRecord;
// }
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
    for (int i = 0; i < 4; i++){
        os << person.getMarks1()[i] << ' ';
    }
    return os;
}