//
// Created by 薛子玥 on 2023/12/10.
//
#include "Student.h"
#include "Course.h"
#include "Teacher.h"
#include "Assistant.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<cstring>
extern Teacher *pThead,*pTrear;
extern int homeworkid;
extern Student *pShead,*pSrear;

extern Assistant *pAhead,*pArear;
extern vector<Homework> homeworks;
extern Student *Swho;
extern note *nhead;
extern note*nrear;
extern note*np;
extern vector<Homework> homeworkscore;
map<int,map<string, string>> answers;//答案列表:<作业序号<学生名，答案>>
map<int,map<string, double>> scores;//成绩列表:<作业序号<学生名，成绩>>

Student::Student(const std::string &username) : User(username, 2) {}
Student::Student() : User() {}

void Student::homework(){
    cout<<"Please enter service: 1: View all completed assignments; 2: Submit homework"<<endl;
    int stuchoise;
    cin>>stuchoise;
    switch(stuchoise)
    {
        case 1:Swho->outputCompleteHomeworks(Swho->name);  break;
        case 2:
        { cout<<"enter your the number of homework"<<endl;
            int hnum;
            cout<<"enter your answer"<<endl;
            string answer;



            cin>>hnum;  cin>>answer;Swho->addAnswer(hnum,Swho->name ,answer);  break;}
        default:cout<<"Sorry, this service is not available!"<<endl;
    }
}

void Student::score_analyse(){
    string courseName;
    cin>>courseName;
    for (Course &course:courses) {
        if (course.courseName==courseName) {
            cout << "Please enter service: 1: View your total score" << endl;
            int choose = 0;
            cin >> choose;
            cout<<"Please enter the assignment name:";
            string hname;
            cin>>hname;
            switch (choose) {
                case 1:
                    course.viewhisScore(hname,name);break;
                default:
                    cout << "Sorry, this service is not available!" << endl;
            }
        }
    }
}


void Student::addAnswer(int homeworkNumber, const string& studentName, const string& answer) {
    // 检查作业序号是否存在，若不存在则创建新的映射
    if (answers.find(homeworkNumber) == answers.end()) {
        answers[homeworkNumber] = map<string, string>();
        cout<<"please enter the name of homework"<<endl;
        string homeworkName;
        cin>>homeworkName;

    }

    // 添加学生名和答案
    answers[homeworkNumber][studentName] = answer;

}

    // 删除答案
   /* void Student::removeAnswer(int homeworkNumber, const string& studentName) {
        // 检查作业序号是否存在
        auto it = answers.find(homeworkNumber);
        if (it != answers.end()) {
            // 删除学生名对应的答案
            it->second.erase(studentName);

            // 如果该作业序号下没有答案了，则从答案列表中删除该作业序号
            if (it->second.empty()) {
                answers.erase(it);
            }
        }
    }
    // 修改答案
    void Student::modifyAnswer(int homeworkNumber, const string& studentName, const string& newAnswer) {
        // 检查作业序号是否存在
        auto it = answers.find(homeworkNumber);
        if (it != answers.end() && it->second.find(studentName) != it->second.end()) {
            // 修改学生名对应的答案
            it->second[studentName] = newAnswer;
        }
    }
*/
// 查找答案
string Student::findAnswer(int homeworkNumber, const string& studentName) {
    // 检查作业序号是否存在
    auto it = answers.find(homeworkNumber);
    if (it != answers.end() && it->second.find(studentName) != it->second.end()) {
        // 返回学生名对应的答案
        return it->second[studentName];
    }

    return ""; // 如果未找到答案，返回空字符串
}
//输出学生已完成作业：遍历答案列表的每个作业序号，检查每个学生的答案是否为空。如果学生的答案非空，则输出该作业序号
void Student::outputCompleteHomeworks(const string& studentName) {
    for (const auto& pair : answers) {
        int homeworkNumber = pair.first;
        bool allAnswersEmpty = true;

        for (const auto& studentPair : pair.second) {
            const std::string& answer = studentPair.second;
            if (!answer.empty()&& studentPair.first==studentName) {
                for (const auto& homework : homeworks) {
                    if (homework.homeworkid == homeworkNumber) {
                        std::cout << "Number of homework " << homeworkNumber <<" course name"<< homework.homeworkname << std::endl;
                        break; // 如果找到匹配的 homework，可以选择退出循环
                    }
                }
                break;
            }
        }

    }
}

void Student::joinCourse( Course& courseName) {
    if (find(courses.begin(), courses.end(), courseName.courseName) == courses.end()) {
        courses.push_back(courseName);
       courseName.students.emplace_back(Swho->name);
        cout << "Successfully joined the course:" << courseName.courseName << endl;
    }
    else {
        cout << "You have already joined this course" << courseName.courseName << endl;
    }
}

void Student::leaveCourse( Course& courseName) {
    cout<<"please enter the name of teacher"<<endl;
    string tem;
    cin>>tem;//单独一行输入


     auto it = find(courses.begin(), courses.end(), courseName.courseName);
    if (it != courses.end()){
        courses.erase(it);
        cout << "Course successfully exited:" << courseName.courseName << endl;
        Teacher *p;
        for (p = pThead->next; p != pTrear->next; p = p->next) {
            if (tem== p->name) break;}
        for (Course &course :p-> courses) {
            auto it2 = find(course.students.begin(), course.students.end(), Swho->name);
            course.students.erase(it2);
        }

    } else {
        cout << "Course does not exist:" << courseName << endl;
    }
}


void Student::viewCourses() {
    if (courses.empty()) {
        cout << "You have not joined any courses." << endl;
    } else {
        cout << "The courses you have joined include:" << endl;
        for (const auto& course : courses) {
            cout << course.courseName << endl;
        }
    }
}

void Student::viewMembers(const string& courseName) {
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

Student::~Student() {
    for (Course &course : courses) {
        leaveCourse(course);
    }
}

void Student::reviewGrades(const string& courseName, const string& homeworkName)  {





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

                        string stuname=this->name;

                        int flag2=0;



                        for(student_score &stu:homework.student_scores)
                        {
                            if(stuname==stu.studentname)
                            {cout<<"your score is:"<<stu.score<<endl;
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
void Student::Scourse() {cout<<"please enter your choice"<<endl;
    int a;

    string ch;
    cin>>ch;
    a=ch[0]-'0';


    switch (a) {

        case 1:{//加入(调不了)
            cout<<"please enter name of first teacher"<<endl;
            string tname;
            cin>>tname;//老师
            int flag=0;
            for (Teacher *p = pThead; p != pTrear->next; p=p->next) {
                if (tname==p->name) {
                    flag=1;
                    cout<<"please enter name of course"<<endl;
                    string cname;
                    cin>>cname;

                    for(Course &course:p->courses){
                        if (cname==course.courseName)
                        {joinCourse(course);
                        cout<<"successfully join course"<<cname<<endl;}
                        else cout<<"Course does not exist:"<<cname<<endl;
                    }
                }

            }
           if(flag==0)cout<<"Teacher does not exist:"<<tname<<endl;
            break;
        }
        case 2: {//离开
            cout<<"please enter the name of course"<<endl;
            string name;
            cin >> name;
            for(Course &course:Swho->courses){
                if (name==course.courseName)
                {leaveCourse(course);}
                else cout<<"You have not joined the current course: "<<name<<endl;
            }

            break;
        }
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
        case 5:{//查看分数
            cout<<"please enter name of course"<<endl;
            string name;
            cin >> name;
            cout<<"please enter name of homework"<<endl;
            string hname;
            cin >> hname;
            reviewGrades(name,hname);

            break; }
    }
}

void Student::notice(){
    int n;
    std::cout<<" To view all published notifications, please enter 2"<<endl;
    std::cin>>n;
    if (n == 2) {
        if (nhead == nrear) {
            cout << "No notification has been issued yet" << endl;
        }
        else {
            np=nhead->next;
            while(np!=NULL){
                cout<<np->note_notice<<endl;
                np=np->next;
            }
        }

    }}




void Student::communicate() {
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
                } else { cout << "The user you entered does not exist" << endl; }
            }
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
                } else cout << "The user you entered does not exist" << endl;
            }
            break;
        }

    }}


void Student::gradeT(){
    string courseName;
    cout<<"Please input the course you want to evaluate"<<endl;
    cin>>courseName;
    string nameoft;
    int n,flag=1,flag2=1,flag3=1,flag4=0,flag6=0;
    if (!courses.empty()) {
        if (find(courses.begin(), courses.end(), courseName) == courses.end()) {
            cout << "You don't have the course you are looking for" << endl;
            return;
        } else {
//            Course temcourse(courseName);
            cout << "Please input the teacher you want to evaluate" << endl;
            cin >> nameoft;
            for (Course &course: courses) {
                if(course.courseName==courseName){
                    if (find(course.teacherinclude.begin(), course.teacherinclude.end(), nameoft) ==
                        course.teacherinclude.end()) {
                        cout << "The teacher isn't in the course" << endl;
                        return;
                    }}

            }
//            auto it = find(temcourse.teacherinclude.begin(), temcourse.teacherinclude.end(), nameoft);
//            if (it == temcourse.teacherinclude.end()) {cout<<"The teacher isn't in the course"<<endl;return;}
            for (Teacher *p = pThead; p != pTrear->next; p = p->next) {
                if (nameoft == p->name) {
                    flag3 = 1;
                    for (Course &course: p->courses) {
                        if (courseName == course.courseName) {
                            for (p->cotem = p->cohead;
                                 p->cotem != p->corear->next; p->cotem = p->cotem->next) {
                                if (p->cotem->desti==courseName&&p->cotem->nameofstu == name) {
                                    cout << "You have evaluated the teacher" << endl;
                                    return;
                                }
                            }
                            p->cotem = new commenttoT;
                            p->corear->next =p->cotem;
                            cout << "Please input your evaluation" << endl;
                            cin >> p->cotem->comment;
                            cout << "Please input your grade" << endl;
                            p->cotem->desti=courseName;
                            cin >> n;
                            p->cotem->grade = n;
                            p->cotem->count=p->cotem->count+1;
                            p->corear = p->cotem;
                            p->cotem->nameofstu = name;
                            p->cotem->next = NULL;return;
                        }

                    }
//                        else {flag2=0;}
cout<<"The teacher isn't in the course"<<endl;
                }
//                if (flag2 == 1)break;
//                if (flag2 == 0) {
//                    cout << "The teacher don't have the course" << endl;
//                    break;
//                }
            }
//            else flag3 = 0;
        }
//            if(flag3==0)cout<<"The teacher isn't in the course"<<endl;
//        }
    }
    else cout<<"You don't have any course"<<endl;}





//void Student::Sgrade() {
//    string temnameofc,temnameoft;
//    cin>>temnameofc>>temnameoft;
//    if (find(courses.begin(), courses.end(), temnameofc) == courses.end()) {
//        cout << "课程不存在：" << temnameofc << endl;
//    }
//    else {
//        for (const auto& course : courses) {
//            if (course.courseName==temnameofc){
//                for (const auto& teacher : course.teachers){
//                    if(course.teachers==temnameoft)
//                }
//            }
//        }
//    }
//}