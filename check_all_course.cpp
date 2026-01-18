//
// Created by Lenovo on 2023/11/30.


#include "check_all_course.h"
#include"login.h"
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
extern int identity;
void checkcourse()
{
  for( Teacher*p=pThead->next;pThead!=pTrear->next;p=p->next)
  {p->viewCourses();
  }

}