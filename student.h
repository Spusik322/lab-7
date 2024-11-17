#pragma once
#include <iostream>
#include <array>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstring>
#include <array>
#include <random>
#include <vector>
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
    student(char* _name, int _course, int _group);
    student(const student &other);
    int getId() const;
    char* getName();
    int getGroup() const;
    int getRecordBook() const;
    int getCourse() const;
    void setName(char* _name);
    void setGroup(int _group);
    void setCourse(int _course);
    virtual double avarageScore();
};
std::ostream& operator << (std::ostream &os, student &person);
double avarageScoreofVector(std::vector<student*> &students);
double avarageScoreofGroup(std::vector<student*> &students, int group);