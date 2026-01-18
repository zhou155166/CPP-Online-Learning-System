//
// Created by 薛子玥 on 2023/12/5.
//

#ifndef XIANGMU_TEACHER_H
#define XIANGMU_TEACHER_H

#include "User.h"
#include "Course.h"
#include "notice.h"
#include "homework.h"
#include <vector>
#include <string>

using namespace std;
struct commenttoT{
    string comment;
    commenttoT *next;
//    int grade;
    string nameofstu;
    string desti;
    int grade=0;
    int count=0;
};
class Teacher : public User {
public:

    Teacher();

    Teacher *next;
    bool isnotice=0;
    bool islog=0;

    void Tcourse();
    void notice();
    void homework();
    //void score();
    void viewevaluation();
    void communicate();
    void score_analyse();

    note *snote=nullptr;
    communicatebox *chead=new communicatebox,*crear=chead,*cp= chead,*ctem;
    commenttoT *cohead=new commenttoT,*corear=cohead,*cotem;
    int sumofcomment,numofcomment;

    Teacher(const string& username);
    ~Teacher();
    void createCourse(const string Name);
    void deleteCourse(const string& courseName);
    void viewCourses();
    void viewMembers(const string& courseName);
    void gradeHomework(const string& courseName, const string& homeworkName);
    void reviewGrades(const string& courseName, const string& homeworkName);
    void joinOtherTeacherCourse(Course& courseName);



    //void publishHomework();
    //void viewHomework();


    //新加上的作业序号
    vector<Course> courses;





    string name;
    void publishHomework();
    void viewHomework();



};


#endif //XIANGMU_TEACHER_H
