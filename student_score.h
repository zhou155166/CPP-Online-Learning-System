//
// Created by Lenovo on 2023/12/27.
//

#ifndef PIECEOFSHITOK_STUDENT_SCORE_H
#define PIECEOFSHITOK_STUDENT_SCORE_H

#include <string>
using namespace std;
class student_score
{public:
    string studentname="";
    int score=0;
    student_score(string name,int fenshu):studentname(name),score(fenshu){};


};
#endif //PIECEOFSHITOK_STUDENT_SCORE_H
