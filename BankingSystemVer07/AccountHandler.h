#ifndef __ACCOUNT_HANDLER_H_
#define __ACCOUNT_HANDLER_H_

#include "Account.h"
/* Control class */
class AccountHandler{
    private:
        Account * accArr[100];  // Account 저장을 위한 배열
        int accNum=0;   // 저장된 Account 수
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