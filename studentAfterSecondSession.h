#pragma once

#include "studentAfterFirstSession.h"

class studentAfterSecondSession : public studentAfterFirstSession {
    protected:
        std::vector<int> marksSecondSession {0, 0, 0, 0, 0};
   
    public:
        studentAfterSecondSession() = delete;
        studentAfterSecondSession(char* _name, int _course, int _group, std::vector<int> marks1, std::vector<int> marks2);
        studentAfterSecondSession(const studentAfterSecondSession &other);
    
        std::vector<int> getMarksSecondSession() const;
        int getOneMarkSecondSession(int position) const;
   
        void printMarksSecondSession () const;
   
        void setMarksSecondSession(std::vector<int> marks);
        void setOneMarkSecondSession(int mark, int position);
    
        double avarageScore() override;
};

std::ostream& operator << (std::ostream &os, const studentAfterSecondSession &person);