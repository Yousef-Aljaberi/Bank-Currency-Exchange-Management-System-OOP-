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
			cout << "\nPlease enter username: ";
			UserName = clsInputValidate::ReadString();

			cout << "\nPlease enter passowrd: ";
			Password = clsInputValidate::ReadString();

			clsUser User = clsUser::Find(UserName, Password);

			LoginFail = User.IsEmpty();

		} while (LoginFail);

		clsMainScreen::ShowMainMenue();

	}


public:
	static void ShowLoginScreen()
	{
		_DrawScreenHeader("\t Login Screen");

		_Login();
	}
};

