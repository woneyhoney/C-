#ifndef __HIGHCREDIT_ACCOUNT_H_
#define __HIGHCREDIT_ACCOUNT_H_

#include "NormalAccount.h"
/* 신용신뢰계좌: 신용도가 높은 고객에게만 개설을 허용하는 높은 이율의 계좌 */
class HighCreditAccount : public NormalAccount {
    private:
        int specialRate;
    public:
        HighCreditAccount(int ID, int money, char * name, int rate, int special)
            : NormalAccount(ID, money, name, rate), specialRate(special) {}
        virtual void Deposit(int money){
            NormalAccount::Deposit(money);  // 원금과 이자추가
            Account::Deposit(money*(specialRate/100.0));    // 특별이자추가
        }
};
#endif