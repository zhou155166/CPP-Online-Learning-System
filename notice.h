//
// Created by Y9000P on 2023/12/7.
//

#ifndef DADADAZUOYE_NOTICE_H
#define DADADAZUOYE_NOTICE_H
#include<string>
using namespace std;
struct note{
    string note_notice;
    int length;
    note *next;
};

struct communicatebox{
    string message;
    communicatebox *next;
};
//struct commenttoT{
//    string comment;
//    commenttoT *next;
////    int grade;
//   string nameofstu;
//
//};
#endif //DADADAZUOYE_NOTICE_H
