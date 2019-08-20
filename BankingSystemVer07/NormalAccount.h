#ifndef __NORMAL_ACCOUNT_H_
#define __NORMAL_ACCOUNT_H_

#include "Account.h"
/* ���뿹�ݰ���: �ּ����� ���ڸ� �����ϴ� ���� ����ݽ� ���� */
class NormalAccount : public Account {
    private:
        int interRate;  // ������ %����
    public:
        NormalAccount(int ID, int money, char * name, int rate)
            : Account(ID, money, name), interRate(rate) {}
        virtual void Deposit(int money){
            Account::Deposit(money);    // �����߰�
            Account::Deposit(money*(interRate/100.0));  // �����߰�
        }
};
#endif