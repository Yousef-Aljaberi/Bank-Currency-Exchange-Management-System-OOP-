#pragma once
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"
#include"clsMainScreen.h"
#include"Global.h"
#include<iostream>
class clsLoginScreen:protected clsScreen
{
private:
	static bool _Login()
	{
		bool LoginFail = false;
		string UserName, Password;

		short FaildLoginCount = 0;
		short NumberOfTrayLogin = 3;
		bool LockAccount = false;

		do
		{
			if (LoginFail)
			{
				 FaildLoginCount++;

				cout << "\nInvalid UserName/Password! \n";
				cout << "You Have " << NumberOfTrayLogin - FaildLoginCount << " Trail(s) to login.\n\n";
			}

			if (FaildLoginCount == NumberOfTrayLogin)
			{
				cout << "Your Locked after " << FaildLoginCount << " faild trails\n\n";
				return false;
			}
			
			cout << "\nPlease enter username: ";
			UserName = clsInputValidate::ReadString();

			cout << "\nPlease enter passowrd: ";
			Password = clsInputValidate::ReadString();

			 CurrentUser = clsUser::Find(UserName, Password);

			LoginFail = CurrentUser.IsEmpty();
			

		} while (LoginFail && (FaildLoginCount < NumberOfTrayLogin));
		
		CurrentUser.SaveLoginRegister();
		clsMainScreen::ShowMainMenue();
		return true;

	}


public:
	static bool  ShowLoginScreen()
	{
		system("cls");

		_DrawScreenHeader("\t Login Screen");

		return _Login();
	}
};

