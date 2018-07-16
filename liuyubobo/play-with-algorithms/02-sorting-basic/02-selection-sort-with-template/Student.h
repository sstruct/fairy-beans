#ifndef SELECTIONSORT_STUDENT_H
#define SELECTIONSORT_STUDENT_H

#include <iostream>
#include <string>

using namespace std;

struct Student
{
    string name;
    int score;

    // cpp 的运算符重载，了解即可
    bool operator<(const Student &otherStudent)
    {
        return score != otherStudent.score ? score > otherStudent.score : name < otherStudent.name;
    }
    friend ostream &operator<<(ostream &os, const Student &student)
    {
        os << "Student: " << student.name << " " << student.score << endl;
        return os;
    }
};
#endif