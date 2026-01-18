//
// Created by ThinkPad on 2023/12/24.
//

#ifndef SHANGJI_HOMEWORK_H
#define SHANGJI_HOMEWORK_H

#include "User.h"
#include "Course.h"
#include "student_score.h"
#include <string>
#include <vector>
#include <map>
using namespace std;
class Homework {
public:
double weigh=0;
    int homeworkid=0;
    string homeworkname;
    string coursename;
    string teachername;
//   ~Homework();
//    Homework( string& question,int id,Course* coursename):homeworkName(question),homeworkid(id),course(coursename){};
    Homework(): homeworkname(""), homeworkid(0) ,coursename(""),teachername(""){};
    Homework(const string& question,int id);
    //   int getId()const;
    string gethomeworkName() const{
        return homeworkname;
    }
    string getcoursename() const{
        return coursename;
    }
    string getteachername() const{
        return teachername;
    }

vector<student_score> student_scores;
};
#endif //SHANGJI_HOMEWORK_H
