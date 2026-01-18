//
// Created by 薛子玥 on 2023/12/5.
//

#ifndef XIANGMU_USER_H
#define XIANGMU_USER_H

#include <string>
using namespace std;

class User {
public:
    User(const string& username, int identity);

    User();

    virtual ~User();




    string name;
    int role;
};

#endif //XIANGMU_USER_H
