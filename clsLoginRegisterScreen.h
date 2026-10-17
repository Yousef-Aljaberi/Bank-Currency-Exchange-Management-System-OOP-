#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsUtil.h"
#include<iomanip>

class clsRegisterScreen:protected clsScreen
{
private:

    static void _PrintRegisterRecordLine(clsUser::stLoginRegisterRecord Register)
    {

        cout << setw(8) << left << "" << "| " << setw(35) << left << Register.Date;
        cout << "| " << setw(20) << left << Register.UserName;
        cout << "| " << setw(20) << left << Register.Password;
        cout << "| " << setw(10) << left << Register.Permissions;

    }


public:

    static void ShowLoginRegisterScreen()
    {
        vector<clsUser::stLoginRegisterRecord> vLoginRegister;

        vLoginRegister = clsUser::GetLoginRegisterList();
        string Title = "Login Register List Screen";
        string SubTitle = "(" + to_string(vLoginRegister.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if(vLoginRegister.size()==0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else
        {
            for (clsUser::stLoginRegisterRecord L : vLoginRegister)
            {
                _PrintRegisterRecordLine(L);
                cout << endl;
            }
        }
    }
};

