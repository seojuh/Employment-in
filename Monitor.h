#ifndef MONITOR_H
#define MONITOR_H

#include <sqlite3.h>
#include <string>

using namespace std;

class monitor
{
private:
    sqlite3* db;
public:
    monitor();
    ~monitor();
    void Start();
    void Display();
    void Search1();
    void Search2();
    void Search3();
    void Search4();
    void Search5();
    void announcement(const string & company_name);
    void Company_information(const string&company_name);
    void recommend();
    void final();
    void menu();
};

#endif