// Created by 薛子玥 on 2023/12/5.
//
#include "Teacher.h"
#include "Course.h"
#include "login.h"
#include "Assistant.h"
#include "Student.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<cstring>
#include<map>
#include"homework.h"
extern Teacher *pThead,*pTrear;

extern Student *pShead,*pSrear;
extern vector<Homework> homeworks;
extern int homeworkid;
extern Assistant *pAhead,*pArear;
extern Teacher *Twho;//记录登陆者所对应的类的地址
extern Student *Swho;
extern Assistant *Awho;
using namespace std;
extern note *nhead;
extern note*nrear;
extern note*np;
typedef bool(*func_t) (const Teacher&,const Teacher&);
bool teacherCmp(const Teacher t1,const Teacher t2){
    return t1.name<t2.name;
}

map<Teacher,Homework,func_t> questions;
/*typedef bool(*func_t) (const Teacher&,const Teacher&);
bool teacherCmp(const Teacher t1,const Teacher t2){
    return t1.name<t2.name;
}

map<Teacher,Homework,func_t> questions;//作业列表：<教师，题目>
*/
/*
void Teacher::publishHomework(const string& courseName,const string& question,const string& tname){
     if (std::find_if(courses.begin(), courses.end(), [&](const Course& c) { return c.courseName == courseName; }) == courses.end()) {
        std::cout << "课程不存在：" << courseName << std::endl;
    }else {
        Homework newHomework;
        newHomework.homeworkid=homeworkid++;
        newHomework.homeworkname=question;
        newHomework.coursename=courseName;
        newHomework.teachername=tname;
        homeworks.push_back (newHomework);
        std::cout<<"作业发布成功";
    }
}
*/
void Teacher::publishHomework() {
    cout<<"Please enter the course name"<<endl;
    string cname;
    cin >> cname;
    if (find(courses.begin(), courses.end(), cname) == courses.end()) {
        cout << "Course does not exist" << cname << endl;
    }  else {
        cout<<"Please enter the assignment name"<<endl;
        string hname;
        cin >> hname;


        Homework *p=new Homework ;
        p->homeworkid=homeworkid++;
        p->homeworkname=hname;
        p->coursename=cname;
        p->teachername=this->name;




        for (Course &course : courses) {
            if (course.courseName==cname){

                for(string stu:course.students)
                {
                    student_score* xuefen=new student_score(stu,0);

                    p->student_scores.push_back(*(xuefen));

                }

                break;
            }
        }

        homeworks.push_back( *p);
}}
void Teacher::viewHomework(){
    for (const auto& hw : homeworks) {
        if(this->name==hw.teachername)
            std::cout << hw.homeworkname << std::endl;
    }
}
void Teacher::homework(){
    cout << "Please enter service: 1: Publish homework; 2: View all published assignments"<<endl;
    int choose=0;
    cin >> choose;
    switch(choose){
        case 1:publishHomework();break;
        case 2:viewHomework();break;
        default:cout<<"Sorry, this service is not available!"<<endl;
    }
}










void Teacher::notice()
{
    int n;
    std::cout<<"To send notifications, please enter 1. To view all published notifications, please enter 2"<<endl;
    std::cin>>n;
    if(n==1){
        np=new note;
        nrear->next=np;
        np->next=NULL;
        cout<<"please enter the notice"<<endl;
//        cin.get();
//        cin.getline(np->note_notice,500);
        cin>>np->note_notice;
        nrear=np;

    }
    if(n==2) {
        if(nhead==nrear){
            cout<<"No notification has been issued yet"<<endl;
        }
        else{
            Twho->snote=nhead->next;
            while(snote!=NULL){
                cout<<snote->note_notice<<endl;
                snote=snote->next;
            }
        }}
}


void Teacher::communicate() {
    cout << "Please enter the identity of the person you want to send the message to" << endl;//T,S,A
    char checkwho3;
    string tem;
    int flag;
    cin >> checkwho3;
    switch (checkwho3) {

        case 'T': {
            cout << "Please enter the name of the person you want to message" << endl;
            cin>>tem;//单独一行输入
            flag = 0;
            Teacher *p;
            for (p = pThead; p != pTrear; p = p->next) {
                if (tem==p->name) {
                    p->ctem = new communicatebox;
                    p->crear->next = p->ctem;
                    p->crear = p->ctem;
                    p->crear->next = NULL;
                    cout<<"please enter the massage"<<endl;
                    cin>>p->ctem->message;
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                if (tem== pTrear->name) {
                    p = pTrear;
                    p->ctem = new communicatebox;
                    p->crear->next = p->ctem;
                    p->crear = p->ctem;
                    p->crear->next = NULL;
                    cout<<"please enter the massage"<<endl;
                    cin>>p->ctem->message;
                    flag = 1;
                } else { cout << "The person you are looking for does not exist" << endl; }
            }
            break;
        }
        case 'S': {
            int n, j = 0;
            flag = 0;
            string tem3;
            char tem4[500];
            Student *p;
            cout << "Please enter notification:" << endl;
            cin.get();
            cin.getline(tem4, 500);
//                    *xinhead=new student,*xinrear,*xinp;
//                    xinrear=xinhead;xinhead->next=NULL;
            do {j=0;
                cout << "Please enter 1 to select the message recipient. Once the selection is complete, please enter 2"<<endl;
                cin >> n;
                switch (n) {
                    case 1: {
                        cout << "Please enter the name of the person you want to message" << endl;
                        cin>>tem3;
                        if (tem3== pSrear->name) {
                            p = pSrear;
                            p->ctem = new communicatebox;
                            p->crear->next = p->ctem;
                            p->crear = p->ctem;
                            p->crear->next = NULL;
                            j = 1;
                        } else {
                            for (p = pShead; p != pSrear; p = p->next) {
                                if (tem3== p->name) {
                                    p->ctem = new communicatebox;
                                    p->crear->next = p->ctem;
                                    p->crear = p->ctem;
                                    p->crear->next = NULL;
                                    j = 1;
                                    break;
//                        cin.getline(p->ctem->message,500);
                                }
                            }
                        }
                        if (j == 1) {
                            p->crear->message= tem4;
                        } else cout << "The person you are looking for does not exist" << endl;
                        break;
                    }

                    case 2:
                        break;
                    default:
                        break;
                }
            } while (n == 1);
            break;
        }
        case 'A': {
            cout << "Please enter the name of the person you want to message" << endl;
            cin>>tem;//单独一行输入
            flag = 0;
            Assistant *p;
            for (p = pAhead; p != pArear; p = p->next) {
                if (tem== p->name) {
                    p->ctem = new communicatebox;
                    p->crear->next = p->ctem;
                    p->crear = p->ctem;
                    p->crear->next = NULL;
                    cout<<"please enter the massage"<<endl;
                    cin>>p->ctem->message;
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                if (tem== pArear->name) {
                    p = pArear;
                    p->ctem = new communicatebox;
                    p->crear->next = p->ctem;
                    p->crear = p->ctem;
                    p->crear->next = NULL;
                    cout<<"please enter the massage"<<endl;
                    cin>>p->ctem->message;
                    flag = 1;
                } else cout << "The person you are looking for does not exist" << endl;
            }
            break;
        }

    }}
void Teacher::viewevaluation() {
    string nameofcourse;
    int count=0;
    int sum=0;
    double average;
//    int shifouzhaodaokecheng;
    if (!courses.empty()){
        cout<<"Please input the course you are looking for"<<endl;
        cin>>nameofcourse;
        if (find(courses.begin(), courses.end(), nameofcourse) == courses.end()) {
            cout << "You don't have the course you are looking for"  << endl;
            return;
        }
        else{//该老师有这个课程
//            if(Twho->corear->count==0){cout<<"There has been none evaluation"<<endl;return;}
//            else{
            for (Twho->cotem = Twho->cohead;
                 Twho->cotem != Twho->corear->next; Twho->cotem = Twho->cotem->next) {
                if(Twho->cotem->desti==nameofcourse){
                    cout<<Twho->cotem->comment<<endl;
                    sum+=Twho->cotem->grade;
                    count++;}

            }
            if(count==0){cout<<"There has been none evaluation"<<endl;return;}
            average=double(sum)/count;
            cout<<"Your average grade is:"<<average<<endl;return;
//            }

//
//
//            for(Course &course:Twho->courses){
//                if (nameofcourse==course.courseName){//找到了这个课程
//                    if(course.count==0)cout<<"There has been none evaluation"<<endl;
//                    else{
//                        for(course.ctem=course.cohead->next;course.ctem!=NULL;course.ctem=course.ctem->next)
//                        {if(course.ctem->desti==name){cout<<course.ctem->comment<<endl;
//                                average=double(course.sum)/course.count;
//                                cout<<"Your average grade is:"<<average<<endl;}}
//                    }
//
//                    break;
//                }
//
//            }

        }
    }
    else cout<<"You don't have any course"<<endl;}



Teacher::Teacher(const string& username) : User(username, 1) {
}

Teacher::Teacher() : User() {
}


//void Teacher::createCourse(string Name) {
//    Course *p=new Course(Name) ;
//    int flag=0;
//    for(Course&course:courses)
//    {
//        if(course.courseName==name)flag=1;
//    }
//
//    if (flag==0) {
//        //courses.back().next = &courseName;
//        courses.push_back(*p);
//        p->teacherinclude.push_back(this->name);
//        cout << "Course created successfully:" << Name << endl;
//    } else {
//        cout << "Course already exists:" << Name << endl;
//    }
//}


void Teacher::createCourse(string Name) {
    Course courseName(Name);
    auto it = find(courses.begin(), courses.end(), Name);
    if (it == courses.end()) {
        //courses.back().next = &courseName;
        courses.push_back(courseName);
        for(Course &course:courses){
            if (Name==course.courseName){
                course.teacherinclude.push_back(name);break;
            }}

        cout << "Course created successfully:" << Name << endl;
    } else {
        cout << "Course already exists:" << courseName << endl;
    }
}



void Teacher::deleteCourse(const string& courseName1) {

    auto it = find(courses.begin(), courses.end(), courseName1);

        if (it!=courses.end()) {


            for(Course &course:courses)
            {
                if(course.courseName==courseName1)
                {


                    for(string&stu:course.students)
                    {
                        for ( Student*p = pShead; p != pSrear->next; p = p->next) {
                            if (stu== p->name) {
                                auto it2 = find(p->courses.begin(), p->courses.end(), courseName1);
                                p->courses.erase(it2);
                            }
                        }

                    }


                    for(string&ass:course.assistants)
                    {
                        for ( Assistant*p = pAhead; p != pArear->next; p = p->next) {
                            if (ass== p->name) {
                                auto it2 = find(p->courses.begin(), p->courses.end(), courseName1);
                                p->courses.erase(it2);
                            }
                        }

                    }




                }
            }


            courses.erase(it);


            cout << "Course deleted successfully:" << courseName1 << endl;

        }else {
            cout << "Course does not exist:" << courseName1 << endl;
        }
    }



void Teacher::viewCourses() {

    if (courses.empty()) {
        cout << "You have not created any courses." << endl;
    } else {
        cout << "The courses you have created include:" << endl;
        for (Course&course : courses) {
            cout << course.courseName << endl;
        }
    }
}

void Teacher::viewMembers(const string& courseName) {
    if (find(courses.begin(), courses.end(), courseName) == courses.end()) {
        cout << "Course does not exist:" << courseName << endl;
    } else {
        cout<<"please enter the name of first teacher"<<endl;
        string tem;
        cin>>tem;//单独一行输入
        int flag = 0;
        Teacher *p;
        for (p = pThead->next; p != pTrear->next; p = p->next) {
            if (tem== p->name) break;}
        for (Course &course :p-> courses) {
            if (course.courseName==courseName){
                cout << "The course members include:" << endl;
                course.getMembers(course);
                break;
            }
        }
    }
}

void Teacher::gradeHomework(const string& courseName, const string& homeworkName) {




    if (find(courses.begin(), courses.end(), courseName) == courses.end()) {
        cout << "Course does not exist:" << courseName << endl;
    } else {
        cout<<"Please enter the first teacher's name"<<endl;
        string  firstteacher;
        cin>>firstteacher;
        for (auto& course : courses) {
            if (course.courseName==courseName) {
int flag=0;
                for(Homework& homework:homeworks)
                {
                    if(homework.coursename==courseName&&homework.homeworkname==homeworkName&&firstteacher==homework.teachername)
                    { flag=1;
                        cout<<"please enter the name of student"<<endl;
                        string stuname;
                        cin>>stuname;
                        int flag2=0;



                        for(student_score &stu:homework.student_scores)
                        {
                            if(stuname==stu.studentname)
                            {flag2=1;
                                cout<<"please enter the grade"<<endl;
                                int num;
                                cin>>num;
                                stu.score=num;

                                break;
                            }
                        }
                        if(flag2==0)cout<<"student does not exist"<<endl;
                        break;
                    }
                }

                if(flag==0)cout<<"homework does not exist"<<endl;

              /*  if (course.homeworkscore.find(homeworkName) == course.homeworkscore.end()) {
                    cout << "Assignment does not exist:" << homeworkName << endl;
                } else {
                    for (auto &homework:course.homeworkscore) {
                        if (homework.first==homeworkName){
                            for (pair< basic_string<char>, int> student:homework.second) {
                                int score;
                                string stuname;
                                cout<<"Enter student name:"<< endl;
                                cin>>stuname;
                                cout<<"Enter student score:"<<endl;
                                cin>>score;
                                student.first=stuname;
                                student.second=score;
                            }
                        }
                    }
                }*/
            }
        }
    }
}

void Teacher::reviewGrades(const string& courseName, const string& homeworkName) {




    if (find(courses.begin(), courses.end(), courseName) == courses.end()) {
        cout << "Course does not exist:" << courseName << endl;
    } else {
        cout<<"Please enter the first teacher's name"<<endl;
        string  firstteacher;
        cin>>firstteacher;
        for (auto& course : courses) {
            if (course.courseName==courseName) {
                int flag=0;
                for(Homework& homework:homeworks)
                {
                    if(homework.coursename==courseName&&homework.homeworkname==homeworkName&&firstteacher==homework.teachername)
                    { flag=1;

                        for(student_score &stu:homework.student_scores)
                        {
                            cout<<"student:"<<stu.studentname<<"  score:"<<stu.score<<endl;
                        }

                        break;
                    }
                }

                if(flag==0)cout<<"homework does not exist"<<endl;


            }
        }
    }









   /* if (find(courses.begin(), courses.end(), courseName) == courses.end()) {
        cout << "Course does not exist:" << courseName << endl;
    } else {
        for (Course &course : courses) {
            if (course.courseName==courseName){
                if (course.homeworkscore.find(homeworkName)==course.homeworkscore.end()) {
                    cout << "Assignment does not exist:" << homeworkName << endl;
                }
                else{
                    cout << "homework:" << homeworkName << "grade:" << endl;
                    for (auto &&student:course.homeworkscore[homeworkName]) {
                        cout<<"student："<<student.first<<" grade："<<student.second<<endl;
                    }
                    break;
                }
            }
            break;
        }
    }*/
}

Teacher::~Teacher() {
    courses.clear();
}

void Teacher::joinOtherTeacherCourse(Course& courseName) {
    if (find(courses.begin(), courses.end(), courseName.courseName) == courses.end()) {
        cout << "Successfully joined the course:" << courseName.courseName << endl;
        courses.push_back(courseName);
        for(Course &course:courses) {
            if (courseName == course.courseName) {
                course.teacherinclude.assign(courseName.teacherinclude.begin(), courseName.teacherinclude.end());
                for (string tea: course.teacherinclude) {
                    for (Teacher *p = pThead->next; p != pTrear->next; p = p->next) {
                        if (p->name == tea) {
                            for (Course &course1: p->courses) {
                                if (courseName == course1.courseName) {
                                    course1.teacherinclude.assign(courseName.teacherinclude.begin(),
                                                                  courseName.teacherinclude.end());
                                    break;
                                }
                            }
                            break;
                        }

                    }
                }
                for (string stu: course.students) {
                    for (Student *p = pShead->next; p != pSrear->next; p = p->next) {
                        if (p->name == stu) {
                            for (Course &course1: p->courses) {
                                if (courseName == course1.courseName) {
                                    course1.teacherinclude.assign(courseName.teacherinclude.begin(),
                                                                  courseName.teacherinclude.end());
                                    break;
                                }
                            }
                            break;
                        }

                    }
                }
            }

//        courseName.teacherinclude.emplace_back(Twho->name);
//        courseName.teacherinclude.push_back(this->name);
        }}  else{
        cout << "Course cannot be added:" << courseName.courseName << endl;
    }
}

void Teacher::Tcourse() {
    cout<<"please enter your choice for course"<<endl;
    int a;
    string ch;
    cin>>ch;
    a=ch[0]-'0';

    switch (a) {
        case 1:{//创建
            cout<<"please enter the name of course"<<endl;
            string name;
            cin >> name;

            createCourse(name);
            break;
        }
        case 2: {//解散
            cout<<"please enter the name of course"<<endl;
            string name;
            cin >> name;
            deleteCourse(name);
            break;
        }
        case 3:{//查看课程
            viewCourses();
            break;
        }
        case 4:{//查看成员
            cout<<"please enter the name of course"<<endl;
            string name;
            cin >> name;
            viewMembers(name);
            break;
        }
        case 5:{//作业打分
            cout<<"please enter the name of course"<<endl;
            string name;
            cin >> name;
            cout<<"please enter the name of homework"<<endl;
            string hname;
            cin >> hname;
            gradeHomework(name,hname);
            break;
        }
        case 6:{//查看分数
            cout<<"please enter the name of course"<<endl;
            string name;
            cin >> name;
            cout<<"please enter the name of homework"<<endl;
            string hname;
            cin >> hname;
            reviewGrades(name,hname);
            break;
        }
        case 7:{//加入其他老师课程
            cout<<"please enter the name of teacher"<<endl;
            string tname;
            cin>>tname;//老师
            for (Teacher *p = pThead; p != pTrear->next; p=p->next) {
                if (tname==p->name) {
                    cout<<"please enter the name of course"<<endl;
                    string cname;
                    cin>>cname;
                    for(Course& course:p->courses){
                        if (cname==course.courseName){
                            course.teacherinclude.push_back(name);
                            joinOtherTeacherCourse(course);}

                    }
                }
            }
            break;
        }
    }
}

void Teacher::score_analyse(){
    cout<<"please enter name of course"<<endl;
    string courseName;
    cin>>courseName;
    for (Course &course:courses) {
        if (course.courseName==courseName){
            cout <<"Please enter the service: 1. Set the proportion of homework and exams to the total score; 2. View the total scores of all students; 3. Check the average score of each course; 4. View the highest scores for each course; 5. View the minimum scores for each course"<<endl;
            int choose=0;
            string ch;
            cin>>ch;
            choose=ch[0]-'0';
            cin>>choose;

            string hname=" ";

            switch(choose){
                case 1:
                {cout<<"Please enter the assignment name:";
                    string hname;
                    cin>>hname;
                    course.setWeights(hname,courseName,Twho->name);break;}
                case 2:course.viewTotalScore(hname,courseName);break;
                case 3:course.get_average_score(hname,courseName);break;
                case 4:course.get_max_score(hname,courseName);break;
                case 5:course.get_min_score(hname,courseName);break;
                default:cout<<"Sorry, this service is not available!"<<endl;
            }
        }
    }
}

