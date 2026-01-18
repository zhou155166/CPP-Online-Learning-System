//
// Created by 薛子玥 on 2023/12/10.
//

#ifndef XIANGMU_STUDENT_H
#define XIANGMU_STUDENT_H

#include "User.h"
#include "Course.h"
#include "notice.h"
#include <vector>
#include <string>

using namespace std;

class Student : public User {
public:

    note *snote=nullptr;
    communicatebox *chead=new communicatebox,*crear=chead,*cp= chead,*ctem;

    Student();

    Student *next;

    bool isnotice=0;
    bool ishomework=0;
    bool islog=0;
    void Scourse();
    void notice();
    void homework();
   // void score();
    void gradeT();
    void communicate();
   void score_analyse();


    explicit Student(const string& username);
    ~Student() override;

    void joinCourse( Course& courseName);
    void leaveCourse( Course& courseName);
    void viewCourses();
    void viewMembers(const string& courseName);
    void reviewGrades(const string& courseName, const string& homeworkName);

    void Sgrade();
    void addAnswer(int homeworkNumber, const string& studentName, const string& answer);
    //void removeAnswer(int homeworkNumber, const string& studentName);
    //void modifyAnswer(int homeworkNumber, const string& studentName, const string& newAnswer);
    string findAnswer(int homeworkNumber, const string& studentName);
    void outputCompleteHomeworks(const string& studentName);

//private:
    vector<Course> courses;

};

#endif //XIANGMU_STUDENT_H
