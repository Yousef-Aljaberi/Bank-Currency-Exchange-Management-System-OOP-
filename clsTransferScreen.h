#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
class clsTransferScreen:protected clsScreen
{
private:

	static string _ReadAccountNumber()
	{
		string AccountNumber;
		cout << "\nPlease Enter Account to Transfer From: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is Not Found, choose another one:  ";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}

	static float ReadAmount(clsBankClient SourceClient)
	{
		float Amount;

		cout << "\nEnter Transfer Amount? ";

		Amount = clsInputValidate::ReadDblNumber();

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
			Amount = clsInputValidate::ReadFloatNumber();
		}
		return Amount;
	}

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAccuntNumber : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

public:

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t Transfer Screent");

		
		clsBankClient Client1 = clsBankClient::Find(_ReadAccountNumber());
		_PrintClient(Client1);

		clsBankClient Client2 = clsBankClient::Find(_ReadAccountNumber());
		_PrintClient(Client2);

		float Amount = ReadAmount(Client1);

		char Answer;

		cout << "Are you sure you want to perform this Opration? y/n?  ";
		cin >> Answer;


		if (Answer == 'y' || Answer == 'Y')
		{
			if (Client1.Transfer(Amount, Client2))
			{
				cout << "\nDone successfully :-)\n\n";

			}
			else
			{
				cout << "\nTransfer Faild \n";
			}


			_PrintClient(Client1);
			_PrintClient(Client2);
		}

	}
};

