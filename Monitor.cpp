#include "Monitor.h"
#include <iostream>
#include <vector>
#include <unistd.h>

using namespace std;

monitor::monitor():db(nullptr)
{
    if(sqlite3_open("project_database.db",&db))
    {
    cout<<"데이터베이스를 열 수 없습니다."<<sqlite3_errmsg(db)<<endl;
    }
}

monitor::~monitor()
{
    if(db)
    sqlite3_close(db);
}

//시작화면
void monitor::Start()
{

    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⣿⣿⣿⠀⠀⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀ "<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣷⣴⣾⣿⣿⣿⣷⣦⣾⣿⣦⡀⠀⠀⠀⠀⠀⠀ "<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿⣿⡿⠿⠛⠿⢿⣿⣿⣿⡋⠀⠀⠀⠀⠀⠀⠀ "<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⣤⣿⣿⣿⠋⠀⠀⠀⠀⠀⠹⣿⣿⣷⣤⣤⠀⠀⠀⠀⠀ "<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⢿⣿⣿⣆⠀⠀⠀⠀⠀⣴⣿⣿⡿⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⣿⣿⣿⣿⣶⣶⣶⣿⣿⣿⣿⣷⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣿⠟⠛⠿⣿⣿⣿⠿⠛⠙⠿⠟⠀⢴⣦⣠⣤⡀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠿⠿⠿⠃⠀⠀⠀⠸⣿⡿⠛⠛⣿⣦⡆⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣄⠀⠀⠀⣠⣄⣀⠀⣾⣿⣇⠀⢀⣼⣿⡁⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿⣿⣤⣤⣴⣿⣿⣿⠇⠀⢸⣿⠿⣿⡟⠙⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣄⣀⣠⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⡀⣀⣀⠀⠉⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣄⣀⣿⣿⣄⣠⣄⠀⢀⣾⣿⣿⣿⣿⣿⡿⠛⠉⠉⠙⠻⣿⣿⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⢙⣿⣿⠟⠛⠻⣿⣯⣀⠈⠙⢻⣿⣿⣿⠏⠀⠀⠀⠀⠀⠀⠈⢿⣿⣿⣿⠟⠋⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⢰⣾⣿⡇⠀⠀⠀⢹⣿⣿⠇⠀⢸⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⣿⣷⣤⣠⣴⣿⣿⡄⢰⣾⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⢀⣾⣿⣿⣿⣿⣶⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⠛⠛⣿⡟⠉⠛⠁⠀⢻⣿⠿⣿⣿⣿⣷⣦⣤⣤⣤⣶⣿⣿⣿⡿⢿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠀⣶⣶⡆⠀⢀⡀⠀⠈⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣿⣶⣾⣿⣿⣿⣷⣿⣿⠆⠀⢾⣿⣿⡿⠛⠛⠛⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢨⣿⣿⠟⠉⠉⠉⠻⣿⣿⣆⣀⠀⠈⠙⠁⠀⠀⠀⠘⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⣿⠀⠀⠀⠀⠀⢹⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠙⣿⣿⣦⡀⠀⢀⣠⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⣾⣿⣿⣿⣿⣿⣿⠿⣿⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠋⠀⠉⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"=========================================================================="<<endl;
    cout<<"안녕하세요 취업in 프로그램 입니다. 원하시는 행동을 선택해주세요"<<endl;
    cout<<"1. 로그인"<<endl;
    cout<<"2. 회원가입"<<endl;
    cout<<"3. 종료"<<endl;
    cout<<"=========================================================================="<<endl;
}

//기업 추천 매서드
void monitor::recommend()
{
    const char*sql = "SELECT * FROM announcement ORDER BY RANDOM() LIMIT 5;";
    sqlite3_stmt*stmt;
    if(sqlite3_prepare_v2(db,sql, -1, &stmt, NULL)!=SQLITE_OK)
    {
        cout<<"오류 발생: "<<sqlite3_errmsg(db)<<endl;
        return;
    } 
    cout<<"추천 기업 목록"<<endl;
    while(sqlite3_step(stmt)==SQLITE_ROW)
    {
        cout<<"회사명: "<<sqlite3_column_text(stmt, 0)<<endl;
        cout<<"공고내용: "<<sqlite3_column_text(stmt, 4)<<endl;
        cout<<endl;     
    }
    sqlite3_finalize(stmt);
}

//추천 기업 화면 매서드
void monitor::Display()
{

    cout<<"⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⣰⣿⣿⣿⣿⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⢿⣿⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⣿⣿⣿⣿⡿⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠈⢻⡿⠿⠟⠋⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⣠⣤⣤⣤⣤⣄⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠙⠻⠿⢿⡟⠁⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠘⣧⢀⣠⣴⣶⣶⣤⣤⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣤⣤⣶⣶⣦⣄⡀⣾⠁⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⣹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⣿⣿⣿⣿⣿⡿⠟⠛⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠙⠛⠿⣿⣿⣿⣿⣿⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣿⣿⣿⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⡿⠁⠀⠀⣀⣤⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡄⠀⠀⠀⠹⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⡇⠀⠀⢰⣿⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣾⣋⣀⡀⠀⠀⠀⢿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⡀⠀⠀⠀⠻⣿⣿⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠉⠉⠁⠀⠀⠀⣸⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⣶⣶⣶⣶⣶⣶⣶⣶⡆⠀⠀⠀⠀⠀⠀⠀⢀⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿⣿⣿⣄⠀⠀⠀⠀⠀⠀⠀⠻⣿⣿⣿⣿⣿⣿⡿⠃⠀⠀⠀⠀⠀⠀⢀⣼⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⣿⣿⣧⣄⠀⠀⠀⠀⠀⠀⠈⠛⠻⠿⠛⠋⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⣿⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣿⣿⣿⣿⣿⣿⣶⣶⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣴⣶⣾⣿⣿⣿⣿⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠙⠻⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠛⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠉⠉⠉⠉⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"안녕하세요 전 동글이 입니다!!!"<<endl;
    sleep(1);
    cout<<"저는 당신에게 도움을 드릴수 있습니다!!!"<<endl;
    sleep(1);
    cout<<"기업을 보고싶은 당신! 제가 기업을 추천해드릴게요. 잠시만 기다려주세요"<<endl;
    sleep(2);
    cout<<endl;
    recommend();
    sleep(1);
    cout<<endl;
    cout<<"그럼 이제 Enter를 누르시면 검색화면으로 넘어 갈게요!"<<endl;
    cin.get();
    sleep(1.5);
    system("clear");
}

//학력 검색 결과 매서드
void monitor::Search1()
{
    string search;
    vector<string> columns ={"학력"};
    bool found = false;

    for(const string& column:columns)
    {
        //해당 컬럼 값 추가 쿼리문 
        string sql = "SELECT 회사명, "+ column + " FROM information";
        sqlite3_stmt* stmt;

        if(sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL) != SQLITE_OK)
        {
            cout<<"SQL 에러: "<< sqlite3_errmsg(db)<<endl;
            return;
        }

        string searchpattern = search;
        sqlite3_bind_text(stmt, 1, searchpattern.c_str(), -1, SQLITE_TRANSIENT);

        while(sqlite3_step(stmt) == SQLITE_ROW)
        {
            if(!found)
            {
                cout<<"검색 결과"<<endl;
                found = true;
            }
            cout<<"회사명: "<<sqlite3_column_text(stmt, 0)<< endl;
            cout<< column<< ": "<<sqlite3_column_text(stmt, 1)<<endl;
            cout<<endl;
        }
        sqlite3_finalize(stmt);
    }
    if(!found)
    {
        cout<< "검색 결과가 없습니다." << sqlite3_errmsg(db)<< endl;
    }
}
//경력 검색 결과 매서드
void monitor::Search2()
{
    string search;
    //해당 컬럼 값 추가 쿼리문 
    vector<string> columns ={"경력"};
    bool found = false;

    for(const string& column:columns)
    {
        string sql = "SELECT 회사명, "+ column + " FROM information";
        sqlite3_stmt* stmt;

        if(sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL) != SQLITE_OK)
        {
            cout<<"SQL 에러: "<< sqlite3_errmsg(db)<<endl;
            return;
        }

        string searchpattern = search;
        sqlite3_bind_text(stmt, 1, searchpattern.c_str(), -1, SQLITE_TRANSIENT);

        while(sqlite3_step(stmt) == SQLITE_ROW)
        {
            if(!found)
            {
                cout<<"검색 결과"<<endl;
                found = true;
            }
            cout<<"회사명: "<<sqlite3_column_text(stmt, 0)<< endl;
            cout<< column<< ": "<<sqlite3_column_text(stmt, 1)<<endl;
            cout<<endl;
        }
        sqlite3_finalize(stmt);
    }
    if(!found)
    {
        cout<< "검색 결과가 없습니다." << sqlite3_errmsg(db)<< endl;
    }
}
//지역 검색 결과 매서드
void monitor::Search3()
{
    string search;
    //해당 컬럼 값 추가 쿼리문
    vector<string> columns ={"지역"};
    bool found = false;

    for(const string& column:columns)
    {
        string sql = "SELECT 회사명, "+ column + " FROM information";
        sqlite3_stmt* stmt;

        if(sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL) != SQLITE_OK)
        {
            cout<<"SQL 에러: "<< sqlite3_errmsg(db)<<endl;
            return;
        }

        string searchpattern = search;
        sqlite3_bind_text(stmt, 1, searchpattern.c_str(), -1, SQLITE_TRANSIENT);

        while(sqlite3_step(stmt) == SQLITE_ROW)
        {
            if(!found)
            {
                cout<<"검색 결과"<<endl;
                found = true;
            }
            cout<<"회사명: "<<sqlite3_column_text(stmt, 0)<< endl;
            cout<< column<< ": "<<sqlite3_column_text(stmt, 1)<<endl;
            cout<<endl;
        }
        sqlite3_finalize(stmt);
    }
    if(!found)
    {
        cout<< "검색 결과가 없습니다." << sqlite3_errmsg(db)<< endl;
    }
}
//산업 검색 결과 매서드
void monitor::Search4()
{
    string search;
    //해당 컬럼 값 추가 쿼리문
    vector<string> columns ={"산업"};
    bool found = false;

    for(const string& column:columns)
    {
        string sql = "SELECT 회사명, "+ column + " FROM information";
        sqlite3_stmt* stmt;

        if(sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL) != SQLITE_OK)
        {
            cout<<"SQL 에러: "<< sqlite3_errmsg(db)<<endl;
            return;
        }

        string searchpattern = search;
        sqlite3_bind_text(stmt, 1, searchpattern.c_str(), -1, SQLITE_TRANSIENT);

        while(sqlite3_step(stmt) == SQLITE_ROW)
        {
            if(!found)
            {
                cout<<"검색 결과"<<endl;
                found = true;
            }
            cout<<"회사명: "<<sqlite3_column_text(stmt, 0)<< endl;
            cout<< column<< ": "<<sqlite3_column_text(stmt, 1)<<endl;
            cout<<endl;
        }
        sqlite3_finalize(stmt);
    }
    if(!found)
    {
        cout<< "검색 결과가 없습니다." << sqlite3_errmsg(db)<< endl;
    }
}
//매출액 검색 결과 매서드
void monitor::Search5()
{
    string search;
    //해당 컬럼 값 추가 쿼리문
    vector<string> columns ={"매출액"};
    bool found = false;

    for(const string& column:columns)
    {
        string sql = "SELECT 회사명, "+ column + " FROM information";
        sqlite3_stmt* stmt;

        if(sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL) != SQLITE_OK)
        {
            cout<<"SQL 에러: "<< sqlite3_errmsg(db)<<endl;
            return;
        }

        string searchpattern = search;
        sqlite3_bind_text(stmt, 1, searchpattern.c_str(), -1, SQLITE_TRANSIENT);

        while(sqlite3_step(stmt) == SQLITE_ROW)
        {
            if(!found)
            {
                cout<<"검색 결과"<<endl;
                found = true;
            }
            cout<<"회사명: "<<sqlite3_column_text(stmt, 0)<< endl;
            cout<< column<< ": "<<sqlite3_column_text(stmt, 1)<<endl;
            cout<<endl;
        }
        sqlite3_finalize(stmt);
    }
    if(!found)
    {
        cout<< "검색 결과가 없습니다." << sqlite3_errmsg(db)<< endl;
    }
}

//공고 상세 내용 매서드
void monitor::announcement(const string & company_name)
{
    cout<< company_name <<" 회사의 상세 공고 정보"<<endl;
    string sql = "SELECT * FROM announcement WHERE 회사명 = ?;";
    sqlite3_stmt*stmt;

    if(sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL)!= SQLITE_OK)
    {
        cout<<"SQL 에러:"<<sqlite3_errmsg(db)<<endl;
        return;
    }
    sqlite3_bind_text(stmt, 1, company_name.c_str(), -1, SQLITE_TRANSIENT);
    
    while(sqlite3_step(stmt) == SQLITE_ROW)
    {
        cout<<"================================================================="<<endl;
        cout<<"공고내용: "<<sqlite3_column_text(stmt, 4)<<endl;
        cout<<"회사소개: "<<sqlite3_column_text(stmt, 1)<<endl;
        cout<<"필요스킬: "<<sqlite3_column_text(stmt, 2)<<endl;
        cout<<"담당업무: "<<sqlite3_column_text(stmt, 3)<<endl;
        cout<<"================================================================="<<endl;
    }
    sqlite3_finalize(stmt);
}

//기업 정보 매서드
void monitor::Company_information(const string&company_name)
{
    cout<< company_name<<" 회사의 상세 기업 정보"<<endl;
    string sql = "SELECT * FROM information WHERE 회사명 = ?;";
    sqlite3_stmt * stmt;
    
    if(sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL) != SQLITE_OK)
    {
        cout<<"SQL 에러: "<< sqlite3_errmsg(db)<<endl;
        return;
    }
    sqlite3_bind_text(stmt, 1, company_name.c_str(), -1, SQLITE_TRANSIENT);
    while(sqlite3_step(stmt) == SQLITE_ROW)
    {
        cout<<"================================================================="<<endl;
        cout<<"경력: "<<sqlite3_column_text(stmt, 1)<<endl;
        cout<<"학력: "<<sqlite3_column_text(stmt, 2)<<endl;
        cout<<"고용형태: "<<sqlite3_column_text(stmt, 3)<<endl;
        cout<<"지역: "<<sqlite3_column_text(stmt, 4)<<endl;
        cout<<"사원수: "<<sqlite3_column_int(stmt, 5)<<endl;
        cout<<"산업: "<<sqlite3_column_text(stmt, 6)<<endl;
        cout<<"기업형태: "<<sqlite3_column_text(stmt, 7)<<endl;
        cout<<"설립년도: "<<sqlite3_column_int(stmt, 8)<<endl;
        cout<<"매출액: "<<sqlite3_column_text(stmt, 9)<<endl;
        cout<<"================================================================="<<endl;
    }
    sqlite3_finalize(stmt);
}
//종료 화면 매서드
void monitor::final()
{
    system("clear");
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⣶⣶⡄⣶⠀⠀⠀⠀⣤⠀⠀⣦⠀⠀⠀⢠⣤⣶⣤⢰⡆⠀⢠⡄⠀⠀⢰⡆⠀⢠⣤⣤⡄⣴⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠟⠁⣿⠛⠀⢀⣼⢿⣄⠀⣿⠶⠆⠀⠰⣏⣈⡿⢸⡟⠃⢸⡇⠀⠀⢸⡇⠀⢸⡇⠀⠀⣿⠦⠄⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣵⠶⠶⣿⠀⠀⠘⠁⠀⠙⠀⡿⠀⠀⠀⠀⢸⣯⣤⣼⡄⠀⠘⠛⠛⠛⠺⠇⠀⠘⠷⠶⠒⢿⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⠛⠓⠛⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⠛⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⣴⠶⠶⠶⠶⠶⠶⠶⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⣀⡴⠞⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠳⢦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⣠⡾⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢷⡀⠀⠀⠀⠀⠀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⣰⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⡄⣀⣴⠞⠛⠛⠙⠛⠛⠷⣦⣀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⢠⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠀⠀⠀⠀⠀⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠹⣧⡀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⢸⣧⡞⠀⠀⠀⠀⠀⠀⠀⠀⣶⠀⠀⠀⠀⠀⠀⠀⠀⠘⣷⠀⠀⠀⢸⡏⠀⠶⢶⣤⣤⣴⣦⠀⠀⠀⠀⢸⣧⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⢸⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡆⠀⠀⣾⠃⠀⠀⠨⣿⣿⠁⠀⠀⠀⠀⠀⠀⢻⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⢿⡄⠀⠀⠀⠀⠀⠀⠀⠀⣻⡀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠇⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠈⠳⣄⠀⠀⠀⠀⠀⢀⣴⠏⠳⣄⠀⠀⠀⠀⠀⠀⣠⠟⢀⣠⠞⢹⡆⠀⠀⠀⠀⠀⠀⣀⠀⢀⡀⠀⠀⣿⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠈⠛⠶⣶⣶⣖⡋⠁⠀⠀⠈⠙⠒⠶⢶⣒⣫⡥⢶⡟⠁⠀⢸⣷⣄⠘⠷⣤⣤⠾⠋⢀⡾⠁⠀⠀⣿⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠻⢿⣟⠛⠛⢛⣿⣉⣉⣥⠶⠋⠀⠀⠀⢸⡇⠙⠳⠦⠼⠷⠶⠞⠋⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⡟⠛⠋⠁⣬⠷⢤⡄⠀⠀⠀⢠⡟⢿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⡇⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡁⠀⠀⣰⠏⠀⢸⠀⠀⠀⣠⠟⠀⠸⣆⠀⠰⢶⠶⠶⠶⢶⠀⠀⢀⡿⠀⠀⠀⠀⠀⠀⠀"<<endl;
    cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠳⠶⠚⠁⠀⠀⠈⠳⠶⠞⠁⠀⠀⠀⠘⠳⠶⠋⠀⠀⠀⠈⠳⠶⠛⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
}

//검색 키워드 화면 매서드
void monitor::menu()
{
    cout<<"기업 검색 키워드"<<endl;
    cout<<"번호를 입력하시면 기업명과 해당 키워드의 내용을 안내해드립니다."<<endl;
    cout<<"=============================================================="<<endl;
    cout<<"1. 학력"<<endl;
    cout<<"2. 경력"<<endl;
    cout<<"3. 지역"<<endl;
    cout<<"4. 산업"<<endl;
    cout<<"5. 매출액"<<endl;
    cout<<"=============================================================="<<endl;            
    cout<<"검색하고 싶은 키워드를 번호를 입력해주세요: "; 
}