#include "User.h"
#include "Monitor.h"
#include <iostream>

int main()
{
    string dbName = "project_database.db"; //DB파일 
    User user(dbName); //User 클래스 인스턴스 생성 
    monitor monitor;
    string search;
    string company_name;
    int num;
    int search_num=0;
    int act_num;
    int com_num;
    bool loginsuccess = false;
    while(true)
    {
        if(!loginsuccess)
        {
            monitor.Start();
            int choice;
            cout<<"선택: ";
            cin>>choice;
            cin.ignore();
            switch(choice)
            {
                case 1:
                    loginsuccess = user.User_login();
                    break;
                case 2:
                    user.User_join();
                    break;
                case 3:
                    monitor.final();
                    cout<<"프로그램을 종료합니다. 이용 감사합니다."<<endl;
                    return 0;
                default:
                    cout<<"잘못된 선택입니다."<<endl;
                    break;
            }
        }
        else if(loginsuccess)
        {
           if(search_num == 0)
            { 
                monitor.Display();
            }                
            monitor.menu();
            cin>>num;
            cout<<endl;
            cin.ignore();
            switch(num)
            {
                case 1:
                    monitor.Search1();
                    search_num++;
                    break;
                case 2:
                    monitor.Search2();
                    search_num++;
                    break;
                case 3:
                    monitor.Search3();
                    search_num++;                        
                    break;
                case 4:
                    monitor.Search4();
                    search_num++;
                    break;
                case 5:
                    monitor.Search5();
                    search_num++;
                    break;
                default:
                    cout<<"제대로 된 키워드의 번호를 입력해주세요!"<<endl;
                    break; 
            }
            cout<<"Enter를 누르시면 다음 안내로 넘어가겠습니다."<<endl;
            cin.get();
            sleep(1);
            system("clear");

            cout << " " << "┌────────────────────────────────────────────────────┐" << endl;
            cout << " " << "│             회원님께서 검색한 횟수: "<<search_num<<"              │" << endl;
            cout << " " << "└────────────────────────────────────────────────────┘" << endl;
            cout << "==========================================================================="<<endl;
            cout<<"1. 추가 검색"<<endl;
            cout<<"2. 공고 내용 확인"<<endl;
            cout<<"3. 로그아웃"<<endl;
            cout<<"4. 종료"<<endl;
            cout << "==========================================================================="<<endl;  
            cout<<"회원님께서 원하시는 행동을 번호로 입력해주세요: ";          
            cin>>act_num;
            cin.ignore();
            sleep(1);
            system("clear");
            switch(act_num)
            {
                case 1:
                    break;
                case 2:
                    cout<<"회사의 이름을 입력하시면 공고 내용이 검색됩니다."<<endl;
                    cout<<"원하시는 회사의 이름을 입력해주세요:";
                    cin>>company_name;
                    cout<<endl;
                    monitor.announcement(company_name);
                    cout<<endl;

                    cout << " " << "┌────────────────────────────────────────────────────┐" << endl;
                    cout << " " << "│             1.기업 정보 보기                       │" << endl;
                    cout << " " << "│             2.키워드 검색화면 전환                 │" << endl;
                    cout << " " << "│             3.종료                                 │" << endl;
                    cout << " " << "└────────────────────────────────────────────────────┘" << endl;
                    cout<<"회원님께서 원하시는 행동을 번호로 입력해주세요: ";
                    cin>>com_num;
                    cout<<endl;
                    if(com_num == 1)
                    {
                        monitor.Company_information(company_name);
                        cout<<endl;
                        cout<<"이용 감사합니다. 잠시후에 키워드 검색 화면으로 돌아가겠습니다."<<endl;
                        sleep(5);
                        system("clear");
                        break;
                    }
                    else if(com_num == 2)
                    {
                        system("clear");
                        break;
                    }
                    else if(com_num ==3)
                    {
                        monitor.final(); 
                        cout<<"프로그램을 종료하겠습니다. 이용 감사합니다."<<endl;
                        return 0;
                    }
                case 3: 
                    loginsuccess =false;
                    search_num = 0;
                    break;
                case 4:
                    monitor.final(); 
                    cout<<"프로그램을 종료하겠습니다. 이용 감사합니다."<<endl;
                    return 0;
                default:
                    cout<<"잘못된 선택입니다."<<endl;
                    break;
            }
        }
    }
    return 0;
}