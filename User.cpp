#include "User.h"

using namespace std;

User::User(const string& username, int role) : name(username), role(role) {}
User::User() {}
User::~User() {}