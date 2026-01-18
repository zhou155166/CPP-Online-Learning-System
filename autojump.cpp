#include "autojump.h"
#include<iostream>
#include "login.h"
#include "Teacher.h"
#include "Assistant.h"
#include "Student.h"
#include "notice.h"

extern Teacher *pThead,*pTrear;

extern Student *pShead,*pSrear;

extern Assistant *pAhead,*pArear;
extern Teacher *Twho;//记录登陆者所对应的类的地址
extern Student *Swho;
extern Assistant *Awho;
extern int identity;
extern note *nhead;
extern note*nrear;
extern note*np;
using namespace std;
void jump()
{
    switch(identity)
    {
        case 1:
        {while (Twho->cp!=Twho->crear&&Twho->crear!=Twho->chead){
                cout<<"Message:"<<Twho->cp->next->message<<endl;
                Twho->cp=Twho->cp->next;
            }
            break;}


        case 2:
        {
            while(Swho->snote!=nrear&&nrear!=nhead){
                cout<<Swho->snote->next->note_notice<<endl;
                Swho->snote= Swho->snote->next;
            }
            while (Swho->cp!=Swho->crear&&Swho->crear!=Swho->chead){
                cout<<Swho->cp->next->message<<endl;
                Swho->cp=Swho->cp->next;
            }
            // if(Swho->ishomework==0){Swho->homework();}
            break;}

        case 3:
        {while (Awho->cp!=Awho->crear&&Awho->crear!=Awho->chead){
                cout<<"Message:"<<Awho->cp->next->message<<endl;
                Awho->cp=Awho->cp->next;
            }
            break;}
        default: break;


    }}
