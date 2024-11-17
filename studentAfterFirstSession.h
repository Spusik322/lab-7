#pragma once 

#include "student.h"

class studentAfterFirstSession : public student {
    protected:
        std::vector<int> marksFirstSession {0, 0, 0, 0};
    public:
        studentAfterFirstSession() = delete;
        studentAfterFirstSession(char* _name, int _course, int _group, std::vector<int> marks);
        studentAfterFirstSession(const studentAfterFirstSession &other);
        
        std::vector<int> getMarksFirstSession() const;
        int getOneMarkFirstSession(int position) const;
        void printMarksFirstSession () const;

        void setMarksFirstSession(std::vector<int> marks);
        void setOneMarkFirstSession(int mark, int position);
        
        double avarageScore() override;
};

std::ostream& operator << (std::ostream &os, const studentAfterFirstSession &person);