//
// Created by Lenovo on 2023/12/17.
//

#include "worker.h"
#include<iostream>
#include"login.h"
#include"autojump.h"
#include<cstring>
#include"check_all_course.h"
#include "Teacher.h"
#include "Assistant.h"
#include "Student.h"

using namespace std;

extern Teacher *pThead,*pTrear;

extern Student *pShead,*pSrear;

extern Assistant *pAhead,*pArear;


extern Teacher *Twho;//记录登陆者所对应的类的地址
extern Student *Swho;
extern Assistant *Awho;
void worker_seecourse()
{for(Teacher*p=pThead->next;p!=pTrear->next;p=p->next)
    {
        p->viewCourses();

    }

    }
    void worker_checkwho(){
    cout<<"who do you want to check"<<endl;//T,S,A
            char checkwho1 ;
            cin>>checkwho1;
            switch(checkwho1)
            {
                case 'T':
                    for( Teacher*p=pThead->next;p!=pTrear->next;p=p->next)
                    {cout<<p->name<<endl;}
                    break;
                case'S':
                    for( Student*p=pShead;p!=pSrear->next;p=p->next)
                    {cout<<p->name<<endl;}
                    break;
                case'A':
                    for( Assistant*p=pAhead;p!=pArear->next;p=p->next)
                    {cout<<p->name<<endl;}
                    break;



            }
            }
            void check_whocourse()
            { cout<<"Please enter the person you want to search for"<<endl;//T,S,A
                char checkwho2 ;
                string tem;
                cin>>checkwho2;
                cout<<"Please enter the name of the person you are looking for"<<endl;int flag=0;
                cin>>tem;
                //单独一行输入
                switch(checkwho2)
                {
                    case 'T':
                        flag=0;
                        for(Teacher*p=pThead->next;p!=pTrear->next;p=p->next)
                        {if (tem== p->name){p->viewCourses();flag=1;break; }}
                        if(flag==0){cout<<"The person you are looking for does not exist"<<endl;}
                        break;
                    case'S':
                        flag=0;
                        for( Student*p=pShead->next;p!=pSrear->next;p=p->next)
                        {if (tem== p->name){p->viewCourses();flag=1;break;} }
                        if(flag==0){cout<<"The person you are looking for does not exist"<<endl;}
                        break;
                    case'A':
                        flag=0;
                        for( Assistant*p=pAhead->next;p!=pArear->next;p=p->next)
                        {if (tem== p->name){p->viewCourses();flag=1;break;} }
                        if(flag==0){cout<<"The person you are looking for does not exist"<<endl;}
                        break;



                }
                }
                void dissolve_teachercourese()
                {  cout<<"Dissolve which teacher's course?"<<endl;
                    string checkname;
                    cin>>checkname;
                    int flag=0;
                    for (Teacher *p = pThead->next; p != pTrear->next; p=p->next) {

                        if (checkname== p->name) {
                            cout<<"please enter the name of course"<<endl;
                            string name;
                            cin >> name;
                            p->deleteCourse(name);


                            flag = 1;
                            break;
                        }
                    }
                    if(flag==0){cout<<"The person you are looking for does not exist"<<endl;}
                    }
                    void enterexit()
                    {  cout<<"Which student should I invite to join/exit the course?"<<endl;
                        string checkname;
                        cin>>checkname;
                        int flag=0;
                        for (Student *p = pShead->next; p != pSrear->next; p=p->next) {

                            if (checkname== p->name) {
                                p->Scourse();//提示输入退出还是加入？与学生加入课程保持一致
                                flag = 1;
                                break;
                            }
                        }
                        if(flag==0){cout<<"The person you are looking for does not exist"<<endl;}
                       }


/*void worker(int choice)
{
    switch(choice)
    {{
            case 2:{for(Teacher*p=pThead->next;p!=pTrear->next;p=p->next)
                {
                p->viewCourses();

                }

                ;break;}

            case 3:
            {cout<<"who do you want to check"<<endl;//T,S,A
                char checkwho1 ;
                cin>>checkwho1;
                switch(checkwho1)
                {
                    case 'T':
                        for( Teacher*p=pThead->next;p!=pTrear->next;p=p->next)
                        {cout<<p->name<<endl;}
                        break;
                    case'S':
                        for( Student*p=pShead;p!=pSrear->next;p=p->next)
                        {cout<<p->name<<endl;}
                        break;
                    case'A':
                        for( Assistant*p=pAhead;p!=pArear->next;p=p->next)
                        {cout<<p->name<<endl;}
                        break;



                }
                break;}

            case 4://查找名下课程
            { cout<<"Please enter the person you want to search for"<<endl;//T,S,A
                char checkwho2 ;
                string tem;
                cin>>checkwho2;
                cout<<"Please enter the name of the person you are looking for"<<endl;int flag=0;
                cin>>tem;
                //单独一行输入
                switch(checkwho2)
                {
                    case 'T':
                        flag=0;
                        for(Teacher*p=pThead->next;p!=pTrear->next;p=p->next)
                        {if (tem== p->name){p->viewCourses();flag=1;break; }}
                        if(flag==0){cout<<"The person you are looking for does not exist"<<endl;}
                        break;
                    case'S':
                        flag=0;
                        for( Student*p=pShead->next;p!=pSrear->next;p=p->next)
                        {if (tem== p->name){p->viewCourses();flag=1;break;} }
                        if(flag==0){cout<<"The person you are looking for does not exist"<<endl;}
                        break;
                    case'A':
                        flag=0;
                        for( Assistant*p=pAhead->next;p!=pArear->next;p=p->next)
                        {if (tem== p->name){p->viewCourses();flag=1;break;} }
                        if(flag==0){cout<<"The person you are looking for does not exist"<<endl;}
                        break;



                }
                break;}
            //解散课程
            case 5:
            {  cout<<"Dissolve which teacher's course?"<<endl;
               string checkname;
               cin>>checkname;
                int flag=0;
                for (Teacher *p = pThead->next; p != pTrear->next; p=p->next) {

                    if (checkname== p->name) {
                        cout<<"please enter the name of course"<<endl;
                        string name;
                        cin >> name;
                        p->deleteCourse(name);


                        flag = 1;
                        break;
                    }
                }
                if(flag==0){cout<<"The person you are looking for does not exist"<<endl;}
                break;}

            case 6:

            {  cout<<"Which student should I invite to join/exit the course?"<<endl;
                string checkname;
                int flag=0;
                for (Student *p = pShead->next; p != pSrear->next; p=p->next) {

                    if (checkname== p->name) {
                        p->Scourse();//提示输入退出还是加入？与学生加入课程保持一致
                        flag = 1;
                        break;
                    }
                }
                if(flag==0){cout<<"The person you are looking for does not exist"<<endl;}
                break;}








        }



    }



}
*/