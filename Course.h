//
// Created by 薛子玥 on 2023/12/5.
//

#ifndef XIANGMU_COURSE_H
#define XIANGMU_COURSE_H

#include <string>
#include <vector>
#include <map>
#include "notice.h"

using namespace std;
struct TeacherInfo {
    int score;
    string evaluation;

    TeacherInfo() : evaluation(""), score(0) {}
};
struct comments{
    vector<string> stuname;
    vector<string> comment;
    vector<int> score;
};

class Course : public basic_string<char> {
public:
    Course(string& courseName);//, vector<basic_string<char>> teacherUsername

    ~Course();
    bool operator==(string );
    void addStudent(const string& studentUsername);
    void removeStudent(const string& studentUsername);
    void addHomework(const string& homeworkName);
    void removeHomework(const string& homeworkName);
    void gradeHomework(const string& homeworkName, const string& studentUsername);
    void reviewGrades(const string& homeworkName);
    void getMembers( Course& coursename) const;
    void getHomeworks() const;
    void addTeacher(const string& teacherUsername);


    void get_max_score(const std::string& homeworkName, string CourseName);
    void get_min_score(const std::string& homeworkName, string CourseName);
   void get_average_score(const std::string& homeworkName, string CourseName);
   void setWeights(const std::string& homeworkName, string CourseName,string Tname);
    void viewTotalScore(const std::string& homeworkName, string CourseName);


    string courseName;
    map<string,map<string,TeacherInfo>>teachers;
    vector<string> assistants;
    vector<string> students;
    vector<string> teacherinclude;
    map<string,map<string, int>> homeworkscore;//<作业名<学生名，分数>>
    Course* next;
    void viewhisScore(const std::string& homeworkName,string name);
};


#endif //XIANGMU_COURSE_H
