#pragma once
#include"clsBankClient.h"
#include"clsScreen.h"
#include<iostream>
#include<iomanip>
#include"clsInputValidate.h"
class clsFindClientScreen:protected clsScreen
{
private:

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAccuntNumber : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}
public:

	static void ShowFindClientScreen()
	{
		_DrawScreenHeader("\t Find Client Screen");

		string AccountNumber = "";

		cout << "Please Enter Account Number:  ";
		AccountNumber = clsInputValidate::ReadString();

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		if (!Client.IsEmpty())
		{
			cout << "\nClient Found :-)\n";
			_PrintClient(Client);
		}
		else
		{
			cout << "\nClient Was not Found :-(\n";
		}

		
	}
};

