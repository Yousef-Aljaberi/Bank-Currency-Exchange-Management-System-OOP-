#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"

class clsUpdateCurrencyRateScreen:protected clsScreen
{
	static void _PrintCurrecyCard(clsCurrency Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "__________________________________________\n";
		cout << "\nCountry		: " << Currency.Country();
		cout << "\nCode    	: " << Currency.CountryCode();
		cout << "\nName    	: " << Currency.CurrencyName();
		cout << "\nRate    	: " << Currency.Rate();
		cout << "\n__________________________________________\n";
	}

	static void _UpdateRate(clsCurrency &Currency)
	{
		float NewRate = 0;

		cout << "\nUpdate Currency Rate:\n";
		cout << "____________________________\n";

		cout << "\nEnter New Rate: ";
		cin >> NewRate;
		
		Currency.UpdateRate(NewRate);

		cout << "\nCurrency Update Successfully :-)\n";
	}
public:

	static void ShowUpdateRateScreen()
	{
		_DrawScreenHeader("\t Update Rate Screen");

		string CountryCode;

		cout << "\nPlease Enter Currency Code? ";
		CountryCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CountryCode))
		{
			cout << "\nCureency Code Not Found, Please choose anthor one ? ";
			CountryCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency= clsCurrency::FindByCode(CountryCode);
		_PrintCurrecyCard(Currency);

		char answer = 'n';
		cout << "\nAre you sure you want to update the rate of this currency  y/n? ";
		cin >> answer;

		if (answer == 'y' || answer == 'Y')
		{
			_UpdateRate(Currency);
			_PrintCurrecyCard(Currency);
		}

	}
};

