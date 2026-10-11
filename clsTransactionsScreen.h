#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsMainScreen.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalancesScreen.h"
class clsTransactionsScreen:protected clsScreen
{
private:
    enum enTransactionsMenuOption { eDeposit = 1, eWithdraw = 2, eShowTotalBalance = 3, eMainMenu = 4 };

    static short _ReadTransactionMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 4]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 4, "Enter Number between 1 to 4? ");
        return Choice;
    }

    static void _GoBackToMainMenu()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

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

   static void _PerformTransacionsMenuOptions(enTransactionsMenuOption Option)
    {
        switch (Option)
        {
        case enTransactionsMenuOption::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToMainMenu();
            break;
        }

        case enTransactionsMenuOption::eWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToMainMenu();
            break;
        }
        
        case enTransactionsMenuOption::eShowTotalBalance:
        {
            system("cls");
            _ShowTotalBalanceScreen();
            _GoBackToMainMenu();
        }
        case enTransactionsMenuOption::eMainMenu:
        {
            system("cls");
        }

        }
    }
public:
	static void ShowTransactionsMenu()
	{
        system("cls");
		_DrawScreenHeader("\t Transactions  Screen");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balance.\n";
        cout << setw(37) << left << "" << "\t[4] Mian Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransacionsMenuOptions((enTransactionsMenuOption)_ReadTransactionMenuOption());
	}
};

