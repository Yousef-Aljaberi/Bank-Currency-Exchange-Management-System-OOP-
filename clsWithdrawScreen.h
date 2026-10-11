#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"

class clsWithdrawScreen:protected clsScreen
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
	static string _ReadAccountNumber()
	{
		string AccountNumber = "";

		cout << "\nPlease Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		return AccountNumber;
	}

public:

	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("\t Withdraw Screen");

		string AccountNumber = "";
		AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with  [ " << AccountNumber << " ] Not Exist, Choose another one : ";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_PrintClient(Client);

		float Amount = 0;

		cout << "\nPlease Enter Withdraw Amount : ";
		Amount = clsInputValidate::ReadFloatNumber();

		char Answer = 'y';

		cout << "Are you sure you want to perform this transaction? y/n?  ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (Client.Withdraw(Amount))
			{
				cout << "\n Amount  Withdrew successfully.\n";
				cout << "\nNew Balance is: " << Client.AccountBalance;
			}
			else
			{
				cout << "\nCannot withdraw, Insuffecient Balance!\n";
				cout << "\nAmount to withdraw is: " << Amount;
				cout << "\nYour Balance is: " << Client.AccountBalance;
			}
		}
	}
	
};

