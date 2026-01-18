//
// Created by 薛子玥 on 2023/12/10.
//

#ifndef XIANGMU_ASSISTANT_H
#define XIANGMU_ASSISTANT_H

#include "User.h"
#include "Course.h"
#include "notice.h"
#include <vector>
#include <string>

using namespace std;

class Assistant : public User {
public:
    Assistant();

    explicit Assistant(const string& username);
    ~Assistant() override;

    Assistant *next;
    bool isnotice=0;
    bool islog=0;
    void Acourse();
    void notice();
    //void homework();
    //void score();

    void communicate();
    void score_analyse();

    note *snote=nullptr;
    communicatebox *chead=new communicatebox,*crear=chead,*cp= chead,*ctem;

    void joinCourse( Course& courseName);
    void leaveCourse( Course& courseName);
    void viewCourses();
    void viewMembers(const string& courseName);
    void gradeHomework(const string& courseName, const string& homeworkName);
    void reviewGrades(const string& courseName, const string& homeworkName);


//private:
    vector<Course> courses;
};

#endif //XIANGMU_ASSISTANT_H
