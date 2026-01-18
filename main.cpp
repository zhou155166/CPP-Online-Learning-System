#include<iostream>
#include"login.h"
#include"autojump.h"
#include<cstring>
#include"check_all_course.h"
#include "Teacher.h"
#include "Assistant.h"
#include "worker.h"
#include "Student.h"

using namespace std;
note *nhead;
note*nrear;
note*np;
vector<Homework>homeworks;
 int homeworkid=0;
Teacher *pThead,*pTrear;

Student *pShead,*pSrear;

Assistant *pAhead,*pArear;

int identity=0;
Teacher *Twho;//记录登陆者所对应的类的地址
Student *Swho;
Assistant *Awho;

int main(){
    nhead=new note;
    nrear=nhead;

    pThead=pTrear=new Teacher;
    pShead=pSrear=new Student;
    pAhead=pArear=new Assistant;
    cout<<"Welcome to the teaching management system. Please enter 1 login account first"<<endl;
    int function=0;
string ch;
           //教务的2查看全部课程，3查看全部教师，查看所有学生，查看所有助教，4查看教师，老师，学生名下课程，5解散某课程，6将学生移入或移除课程
         do
           {
               cout<<" Please enter your choice"<<endl;

               if(identity==0){cout<<"You haven't logged in yet, please log in first"<<endl;}



               else{ jump();}
               cin>>ch;
              function=ch[0]-'0';

           switch(function)
           {
               case 1:{login();break;}

               case 2:
                   if(identity==1)
                   {Twho->Tcourse();break;}
                   if(identity==2)
                   {Swho->Scourse();break;}
                   if(identity==3)
                   {Awho->Acourse();break;}
                   if(identity==4)
                   {worker_seecourse();break;}
             case 3:
                   if(identity==1)
                   {Twho->notice();break;}
                   if(identity==2)
                   {Swho->notice();break;}
                   if(identity==3)
                   {Awho->notice();break;}
                   if(identity==4)
                   {worker_checkwho();break;}

               case 4:
                   if(identity==1)
                   {Twho->homework();break;}
                   if(identity==2)
                   {Swho->homework();break;}
                   if(identity==4)
                   {check_whocourse();break;}
              case 5:
                   if(identity==1)
                   {cout<<"This is an incorrect input method, please read the user manual carefully"<<endl;break;}
                   if(identity==2)
                   {cout<<"This is an incorrect input method, please read the user manual carefully"<<endl;break;}
                  if(identity==3)
                   {cout<<"This is an incorrect input method, please read the user manual carefully"<<endl;break;}
                   if(identity==4)
                   {dissolve_teachercourese();break;}

               case 6:
               {if(identity==1)
                   {Twho->viewevaluation();break;}
                   if(identity==2)
                   {
                       Swho->gradeT();break;}
                   }
                   if(identity==4)
                   {enterexit();break;}
               case 7:
                   if(identity==1)
                   {Twho->communicate();break;}
                   if(identity==2)
                   {Swho->communicate();break;}
                   if(identity==3)
                   {Awho->communicate();break;}
                   if(identity==4)
                   {cout<<"This is an incorrect input method, please read the user manual carefully"<<endl;break;}
               case 8:
                   if(identity==1)
                   {Twho->score_analyse();break;}
                  if(identity==2)
                   {Swho->score_analyse();break;}
                   if(identity==3)
                   {Awho->score_analyse();break;}
                   if(identity==4)
                   {cout<<"This is an incorrect input method, please read the user manual carefully"<<endl;break;}

               default:
               {cout<<"This is an incorrect input method, please read the user manual carefully"<<endl;}

           }}while(identity!=-1);

        return 0;
         }