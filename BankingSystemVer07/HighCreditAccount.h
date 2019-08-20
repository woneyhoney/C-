#ifndef __HIGHCREDIT_ACCOUNT_H_
#define __HIGHCREDIT_ACCOUNT_H_

#include "NormalAccount.h"
/* �ſ�ŷڰ���: �ſ뵵�� ���� �����Ը� ������ ����ϴ� ���� ������ ���� */
class HighCreditAccount : public NormalAccount {
    private:
        int specialRate;
    public:
        HighCreditAccount(int ID, int money, char * name, int rate, int special)
            : NormalAccount(ID, money, name, rate), specialRate(special) {}
        virtual void Deposit(int money){
            NormalAccount::Deposit(money);  // ���ݰ� �����߰�
            Account::Deposit(money*(specialRate/100.0));    // Ư�������߰�
        }
};
#endif