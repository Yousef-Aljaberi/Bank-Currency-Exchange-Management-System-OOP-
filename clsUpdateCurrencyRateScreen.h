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
		cout << "\nCode    	: " << Currency.CurrencyCode();
		cout << "\nName    	: " << Currency.CurrencyName();
		cout << "\nRate    	: " << Currency.Rate();
		cout << "\n__________________________________________\n";
	}


	static float _ReadRate()
	{
		float NewRate = 0;

		cout << "\nEnter New Rate: ";
		NewRate = clsInputValidate::ReadFloatNumber();

		return NewRate;
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
			cout << "\nCureency is not found, Please choose anthor one ? ";
			CountryCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency= clsCurrency::FindByCode(CountryCode);
		_PrintCurrecyCard(Currency);

		char answer = 'n';
		cout << "\nAre you sure you want to update the rate of this currency  y/n? ";
		cin >> answer;

		if (answer == 'y' || answer == 'Y')
		{
			cout << "\nUpdate Currency Rate:\n";
			cout << "____________________________\n";

			Currency.UpdateRate(_ReadRate());

			cout << "\nCurrency Update Successfully :-)\n";
			_PrintCurrecyCard(Currency);
		}

	}
};

