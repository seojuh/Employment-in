#include "User.h"
#include <iostream>

using namespace std;

User::User(const string& dbName) : DB_Name(dbName)
{
    if(sqlite3_open(DB_Name.c_str(),&db))
        cout<<"데이터베이스를 열 수 없습니다: "<<sqlite3_errmsg(db)<<endl;
    //데이터베이스와 연결되면 나오는 문구
    // else
    //     cout<<"데이터베이스에 성공적으로 연결되었습니다"<<endl;
}

User::~User()
{
    sqlite3_close(db);
}


//회원가입 매서드
void User::User_join()
{
    int num;
    string join_id;
    string join_pw;
    string join_hp;
    string join_email;
    system("clear");
    

    cout << " " << "┌────────────────────────────────────────────────────┐" << endl;
    cout << " " << "│              회원가입을 진행하겠습니까?            │"<<endl;
    cout << " " << "├────────────────────────────────────────────────────┤" << endl;
    cout << " " << "│                   1.예 / 2.아니오                  │"<<endl;
    cout << " " << "└────────────────────────────────────────────────────┘" << endl;
    cin >> num;
    sleep(1);
    system("clear");

    if(num!=1)
        return;
    while(true)
    {
        cout << " " << "┌────────────────────────────────────────────────────┐" << endl;
        cout << " " << "│                  ID를 설정해주세요                 │" << endl;
        cout << " " << "└────────────────────────────────────────────────────┘" << endl;
        cin>>join_id;
        if(User_overlap_id(join_id))
        {
            cout<<"이미 존재하는 아이디 입니다 다른 아이디를 입력해주세요!"<<endl;
        }
        else
            break;
    }
        while(true)
        {
            cout << " " << "┌────────────────────────────────────────────────────┐" << endl;
            cout << " " << "│            패스워드를 4자리 설정해주세요           │" << endl;
            cout << " " << "└────────────────────────────────────────────────────┘" << endl;
            cin>>join_pw;
            sleep(1);
            system("clear");

            //핀번호 4자리를 확인, isdigit 숫자로만 확인하는 함수
            if(join_pw.length()==4 && all_of(join_pw.begin(), join_pw.end(), ::isdigit))
            {
                break;
            }
            else
            {
                cout << " " << "┌──────────────────────────────────────────────────────┐" << endl;
                cout << " " << "│패스워드를 제대로 4자리 입력해주세요 숫자만 가능합니다│" << endl;
                cout << " " << "└──────────────────────────────────────────────────────┘" << endl;
            }
        }
        while(true)
        {
                cout << " " << "┌────────────────────────────────────────────────────┐" << endl;
                cout << " " << "│            핸드폰 번호를 입력해주세요              │" << endl;
                cout << " " << "└────────────────────────────────────────────────────┘" << endl;
            cin>>join_hp;
            sleep(1);
            system("clear");
            if(User_overlap_hp(join_hp))
            {
                cout<<"이미 존재하는 휴대폰 번호 입니다. 다른 휴대폰 번호를 입력해주세요!"<<endl;
            }
            else 
                break;
        }
        while(true)
        {
            cout << " " << "┌────────────────────────────────────────────────────┐" << endl;
            cout << " " << "│            이메일을 입력해주세요                   │" << endl;
            cout << " " << "└────────────────────────────────────────────────────┘" << endl;
            cin>>join_email;
            sleep(1);
            system("clear");

            if(User_overlap_email(join_email))
            {
                cout<<"이미 존재하는 이메일 입니다. 다른 이메일을 입력해주세요!"<<endl;
            }
            else
                break;
        }
    int unique_number = UniqueNumber();
    Save_User_DB(join_id, join_pw, join_hp, join_email, unique_number);    
};

//중복검사 아이디 매서드
bool User::User_overlap_id(const string& join_id) 
{
    //stmt 포인터 선언
    sqlite3_stmt* stmt;
    //sql에 변수로 할당
    const char* sql = "SELECT * FROM User WHERE user_id=?";

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) 
    {
        cout << "SQL 에러: " << sqlite3_errmsg(db) << endl;
        return false;
    }
    sqlite3_bind_text(stmt, 1, join_id.c_str(), -1, SQLITE_TRANSIENT);

    bool user_overlap = false;
    if(sqlite3_step(stmt) == SQLITE_ROW)
    {
        user_overlap= true;
    }
    sqlite3_finalize(stmt);
    return user_overlap;
}

//중복검사 휴대폰 번호 매서드
bool User::User_overlap_hp(const string&join_hp)
{
    //stmt 포인터 선언    
    sqlite3_stmt*stmt;
    //sql에 변수로 할당
    const char* sql = "SELECT * FROM user WHERE user_hp=?";
    if(sqlite3_prepare_v2(db,sql,-1,&stmt, NULL)!=SQLITE_OK)
    {
        cout<<"SQL 에러: "<<sqlite3_errmsg(db)<<endl;
        return false;
    }
    sqlite3_bind_text(stmt, 1, join_hp.c_str(), -1, SQLITE_TRANSIENT);

    bool user_overlap = false;
    if(sqlite3_step(stmt) == SQLITE_ROW)
    {
        user_overlap = true;
    }
    sqlite3_finalize(stmt);
    return user_overlap;
}

//중복검사 이메일 매서드
bool User::User_overlap_email(const string& join_email) 
{
    //stmt 포인터 선언 
    sqlite3_stmt*stmt;
    //sql에 변수로 할당
    const char*sql = "SELECT * FROM user WHERE user_email=?";

    if(sqlite3_prepare_v2(db, sql, -1, &stmt, NULL)!=SQLITE_OK)
    {
        cout<<"SQL 에러: "<<sqlite3_errmsg(db)<<endl;
        return false;
    }
    sqlite3_bind_text(stmt, 1, join_email.c_str(), -1, SQLITE_TRANSIENT);
    
    bool user_overlap=false;
    if(sqlite3_step(stmt)==SQLITE_ROW)
    {
        user_overlap =true;
    }
    sqlite3_finalize(stmt);
    return user_overlap;
}

//ID, PW, HP, EMAIL DB에 저장 매서드
void User::Save_User_DB(const string& join_id, const string& join_pw, const string& join_hp, const string&join_email, int user_unique_num)
{
    string sql = "INSERT INTO User (user_id, user_pw, user_hp, user_email, user_unique_num) VALUES(?, ?, ?, ?, ?);";
    sqlite3_stmt*stmt;
    srand((unsigned)time(NULL));

    if(sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL)!= SQLITE_OK)
    {
        cout<<"데이터를 저장하지 못했습니다."<<sqlite3_errmsg(db)<<endl;
        return;
    }

    //id, pw, hp, email,고유번호 바인딩
    sqlite3_bind_text(stmt, 1, join_id.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, join_pw.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, join_hp.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, join_email.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 5, user_unique_num);
    
    if(sqlite3_step(stmt) != SQLITE_DONE)
    {
        cout<<"데이터를 데이터베이스에 저장하지 못했습니다."<<sqlite3_errmsg(db)<<endl;
    }
    else
    {
        cout << " " << "┌─────────────────────────────────────────────────────┐" << endl;
        cout << " " << "│회원가입이 완료되셨습니다. 이제 로그인이 가능하십니다│" << endl;
        cout << " " << "└─────────────────────────────────────────────────────┘" << endl;
        cout << " " << "┌─────────────────────────────────────────────────────┐" << endl;
        cout << " " << "     "<<join_id<<" 회원님의 고유 번호는 "<< user_unique_num << " 입니다."<<endl;
        cout << " " << "└─────────────────────────────────────────────────────┘" << endl;       
    }
    sleep(1);
    system("clear");  
    //메모리 SQL문장 제거 
    sqlite3_finalize(stmt);
};

//고유번호 생성 매서드
int User::UniqueNumber()
{
    int unique_number;
    do
    {
        unique_number = rand()%10000+1;
    }
    while(User_overlap_unique(unique_number));//고유번호 중복 확인
    return unique_number;
}

//고유번호 중복검사 매서드
bool User::User_overlap_unique(int unique_number)
{
    //stmt 포인터 선언
    sqlite3_stmt*stmt;
    //sql에 변수로 할당
    const char * sql = "SELECT * FROM user WHERE user_unique_num=?";
    if(sqlite3_prepare_v2(db, sql, -1, &stmt, NULL)!= SQLITE_OK)
    {
        cout<<"SQL 에러: "<< sqlite3_errmsg(db)<<endl;
        return true;
    }
    sqlite3_bind_int(stmt, 1, unique_number);

    bool overlap = false;
    if(sqlite3_step(stmt) == SQLITE_ROW)
    {
        overlap=true;
    }
    sqlite3_finalize(stmt);
    return overlap;
}

//로그인 매서드
bool User::User_login()
{
    string input_id;
    string input_pw;
    bool Login = false;
    
    while(!Login)
    {
        sleep(1.5);
        system("clear");
        cout << " " << "┌────────────────────────────────────────────────────┐" << endl;
        cout << " " << "│                로그인 진행중입니다.                │" << endl;
        cout << " " << "└────────────────────────────────────────────────────┘" << endl;
        cout<<"아이디를 입력해주세요: ";
        getline(cin,input_id);
        cout<<"비밀번호 4자리를 입력해주세요: ";
        getline(cin,input_pw);

        sqlite3_stmt*stmt;
        const char*sql ="SELECT * FROM user WHERE user_id =? AND user_pw=?";

        if(sqlite3_prepare_v2(db,sql,-1, &stmt, NULL)!=SQLITE_OK)
        {
            cout<<"SQL 에러: "<< sqlite3_errmsg(db)<<endl;
            return false;
        }

        sqlite3_bind_text(stmt, 1, input_id.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 2, input_pw.c_str(), -1, SQLITE_TRANSIENT);

        if(sqlite3_step(stmt) == SQLITE_ROW)
        {
            sleep(1);
            system("clear");
            cout << " " << "┌────────────────────────────────────────────────────┐" << endl;
            cout << " " << "│                로그인 되셨습니다.                  │" << endl;
            cout << " " << "└────────────────────────────────────────────────────┘" << endl;
            sqlite3_finalize(stmt);
            sleep(1);
            system("clear");
            return true;
        }
        else
        {
            cout<<"아이디 또는 비밀번호가 잘못되셨습니다. 다시 로그인 해주시길 부탁드립니다." <<endl;
            sqlite3_finalize(stmt);
            sleep(1);
            system("clear");
            return false;            
        }
    }
    return Login;
}