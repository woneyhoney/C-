#ifndef __ACCOUNT_HANDLER_H_
#define __ACCOUNT_HANDLER_H_

#include "Account.h"
/* Control class */
class AccountHandler{
    private:
        Account * accArr[100];  // Account ������ ���� �迭
        int accNum=0;   // ����� Account ��
    public:
        AccountHandler();
        void ShowMenu(void);    
        void MakeAccount(void); 
        void DepositMoney(void);    
        void WithdrawMoney(void);   
        void ShowAllAccInfo(void);  
        ~AccountHandler();
    protected:
        void MakeNormalAccount(void);
        void MakeCreditAccount(void);
};
#endif