#pragma once
#include <iostream>
#include <array>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstring>
#include <array>
#include <random>
int generateUniqueId() {
  std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_int_distribution<> distribution(100000000, 999999999);
  int uniqueId = distribution(generator);
  return uniqueId;
}
int generateRecord() {
  std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_int_distribution<> distribution(0, 100);
  int uniqueRecord = distribution(generator);
  return uniqueRecord;
}
class student {
    private:
    const int id = generateUniqueId();
    const int recordBook = generateRecord();;
    char name[100];
    int course;
    int group;
    public:
    student() = delete;
    student(char* _name, int _course, int _group) : course(_course), group(_group) {
        strcpy(name, _name);
    }
    student(const student &other) : id(other.id), recordBook(other.recordBook) {
        strcpy(name, other.name);
        course = other.course;
        group = other.group;
    }
    int getId() const{
        return id;
    }
    char* getName() {
        return name;
    }
    int getGroup() const{
        return group;
    }
    int getRecordBook() const{
        return recordBook;
    }
    int getCourse() const{
        return course;
    }
};
class studentAfterSession1 : student {
    private:
    int markSession1[4];
    public:
    studentAfterSession1() = delete;
    studentAfterSession1(int* mraks) {
        
    }
};

std::ostream& operator << (std::ostream &os, student &person)
{
    return os << "ID: " << person.getId() << '\n' << "Имя студента: " << person.getName() << '\n' << "Учиться на курсе: " << person.getCourse() << '\n' << "В группе: " << person.getGroup() << '\n' << "Номер зачетки: " << person.getRecordBook();
}