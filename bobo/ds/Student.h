//
// Created by 陈杨子 on 2017/7/17.
//

#ifndef DS_STUDENT_H
#define DS_STUDENT_H

using namespace std;

struct Student {
    string name;
    int score;

    // 定义操作符 < 的行为
    bool operator<(const Student &otherStudent) {
        return score < otherStudent.score;
    }
    bool operator>(const Student &otherStudent) {
        return score > otherStudent.score;
    }

    // C++ 运算符重载什么的，不清楚。不是重点，暂时不看
    friend ostream &operator<<(ostream &os, Student &student) {
        os << "Student: " << student.name << " " << student.score << endl;
        return os;
    }
};

#endif //DS_STUDENT_H
