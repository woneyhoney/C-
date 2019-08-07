/* Baning System Ver 0.1 */
#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN=20;

void ShowMenu(void);    // 메뉴출력
void MakeAccount(void); // 계좌개설
void DepositMoney(void);    // 입금
void WithdrawMoney(void);   // 출금
void ShowAllAccInfo(void);  // 잔액조회

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

typedef struct{
    int accID;  //계좌번호
    int balance;    // 잔액
    char cusName[NAME_LEN]; // 고객이름
} Account;

Account accArr[100];    // Account 저장을 위한 배열
int accNum=0;   // 저장된 Account 수

int main(void){
    int choice;

    while(1){
        ShowMenu();
        cout<<"Option: ";
        cin>>choice;
        cout<<endl;

        switch(choice){
            case MAKE:
                MakeAccount();
                break;
            case DEPOSIT:
                DepositMoney();
                break;
            case WITHDRAW:
                WithdrawMoney();
                break;
            case INQUIRE:
                ShowAllAccInfo();
                break;
            case EXIT:
                return 0;
            default:
                cout<<"Illegal selection.."<<endl;
        }
    }
    return 0;
}

void ShowMenu(void){
    cout<<"-----Menu------"<<endl;
    cout<<"1.   Make Account"<<endl;
    cout<<"2.   Deposit"<<endl;
    cout<<"3.   Withdraw"<<endl;
    cout<<"4.   All Accounts Info"<<endl;
    cout<<"5.   Terminate"<<endl;
}

void MakeAccount(void){
    int id;
    char name[NAME_LEN];
    int balance;

    cout<<"[Make Account]"<<endl;
    cout<<"Account ID: "; cin>>id;
    cout<<"Name: "; cin>>name;
    cout<<"Deposit Money: "; cin>>balance;
    cout<<endl;

    accArr[accNum].accID=id;
    accArr[accNum].balance=balance;
    strcpy(accArr[accNum].cusName, name);
    accNum++;
}

void DepositMoney(void){
    int money;
    int id;
    cout<<"[Deposit]"<<endl;
    cout<<"Account ID: "; cin>>id;
    cout<<"Deposit Money: "; cin>>money;

    for(int i=0; i<accNum; i++){
        if(accArr[i].accID==id){
            accArr[i].balance+=money;
            cout<<"Deposit Done"<<endl;
            return;
        }
    }

    cout<<"Invalid Account ID"<<endl<<endl;
}

void WithdrawMoney(void){
    int money;
    int id;
    cout<<"[Withdraw]"<<endl;
    cout<<"Account ID: "; cin>>id;
    cout<<"Withdraw Money: "; cin>>money;

    for(int i=0; i<accNum; i++){
        if(accArr[i].accID==id){
            if(accArr[i].balance<money){
                cout<<"Insufficient funds"<<endl;
                return;
            }
            
            accArr[i].balance-=money;
            cout<<"Withdrawal Done"<<endl<<endl;
            return;
        }
    }

    cout<<"Invalid Account ID"<<endl<<endl;
}

void ShowAllAccInfo(void){
    for(int i=0; i<accNum; i++){
        cout<<"Account ID: "<<accArr[i].accID<<endl;
        cout<<"Name: "<<accArr[i].cusName<<endl;
        cout<<"Balance: "<<accArr[i].balance<<endl<<endl;
    }
}