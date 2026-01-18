//
// Created by Lenovo on 2023/12/17.
//

#include "Assistant.h"
//
// Created by 薛子玥 on 2023/12/10.
//
#include "Assistant.h"
#include "Course.h"
#include "Teacher.h"
#include "Student.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<cstring>
extern Teacher *pThead,*pTrear;

extern Student *pShead,*pSrear;

extern Assistant *pAhead,*pArear;
extern vector<Homework> homeworks;
extern int homeworkid;
extern Teacher *Twho;//记录登陆者所对应的类的地址
extern Student *Swho;
extern Assistant *Awho;
extern note *nhead;
extern note*nrear;
extern note*np;

Assistant::Assistant(const string &username)  : User(username, 3) {}
Assistant::Assistant()  : User() {};



void Assistant::joinCourse(Course& courseName) {
    if (find(courses.begin(), courses.end(), courseName.courseName) == courses.end()) {
        courses.push_back(courseName);
        courseName.assistants.emplace_back(Awho->name);
        cout << "Course Joining Success" << courseName << endl;
    } else {
        cout << "Course Already Exists" << courseName << endl;
    }
}

void Assistant::leaveCourse( Course& courseName) {
    auto it = find(courses.begin(), courses.end(), courseName.courseName);
    if (it != courses.end()) {
        courses.erase(it);
        cout << "Course Withdrawal Success" << courseName << endl;
        auto it2 = find(courseName.assistants.begin(), courseName.assistants.end(), Awho->name);
        courseName.assistants.erase(it2);
    } else {
        cout << "The course does not exist" << courseName << endl;
    }
}


void Assistant::viewCourses() {
    if (courses.empty()) {
        cout << "You didn't create any courses" << endl;
    } else {
        cout << "The courses you create are" << endl;
        for (const auto& course : courses) {
            cout << course.courseName << endl;
        }
    }
}

void Assistant::viewMembers(const string& courseName) {
    if (find(courses.begin(), courses.end(), courseName) == courses.end()) {
        cout << "The course does not exist" << courseName << endl;
    } else {
        cout<<"please enter the name of teacher"<<endl;
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

void Assistant::gradeHomework(const string& courseName, const string& homeworkName) {





    if (find(courses.begin(), courses.end(), courseName) == courses.end()) {
        cout << "Course does not exist:" << courseName << endl;
    } else {
cout<<"please enter the name of  first teacher include:"<<endl;
string firstteacher;
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

void Assistant::reviewGrades(const string& courseName, const string& homeworkName) {




    if (find(courses.begin(), courses.end(), courseName) == courses.end()) {
        cout << "Course does not exist:" << courseName << endl;
    } else {

        for (auto& course : courses) {
            if (course.courseName==courseName) {
                int flag=0;
                for(Homework& homework:homeworks)
                {
                    if(homework.coursename==courseName&&homework.homeworkname==homeworkName)
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

Assistant::~Assistant() {
    for (Course &course : courses) {
        leaveCourse(course);
    }
}

void Assistant::Acourse() {
    int a;
    string ch;
    cin>>ch;
   a=ch[0]-'0';
    switch (a) {
        case 1:{//加入(调不了)
            cout<<"please enter name of teacher"<<endl;
            string tname;
            cin>>tname;//老师
            for (Teacher *p = pThead; p != pTrear->next; p=p->next) {
                if (tname==p->name) {
                    cout<<"please enter name of course"<<endl;
                    string cname;
                    cin>>cname;
                    for(Course course:p->courses){
                        if (cname==course.courseName)
                            joinCourse(course);
                    }
                }
            }
            break;
        }
        case 2: {//离开
            cout<<"please enter name of course"<<endl;
            string name;
            cin >> name;
            for(Course &course:Swho->courses){
                if (name==course.courseName)
                {leaveCourse(course);}
                else cout<<"You have not joined the current course: "<<name<<endl;
                break;
            }}
        case 3:{//查看课程
            viewCourses();
            break;
        }
        case 4:{//查看成员
            cout<<"please enter name of course"<<endl;
            string name;
            cin >> name;
            viewMembers(name);
            break;
        }
        case 5:{//作业打分
            cout<<"please enter name of course"<<endl;
            string name;
            cin >> name;
            cout<<"please enter name of homework"<<endl;
            string hname;
            cin >> hname;
            gradeHomework(name,hname);
            break;
        }
        case 6:{//查看分数
            cout<<"please enter name of course"<<endl;
            string name;
            cin >> name;
            cout<<"please enter name of homework"<<endl;
            string hname;
            cin >> hname;
            reviewGrades(name,hname);
            break;}
    }
}

void Assistant::notice(){
    int n;
    std::cout<<"To send notifications, please enter 1. To view all published notifications, please enter 2"<<endl;
    std::cin>>n;
    if(n==1){
        np=new note;
        nrear->next=np;
        np->next=NULL;
        cout<<"please enter the notice"<<endl;
//        cin.getline(np->note_notice,500);
        cin>>np->note_notice;
        nrear=np;

    }
    if(n==2) {
        if(nhead==nrear){
            cout<<"No notification has been issued yet"<<endl;
        }
        else{
            np=nhead->next;
            while(np!=NULL){
                cout<<np->note_notice<<endl;
                np=np->next;
            }
        }}
}



void Assistant::communicate() {
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
            string tem4;
            Student *p;
            cout << "please enter the notice" << endl;
            cin>>tem4;
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

void Assistant::score_analyse(){
    cout<<"please enter name of course"<<endl;
    string courseName;
    cin>>courseName;
    for (Course &course:courses) {
        if (course.courseName==courseName){
            cout <<"Please enter the service: 1. View the total grade of all students; 2. Check the average score of each course; 3. Check the highest scores for each course; 4. Check out the lowest scores for each course"<<endl;
            int choose=0;
            cin>>choose;
            cout<<"Please enter homework name";
            string hname;
            cin>>hname;
            switch(choose){
                case 1:course.viewTotalScore(hname,courseName);break;
                case 2:course.get_average_score(hname,courseName);break;
                case 3:course.get_max_score(hname,courseName);break;
                case 4:course.get_min_score(hname,courseName);break;
                default:cout<<"Sorry, there is no such service!"<<endl;
            }
        }
    }
}

