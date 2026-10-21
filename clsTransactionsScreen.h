#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsMainScreen.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalancesScreen.h"
#include"clsTransferScreen.h"
#include "clsTransferLogScreen.h"

class clsTransactionsScreen:protected clsScreen
{
private:
    enum enTransactionsMenuOption { eDeposit = 1, eWithdraw = 2, 
        eShowTotalBalance = 3, eTransfer=4, eTransferLog = 5, eShowMainMenue = 6};

    static short _ReadTransactionMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static void _GoBackToTransactionsMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Transactions Menue...\n";

        system("pause>0");
        ShowTransactionsMenu();
    }

    static void _ShowDepositScreen()
    {
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
        clsWithdrawScreen::ShowWithdrawScreen();
    }
    
    static void _ShowTotalBalanceScreen()
    {
        clsTotalBalancesScreen::ShowTotalBalances();
    }

    static void _ShowTransferScreen()
    {
        clsTransferScreen::ShowTransferScreen();
    }

    static void _ShowTransferLogScreen()
    {
        clsTransferLogScreen::ShowTransferLogScreen();
    }


   static void _PerformTransacionsMenuOptions(enTransactionsMenuOption Option)
    {
        switch (Option)
        {
        case enTransactionsMenuOption::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenuOption::eWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        
        case enTransactionsMenuOption::eShowTotalBalance:
        {
            system("cls");
            _ShowTotalBalanceScreen();
            _GoBackToTransactionsMenue();
        } 
        
        case enTransactionsMenuOption::eTransfer:
        {
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionsMenue();
        }
        case enTransactionsMenuOption::eTransferLog: {
            system("cls");
            _ShowTransferLogScreen();
            _GoBackToTransactionsMenue;
            break;
        }

        case enTransactionsMenuOption::eShowMainMenue: {
            system("cls");

            break;
        }
        }
    }
public:
	static void ShowTransactionsMenu()
	{
        system("cls");

        if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
        {
            return;  //this will exit from function
        }

		_DrawScreenHeader("\t Transactions  Screen");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balance.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransacionsMenuOptions((enTransactionsMenuOption)_ReadTransactionMenuOption());
	}
};

