#ifndef USER_H
#define USER_H

#include <string>
#include <sqlite3.h>
#include <stdlib.h>
#include <cctype> //isdigit= 숫자(0~9)여야 1을 반환
#include <algorithm> //all_of=주어진 범위에서 조건을 만족하면 True 반환, 아니면 False
#include <unistd.h>

using namespace std;

class User
{
private:
    sqlite3*db;
    string DB_Name;
public:
    User(const string& dbName);
    ~User();

    void User_join();
    bool User_overlap_id(const string& join_id);
    bool User_overlap_email(const string&join_email);
    bool User_overlap_hp(const string&join_hp);
    bool User_login();
    void Save_User_DB(const string& join_id, const string& join_pw, const string& join_hp, const string&join_email, int user_unique_num);
    int UniqueNumber();
    bool User_overlap_unique(int unique_number);
};


#endif