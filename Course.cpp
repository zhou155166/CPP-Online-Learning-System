//
// Created by 薛子玥 on 2023/12/5.
//
#include "Course.h"
#include "User.h"
#include "Teacher.h"
#include "login.h"
#include "Assistant.h"
#include "Student.h"
#include <iostream>
#include <algorithm>
extern Teacher *pThead,*pTrear;

extern Student *pShead,*pSrear;

extern Assistant *pAhead,*pArear;
extern vector<Homework> homeworks;
using namespace std;

Course::Course( string& courseName): courseName(courseName) {};//, vector<basic_string<char>> teacherUsername , teachers(teacherUsername) {}

Course::~Course() {
    teachers.clear();
    assistants.clear();
    students.clear();
}

void Course::addStudent(const string& studentUsername) {
    students.push_back(studentUsername);
}

void Course::removeStudent(const string& studentUsername) {
    students.erase(remove(students.begin(), students.end(), studentUsername), students.end());
}

void Course::addHomework(const string& homeworkName) {
    homeworkscore[homeworkName];
//    string stuname;
//    int score;
//    homeworks[string ,pair<string,int>]
}

void Course::removeHomework(const string& homeworkName) {
    homeworkscore.erase(homeworkName);
}

void Course::gradeHomework(const string& homeworkName, const string& courseName) {
    if (homeworkscore.find(homeworkName) == homeworkscore.end()) {
        cout << "Assignment does not exist:" << homeworkName << endl;
    }
    else {
        for (auto& homework:homeworkscore) {
            if (homework.first==homeworkName){
                for (pair< basic_string<char>, int> student:homework.second) {
                    int score;
                    string stuname;
                    cout<<"Enter student name:"<< endl;
                    cin>>stuname;
                    cout<<"Enter student scores:"<<endl;
                    cin>>score;
                    student.first=stuname;
                    student.second=score;
                }
            }
        }
    }
}

void Course::reviewGrades(const std::string& homeworkName) {
    if (homeworkscore.find(homeworkName)==homeworkscore.end()) {
        cout << "Assignment does not exist:" << homeworkName << endl;
    }
    else{
        cout << "homework" << homeworkName << "greade:" << endl;
        for (auto &&student:homeworkscore[homeworkName]) {
            cout<<"student："<<student.first<<" grade："<<student.second<<endl;
        }
    }
}

void Course::getMembers(Course& coursename) const {
    for (const auto& student : coursename.students) {
        cout << student<< endl;
    }
}

void Course::getHomeworks() const {
    for (const auto& homework : homeworkscore) {
        cout << homework.first << endl;
    }
}

void Course::addTeacher(const string& teacherUserName) {
    // 在 teachers 中插入一条新的记录
    if (teachers.find(teacherUserName) == teachers.end()) {
        cout << "Teacher already exists" << endl;
        return;
    }
    teachers[teacherUserName]={};
}

void Course::setWeights(const std::string& homeworkName,string CourseName,string Tname){


    int flag=0;
    for(Homework& homework:homeworks)
    {
        if(homework.coursename==CourseName&&homework.homeworkname==homeworkName)
        { flag=1;
            cout<<"please enter the weight"<<endl;
            double weight;
            cin>>weight;
            homework.weigh=weight;





            break;
        }
    }

    if(flag==0)cout<<"homework does not exist"<<endl;




   /* for (auto &&student:homeworkscore[homeworkName]) {
        int gs =0;
        gs++;
        char rate[gs];
        cout << "Please enter the proportion"<<endl;
        cin>>rate[gs];
    }*/
}
void Course::viewTotalScore(const std::string& homeworkName, string CourseName
){
string firstteacher;
cout<<"please enter the first teacher name"<<endl;
    cin>>firstteacher;
  int j=0;
    int renshu=0;
    for(string&stu:students){renshu++;}

    double *stuscore=new double[renshu]{0};

for(Homework &homework:homeworks)
{if(homework.coursename==CourseName&&firstteacher==homework.teachername)
    {




        for(string &name:students)
        {
            for(student_score &s:homework.student_scores)
            {if(s.studentname==name)
        {stuscore[j]+=(s.score)*(homework.weigh);
        break;
        }}
        j++;
        }
        j=0;


    }


}

for(string &name:students)
{
    cout<<name<<":"<<stuscore[j]<<endl;
    j++;
}
delete []stuscore;
    /*int gs =0;


    char rate[gs];
    for (auto &&student:homeworkscore[homeworkName]) {
        gs++;
        int score=student.second*rate[gs];
        cout <<score << endl;
    }*/
}
void Course::get_average_score(const std::string& homeworkName, string CourseName){
    string firstteacher;
    cout<<"please enter the first teacher name"<<endl;
    cin>>firstteacher;
    int j=0;
    int renshu=0;
    for(string&stu:students){renshu++;}

    double *stuscore=new double[renshu]{0};

    for(Homework &homework:homeworks)
    {if(homework.coursename==CourseName&&firstteacher==homework.teachername)
        {




            for(string &name:students)
            {
                for(student_score &s:homework.student_scores)
                {if(s.studentname==name)
                    {stuscore[j]+=(s.score)*(homework.weigh);
                        break;
                    }}
                j++;
            }
            j=0;


        }


    }
double sum=0;
    for(string &name:students)
    {
        sum+=stuscore[j];
        j++;
    }
    cout<<"average score:"<<sum/renshu<<endl;
    delete []stuscore;


    /*int sum=0;
    int gs=0;
    for (auto &&student:homeworkscore[homeworkName]) {
        sum+=student.second;
        gs++;
    }
    cout << sum/gs << endl;*/
}
void Course::get_max_score(const std::string& homeworkName, string CourseName){

    string firstteacher;
    cout<<"please enter the first teacher name"<<endl;
    cin>>firstteacher;
    int j=0;
    int renshu=0;
    for(string&stu:students){renshu++;}

    double *stuscore=new double[renshu]{0};

    for(Homework &homework:homeworks)
    {if(homework.coursename==CourseName&&firstteacher==homework.teachername)
        {




            for(string &name:students)
            {
                for(student_score &s:homework.student_scores)
                {if(s.studentname==name)
                    {stuscore[j]+=(s.score)*(homework.weigh);
                        break;
                    }}
                j++;
            }
            j=0;


        }


    }
   double max=0;
    for(string &name:students)
    {
        stuscore[j]>max?max=stuscore[j]:max=max;
        j++;
    }

    delete []stuscore;

    cout << max << endl;
}
void Course::get_min_score(const std::string& homeworkName, string CourseName){
    string firstteacher;
    cout<<"please enter the first teacher name"<<endl;
    cin>>firstteacher;
    int j=0;
    int renshu=0;
    for(string&stu:students){renshu++;}

    double *stuscore=new double[renshu]{0};

    for(Homework &homework:homeworks)
    {if(homework.coursename==CourseName&&firstteacher==homework.teachername)
        {




            for(string &name:students)
            {
                for(student_score &s:homework.student_scores)
                {if(s.studentname==name)
                    {stuscore[j]+=(s.score)*(homework.weigh);
                        break;
                    }}
                j++;
            }
            j=0;


        }


    }
    double min=1000;
    for(string &name:students)
    {
        stuscore[j]<min?min=stuscore[j]:min=min;
        j++;
    }

    delete []stuscore;

    cout << min << endl;
}

bool Course::operator==(string who){

    return who==this->courseName;
}
void Course::viewhisScore(const std::string& homeworkName,string name){



double allscore=0;


    for(Homework &homework:homeworks)
    {if(homework.coursename==courseName)
        {





                for(student_score &s:homework.student_scores)
                {if(s.studentname==name)
                    {allscore+=(s.score)*(homework.weigh);
                        break;
                    }}





        }


    }

 cout<<"your total score is:"<<allscore<<endl;

}
