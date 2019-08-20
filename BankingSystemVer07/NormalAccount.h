#ifndef __NORMAL_ACCOUNT_H_
#define __NORMAL_ACCOUNT_H_

#include "Account.h"
/* 보통예금계좌: 최소한의 이자를 지급하는 자율 입출금식 계좌 */
class NormalAccount : public Account {
    private:
        int interRate;  // 이자율 %단위
    public:
        NormalAccount(int ID, int money, char * name, int rate)
            : Account(ID, money, name), interRate(rate) {}
        virtual void Deposit(int money){
            Account::Deposit(money);    // 원금추가
            Account::Deposit(money*(interRate/100.0));  // 이자추가
        }
};
#endif