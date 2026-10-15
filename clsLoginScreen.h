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
	static void _Login()
	{
		bool LoginFail = false;
		string UserName, Password;


		do
		{
			if (LoginFail)
			{
				cout << "\nInvalid UserName/Password! \n\n";
			}
			cout << "\nPlease enter username: ";
			UserName = clsInputValidate::ReadString();

			cout << "\nPlease enter passowrd: ";
			Password = clsInputValidate::ReadString();

			 CurrentUser = clsUser::Find(UserName, Password);

			LoginFail = CurrentUser.IsEmpty();

		} while (LoginFail);

		clsMainScreen::ShowMainMenue();

	}


public:
	static void ShowLoginScreen()
	{
		system("cls");

		_DrawScreenHeader("\t Login Screen");

		_Login();
	}
};

